#include "iostream"
using namespace std;

class Exam{
    private:
    char* stdname;
    char* date;
    int score;

    public:
    Exam()
    {
        stdname = new char[100];
        date = new char[100];
    }
    void setName(char* name)
    {
        delete[] stdname;
        stdname = name;
    }

    void setDate(char* d)
    {
        delete[] date;
        date = d;
    }

    void setScore(int s)
    {
        score = s;
    }

    void displayName()
    {
        cout << "Student Name: " << stdname << endl;
    }
    void displayDetails()
    {
        cout << "Exam Date: " << date << endl;
        cout << "Exam Score: " << score << endl;
    }

    ~Exam()
    {
        delete []stdname;
        delete []date;
    }
};

int main()
{
    Exam e1;
    char nm[100];
    char dt[100];
    int sc;
    int num;
    cout << "Enter Student Name: ";
    cin.getline(nm,100);
    e1.setName(nm);
    cout << "Enter the date for Exam: ";
    cin.getline(dt,100);
    e1.setDate(dt);
    cout << "Enter the score for Exam: ";
    cin >> sc;
    e1.setScore(sc);
    cout << endl;
    cout << "Original\n";
    e1.displayName();
    e1.displayDetails();
    Exam e2(e1);
    cout << endl;
    cout << "Shallow copy\n";
    e2.displayName();
    e2.displayDetails();

}
