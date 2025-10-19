#include "iostream"
using namespace std;
#define SIZE 10

class LinearQueue
{
    int start;
    int end;
    int arr[SIZE];

public:
    LinearQueue()
    {
        start = end = -1;
    }
    bool isFull()
    {
        if (end == SIZE - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (start == -1 || start > end)
        {
            return true;
        }
        return false;
    }

    void enqueue(int val)
    {
        if (isFull() == true)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (start = -1)
        {
            start = 0;
        }
        end += 1;
        arr[end] = val;
    }

    int deQueue()
    {
        if (isEmpty() == true)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[start++];
    }

    void display()
    {
        if (isEmpty() == true)
            cout << "Queue is empty\n";
        else
        {
            cout << "Queue contents: ";
            for (int i = start; i <= end; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    LinearQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.deQueue();
    q.deQueue();
    q.enqueue(60);
    q.enqueue(70);
    q.display();
}
