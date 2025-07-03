#ifndef ALGO_TRADER_TRADER_HPP
#define ALGO_TRADER_TRADER_HPP

namespace AlgoTrader
{
class Trader {
    public:
	Trader(int argc, char **argv);
	~Trader();

	bool run();

    private:
	bool traderShouldRun();

    private:
	bool m_TraderShouldRun;
};
}

#endif