#ifndef ALGO_TRADER_ALPACA_PROVIDER_HPP
#define ALGO_TRADER_ALPACA_PROVIDER_HPP

#include <mutex>
#include <unordered_map>

#include "../interfaces/portfolio_state_provider.hpp"
#include "../secrets.hpp"
#include "../account_data.hpp"
#include "../position.hpp"

namespace AlgoTrader
{
class Alpaca_Provider : public PortfolioStateProvider {
    public:
	Alpaca_Provider(const AlgoTrader::Secrets &secrets);

    private:
	const AlgoTrader::Secrets &m_Secrets;
        AlgoTrader::AccountData m_CachedAccountData;
        std::unordered_map<std::string, AlgoTrader::Position> m_Positions;
        mutable std::mutex m_Mutex;
};
}

#endif