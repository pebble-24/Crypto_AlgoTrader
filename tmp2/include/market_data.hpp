#ifndef ALGO_TRADER_MARKET_DATA_HPP
#define ALGO_TRADER_MARKET_DATA_HPP

#include <string>

namespace AlgoTrader
{
class MarketData {
    public:
	MarketData();
	~MarketData();

	MarketData(const MarketData &o);
	MarketData &operator=(const MarketData &o);

	MarketData(MarketData &&o) noexcept;
	MarketData &operator=(MarketData &&o) noexcept;

    private:
	std::string m_Symbol;
	double m_Prices;
};
}

#endif