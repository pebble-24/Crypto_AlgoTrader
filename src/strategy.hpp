#ifndef ALGO_TRADER_STRATEGY_HPP
#define ALGO_TRADER_STRATEGY_HPP

#include <string>

#include "market_data.hpp"

namespace AlgoTrader
{
enum class Signal {
	UNDEFINED = 0, //
	BUY,
	SELL,
	HOLD
};

class Strategy {
    public:
	virtual ~Strategy() = default;

	virtual Signal evaluate(const AlgoTrader::MarketData &data) = 0;
	virtual inline std::string name() = 0;
};
}

#endif