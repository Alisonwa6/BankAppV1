//
// Created by awalt on 10/27/2026.
//

#ifndef BANKAPPV1_0_CHECKINGACCOUNT_H
#define BANKAPPV1_0_CHECKINGACCOUNT_H
#include <iostream>

#include "BankAccount.h"

class CheckingAccount:public BankAccount {
private:
    double m_overDraftLimit;
public:
    CheckingAccount(const std::string &accHolder, const std::string &accNum, double balance, double overDraft):BankAccount(accHolder, accNum, balance) {
        m_overDraftLimit = overDraft;
    };
    ~CheckingAccount() {
        // cleanup of objects and resources that the object used
        std::cout << "Checking Account Destructed\n";
    };
    bool withdraw(double amount) {  // override base class withdraw method - form of polymorphism.
        if (amount <= m_balance + m_overDraftLimit) {
            if (amount > m_balance) {
                m_overDraftLimit += (m_balance - amount);
                m_balance -= amount;
                return true;
            }
        }
        if (m_balance < 0 && amount <= m_overDraftLimit) {
            m_overDraftLimit -= amount;
            m_balance -= amount;
            return true;
        }
        return false;

    };
    void display() {
        BankAccount::display();
        std::cout << "Overdraft Limit: $" << m_overDraftLimit << "\n" << std::endl;
    };
};

#endif //BANKAPPV1_0_CHECKINGACCOUNT_H
