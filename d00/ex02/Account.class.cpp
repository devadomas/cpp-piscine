#include "Account.class.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_totalNbDeposits++;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << "amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	std::cout << "index:" << this->_accountIndex << "amount:" << this->_amount << ";closed" << std::endl;
}

void		Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index: " << this->_accountIndex << ";"
				<< "p_amount;" << this->_amount - deposit << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_deposits:" << this->_nbDeposits << std::endl;

}

bool		Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
		return false;
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Athis->_totalNbWithdrawals++;
	return true;
}

int			Account::checkAmount(void) const
{
	return this->_amount;
}

void		Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";"
				<< "total:" << Account::_totalAmount << ";"
				<< "deposits:" << Account::_nbDeposits << ";"
				<< "withdrawals:" << Account::_nbWithdrawals << std::endl;

}

void		Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << "deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
