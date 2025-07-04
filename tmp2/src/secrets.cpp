#include <string>
#include <fstream>

#include "../include/logger.hpp"
#include "../include/secrets.hpp"

AlgoTrader::Secrets::Secrets(const std::string &api_key_filename,
			     const std::string &api_secret_filename)
{
	std::ifstream api_key_file(api_key_filename);
	if (api_key_file.is_open()) {
		getline(api_key_file, api_key);
	} else {
                AlgoTrader::Logger::logError("Failed to open API Key file");
		api_key.clear();
	}

	std::ifstream api_secret_file(api_secret_filename);
	if (api_secret_file.is_open()) {
		getline(api_secret_file, api_secret);
	} else {
                AlgoTrader::Logger::logError("Failed to open API Secret file");
		api_secret.clear();
	}
}
