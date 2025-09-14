#include "iostream"
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        while(prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1]  = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    } 
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void BinarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    bool found = false;
    while(low <= high)
    {
        int middle = (low + high)/2;
        if(arr[middle] == target)
        {
            cout << "Value found at index: " << middle << endl;
            found = true;
            break;
        }
        else if(arr[middle] < target)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }
    if(!found)
    {
        cout << "Value Not Found!!!" << endl;
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
    cout << "Unsorted Array\n";
    display(arr,n);
    cout << "Sorted Array using Selection Sort\n";
    insertionSort(arr,n);
    display(arr,n);
    cout <<"\nEnter the value to find in the sorted array: ";
    cin >> target;
    BinarySearch(arr,n,target);
    delete[] arr;
}