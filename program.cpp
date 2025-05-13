

#include <iostream>
using namespace std;

class BankAccount
{
protected:
    long long int accountNumber;
    string accountHolderName;
    double balance = 0;

public:
    void setaccount()
    {
        cout << "Enter Your Account No. : ";
        cin >> this->accountNumber;
        cout << "Enter Your Name : ";
        cin >> this->accountHolderName;
        // cout << "Enter your balance : ";
        // cin >> this->balance;
    }

    void deposit()
    {
        double deposit;
        cout << "Your Current Balance : " << this->balance << endl;

        cout << "Enter Amount You want to Deposit : ";
        cin >> deposit;

        balance += deposit;

        cout << "Deposit successful. New Balance: " << balance << endl;
    }

    void withdraw()
    {
        double amount;
        cout<<"Enter Amount for withdraw : ";
        cin>>amount;
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful. Remaining Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void getbalance()
    {
        cout << "------Done------" << endl;
        cout << "Your Current Balance is : " << balance << endl;
    }
    double getblance()
    {
        return balance;
    }
    void setBalance(double b)
    {
        balance = b;
    }
    void displayAccountInfo()
    {
        cout << "Your Account No. = " << this->accountNumber << endl;
        cout << "Account Holder Name = " << this->accountHolderName << endl;
        cout << "Your Balance = " << this->balance << endl;
    }
};

class SavingAccount : public BankAccount
{
    double interestRate = 5;

public:
    void Interest()
    {
        double interest, deposit, years;
        cout << "Enter Initial Deposit: ";
        cin >> deposit;
        setBalance(deposit);

        cout << "Enter number of years: ";
        cin >> years;

        interest = (deposit * interestRate * years) / 100;
        cout << "Interest Earned: " << interest << endl;
        cout << "Total Balance after " << years << " years: " << deposit + interest << endl;
    }
};
class CheckingAccount : public BankAccount
{
    double overdraftLimit = 5000;

public:
    void overDraft()
    {
        double amount;

        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance + overdraftLimit)
        {
            balance -= amount;
            cout << "Withdrawal successful. New Balance: " << balance << endl;
        }
        else
        {
            cout << "Transaction denied! Overdraft limit exceeded." << endl;
        }
    }
};

class FixedDepositAccount : public BankAccount
{
public:
    int term;
    double FD_interest = 7, interest, balance, maturity_amount;

    void calcInterest()
    {
        cout << "Enter your Current balance : ";
        cin >> balance;

        cout << "Enter Duration in year : ";
        cin >> term;

        interest = (balance * FD_interest * term) / 100;

        maturity_amount = balance + interest;

        cout << "Your amout after " << term << " year : " << maturity_amount << endl;
        setBalance(maturity_amount);
    }
};

int main()
{
    int choice;
    string account;
    BankAccount user;

    cout << "Enter Account Type For Open : ";
    cin >> account;
    if (account == "saving")
    {
        SavingAccount save;

        user.setaccount();

        save.Interest();

        cout << endl
             << "Congrats ! Your Account is open" << endl;

        do
        {

            cout << endl
                 << "PRESS 1 FOR DEPOSIT" << endl;
            cout << "PRESS 2 FOR WITHDRAWAL" << endl;
            cout << "PRESS 3 FOR CHECK BALANCE" << endl;
            cout << "PRESS 4 FOR ACCOUNT INFO" << endl;
            cout << "PRESS 0 FOR EXIT" << endl;

            cout << "ENTER YOUR CHOICE : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                save.deposit();
                break;

            case 2:
                save.withdraw();
                break;

            case 3:
                save.getbalance();
                break;

            case 4:
                save.displayAccountInfo();
                break;

            default:
                break;
            }

        } while (choice != 5);
    }
    else if (account == "checking")
    {
        CheckingAccount check;
        double balance;
        user.setaccount();

        cout << "Enter Your Current Balance : ";
        cin >> balance;
        check.setBalance(balance);

        check.overDraft();

        do
        {

            cout << endl
                 << "PRESS 1 FOR DEPOSIT" << endl;
            cout << "PRESS 2 FOR WITHDRAWAL" << endl;
            cout << "PRESS 3 FOR CHECK BALANCE" << endl;
            cout << "PRESS 4 FOR ACCOUNT INFO" << endl;
            cout << "PRESS 0 FOR EXIT" << endl;

            cout << "ENTER YOUR CHOICE : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                check.deposit();
                break;

            case 2:
                check.withdraw();
                break;

            case 3:
                check.getbalance();
                break;

            case 4:
                check.displayAccountInfo();
                break;

            default:
                break;
            }

        } while (choice != 5);
    }
    else if (account == "fixed")
    {
        FixedDepositAccount fix;
        fix.setaccount();

        fix.calcInterest();

        do
        {

            cout << endl
                 << "PRESS 1 FOR DEPOSIT" << endl;
            cout << "PRESS 2 FOR WITHDRAWAL" << endl;
            cout << "PRESS 3 FOR CHECK BALANCE" << endl;
            cout << "PRESS 4 FOR ACCOUNT INFO" << endl;
            cout << "PRESS 0 FOR EXIT" << endl;

            cout << "ENTER YOUR CHOICE : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                fix.deposit();
                break;

            case 2:
                fix.withdraw();
                break;

            case 3:
                fix.getbalance();
                break;

            case 4:
                fix.displayAccountInfo();
                break;

            default:
                break;
            }

        } while (choice != 5);
    }

    return 0;
}
