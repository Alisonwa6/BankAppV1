#include <iostream>
#include <iomanip>
#include "BankAccount.h"

//#include <stdexcept>

BankAccount::BankAccount(const std::string &accHolder, const std::string &accNum, const double balance) {
    m_accHolder = accHolder;
    m_accNum = accNum;
    m_balance = balance;
}
BankAccount::~BankAccount(){
    // cleanup of objects and resources that the object used
    std::cout << "Bank Account Destructed\n";
}
void BankAccount::deposit(double amount) {
    if (amount > 0) {
       m_balance += amount;
    }
    else {
        //throw std::invalid_argument("Can't deposit balance");
        std::cout << "Can't deposit balance\n";
    }
}
bool BankAccount::withdraw(double amount) {
    if (amount <= m_balance - 5.0) {
        m_balance -= amount;
        return true;
    }
    else {
        return false;
    }
}
void BankAccount::display() {
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << std::endl;
    std::cout << "Client Name: " << m_accHolder << std::endl;
    std::cout << "Account Number: " << m_accNum << std::endl;
    std::cout << "Account Balance $" << m_balance << std::endl;
}