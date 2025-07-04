#include <cstdlib>
#include <iostream>

#include "../include/trader.hpp"
#include "../include/logger.hpp"

int main(int argc, char **argv)
{
	AlgoTrader::Trader trader(argc, argv);

	if (!trader.run()) {
		AlgoTrader::Logger::log("Trader Failed");
		std::cerr << "Trader Failed" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}