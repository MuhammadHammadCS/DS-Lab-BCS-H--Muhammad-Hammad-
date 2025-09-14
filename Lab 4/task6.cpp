#include "iostream"
using namespace std;

void combSort(int arr[], int size)
{
    int count = 0;
    float shrink = 1.3;
    int gap = size;
    bool swapped = true;

    while(gap > 1 || swapped == true)
    {
        gap = (int)(gap/shrink);
        if(gap < 1)
        {
            gap = 1;
        }
        swapped = false;
        for (int i = 0; i + gap < size; i++)
        {
            if(arr[i] > arr[gap + i])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
                count++;
            }
        } 
    }
    cout << "\nComplexity Analysis:\nnumber of comparisons and swapped: " << count << endl;
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
    combSort(arr, n);
    cout << "\nSorted Array\n";
    display(arr, n);
    delete[] arr;
}
