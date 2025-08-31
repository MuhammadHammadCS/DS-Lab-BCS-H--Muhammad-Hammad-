#include "iostream"
using namespace std;

int main()
{
    int row1,row2;
    int col1,col2;

    int** arr1;
    int** arr2;
    int** sum;
    int** sub;

    cout << "Enter the number of Rows for Matrix 1: ";
    cin >> row1;
    cout << "Enter the number of Columns for Matrix 1: ";
    cin >> col1;
    cout << "Enter the number of Rows for Matrix 2: ";
    cin >> row2;
    cout << "Enter the number of Columns for Matrix 2: ";
    cin >> col2;

    arr1 = new int*[row1];
    arr2 = new int*[row2];
    for (int i = 0; i < row1; i++)
    {
        arr1[i] = new int[col1];
    }
    for (int i = 0; i < row2; i++)
    {
        arr2[i] = new int[col2];
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout << "Enter element for [" << i << "][" << j << "] for Matrix 1: ";
            cin >> arr1[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << "Enter element for [" << i << "][" << j << "] for Matrix 2: ";
            cin >> arr2[i][j];
        }
    }
    
    
    if(row1 == row2 && col1 == col2)
    {
        sum = new int*[row1];
        for (int i = 0; i < row1; i++)
        {
            sum[i] = new int[col1];
        }
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                sum[i][j] = arr1[i][j] + arr2[i][j];
            }
        }
        cout << "Addition Matrix: \n";
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                cout << sum[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        sub = new int*[row1];
        for (int i = 0; i < row1; i++)
        {
            sub[i] = new int[col1];
        }
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                sub[i][j] = arr1[i][j] - arr2[i][j];
            }
        }
        cout << "Subtraction Matrix: \n";
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                cout << sub[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Row and Column for both matrix should be SAME for Addition and Subtraction\n";
    }
    for (int i = 0; i < row1; i++)
    {
        delete[] arr1[i];
        delete[] sum[i];
        delete[] sub[i];
    }
    for (int i = 0; i < row2; i++)
    {
        delete[] arr2[i];
    }
    delete[] arr1;
    delete[] arr2;
    delete[] sum;
    delete[] sub;
    
}
