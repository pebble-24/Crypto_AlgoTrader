#ifndef ALGO_TRADER_COMMON_LOGGER_HPP
#define ALGO_TRADER_COMMON_LOGGER_HPP

#include <string>
#include <fstream>
#include <mutex>
#include <string_view>

namespace AlgoTrader
{
enum class LogSignal { UNDEFINED = 0, BUY, SELL, HOLD };

class Logger {
    public:
	static void logTrade(const AlgoTrader::LogSignal &signal, std::string_view symbol,
			     double positionSize, std::string_view strategyName)
	{
		getInstance().logTradeImpl(signal, symbol, positionSize, strategyName);
	}

	static void log(std::string_view message)
	{
		getInstance().logImpl(message);
	}

	static void logError(std::string_view message)
	{
		getInstance().logErrorImpl(message);
	}

    private:
	Logger();
	~Logger();

	Logger(const Logger &) = delete;
	Logger &operator=(const Logger &) = delete;

	Logger(Logger &&) = delete;
	Logger &operator=(Logger &&) = delete;

	static Logger &getInstance()
	{
		static Logger instance;
		return instance;
	}

	void logTradeImpl(const AlgoTrader::LogSignal &signal, std::string_view symbol,
			  double positionSize, std::string_view strategyName);

	void logImpl(std::string_view message);
	void logErrorImpl(std::string_view message);

	void logInternal(std::string_view message);

	std::string getTime();
	std::string convertSignalToString(const AlgoTrader::LogSignal &signal);

    private:
	std::ofstream m_LogOutput;
	mutable std::mutex m_Mutex;
};
}

#endif
