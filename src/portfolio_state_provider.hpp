#ifndef ALGO_TRADER_PORTFOLIO_STATE_PROVIDER_HPP
#define ALGO_TRADER_PORTFOLIO_STATE_PROVIDER_HPP

#include "secrets.hpp"

namespace AlgoTrader
{
class PortfolioStateProvider {
    public:
	PortfolioStateProvider(const AlgoTrader::Secrets &secrets);
        ~PortfolioStateProvider();



    private:
	const AlgoTrader::Secrets &m_Secrets;
};
}

#endif