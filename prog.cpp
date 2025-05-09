#include <iostream>
using namespace std;

class BankAccount
{
private:
    long int accountNumber;
    string accountHolderName;
    double balance;

public:
    void setAccount()
    {
        cout << "Enter Account No. : ";
        cin >> this->accountNumber;
        cout << "Enter Account Holder Name : ";
        getline(cin, this->accountHolderName);
    }
    double deposit_amount;
    void Deposit()
    {
        cout << "Ente Amout You Want to Deposite : ";
        cin >> deposit_amount;

        this->balance += deposit_amount;
    }
    void Withdraw(double withdraw_amount)
    {
        cout << "Enter amount for withdraw : ";
        cin >> withdraw_amount;
    }
    void getBalance()
    {
        cout << "Your Current Balance : " << this->balance << endl;
    }
    void displayAccountInfo()
    {
        cout << "Your Account No. = " << this->accountNumber << endl;
        cout << "Account Holder Name = " << this->accountHolderName << endl;
        cout << "Your Balance = " << balance << endl;
    }
};

int main()
{
    BankAccount bank;

    bank.setAccount();
    bank.Deposit();
    bank.displayAccountInfo();

    return 0;
}