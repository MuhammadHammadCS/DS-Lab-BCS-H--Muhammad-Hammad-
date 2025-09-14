#include "iostream"
using namespace std;

void shellSort(int arr[], int size)
{
    int count = 0;
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
            count++;
        }   
    }
    cout << "\nComplexity Analysis for Shell Sort :\nnumber of comparisons and swapped: " << count << endl;
}

void bubbleSort(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
    } 
    cout << "\nComplexity Analysis for Bubble Sort:\nnumber of comparisons and swapped: " << count << endl;
}

void insertionSort(int arr[], int size)
{
    int count;
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
        count++;
    }
    cout << "\nComplexity Analysis for Insertion Sort:\nnumber of comparisons and swapped: " << count << endl; 
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
    bubbleSort(arr,n);
    insertionSort(arr,n);
    shellSort(arr, n);
    cout << "\nSorted Array\n";
    display(arr, n);
    delete[] arr;
}