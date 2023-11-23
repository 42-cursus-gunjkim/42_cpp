#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <map>
#include <string>
#include <algorithm>
#include <ctime>

#define DEFAULT_DB_FILEPATH "data.csv"

class BitcoinExchange
{
public:
	BitcoinExchange(const std::string& input_file);
	BitcoinExchange(const std::string& input_file, const std::string& second_db);
	~BitcoinExchange();
	void Exchange();

public:
	class FileException : public std::exception
	{
	private:
		std::string m_err_msg;
	public:
		FileException(const std::string& err_msg);
		 ~FileException() throw() {}
		const char* what() const throw();
	};

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	void initExchanger(const std::string& intput_file, const std::string& db_file);

private:
	std::map<std::string, double> m_db;
	std::ifstream m_input_reader;
};