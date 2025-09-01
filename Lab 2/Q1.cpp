#include "iostream"
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }

    for (int  j = 0; j < size; j++)
    {
        cout << "Enter the value for arr[" << j << "]: ";
        cin >> arr[j]; 
    }
    cout <<"\nDisplaying...\n";
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }
    char choice = 'y';
    int pos;
    int val;
    while(choice == 'y' || choice == 'Y')
    {
        cout << "Enter the index to change value at from(1 to " << size << ") : ";
        cin >> pos;
        if(pos > 0 && pos <= size)
        {
            cout << "Enter the value: ";
            cin >> val;
            arr[pos-1] = val;
        }
        else
        {
            cout << "Invalid Index!!" << endl;
        }
        cout << "do you want to update any value in the array(y for yes || n for no): ";
        cin >> choice;
    }
    if(choice == 'n' || choice == 'N')
    {
        cout << "No array updated" << endl;
    }
    cout <<"\nDisplaying...\n";
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }
    delete[] arr;
    
}
