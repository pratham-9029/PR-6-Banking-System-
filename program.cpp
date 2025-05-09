

#include <iostream>
using namespace std;

class BankAccount
{
private:
    long int accountNumber;
    string accountHolderName;
    double balance;

public:
    void setaccount()
    {
        cout << "Enter Your Account No. : ";
        cin >> this->accountNumber;
        cout << "Enter Your Name : ";
        getline(cin, this->accountHolderName);
        cout << "Enter your balance : ";
        cin >> this->balance;
    }

    void deposit()
    {
        double deposit;
        cout << "Your Current Balance : " << this->balance << endl;

        cout << "Enter Amount You want to Deposit : ";
        cin >> deposit;

        balance += deposit;

        cout << "----Deposit Done----" << endl;
    }
    void withdraw()
    {
        double withdraw;
        cout << "Enter withdraw amount : ";
        cin >> withdraw;

        balance = balance - withdraw;

        cout << "----Withdraw Done----" << endl;
    }
    void getbalance()
    {
        cout << "------Done------" << endl;
        cout << "Your Current Balance is : " << balance << endl;
    }
    void displayAccountInfo()
    {
        cout << "Your Account No. = " << this->accountNumber << endl;
        cout << "Account Holder Name = " << this->accountHolderName << endl;
        cout << "Your Balance = " << balance << endl;
    }
};

class SavingAccount : public BankAccount
{

};
class CheckingAccount : public BankAccount
{

};

class FixedDepositAccount : public BankAccount
{

};

int main()
{
    int choice;
    BankAccount user;

    user.setaccount();
    do
    {

        cout << endl << "PRESS 1 FOR DEPOSIT" << endl;
        cout << "PRESS 2 FOR WITHDRAWAL" << endl;
        cout << "PRESS 3 FOR CHECK BALANCE" << endl;
        cout << "PRESS 4 FOR ACCOUNT INFO" << endl;
        cout << "PRESS 0 FOR EXIT" << endl;

        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            user.deposit();
            break;

        case 2:
            user.withdraw();
            break;

        case 3:
            user.getbalance();
            break;

        case 4:
            user.displayAccountInfo();
            break;

        default:
            break;
        }

    } while (choice != 5);


    return 0;
}
