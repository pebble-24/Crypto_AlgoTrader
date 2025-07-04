#ifndef ALGO_TRADER_RISK_MANAGER_HPP
#define ALGO_TRADER_RISK_MANAGER_HPP

#include <memory>

#include "market_data.hpp"
#include "interfaces/portfolio_state_provider.hpp"
#include "interfaces/strategy.hpp"

namespace AlgoTrader
{
class RiskManager {
    public:
	RiskManager(
		std::shared_ptr<AlgoTrader::PortfolioStateProvider> provider);
	~RiskManager();

	RiskManager(const RiskManager &) = delete;
	RiskManager &operator=(const RiskManager &) = delete;

	RiskManager(RiskManager &&) = delete;
	RiskManager &operator=(RiskManager &&) = delete;

	double calculate(const AlgoTrader::MarketData &data,
			 const AlgoTrader::Signal &signal);

    private:
	std::shared_ptr<AlgoTrader::PortfolioStateProvider> m_Provider;
};
}

#endif