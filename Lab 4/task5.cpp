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

int InterpolationSearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    
    while(low <= high && target >= arr[low] && target <= arr[high])
    {
        if(low == high)
        {
            if(arr[low] == target)
            {
                return low;
            }
            return -1;
        }
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if(arr[pos] == target)
        {
            return pos;
        }

        if(arr[pos] < target)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }
    return -1;
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
    cout << "Sorted Array\n";
    insertionSort(arr,n);
    display(arr,n);
    cout <<"\nEnter the value to find in the sorted array: ";
    cin >> target;
    int i = InterpolationSearch(arr,n,target);
    cout << "Value found at index: " << i << endl;
    delete[] arr;
}