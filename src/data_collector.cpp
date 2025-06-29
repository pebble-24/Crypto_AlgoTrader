#include "../include/data_collector.hpp"
#include "../include/logger.hpp"
#include "../include/market_data.hpp"
#include "../include/interfaces/portfolio_state_provider.hpp"

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