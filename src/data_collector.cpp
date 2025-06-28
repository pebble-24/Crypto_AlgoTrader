#include "data_collector.hpp"
#include "logger.hpp"
#include "market_data.hpp"

AlgoTrader::DataCollector::DataCollector(const AlgoTrader::Secrets &secrets)
	: m_Secrets(secrets)
{
	Logger::log("Initialising Data Collector");

	Logger::log("Initialised Data Collector");
}

AlgoTrader::DataCollector::~DataCollector()
{
}

AlgoTrader::MarketData AlgoTrader::DataCollector::fetch()
{
}