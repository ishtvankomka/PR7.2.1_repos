#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void Sum(int** a, const int rowCount, const int colCount, int& S);
int main()
{
    srand((unsigned)time(NULL));
    int Low = 1;
    int High = 25;
    int n = 5;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    Create(a, n, Low, High);
    Print(a, n);
    int S;
    Sum(a, n, n, S);
    cout << "  " << S << endl;
        for (int i = 0; i < n; i++)
            delete[] a[i];
    delete[] a;
    return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}
void Sum(int** a, const int rowCount, const int colCount, int& S)
{
    S = 0;
    for (int j = 0; j < colCount; j++)
    {
        if (j % 2 != 0)
        {
            int min = a[0][j];
            for (int i = 0; i < rowCount; i++)
            {
                if (a[i][j] < min)
                    min = a[i][j];
            }
            S += min;

        }
    }
}
