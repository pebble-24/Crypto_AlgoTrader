
#include <memory>
#include <thread>
#include <chrono>

#include "strategy.hpp"
#include "risk_manager.hpp"
#include "data_collector.hpp"
#include "execution_engine.hpp"
#include "secrets.hpp"
#include "logger.hpp"

#include "strategy_smacrossover.hpp"

int main(int argc, char **argv)
{
	AlgoTrader::Secrets secrets("../secrets/alpaca_key",
				    "../secrets/alpaca_secret");

	// Initialize modules
	AlgoTrader::DataCollector collector(secrets);
	std::unique_ptr<AlgoTrader::Strategy> strategy =
		std::make_unique<AlgoTrader::Strategy_SMACrossover>();
	AlgoTrader::ExecutionEngine execution(secrets);
	AlgoTrader::RiskManager riskManager;

	AlgoTrader::Logger::log("Starting trading bot.");

	while (true) {
		AlgoTrader::MarketData data = collector.fetch();

		AlgoTrader::Signal signal = strategy->evaluate(data);

		double positionSize = riskManager.calculate(data, signal);

		if (signal != AlgoTrader::Signal::HOLD && positionSize > 0.0) {
			execution.placeOrder(signal, positionSize);
			AlgoTrader::Logger::logTrade(
				signal, "TMP", positionSize, strategy->name());
		}

		std::this_thread::sleep_for(std::chrono::seconds(30));
	}

	return 0;
}