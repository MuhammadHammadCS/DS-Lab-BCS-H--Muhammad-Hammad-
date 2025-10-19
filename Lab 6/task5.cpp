#include <iostream>
#include "math.h"
using namespace std;
class Stack
{   
    int top;
    int size;
    int *Stackarr;
    
    public:
        Stack(int s)
        {
            top = -1;
            size = s;
            Stackarr = new int[size];
        }
        bool push(int x)
        {
            if(top >= (size - 1))
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

int priority(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string exp)
{
    string postfix = "";
    Stack s(exp.length());

    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];

        if (c == ' ')
            continue;

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c))
        {
            postfix += c;
        }
        
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += (char)s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(')
                s.pop();
        }
        else
        {
            while (!s.isEmpty() && priority(c) <= priority(s.peek()))
            {
                postfix += (char)s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty())
    {
        postfix += (char)s.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix)
{
    Stack s(postfix.length());

    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        if (c == ' ')
            continue;

        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else
        {
            int op2 = s.pop();
            int op1 = s.pop();
            int result;

            if (c == '+')
                result = op1 + op2;
            else if (c == '-')
                result = op1 - op2;
            else if (c == '*')
                result = op1 * op2;
            else if (c == '/')
                result = op1 / op2;
            else if (c == '^')
                result = pow(op1, op2);
            else
            {
                cout << "Invalid operator: " << c << endl;
                return 0;
            }

            s.push(result);
        }
    }

    return s.pop();
}



int main() 
{
    string infix = "3+4-6+1*2";
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
