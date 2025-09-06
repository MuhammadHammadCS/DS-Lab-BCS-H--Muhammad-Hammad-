#include <iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }

};


class List
{
    Node* head;
    Node* tail;

    public:
    List()
    {
        head = NULL;
        tail = NULL;
    }


    void push_front(int val)
    {
        Node* newNode = new Node(val);

        if(head==NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void display()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
    }

    bool isPalindrome()
    {
        Node *curr = head; 
        Node *slow = head;
        Node *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *curr2 = slow;
        Node *prev = NULL;
        Node *next = NULL;
        while(curr2 != NULL)
        {
            next = curr2->next;
            curr2->next = prev;
            prev = curr2;
            curr2 = next;
        }
        Node *newNode = prev;
        while(newNode != NULL)
        {
            if(curr->data != newNode->data)
            {
                return false;
            }
            curr = curr->next;
            newNode = newNode->next;
        }
        return true;
    }
};

int main()
{
    List l1;

    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);

    cout << "\nODD Linked List\n";
    l1.display();
    if(l1.isPalindrome() == 1)
    {
        cout << "\nPalindrome: true\n";
    }
    else
    {
        cout << "\nNot palindrome\n";
    }

    List l2;

    l2.push_front(1);
    l2.push_front(2);
    l2.push_front(2);
    l2.push_front(1);

    cout << "\nEVEN Linked List\n";
    l2.display();
    if(l2.isPalindrome() == 1)
    {
        cout << "\nPalindrome: true\n";
    }
    else
    {
        cout << "\nNot palindrome\n";
    }
}
