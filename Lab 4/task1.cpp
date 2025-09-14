#include "iostream"
using namespace std;

void linearSearch(int arr[], int n , int target)
{
    bool found = false;
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            found = true;
            pos = i;
        }
    }
    if(found)
    {
        cout << "Value found at index: " << pos << endl;
    }
    else
    {
        cout << "Value not found!!" << endl;
    }
}

int main()
{
    int n;
    int target;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n]; 

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for element " << i  << ": ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Enter the value to find: ";
    cin >> target;
    linearSearch(arr,n,target);
    delete[] arr;
}
