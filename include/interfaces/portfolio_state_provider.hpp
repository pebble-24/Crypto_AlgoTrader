#ifndef ALGO_TRADER_PORTFOLIO_STATE_PROVIDER_HPP
#define ALGO_TRADER_PORTFOLIO_STATE_PROVIDER_HPP

namespace AlgoTrader
{
struct Order {
        
};

class PortfolioStateProvider {
    public:
	virtual ~PortfolioStateProvider() = 0;

	PortfolioStateProvider(const PortfolioStateProvider &) = delete;
	PortfolioStateProvider &operator=(const PortfolioStateProvider &) = delete;

	PortfolioStateProvider(PortfolioStateProvider &&) = delete;
	PortfolioStateProvider &operator=(PortfolioStateProvider &&) = delete;

	virtual void refresh() = 0;
};
}

#endif