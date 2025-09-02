// ************************************************************************** //
//                                                                            //
//                                main.cpp                                     //
//                          42 C++ Module 00 - ex02                            //
//                                                                            //
// ************************************************************************** //
#include "Account.hpp"
#include <vector>

int main() {
    Account acc1(42);
    Account acc2(54);
    Account acc3(957);
    Account acc4(432);
    Account acc5(1234);
    Account acc6(0);
    Account acc7(754);
    Account acc8(16576);

    Account::displayAccountsInfos();

    acc1.makeDeposit(5);
    acc2.makeDeposit(765);
    acc3.makeDeposit(564);
    acc4.makeDeposit(2);
    acc5.makeDeposit(87);
    acc6.makeDeposit(23);
    acc7.makeDeposit(9);
    acc8.makeDeposit(20);

    acc1.makeWithdrawal(657);
    acc2.makeWithdrawal(34);
    acc3.makeWithdrawal(657);
    acc4.makeWithdrawal(4);
    acc5.makeWithdrawal(76);
    acc6.makeWithdrawal(657);
    acc7.makeWithdrawal(765);
    acc8.makeWithdrawal(657);

    Account::displayAccountsInfos();

    acc1.displayStatus();
    acc2.displayStatus();
    acc3.displayStatus();
    acc4.displayStatus();
    acc5.displayStatus();
    acc6.displayStatus();
    acc7.displayStatus();
    acc8.displayStatus();

    return 0;
}
