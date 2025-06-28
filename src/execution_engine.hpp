#ifndef ALGO_TRADER_EXECUTION_ENGINE_HPP
#define ALGO_TRADER_EXECUTION_ENGINE_HPP

#include "secrets.hpp"
#include "strategy.hpp"

namespace AlgoTrader
{
class ExecutionEngine {
    public:
	ExecutionEngine(const AlgoTrader::Secrets &secrets);
	~ExecutionEngine();

	/* Delete copy and move constructors */
	ExecutionEngine(const ExecutionEngine &) = delete;
	ExecutionEngine &operator=(const ExecutionEngine &) = delete;

	ExecutionEngine(ExecutionEngine &&) = delete;
	ExecutionEngine &operator=(ExecutionEngine &&) = delete;

	void placeOrder(const AlgoTrader::Signal &signal,
			const double &positionSize);

    private:
	Secrets m_Secrets;
};
}

#endif