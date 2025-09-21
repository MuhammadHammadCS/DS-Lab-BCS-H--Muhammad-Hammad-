#include <iostream>
using namespace std;

// 1.
int printNums(int n)
{
    if(n == 0)
    {
        return 1;
    } 
    cout<< n << " ";
    return printNums(n-1);
}

//2.
int functionB(int n);

int functionA(int n)
{
    if(n==0)
    {
        return 1;
    } 
    cout<<"Func A->"<<"["<<n<<"]"<<endl;
    return functionB(n-1);
}

int functionB(int n)
{
    if(n==0)
    {
        return 1;
    }
    cout<<"Func B->"<<"["<<n<<"]"<<endl;
    return functionA(n-1);
}


int main()
{  
    printNums(9);
    cout << endl;
    functionA(7);
   
    return 0;
}


