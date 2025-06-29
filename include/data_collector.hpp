#ifndef ALGO_TRADER_DATA_COLLECTOR_HPP
#define ALGO_TRADER_DATA_COLLECTOR_HPP

#include <memory>

#include "market_data.hpp"
#include "interfaces/portfolio_state_provider.hpp"

namespace AlgoTrader
{
class DataCollector {
    public:
	DataCollector(
		std::shared_ptr<AlgoTrader::PortfolioStateProvider> provider);
	~DataCollector();

	DataCollector(const DataCollector &) = delete;
	DataCollector &operator=(const DataCollector &) = delete;

	DataCollector(DataCollector &&) = delete;
	DataCollector &operator=(DataCollector &&) = delete;

	AlgoTrader::MarketData fetch();

    private:
	std::shared_ptr<AlgoTrader::PortfolioStateProvider> m_Provider;
};
}

#endif