#include <string>
#include <fstream>

#include "secrets.hpp"

AlgoTrader::Secrets::Secrets(const std::string &api_key_filename,
			     const std::string &api_secret_filename)
{
	std::ifstream api_file(api_key_filename);
	getline(api_file, api_key);
	api_file = std::ifstream(api_secret_filename);
	getline(api_file, api_secret);
}
