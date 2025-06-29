#ifndef ALGO_TRADER_SECRETS_HPP
#define ALGO_TRADER_SECRETS_HPP

#include <string>
#include <string_view>

namespace AlgoTrader
{
struct Secrets {
    public:
	Secrets(const std::string &api_key_filename,
		const std::string &api_secret_filename);
	~Secrets() = default;

	Secrets(const Secrets &o) = default;
	Secrets &operator=(const Secrets &o) = default;

	Secrets(Secrets &&o) noexcept = default;
	Secrets &operator=(Secrets &&o) noexcept = default;

    public:
	std::string api_key;
	std::string api_secret;
};
}

#endif