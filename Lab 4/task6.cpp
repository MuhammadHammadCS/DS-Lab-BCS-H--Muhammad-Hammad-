#include "iostream"
using namespace std;

void shellSort(int arr[], int size)
{
    for (int gap = size/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int res = i;

            while(res >= gap && arr[res - gap] > temp)
            {
                arr[res] = arr[res - gap];
                res -= gap;
            }
            arr[res] = temp;
        }   
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
        cout << "Enter value for element " << i << ": ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Unsorted Array\n";
    display(arr, n);
    shellSort(arr, n);
    cout << "\nSorted Array\n";
    display(arr, n);
    delete[] arr;
}