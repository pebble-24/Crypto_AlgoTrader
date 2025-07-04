#include "../include/strategy/smacrossover.hpp"

AlgoTrader::Strategy_SMACrossover::Strategy_SMACrossover()
	: Strategy()
{
}

AlgoTrader::Strategy_SMACrossover::~Strategy_SMACrossover()
{
}

AlgoTrader::Signal AlgoTrader::Strategy_SMACrossover::evaluate(const AlgoTrader::MarketData &data)
{
	(void)data;
	return AlgoTrader::Signal::BUY;
}
