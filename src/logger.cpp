#include <format>
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <string_view>

#include "logger.hpp"

AlgoTrader::Logger::Logger()
{
	std::time_t now = std::time(nullptr);
	std::tm *t = std::localtime(&now);

	std::ostringstream oss;
	oss << "log_" << std::put_time(t, "%Y-%m-%d_%H-%M-%S") << ".txt";

	m_LogOutput = std::ofstream(oss.str());

	if (!m_LogOutput) {
		std::cerr << "Failed to open log file.\n";
		return;
	}

	m_LogOutput << std::format("{} Initialised Logger\n", getTime());
}

AlgoTrader::Logger::~Logger()
{
	m_LogOutput.close();
}

void AlgoTrader::Logger::logTradeImpl(const AlgoTrader::Signal &signal,
				      std::string_view symbol,
				      double positionSize,
				      std::string_view strategyName)
{
	logInternal(std::format("{} {} {} {} ${:.4f}\n", getTime(),
				strategyName, convertSignalToString(signal),
				symbol, positionSize));
}

void AlgoTrader::Logger::logImpl(std::string_view message)
{
	logInternal(std::format("{} {}\n", getTime(), message));
}

void AlgoTrader::Logger::logErrorImpl(std::string_view message)
{
	logInternal(std::format("{} ERROR: {}\n", getTime(), message));
}

void AlgoTrader::Logger::logInternal(std::string_view message)
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	if (m_LogOutput) {
		m_LogOutput << message;
		m_LogOutput.flush();
	}
}

std::string AlgoTrader::Logger::getTime()
{
	std::time_t now = std::time(nullptr);
	std::tm *t = std::localtime(&now);

	std::ostringstream oss;
	oss << std::put_time(t, "%Y-%m-%d_%H-%M-%S");
	return oss.str();
}

std::string
AlgoTrader::Logger::convertSignalToString(const AlgoTrader::Signal &signal)
{
	switch (signal) {
	case AlgoTrader::Signal::BUY:
		return "Buy";

	case AlgoTrader::Signal::SELL:
		return "Sell";

	case AlgoTrader::Signal::HOLD:
		return "Hold";

	case AlgoTrader::Signal::UNDEFINED:
	default:
		return "Undefined";
	}
}
