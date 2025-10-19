#include <iostream>
using namespace std;
#define SIZE 5
class Stack
{   
    // create an array for stack
    int top = -1;
    int Stackarr[SIZE];
    
    public:
        bool push(int x)
        {
            if(top >= (SIZE - 1))
            {
                cout << "OverFlow!!" << endl;
                return false;
            }
            else
            {
                Stackarr[++top] = x;
                return true;
            }
        }
        
        int pop()
        {
            // underFlow
            if(top < 0)
            {
                cout << "Stack is empty\nUnderFlow" << endl;
                return 0;
            }
            else
            {
                int popnum = Stackarr[top];
                top--;
                return popnum;
            }
            return 0;
        }
        
        int peek()
        {
            if(top < 0)
            {
                cout << "Stack is empty\nUnderFlow" << endl;
                return 0;
            }
            else
            {
                return Stackarr[top];
            }
            return 0;
        }
        bool isEmpty()
        {
            if(top < 0)
            {
                return true;
            }
            return false;
        }
        void Display()
        {
            if(isEmpty() == true)
            {
                cout << "Empty Stack!" << endl;
            }
            for (int i = top; i >= 0; i--)
            {
                cout << Stackarr[i] << " " << endl; 
            }
            
        }
};


int main() 
{
    Stack s1;
    s1.push(4);
    s1.push(7);
    s1.push(8);
    s1.push(9);
    s1.push(3);
    cout << "Top Element: " << s1.peek() << endl;
    s1.Display();
    s1.pop();
    s1.pop();
    cout << endl;
    s1.Display();
    return 0;
}
