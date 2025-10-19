#include "iostream"
using namespace std;

class CircularQueue
{
    int *arr;
    int currSize, cap;
    int front , rear;

    public:
    CircularQueue(int size)
    {
        cap = size;
        arr = new int[cap];
        currSize = 0;
        front = 0;
        rear = -1;
    }

    void pushQ(int num)
    {
        if(currSize == cap)
        {
           cout << "CQ is full" << endl;  
        }

        rear = (rear + 1) % cap;
        arr[rear] = num;
        currSize++;
    }

    void popQ()
    {
        if(Isempty())
        {
            cout << "CQ is empty" << endl;
        }
        front = (front + 1) % cap;
        currSize--;
    }
    int frontQ()
    {
        if(currSize == 0)
        {
            cout << "CQ empty" << endl;
        }
        return arr[front];
    }
    bool Isempty()
    {
        return currSize == 0;
    }
    void displayQ()
    {
        for (int i = 0; i < cap; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    CircularQueue cq(3);
    cq.pushQ(1);
    cq.pushQ(2);
    cq.pushQ(3);
    cq.popQ();
    cq.pushQ(4);
    //cq.displayQ();
    while (!cq.Isempty())
    {
        cout << cq.frontQ() << " ";
        cq.popQ();
    }
    

}
