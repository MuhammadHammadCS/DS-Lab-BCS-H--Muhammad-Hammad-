#include <iostream>
using namespace std;

class JProcess
{
public:
    int id;
    int priority;
};

class JobScheduler
{
private:
    JProcess queue[100];
    JProcess stack[100];
    int front, rear, top, n;

public:
    JobScheduler()
    {
        front = 0;
        rear = -1;
        top = -1;
        n = 0;
    }

    void InputJobs()
    {
        cout << "Enter number of jobs : ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            rear++;
            cout << "Enter Process ID : ";
            cin >> queue[rear].id;
            cout << "Enter Priority : ";
            cin >> queue[rear].priority;
        }
    }

    void sortByPriority()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (queue[i].priority < queue[j].priority)
                {
                    JProcess temp = queue[i];
                    queue[i] = queue[j];
                    queue[j] = temp;
                }
            }
        }
    }

    void TransferToStack()
    {
        for (int i = 0; i < n; i++)
        {
            top++;
            stack[top] = queue[i];
        }
    }

    void ExecuteJobs()
    {
        cout << "\nJob Execution Order (Stack - LIFO) :\n";
        while (top >= 0)
        {
            cout << "Executing Process ID : " << stack[top].id << " Priority : " << stack[top].priority << endl;
            top--;
        }
    }

    void Display_Order()
    {
        cout << "\nJob Arrival Order (Queue - FIFO) :\n";
        for (int i = 0; i < n; i++)
        {
            cout << "Process ID : " << queue[i].id << " Priority : " << queue[i].priority << endl;
        }
    }
};

int main()
{
    JobScheduler js;
    js.InputJobs();
    js.Display_Order();
    js.sortByPriority();
    js.TransferToStack();
    js.ExecuteJobs();

    return 0;
}
