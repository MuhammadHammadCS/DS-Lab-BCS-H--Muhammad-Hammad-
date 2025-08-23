#include "iostream"
using namespace std;

class BankAccount
{
    public:
    int balance;
    BankAccount()
    {
        //name = "account1";
        balance = 100;
    }
    BankAccount(int bal)
    {
        balance = bal;
    }
    BankAccount(BankAccount &ac)
    {
        balance = ac.balance;
        balance -= 200;
    }
    void print()
    {
        cout << "Balance: " << balance << endl;
    }
   
};
int main() {
    BankAccount account1;
    cout << "Account 1\n";
    account1.print();
    BankAccount account2(1000);
    cout << "Account 2\n";
    account2.print();
    BankAccount account3(account2);
    cout << "Account 3\n";
    account3.print();
    cout << "Account 2\n";
    account2.print();
    return 0;
}
