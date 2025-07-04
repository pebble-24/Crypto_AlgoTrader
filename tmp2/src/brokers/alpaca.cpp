#include "../../include/brokers/alpaca.hpp"

// Execution Engine
AlgoTrader::Alpaca_ExecutionEngine::Alpaca_ExecutionEngine(const AlgoTrader::Secrets &secrets)
	: ExecutionEngine()
	, m_Secrets(secrets)
{
}

AlgoTrader::Alpaca_ExecutionEngine::~Alpaca_ExecutionEngine()
{
}

bool AlgoTrader::Alpaca_ExecutionEngine::placeOrder(const AlgoTrader::Signal &signal,
						    std::string_view symbol, double positionSize)
{
	(void)signal;
	(void)symbol;
	(void)positionSize;

	return true;
}

// Provider
AlgoTrader::Alpaca_Provider::Alpaca_Provider(const AlgoTrader::Secrets &secrets)
	: PortfolioStateProvider()
	, m_Secrets(secrets)
{
}

AlgoTrader::Alpaca_Provider::~Alpaca_Provider()
{
}

void AlgoTrader::Alpaca_Provider::refreshAccountData()
{
}