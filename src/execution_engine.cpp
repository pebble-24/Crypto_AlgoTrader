#include "execution_engine.hpp"

AlgoTrader::ExecutionEngine::ExecutionEngine(
	std::shared_ptr<AlgoTrader::PortfolioStateProvider> provider)
	: m_Provider(provider)
{
}

AlgoTrader::ExecutionEngine::~ExecutionEngine()
{
}

void AlgoTrader::ExecutionEngine::placeOrder(const AlgoTrader::Signal &signal,
					     const double &positionSize)
{
}