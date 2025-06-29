
#include <memory>
#include <thread>
#include <chrono>

#include "../include/risk_manager.hpp"
#include "../include/data_collector.hpp"
#include "../include/secrets.hpp"
#include "../include/logger.hpp"

#include "../include/interfaces/strategy.hpp"
#include "../include/interfaces/execution_engine.hpp"
#include "../include/interfaces/portfolio_state_provider.hpp"

#include "../include/alpaca/alpaca_provider.hpp"
#include "../include/alpaca/alpaca_execution_engine.hpp"

#include "../include/strategies/strategy_smacrossover.hpp"

int main(int argc, char **argv)
{
	AlgoTrader::Secrets secrets("../secrets/alpaca_key",
				    "../secrets/alpaca_secret");

        if (secrets.api_secret.empty() || secrets.api_key.empty()) {
                return -1;
        }

	// Initialize modules
	std::shared_ptr<AlgoTrader::PortfolioStateProvider> provider =
		std::make_shared<AlgoTrader::Alpaca_Provider>(secrets);

	AlgoTrader::DataCollector collector(provider);
	std::unique_ptr<AlgoTrader::ExecutionEngine> execution = std::make_unique<AlgoTrader::Alpaca_ExecutionEngine>(secrets);
	AlgoTrader::RiskManager riskManager(provider);

	std::unique_ptr<AlgoTrader::Strategy> strategy =
		std::make_unique<AlgoTrader::Strategy_SMACrossover>();
	
                AlgoTrader::Logger::log("Starting trading bot.");

	while (true) {
                provider->refresh();

		AlgoTrader::MarketData data = collector.fetch();

		AlgoTrader::Signal signal = strategy->evaluate(data);

		double positionSize = riskManager.calculate(data, signal);

		if (signal != AlgoTrader::Signal::HOLD && positionSize > 0.0) {
			execution->placeOrder(signal, positionSize);
			AlgoTrader::Logger::logTrade(
				signal, "TMP", positionSize, strategy->name());
		}

		std::this_thread::sleep_for(std::chrono::seconds(30));
	}

	return 0;
}