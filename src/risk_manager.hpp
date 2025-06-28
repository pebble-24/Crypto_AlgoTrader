#ifndef ALGO_TRADER_RISK_MANAGER_HPP
#define ALGO_TRADER_RISK_MANAGER_HPP

#include "market_data.hpp"
#include "strategy.hpp"

namespace AlgoTrader
{
class RiskManager {
    public:
	RiskManager();
	~RiskManager();

	/* Delete copy and move constructors */
	RiskManager(const RiskManager &) = delete;
	RiskManager &operator=(const RiskManager &) = delete;

	RiskManager(RiskManager &&) = delete;
	RiskManager &operator=(RiskManager &&) = delete;

	double calculate(const AlgoTrader::MarketData &data,
			 const AlgoTrader::Signal &signal);
};
}

#endif