#pragma once

#include "Helper.h"

#include <string>
#include <vector>
#include <sstream>

namespace helper {

	std::vector<std::string> stringSplit(std::string text, char delimiter) 
	{
		std::stringstream lineStream(text);
		std::string cell;
		std::vector<std::string> result;

		while (std::getline(lineStream, cell, delimiter)) {
			result.push_back(cell);
		}

		return result;
	}

	const char* getEnvOrDefault(const char* envName, const char* defaultValue)
	{
		const char* value = std::getenv(envName);
		return value ? value : defaultValue;
	}

	uint64_t getEnvOrDefault(const char* envName, uint64_t defaultValue)
	{
		const char* value = std::getenv(envName);
		return value ? processUInt64(value) : defaultValue;
	}

	int processInt(std::string data)
	{
		return strtol(data.c_str(), nullptr, 10);
	}

	uint64_t processUInt64(std::string data)
	{
		return strtoull(data.c_str(), nullptr, 10);
	}

	float processFloat(std::string data)
	{
		return strtof(data.c_str(), nullptr);
	}

	double processDouble(std::string data)
	{
		return strtod(data.c_str(), nullptr);
	}
}