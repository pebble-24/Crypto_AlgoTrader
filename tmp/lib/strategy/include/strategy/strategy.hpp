#ifndef ALGO_TRADER_STRATEGY_HPP
#define ALGO_TRADER_STRATEGY_HPP

#include <string>

#include <core/data/market_data.hpp>

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

	Strategy(const Strategy &) = delete;
	Strategy &operator=(const Strategy &) = delete;

	Strategy(Strategy &&) = delete;
	Strategy &operator=(Strategy &&) = delete;

	virtual Signal evaluate(const AlgoTrader::MarketData &data) = 0;
	virtual inline std::string name() = 0;

    protected:
	Strategy() = default;
};
}

#endif