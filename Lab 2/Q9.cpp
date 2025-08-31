#include "iostream"
using namespace std;

int main()
{
    int row;
    int col;

    int** arr;

    cout << "Enter the number of Rows for Matrix 1: ";
    cin >> row;
    cout << "Enter the number of Columns for Matrix 1: ";
    cin >> col;

    arr = new int*[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter element for [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nSparse Matrix Form\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "row = " << i << " coloumn = " << j << " Value = " << arr[i][j] << endl;
        }
    }
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

}
