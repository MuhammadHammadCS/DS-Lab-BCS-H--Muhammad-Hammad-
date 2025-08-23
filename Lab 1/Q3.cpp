#include "iostream"
using namespace std;

class Box{
    public:
    int *number;

    Box(int num)
    {
        number = new int(num);
    }
    Box(const Box &b)
    {
        number = new int(*b.number);
    }
    void setNum(int n)
    {
        *number = n;
    }
    void print()
    {
        cout << "Number: " << *number << endl;
    }
    ~Box()
    {
        delete number;
    }
};

int main()
{
    Box b1(20);
    Box b2 = b1;
    cout << "\nIntial Values" << endl;
    cout << "b1: "; 
    b1.print();
    cout << "b2: ";
    b2.print();
    b2.setNum(15);
    cout << "\nAfter changing Intial Values" << endl;
    cout << "b2: ";
    b2.print();
    cout << "b1: ";
    b1.print();

}
