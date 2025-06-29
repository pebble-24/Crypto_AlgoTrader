#ifndef ALGO_TRADER_EXECUTION_ENGINE_HPP
#define ALGO_TRADER_EXECUTION_ENGINE_HPP

#include <memory>

#include "strategy.hpp"
#include "portfolio_state_provider.hpp"

namespace AlgoTrader
{
class ExecutionEngine {
    public:
	ExecutionEngine(std::shared_ptr<AlgoTrader::PortfolioStateProvider> provider);
	~ExecutionEngine();

	ExecutionEngine(const ExecutionEngine &) = delete;
	ExecutionEngine &operator=(const ExecutionEngine &) = delete;

	ExecutionEngine(ExecutionEngine &&) = delete;
	ExecutionEngine &operator=(ExecutionEngine &&) = delete;

	void placeOrder(const AlgoTrader::Signal &signal,
			const double &positionSize);

    private:
	std::shared_ptr<PortfolioStateProvider> m_Provider;
};
}

#endif