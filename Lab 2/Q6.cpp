#include "iostream"
using namespace std;


class SafePointer
{
    private:
    int* val;
    public:
    SafePointer()
    {
        val = new int(0);
    }
    void setValue(int n)
    {
        *val = n;
    }

    int getValue()
    {
        if(val)
        {
            return *val;
        }
        else
        {
            cout << "NULL Pointer\n";
            return 0;
        }
    }

    void release()
    {
        if(val != NULL)
        {
            delete[] val;
        }
    }
    ~SafePointer()
    {
        release();
    }
};
int main()
{
    const int num = 5;
    SafePointer Student[num];
    int marks;

    cout << "Enter marks for students: \n";
    for (int i = 0; i < num; i++)
    {
        cout << "Enter for Student " << i + 1 << ": ";
        cin >> marks;
        Student[i].setValue(marks);
    }
    cout << endl;
    cout << "Displaying Marks for " << num << " Students:\n";
    for (int i = 0; i < num; i++)
    {
        cout << "Student " << i + 1 << ": " << Student[i].getValue() << endl;
    }
    
    
}
