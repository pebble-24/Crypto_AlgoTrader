#ifndef ALGO_TRADER_TRADER_HPP
#define ALGO_TRADER_TRADER_HPP

#include "data_collector.hpp"
#include "interfaces/execution_engine.hpp"
#include "interfaces/portfolio_state_provider.hpp"
#include "interfaces/strategy.hpp"
#include "risk_manager.hpp"
#include "secrets.hpp"
#include <memory>

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
	AlgoTrader::Secrets m_Secrets;
	std::shared_ptr<AlgoTrader::PortfolioStateProvider> m_Provider;

	AlgoTrader::DataCollector m_Collector;
        AlgoTrader::RiskManager m_RiskManager;

        std::unique_ptr<AlgoTrader::ExecutionEngine> m_ExecutionEngine;
        std::unique_ptr<AlgoTrader::Strategy> m_Strategy;

	bool m_TraderShouldRun;
};
}

#endif