//
// Created by brmcbrid on 10/15/2026.
//

#ifndef BANKAPPV1_BANKACCOUNT_H
#define BANKAPPV1_BANKACCOUNT_H
#include <string>

class BankAccount {
private:
    std::string m_accHolder;
    std::string m_accNum;
    double m_balance;
public:
    BankAccount(const std::string &accHolder, const std::string &accNum, double balance);
    ~BankAccount(); // default destructor
    void deposit(double amount);
    bool withdraw(double amount);
    void display();
};


#endif //BANKAPPV1_BANKACCOUNT_H
