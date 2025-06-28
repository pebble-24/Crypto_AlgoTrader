#include <format>
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

#include "logger.hpp"

AlgoTrader::Logger::Logger()
{
	std::time_t now = std::time(nullptr);
	std::tm *t = std::localtime(&now);

	std::ostringstream oss;
	oss << "log_" << std::put_time(t, "%Y-%m-%d_%H-%M-%S") << ".txt";

	m_logOutput = std::ofstream(oss.str());

	if (!m_logOutput) {
		std::cerr << "Failed to open log file.\n";
		return;
	}

	m_logOutput << std::format("{} Initialised Logger\n", getTime());
}

AlgoTrader::Logger::~Logger()
{
	m_logOutput.close();
}

void AlgoTrader::Logger::logTradeImpl(const AlgoTrader::Signal &signal,
				      const std::string &symbol,
				      const double &positionSize,
				      const std::string &strategyName)
{
	logInternal(std::format("{} {} {} {} ${:.4f}\n", getTime(),
				strategyName, convertSignalToString(signal),
				symbol, positionSize));
}

void AlgoTrader::Logger::logImpl(const std::string &message)
{
	logInternal(std::format("{} {}\n", getTime(), message));
}

void AlgoTrader::Logger::logErrorImpl(const std::string &message)
{
	logInternal(std::format("{} ERROR: {}\n", getTime(), message));
}

void AlgoTrader::Logger::logInternal(const std::string &message)
{
	std::lock_guard<std::mutex> lock(m_mutex);
	if (m_logOutput) {
		m_logOutput << message;
		m_logOutput.flush();
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
