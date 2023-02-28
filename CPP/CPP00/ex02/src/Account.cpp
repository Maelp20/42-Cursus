/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:26:20 by mpignet           #+#    #+#             */
/*   Updated: 2023/02/28 17:41:10 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void ) {

	char tmp[20];

	time_t	rawtime = time(&rawtime);
	struct tm	*timestamp = localtime(&rawtime);
	strftime( tmp , 20,"%d%m%Y_%H%M%S", timestamp);
	std::cout << "[" << tmp << "]";
}

Account::Account(int initial_deposit) {

	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	_displayTimestamp();
	std::cout << "index :" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";created" << std::endl;
	return ;
}

Account::~Account(void) {
	
	Account::_nbAccounts--;
	_displayTimestamp();
	std::cout << "index :" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";closed" << std::endl;
	return ;
}

int	Account::getNbAccounts( void ) { return (_nbAccounts); }

int	Account::getTotalAmount( void ) { return (_totalAmount); }

int	Account::getNbDeposits( void ) { return (_totalNbDeposits); }

int	Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

void	Account::displayAccountsInfos( void ) {

	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}


void	Account::makeDeposit( int deposit ) {

	_displayTimestamp();
	std::cout << "index :" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	_displayTimestamp();
	std::cout << "index :" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (this->_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" <<std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals<< std::endl;
	return (true);
}

int		Account::checkAmount( void ) const {

	return (this->_amount);
}

void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout << "index :" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}