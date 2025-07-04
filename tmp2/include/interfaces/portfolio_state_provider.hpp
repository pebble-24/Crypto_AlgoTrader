#ifndef ALGO_TRADER_PORTFOLIO_STATE_PROVIDER_HPP
#define ALGO_TRADER_PORTFOLIO_STATE_PROVIDER_HPP

namespace AlgoTrader
{
class PortfolioStateProvider {
    public:
	virtual ~PortfolioStateProvider() = default;

	PortfolioStateProvider(const PortfolioStateProvider &) = delete;
	PortfolioStateProvider &operator=(const PortfolioStateProvider &) = delete;

	PortfolioStateProvider(PortfolioStateProvider &&) = delete;
	PortfolioStateProvider &operator=(PortfolioStateProvider &&) = delete;

	virtual void refreshAccountData() = 0;

    protected:
	PortfolioStateProvider() = default;
};
}

#endif