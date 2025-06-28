#include "execution_engine.hpp"

AlgoTrader::ExecutionEngine::ExecutionEngine(const AlgoTrader::Secrets &secrets)
	: m_Secrets(secrets)
{
}

AlgoTrader::ExecutionEngine::~ExecutionEngine()
{
}

void AlgoTrader::ExecutionEngine::placeOrder(const AlgoTrader::Signal &signal,
					     const double &positionSize)
{
}