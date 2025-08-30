#include "iostream"
using namespace std;

int main()
{
    int student;
    
    cout << "Enter the number of students: ";
    cin >> student;
    
    int** marks = new int*[student];
    int *courses = new int[student];

    for (int i = 0; i < student; i++)
    {
        cout << "Enter the number of courses for student " << i + 1 << ": ";
        cin >> courses[i];
        marks[i] = new int[courses[i]];
    }
    
    for (int i = 0; i < student; i++)
    {
        cout << "Student " << i + 1 << endl;
        int sum = 0;
        for (int j = 0; j < courses[i]; j++)
        {
            cout << "Enter marks for course " << j + 1 << " : ";
            cin >> marks[i][j];
            sum += marks[i][j];
        }
        cout << "Average marks for Student " << i + 1 << ": " << sum/courses[i] << endl;
    }

    for (int i = 0; i < student; i++)
    {
        delete[] marks[i];
    }
    delete[] marks;
    
}
