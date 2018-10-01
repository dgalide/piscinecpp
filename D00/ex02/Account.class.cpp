#include "Account.class.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// constructor
Account::Account(void) {

	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_accountIndex = _nbAccounts;
	_nbAccounts += 1;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// constructor overload
Account::Account(int initial_deposit) {

	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbAccounts += 1;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// destructor
Account::~Account(void) {
	_displayTimestamp();

	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int 	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int 	Account::getTotalAmount(void) {
	return _totalAmount;
}

int 	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int 	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void 	Account::displayAccountsInfos(void) {
	_displayTimestamp();

	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

int		Account::checkAmount( void ) const {
	return _amount;
}

void Account::makeDeposit(int deposit) {
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;

	_displayTimestamp();

	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {

	_displayTimestamp();

	if (_amount - withdrawal >= 0) {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;

		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	} else {
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return false;
	}
}

void Account::displayStatus(void) const {
	_displayTimestamp();

	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void) {
	time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int year = aTime->tm_year + 1900; // Year is # years since 1900
    std::cout << "[" << year << month << day << "_153629]";
}
