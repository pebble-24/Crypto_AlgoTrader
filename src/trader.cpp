#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

#include "../include/logger.hpp"

#include "../include/trader.hpp"

#include "../include/strategies/strategy_smacrossover.hpp"

#include "../include/alpaca/alpaca_provider.hpp"
#include "../include/alpaca/alpaca_execution_engine.hpp"

AlgoTrader::Trader::Trader(int argc, char **argv)
	: m_Secrets("../secrets/alpaca_key", "../secrets/alpaca_secret")
	, m_Provider(std::make_shared<AlgoTrader::Alpaca_Provider>(m_Secrets))
	, m_Collector(m_Provider)
	, m_ExecutionEngine(std::make_unique<AlgoTrader::Alpaca_ExecutionEngine>(m_Secrets))
        , m_RiskManager(m_Provider)
        , m_Strategy(std::make_unique<AlgoTrader::Strategy_SMACrossover>())
{
	if (m_Secrets.api_secret.empty() || m_Secrets.api_key.empty()) {
                AlgoTrader::Logger::log("Failed to read secrets!");
                std::cerr << "Failed to read secrets!" << std::endl;
		exit(EXIT_FAILURE);
	}

	AlgoTrader::Logger::log("Trading bot initialised");
}

AlgoTrader::Trader::~Trader()
{
}

bool AlgoTrader::Trader::run()
{
	AlgoTrader::Logger::log("Starting trading bot.");

	while (traderShouldRun()) {
		m_Provider->refreshAccountData();

		AlgoTrader::MarketData data = m_Collector.fetch();

		AlgoTrader::Signal signal = m_Strategy->evaluate(data);

		double positionSize = m_RiskManager.calculate(data, signal);

		if (signal != AlgoTrader::Signal::HOLD && positionSize > 0.0) {
			m_ExecutionEngine->placeOrder(signal, "AAPL", positionSize);
			AlgoTrader::Logger::logTrade(signal, "TMP", positionSize, m_Strategy->name());
		}

		std::this_thread::sleep_for(std::chrono::seconds(30));
	}

	return true;
}

bool AlgoTrader::Trader::traderShouldRun()
{
	return m_TraderShouldRun;
}