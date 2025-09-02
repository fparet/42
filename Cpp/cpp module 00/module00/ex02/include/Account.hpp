// ************************************************************************** //
//                                                                            //
//                               Account.hpp                                   //
//                          42 C++ Module 00 - ex02                            //
//                                                                            //
// ************************************************************************** //
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account {
public:
    // Coplien
    Account();
    Account(const Account& other);
    Account& operator=(const Account&);
    ~Account();

    // Subject API
    explicit Account(int initial_deposit);

    static int  getNbAccounts();
    static int  getTotalAmount();
    static int  getNbDeposits();
    static int  getNbWithdrawals();
    static void displayAccountsInfos();

    void        makeDeposit(int deposit);
    bool        makeWithdrawal(int withdrawal);
    int         checkAmount() const;
    void        displayStatus() const;

private:
    static void _displayTimestamp();

    static int  _nbAccounts;
    static int  _totalAmount;
    static int  _totalNbDeposits;
    static int  _totalNbWithdrawals;

    int         _accountIndex;
    int         _amount;
    int         _nbDeposits;
    int         _nbWithdrawals;
};

#endif // ACCOUNT_HPP
