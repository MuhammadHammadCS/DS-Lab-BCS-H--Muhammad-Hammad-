#include "iostream"
using namespace std;

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int smallest_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[smallest_idx])
            {
                smallest_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallest_idx];
        arr[smallest_idx] = temp;
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

int main()
{
    int n;
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
    selectionSort(arr,n);
    display(arr,n);
    delete[] arr;
}