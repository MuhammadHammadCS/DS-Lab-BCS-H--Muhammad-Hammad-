#include "iostream"
using namespace std;

int main()
{
    int months;
    int newmonths;
    int ans;
    cout << "Enter the number of month to calculate expense: ";
    cin >> months;

    int* expense = new int[months];
    int* moreexp;
    int total = 0;
    for (int i = 0; i < months; i++)
    {
        cout << "Enter expense for month " << i + 1 << " : ";
        cin >> expense[i];
        total += expense[i]; 
    }
    cout << "Total Expense: " << total << endl;
    cout << "Average expense: " << total/months << endl;

    cout << "Do you want to track more months (1 for yes || 0 for no): ";
    cin >> ans;
    if(ans == 1)
    {
        cout << "Enter total number of months to track expense for: ";
        cin >> newmonths;
        moreexp = new int[newmonths];
        if(newmonths > months)
        {
            for (int i = 0; i < newmonths; i++)
            {
                moreexp[i] = expense[i];
            }
            for (int j = months; j < newmonths; j++)
            {
                cout << "Enter expense for month " << j + 1 << " : ";
                cin >> moreexp[j];
                total += moreexp[j];
            }
            cout << "New Total Expense: " << total << endl;
            cout << "New Average expense: " << total/newmonths << endl;
        }
        else
        {
            cout << "Invalid size entered!!!" << endl;
        }
    }
    else
    {
        cout << "No months added" << endl;
    }
    delete[] expense;
    delete[] moreexp;
}
