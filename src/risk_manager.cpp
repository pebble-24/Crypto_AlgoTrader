#include "../include/risk_manager.hpp"

AlgoTrader::RiskManager::RiskManager(
	std::shared_ptr<AlgoTrader::PortfolioStateProvider> provider)
	: m_Provider(provider)
{
}

AlgoTrader::RiskManager::~RiskManager()
{
}

double AlgoTrader::RiskManager::calculate(const AlgoTrader::MarketData &data,
					  const AlgoTrader::Signal &signal)
{
}
