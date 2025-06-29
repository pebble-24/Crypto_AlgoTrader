#include "data_collector.hpp"
#include "logger.hpp"
#include "market_data.hpp"
#include "portfolio_state_provider.hpp"

AlgoTrader::DataCollector::DataCollector(std::shared_ptr<AlgoTrader::PortfolioStateProvider> provider)
	: m_Provider(provider)
{
	Logger::log("");
}

AlgoTrader::DataCollector::~DataCollector()
{
}

AlgoTrader::MarketData AlgoTrader::DataCollector::fetch()
{
}