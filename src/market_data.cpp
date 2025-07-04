#include "../include/market_data.hpp"

AlgoTrader::MarketData::MarketData()
{
}

AlgoTrader::MarketData::~MarketData()
{
}

AlgoTrader::MarketData::MarketData(const MarketData &o)
{
	(void)o;
}

AlgoTrader::MarketData &AlgoTrader::MarketData::operator=(const MarketData &o)
{
	(void)o;
	return *this;
}

AlgoTrader::MarketData::MarketData(MarketData &&o) noexcept
{
	(void)o;
}

AlgoTrader::MarketData &AlgoTrader::MarketData::operator=(MarketData &&o) noexcept
{
	(void)o;
	return *this;
}