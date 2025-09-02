// ************************************************************************** //
//                                                                            //
//                               Account.cpp                                   //
//                          42 C++ Module 00 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "Account.hpp"
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Coplien
Account::Account() : _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account(const Account& other)
    : _accountIndex(_nbAccounts), _amount(other._amount), _nbDeposits(other._nbDeposits), _nbWithdrawals(other._nbWithdrawals) {
    _nbAccounts++;
    _totalAmount += _amount;
    _totalNbDeposits += _nbDeposits;
    _totalNbWithdrawals += _nbWithdrawals;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created(copy)" << std::endl;
}

Account& Account::operator=(const Account& other) {
    if (this != &other) {
        // adjust totals: remove current, add other's
        _totalAmount -= _amount;
        _totalNbDeposits -= _nbDeposits;
        _totalNbWithdrawals -= _nbWithdrawals;
        _amount = other._amount;
        _nbDeposits = other._nbDeposits;
        _nbWithdrawals = other._nbWithdrawals;
        _totalAmount += _amount;
        _totalNbDeposits += _nbDeposits;
        _totalNbWithdrawals += _nbWithdrawals;
    }
    return *this;
}

Account::~Account() {
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Subject API
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << _amount;
    if (withdrawal > _amount) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount() const { return _amount; }

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t t = std::time(0);
    std::tm *lt = std::localtime(&t);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", lt);
    std::cout << "[" << buf << "]";
}
