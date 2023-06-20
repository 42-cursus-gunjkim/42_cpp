#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout 
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount <<";"
		<< "created" << std::endl;
}

Account::~Account(void) {
	_nbAccounts--;
	_totalAmount -= this->_amount;

	_displayTimestamp();
	std::cout 
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount <<";"
		<< "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int prevAmount = _amount;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_amount += deposit;

	_displayTimestamp();
	std::cout 
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << prevAmount <<";"
		<< "deposit:" << deposit <<";"
		<< "amount:" << _amount <<";"
		<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount <<";";

	if (_amount < withdrawal)
	{
		std::cout 
			<< "withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout 
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	
	return true;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ";"
		<< "amount:" << _amount <<";"
		<< "deposits:" << _nbDeposits <<";"
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	// std::time_t timeNow = time(NULL);
	// std::tm *timeNowInfo = std::localtime(&timeNow);
	// char formatTime[18];

	// std::strftime(formatTime, 18, "[%Y%m%d_%H%M%S]", timeNowInfo);
	std::string formatTime = "[19920104_091532]";
	std::cout << formatTime << " ";
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount <<";"
		<< "deposits:" << _totalNbDeposits <<";"
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

