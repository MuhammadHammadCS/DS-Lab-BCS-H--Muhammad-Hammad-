#include "iostream"
using namespace std;

int main()
{
    int benches;
    int seats;

    cout << "Enter the number of benches(rows): ";
    cin >> benches;
    cout << "Enter the number of seats(col): ";
    cin >> seats;

    int** room = new int*[benches];

    for (int i = 0; i < benches; i++)
    {
        room[i] = new int[seats];    
    }
    
    for (int i = 0; i < benches; i++)
    {
        for (int j = 0; j < seats; j++)
        {
            room[i][j] = 0;
        }
    }
    cout << "\nEnter 1 to occupy the seat or 0 to not occupy\n";
    for (int i = 0; i < benches; i++)
    {
        for (int j = 0; j < seats; j++)
        {
            cout << "Bench " << i + 1 << " seat " << j + 1 << " : ";
            cin >> room[i][j];
        }
    }

    for (int i = 0; i < benches; i++)
    {
        cout << "Bench " << i + 1 << endl;
        for (int j = 0; j < seats; j++)
        {
            cout << " Seat " << j + 1 << " : " << room[i][j] << "\n";
        }
    }

    for (int i = 0; i < benches; i++)
    {
        delete[] room[i];
    }
    delete[] room;
}
