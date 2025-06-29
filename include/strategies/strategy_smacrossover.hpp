#ifndef ALGO_TRADER_STRATEGY_SMACROSSOVER_HPP
#define ALGO_TRADER_STRATEGY_SMACROSSOVER_HPP

#include "../interfaces/strategy.hpp"

namespace AlgoTrader
{
class Strategy_SMACrossover : public Strategy {
    public:
	Strategy_SMACrossover();
	~Strategy_SMACrossover();

	Strategy_SMACrossover(const Strategy_SMACrossover &) = delete;
	Strategy_SMACrossover &operator=(const Strategy_SMACrossover &) = delete;

	Strategy_SMACrossover(Strategy_SMACrossover &&) = delete;
	Strategy_SMACrossover &operator=(Strategy_SMACrossover &&) = delete;

	Signal evaluate(const AlgoTrader::MarketData &data) override;

	inline std::string name() override
	{
		return "SMACrossover";
	}
};
}

#endif