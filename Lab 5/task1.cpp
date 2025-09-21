#include <iostream>
using namespace std;

int CalculateFactorial(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    } 
    return n* CalculateFactorial(n-1);
}

int main()
{
    int num;
    cout << "Enter the number to find factorial for: ";
    cin >> num;
    cout << "Factorial for: " << num << " is: " << CalculateFactorial(num);
    return 0;
}
