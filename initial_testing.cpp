#include <cpr/api.h>
#include <cpr/cpr.h>
#include <cpr/cprtypes.h>
#include <cpr/response.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <optional>

struct api_secrets {
    public:
	api_secrets(const std::string &api_key_filename,
		    const std::string &api_secret_filename)
	{
		std::ifstream api_file(api_key_filename);
		getline(api_file, api_key);
		api_file = std::ifstream(api_secret_filename);
		getline(api_file, api_secret);
	}

    public:
	std::string api_key;
	std::string api_secret;
};

enum class response_type {
	undefined = 0,
	account,
	assets,
	orders,
	positions
};

std::optional<cpr::Response> get_response(enum response_type type,
					  const api_secrets &secrets)
{
	std::string url;

	switch (type) {
	case response_type::account:
		url = "account";
		break;
	case response_type::assets:
		url = "assets";
		break;
	case response_type::orders:
		url = "orders";
		break;
	case response_type::positions:
		url = "positions";
		break;
	case response_type::undefined:
	default:
		break;
	}

	cpr::Response r;

	if (url == "assets") {
		r = cpr::Get(
			cpr::Url{ "https://paper-api.alpaca.markets/v2/" +
				  url },
			cpr::Parameters{ { "asset_class", "crypto" } },
			cpr::Header{ { "APCA-API-KEY-ID", secrets.api_key },
				     { "APCA-API-SECRET-KEY",
				       secrets.api_secret } });
	} else {
		r = cpr::Get(
			cpr::Url{ "https://paper-api.alpaca.markets/v2/" +
				  url },
			cpr::Header{ { "APCA-API-KEY-ID", secrets.api_key },
				     { "APCA-API-SECRET-KEY",
				       secrets.api_secret } });
	}

	if (r.status_code != 200) {
		std::ofstream error("error.log", std::ios::app);
		error << "Error fetching '" << url << "' — HTTP "
		      << r.status_code << "\n";
		error << "Body: " << r.text << "\n\n";
		return std::nullopt;
	}

	if (r.text.empty()) {
		std::ofstream error("error.log", std::ios::app);
		error << "Empty response for '" << url << "'\n";
		return std::nullopt;
	}

	return r;
}

struct request {
	void get_request(const api_secrets &secrets)
	{
		if (auto r = get_response(response_type::account, secrets)) {
			account = nlohmann::json::parse(r->text);
		}

		if (auto r = get_response(response_type::assets, secrets)) {
			assets = nlohmann::json::parse(r->text);
		}

		if (auto r = get_response(response_type::orders, secrets)) {
			orders = nlohmann::json::parse(r->text);
		}

		if (auto r = get_response(response_type::positions, secrets)) {
			positions = nlohmann::json::parse(r->text);
		}
	}

	void dump_to_files()
	{
		std::ofstream output("request_account.json");
		output << account.dump(4);
		output = std::ofstream("request_assets.json");
		output << assets.dump(4);
		output = std::ofstream("request_orders.json");
		output << orders.dump(4);
		output = std::ofstream("request_positions.json");
		output << positions.dump(4);
		output.close();
	}

	nlohmann::basic_json<> account;
	nlohmann::basic_json<> assets;
	nlohmann::basic_json<> orders;
	nlohmann::basic_json<> positions;
};

int main()
{
	api_secrets secrets("../secrets/alpaca_key",
			    "../secrets/alpaca_secret");

	request r;
	r.get_request(secrets);
	r.dump_to_files();
}
