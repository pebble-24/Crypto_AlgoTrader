#include "portfolio_state_provider.hpp"

AlgoTrader::PortfolioStateProvider::PortfolioStateProvider(
	const AlgoTrader::Secrets &secrets)
	: m_Secrets(secrets)
{
}

AlgoTrader::PortfolioStateProvider::~PortfolioStateProvider()
{
}