#include "BitcoinExchange.hpp"

bool splitKeyValue(std::string line, std::string& keyOut, double& valueOut, char separator)
{
	std::stringstream converter(line);
	std::string garbage;

	std::size_t pos = line.find(separator);
	keyOut = line.substr(0, pos);
	keyOut.erase(keyOut.find_last_not_of(" \t\n\r\f\v") + 1);
	std::getline(converter >> std::ws, garbage, separator);
	if (converter.fail())
		return false;
	converter >> valueOut;
	if (converter.fail())
		return false;
	return true;
}

void BitcoinExchange::initExchanger(const std::string& inputFile, const std::string& dbFile)
{
	std::ifstream dbReader(dbFile);
	if (dbReader.fail() == true)
		throw FileException("DB file open fail...");
	mInputReader.open(inputFile.c_str());
	if (mInputReader.fail() == true)
		throw FileException("Input file open fail...");
	
	std::string line;
	std::getline(dbReader, line);
	if (line != "date,exchange_rate")
		throw FileException("Wrong header in db file");
	std::getline(mInputReader, line);
	if (line != "date | value")
		throw FileException("Wrong header in input file");

	std::getline(dbReader, line);
	std::string key;
	double value;
	while (dbReader.fail() == false)
	{
		if (splitKeyValue(line, key, value, ',') == false)
			throw FileException("Wrong file format");
		mDB.insert(std::pair<std::string, double>(key, value));
		std::getline(dbReader, line);
	}
	dbReader.close();
}

BitcoinExchange::BitcoinExchange(const std::string& inputFile)
{
	initExchanger(inputFile, DEFAULT_DB_FILEPATH);
}

BitcoinExchange::BitcoinExchange(const std::string& inputFile, const std::string& secondDB)
{
	initExchanger(inputFile, secondDB);
}

BitcoinExchange::~BitcoinExchange()
{
	mInputReader.close();
}

void BitcoinExchange::Exchange()
{
	std::string line;
	std::string key;
	double value;

	getline(mInputReader, line);
	while (mInputReader.fail() == false)
	{
		// refactoring 필요
		if (splitKeyValue(line, key, value, '|') == false)
			std::cout << "Error: invalid data format\n";
		else if (value <= 0 || value >= 1000)
			std::cout << "Error: too large number\n";
		else if (key < mDB.begin()->first)
			std::cout << "Error: bad input => " << key << "\n";
		else
		{
			std::map<std::string, double>::iterator it = mDB.find(key);
			if (it == mDB.end())
			{
				it = mDB.lower_bound(key);
				it = it--;
			}
			std::cout << key << " => " << value << " = " << it->first << "//" << it->second << " * " << value << " = " << it->second * value << std::endl;
		}
		getline(mInputReader, line);
	}
}

void BitcoinExchange::PrintDB()
{
	for (auto iter = mDB.begin(); iter != mDB.end(); iter++)
	{
		std::cout << "(" << iter->first << " , " << iter->second << " )\n";
	}
	std::cout << "\n";
}

BitcoinExchange::FileException::FileException(const char* errMsg)
{
	mErrMsg = errMsg;
}

const char* BitcoinExchange::FileException::what() const throw()
{
	return mErrMsg;
}
