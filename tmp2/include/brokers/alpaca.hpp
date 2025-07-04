#ifndef ALGO_TRADER_BROKERS_ALPACA_HPP
#define ALGO_TRADER_BROKERS_ALPACA_HPP

#include <mutex>
#include <unordered_map>

#include "../interfaces/execution_engine.hpp"
#include "../interfaces/portfolio_state_provider.hpp"

#include "../secrets.hpp"
#include "../account_data.hpp"
#include "../position.hpp"

namespace AlgoTrader
{
class Alpaca_ExecutionEngine : public ExecutionEngine {
    public:
	Alpaca_ExecutionEngine(const AlgoTrader::Secrets &secrets);
	~Alpaca_ExecutionEngine();

	bool placeOrder(const AlgoTrader::Signal &signal, std::string_view symbol,
			double positionSize) override;

    private:
	const AlgoTrader::Secrets &m_Secrets;
};

class Alpaca_Provider : public PortfolioStateProvider {
    public:
	Alpaca_Provider(const AlgoTrader::Secrets &secrets);
	~Alpaca_Provider();

	void refreshAccountData() override;

    private:
	const AlgoTrader::Secrets &m_Secrets;
	AlgoTrader::AccountData m_CachedAccountData;
	std::unordered_map<std::string, AlgoTrader::Position> m_Positions;
	mutable std::mutex m_Mutex;
};
}

#endif