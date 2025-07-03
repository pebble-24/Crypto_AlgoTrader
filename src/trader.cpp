#include "../include/trader.hpp"

AlgoTrader::Trader::Trader(int argc, char **argv)
{
	AlgoTrader::Secrets secrets("../secrets/alpaca_key", "../secrets/alpaca_secret");

	if (secrets.api_secret.empty() || secrets.api_key.empty()) {
		return -1;
	}

	// Initialize modules
	std::shared_ptr<AlgoTrader::PortfolioStateProvider> provider =
		std::make_shared<AlgoTrader::Alpaca_Provider>(secrets);

	AlgoTrader::DataCollector collector(provider);

	std::unique_ptr<AlgoTrader::ExecutionEngine> execution =
		std::make_unique<AlgoTrader::Alpaca_ExecutionEngine>(secrets);

	AlgoTrader::RiskManager riskManager(provider);

	std::unique_ptr<AlgoTrader::Strategy> strategy =
		std::make_unique<AlgoTrader::Strategy_SMACrossover>();

	AlgoTrader::Logger::log("Starting trading bot.");
}

AlgoTrader::Trader::~Trader()
{

}

bool AlgoTrader::Trader::run()
{
        while (traderShouldRun()) {
		provider->refreshAccountData();

		AlgoTrader::MarketData data = collector.fetch();

		AlgoTrader::Signal signal = strategy->evaluate(data);

		double positionSize = riskManager.calculate(data, signal);

		if (signal != AlgoTrader::Signal::HOLD && positionSize > 0.0) {
			execution->placeOrder(signal, "AAPL", positionSize);
			AlgoTrader::Logger::logTrade(signal, "TMP", positionSize, strategy->name());
		}

		std::this_thread::sleep_for(std::chrono::seconds(30));
	}

        return true;
}

bool AlgoTrader::Trader::traderShouldRun()
{
        return m_TraderShouldRun;
}