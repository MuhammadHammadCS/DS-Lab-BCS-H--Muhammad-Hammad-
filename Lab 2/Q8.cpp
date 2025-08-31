#include "iostream"
using namespace std;

int main()
{
    int n,m;
    cout << "Enter the number of days: ";
    cin >> n;
    cout << "Enter the differnet number of time: ";
    cin >> m;
    float *avg = new float[n];
    float total;
    float** temp = new float*[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = new float[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter the temperature for " << j + 1 << " at day " << i + 1 << ": ";
            cin >> temp[i][j];
        }
    }
    float maxh = INT_MIN;
    float minc = INT_MAX;
    int h,c;
    for (int i = 0; i < n; i++)
    {
        total = 0.0;
        for (int j = 0; j < m; j++)
        {
            total += temp[i][j];
        }
        avg[i] = total/m;
        maxh = max(avg[i],maxh);
        minc = min(avg[i],minc);
    }
    for (int i = 0; i < n; i++)
    {
        if(maxh == avg[i])
        {
            h = i;
        }
        if(minc == avg[i])
        {
            c = i;
        }
    }
    cout << "Hottest Day: " << h + 1 << endl;
    cout << "Coldest Day: " << c + 1 << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] temp[i];
    }
    delete[] temp;
    delete[] avg;
    
    
}
