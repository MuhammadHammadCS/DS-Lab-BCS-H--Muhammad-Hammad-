#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    Node *reverse_Kgrp(Node*head,int k)
    {
        Node *temp = head;
        int count = 0;
        while(count < k)
        {
            if(temp == NULL)
            {
                return head;
            }
            temp = temp->next;
            count++;
        }

        Node *prevNode = reverse_Kgrp(temp,k);
        temp = head , count = 0;
        while(count < k)
        {
            Node *next = temp->next;
            temp->next = prevNode;

            prevNode = temp;
            temp = next;
            count++;
        }

        return prevNode;
    }
};

int main() 
{
    int k = 3;
    List L1;
    L1.push_front(8);
    L1.push_front(7);
    L1.push_front(6);
    L1.push_front(5);
    L1.push_front(4);
    L1.push_front(3);
    L1.push_front(2);
    L1.push_front(1);

    L1.display();
    cout << endl;

    List L2;
    L2.head = L1.reverse_Kgrp(L1.head,k);
    L2.display();

}
