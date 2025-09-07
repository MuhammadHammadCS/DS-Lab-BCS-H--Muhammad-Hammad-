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

class DoublyLL
{
    public:
    int data;
    DoublyLL *next;
    DoublyLL *prev;
    DoublyLL(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class List
{
    public:
    Node* head;
    Node* tail;

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
};

DoublyLL *convert_doublyLL(Node *head)
{
    if(head == NULL)
    {
        return nullptr;
    }
    DoublyLL *newHead = new DoublyLL(head->data);
    DoublyLL *temp = newHead;
    Node *curr = head->next; 
    while(curr != NULL)
    {
        DoublyLL *newNode = new DoublyLL(curr->data);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
        curr = curr->next;
    }
    return newHead;
}


Node* convert_circularLL(Node* head)
{
    if(head == NULL)
    {
        return nullptr;
    } 

    Node *curr = head;

    while(curr->next)
    {
        curr=curr->next;
    }
    curr->next=head;
    return head;
}

void display(Node *head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void printDoublyLL(DoublyLL *head)
{
    DoublyLL* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data <<"<->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void printCircularLL(Node* head, int n)
{
    Node* temp = head;
    for(int i = 0; i < n; i++)
    { 
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main()
{
    List li;

    li.push_front(1);
    li.push_front(2);
    li.push_front(3);
    li.push_front(4);
    cout << "Singly Linked List: \n";
    display(li.head);
    cout << endl;
    cout << "\nSingly LL TO Doubly LL: \n";
    DoublyLL *hhead = convert_doublyLL(li.head);
    printDoublyLL(hhead);
    cout << endl;
    cout << "\nSingly LL TO Circular LL: \n";
    Node *Chead = convert_circularLL(li.head);
    printCircularLL(Chead,4);

}
