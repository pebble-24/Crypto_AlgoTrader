#ifndef ALGO_TRADER_LOGGER_HPP
#define ALGO_TRADER_LOGGER_HPP

#include <string>
#include <fstream>
#include <mutex>


#include "strategy.hpp"

namespace AlgoTrader
{
class Logger {
    public:
	static void logTrade(const AlgoTrader::Signal &signal,
			     const std::string &symbol,
			     const double &positionSize,
			     const std::string &strategyName)
	{
		getInstance().logTradeImpl(signal, symbol, positionSize,
					   strategyName);
	}

	static void log(const std::string &message)
	{
		getInstance().logImpl(message);
	}

	static void logError(const std::string &message)
	{
		getInstance().logErrorImpl(message);
	}

    private:
	Logger();
	~Logger();

	/* Delete copy and move constructors */
	Logger(const Logger &) = delete;
	Logger &operator=(const Logger &) = delete;

	Logger(Logger &&) = delete;
	Logger &operator=(Logger &&) = delete;

	static Logger &getInstance()
	{
		static Logger instance;
		return instance;
	}

	void logTradeImpl(const AlgoTrader::Signal &signal,
			  const std::string &symbol, const double &positionSize,
			  const std::string &strategyName);

	void logImpl(const std::string &message);
	void logErrorImpl(const std::string &message);

        void logInternal(const std::string &message);

	std::string getTime();
	std::string convertSignalToString(const AlgoTrader::Signal &signal);

    private:
	std::ofstream m_logOutput;
	mutable std::mutex m_mutex;
};
}

#endif