#ifndef ALGO_TRADER_DATA_COLLECTOR_HPP
#define ALGO_TRADER_DATA_COLLECTOR_HPP

#include "market_data.hpp"
#include "secrets.hpp"

namespace AlgoTrader
{
class DataCollector {
    public:
	DataCollector(const AlgoTrader::Secrets &secrets);
	~DataCollector();

	/* Delete copy and move constructors */
	DataCollector(const DataCollector &) = delete;
	DataCollector &operator=(const DataCollector &) = delete;

	DataCollector(DataCollector &&) = delete;
	DataCollector &operator=(DataCollector &&) = delete;

	AlgoTrader::MarketData fetch();

    private:
	AlgoTrader::Secrets m_Secrets;
};
}

#endif