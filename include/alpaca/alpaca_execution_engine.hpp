#ifndef ALGO_TRADER_ALPACA_EXECUTION_ENGINE_HPP
#define ALGO_TRADER_ALPACA_EXECUTION_ENGINE_HPP

#include "../interfaces/execution_engine.hpp"
#include "../secrets.hpp"

namespace AlgoTrader
{
class Alpaca_ExecutionEngine : public ExecutionEngine {
    public:
	Alpaca_ExecutionEngine(const AlgoTrader::Secrets &secrets);

	bool placeOrder(const AlgoTrader::Signal &signal,
			std::string_view symbol, double positionSize) override;
};
}

#endif