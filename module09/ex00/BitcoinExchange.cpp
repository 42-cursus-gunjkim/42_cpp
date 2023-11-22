#include "BitcoinExchange.hpp"

bool isValidDate(const std::string& date)
{
	std::size_t pos = date.find('-', 0);
	std::size_t second_pos = date.find('-', pos + 1);
	if (date.length() > 10 || pos != 4 || second_pos != 7)
		return false;
	struct tm time_struct;

	if (strptime(date.c_str(), "%Y-%m-%d", &time_struct) != NULL)
	{
		switch (time_struct.tm_mon)
		{
			case 0:
				if (time_struct.tm_mday > 31)
					return false;
				break;
			case 1:
				if (time_struct.tm_year % 4 == 0 && !(time_struct.tm_year % 100 == 0 && time_struct.tm_year % 400 != 0))
				{
					if (time_struct.tm_mday > 29)
						return false;
				}
				else 
				{
					if (time_struct.tm_mday > 28)
						return false;
				}
				break;
			case 2:
				if (time_struct.tm_mday > 31)
					return false;
				break;
			case 3:
				if (time_struct.tm_mday > 30)
					return false;
				break;
			case 4:
				if (time_struct.tm_mday > 31)
					return false;
				break;
			case 5:
				if (time_struct.tm_mday > 30)
					return false;
				break;
			case 6:
				if (time_struct.tm_mday > 31)
					return false;
				break;
			case 7:
				if (time_struct.tm_mday > 31)
					return false;
				break;
			case 8:
				if (time_struct.tm_mday > 30)
					return false;
				break;
			case 9:
				if (time_struct.tm_mday > 31)
					return false;
				break;
			case 10:
				if (time_struct.tm_mday > 30)
					return false;
				break;
			case 11:
				if (time_struct.tm_mday > 31)
					return false;
				break;
			default:
				return false;
		}
		return true;
    }
	return false;
}

bool splitDateValue(const std::string& line, std::string& date_out, double& value_out, const char separator)
{
	std::stringstream converter(line);
	std::string garbage;

	std::size_t pos = line.find(separator);
	date_out = line.substr(0, pos);
	date_out.erase(date_out.find_last_not_of(" \t\n\r\f\v") + 1);
	std::getline(converter >> std::ws, garbage, separator);
	if (converter.fail() || isValidDate(date_out) == false)
		return false;
	converter >> value_out;
	if (converter.fail())
		return false;
	return true;
}

void BitcoinExchange::initExchanger(const std::string& input_file, const std::string& db_file)
{
	std::ifstream db_reader(db_file);
	if (db_reader.fail() == true)
		throw FileException("DB file open fail...");
	m_input_reader.open(input_file.c_str());
	if (m_input_reader.fail() == true)
		throw FileException("Input file open fail...");
	
	std::string line;
	std::getline(db_reader, line);
	if (line != "date,exchange_rate")
		throw FileException("Wrong header in db file");
	std::getline(m_input_reader, line);
	if (line != "date | value")
		throw FileException("Wrong header in input file");

	std::getline(db_reader, line);
	std::string date;
	double value;
	while (db_reader.fail() == false)
	{
		if (splitDateValue(line, date, value, ',') == false)
			throw FileException("Wrong file format");
		m_db.insert(std::pair<std::string, double>(date, value));
		std::getline(db_reader, line);
	}
	db_reader.close();
}

BitcoinExchange::BitcoinExchange(const std::string& input_file)
{
	initExchanger(input_file, DEFAULT_DB_FILEPATH);
}

BitcoinExchange::BitcoinExchange(const std::string& input_file, const std::string& second_db)
{
	initExchanger(input_file, second_db);
}

BitcoinExchange::~BitcoinExchange()
{
	m_input_reader.close();
}

void BitcoinExchange::Exchange()
{
	std::string line;
	std::string date;
	double value;

	getline(m_input_reader, line);
	while (m_input_reader.fail() == false)
	{
		// refactoring 필요
		if (splitDateValue(line, date, value, '|') == false)
			std::cout << "Error: bad input => " << date << "\n";
		else if (date < m_db.begin()->first)
			std::cout << "Error: bad input => " << date << "\n"; 
		else if (value <= 0 || value >= 1000)
			std::cout << "Error: invalid value => " << value << "\n";
		else
		{
			std::map<std::string, double>::iterator it = m_db.find(date);
			if (it == m_db.end())
			{
				it = m_db.lower_bound(date);
				it = it--;
			}
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		}
		getline(m_input_reader, line);
	}
}

void BitcoinExchange::PrintDB()
{
	for (auto iter = m_db.begin(); iter != m_db.end(); iter++)
	{
		std::cout << "(" << iter->first << " , " << iter->second << " )\n";
	}
	std::cout << "\n";
}

BitcoinExchange::FileException::FileException(const char* err_msg)
{
	m_err_msg = err_msg;
}

const char* BitcoinExchange::FileException::what() const throw()
{
	return m_err_msg;
}
