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

    Node* merge_sorted(Node* head1, Node* head2) {
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }

        if (head1->data <= head2->data) {
            head1->next = merge_sorted(head1->next, head2);
            return head1;
        } else {
            head2->next = merge_sorted(head2->next, head1);
            return head2;
        }
    }
};

int main() 
{
    List l1;
    l1.push_front(5);
    l1.push_front(3);
    l1.push_front(1);
    l1.display();
    cout << endl;
    List l2;
    l2.push_front(6);
    l2.push_front(4);
    l2.push_front(2);
    l2.display();
    cout << endl;
    List l3;
    l3.head = l3.merge_sorted(l1.head, l2.head);

    l3.display(); 
}
