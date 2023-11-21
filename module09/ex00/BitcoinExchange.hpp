#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <map>
#include <string>
#include <algorithm>

#define DEFAULT_DB_FILEPATH "data.csv"

class BitcoinExchange
{
public:
	BitcoinExchange(const std::string& inputFile);
	BitcoinExchange(const std::string& inputFile, const std::string& secondDB);
	~BitcoinExchange();
	void Exchange();

	//debug
	void PrintDB();

public:
	class FileException : public std::exception
	{
	private:
		const char* mErrMsg;
	public:
		FileException(const char* err_msg);
		const char* what() const throw();
	};

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	void initExchanger(const std::string& intputFile, const std::string& dbFile);

private:
	std::map<std::string, double> mDB;
	std::ifstream mInputReader;
};