#include <iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }

};
class Stack
{   
    Node *top;
    public:
        Stack()
        {
            top = NULL;
        }
        void push(int x)
        {
            Node *temp = new Node(x);
            temp->next = top;
            top = temp;
        }
        
        void pop()
        {
            if(top == NULL)
            {
                cout << "Stack is Empty!" << endl;
            }
            Node* temp;
            temp = top;
            top = top->next;
            delete temp;
        }
        
        int peek()
        {
            if(top == NULL)
            {
                cout << "Stack is empty\nUnderFlow" << endl;
                return 0;
            }
            return top->data;
        }
        bool isEmpty()
        {
            if(top == NULL)
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
            Node* temp = top;
            while(temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
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
    cout << "Top Element: " << s1.peek() << endl;
    s1.Display();
    return 0;
}
