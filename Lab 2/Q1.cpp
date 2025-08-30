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
    
    delete[] arr;
    
}
