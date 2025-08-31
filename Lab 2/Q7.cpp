#include "iostream"
using namespace std;

int main()
{
    int row;
    cout << "Enter the number of departments: ";
    cin >> row;
    int** dept = new int*[row];
    int *emp = new int[row];
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        cout << "Enter the number of employees for department " << i + 1 << ": ";
        cin >> emp[i];
        dept[i] = new int[emp[i]];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < emp[i]; j++)
        {
            cout << "Enter the salary of employee " << j + 1 << " from dept " << i + 1 << ": ";
            cin >> dept[i][j];   
        }
        cout << endl;
    }
    
    int high;

    for (int i = 0; i < row; i++)
    {
        high = INT_MIN;
        for (int j = 0; j < emp[i]; j++)
        {
            if(high < dept[i][j])
            {
                high = dept[i][j];
            }   
        }
        cout << "Highest Salary for department " << i + 1 << ": " << high << endl;
    }
    int *avg = new int[row];
    int total;
    int maxavg = INT_MIN;
    int pos;
    for (int i = 0; i < row; i++)
    {
        total = 0;
        for (int j = 0; j < emp[i]; j++)
        {
            total += dept[i][j];
        }
        avg[i] = total/emp[i];
    }
    for (int i = 0; i < row; i++)
    {
        maxavg = max(avg[i], maxavg);
    }
    for (int i = 0; i < row; i++)
    {
        if(avg[i] == maxavg)
        {
            pos = i;
        }
    }
    cout << "Maximum Average Salary is of department " << pos + 1 << " and it is : " << maxavg << endl;
    
    for (int i = 0; i < row; i++)
    {
        delete[] dept[i];
    }
    delete[] dept;
    delete[] emp;
    delete[] avg;
}
