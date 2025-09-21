#include <iostream>
using namespace std;

// 1.
int sumTail(int n, int total)
{
    if(n==0)
    {
        return total;
    }
    total += n;
    return sumTail(n-1, total);
}

//2.
int sumNonTail(int n)
{
    if(n==0)
    {
        return n;
    }
    return n + sumNonTail(n-1);
}

// Comparison

// Tail Recursion
// In tail recursion, the recursive call is the very last action in the function. This allows the compiler to apply tail call optimization (TCO), where the same stack frame is reused for each call. As a result, memory usage stays constant, i.e., O(1).

// Non-Tail Recursion
// In non-tail recursion, the function still has work to do after the recursive call returns. Because of this, each call must keep its own stack frame until the deeper calls finish. This causes the call stack to grow with each recursive call, leading to O(n) memory usage.

int main()
{
    int result;
    result = sumTail(5,0);
    cout << "Sum Tail: " << result << endl;
   
    result = sumNonTail(5);
    cout << "Sum Non Tail: " << result << endl;
   
    return 0;
}
