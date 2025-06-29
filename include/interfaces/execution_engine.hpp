#ifndef ALGO_TRADER_EXECUTION_ENGINE_HPP
#define ALGO_TRADER_EXECUTION_ENGINE_HPP

#include "strategy.hpp"

namespace AlgoTrader
{
class ExecutionEngine {
    public:
	virtual ~ExecutionEngine();

	ExecutionEngine(const ExecutionEngine &) = delete;
	ExecutionEngine &operator=(const ExecutionEngine &) = delete;

	ExecutionEngine(ExecutionEngine &&) = delete;
	ExecutionEngine &operator=(ExecutionEngine &&) = delete;

	virtual bool placeOrder(const AlgoTrader::Signal &signal,
				std::string_view symbol,
				double positionSize) = 0;
};
}

#endif