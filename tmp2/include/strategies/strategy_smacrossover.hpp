#ifndef ALGO_TRADER_STRATEGY_SMACROSSOVER_HPP
#define ALGO_TRADER_STRATEGY_SMACROSSOVER_HPP

#include "../interfaces/strategy.hpp"

namespace AlgoTrader
{
class Strategy_SMACrossover : public Strategy {
    public:
	Strategy_SMACrossover();
	~Strategy_SMACrossover();

	Signal evaluate(const AlgoTrader::MarketData &data) override;

	inline std::string name() override
	{
		return "SMACrossover";
	}
};
}

#endif