#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* z, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        z[i] = Low + rand() % (High - Low + 1);
}

void Print(int* z, const int n)
{
    for (int i = 0; i < n; i++)
        cout << "z[" << setw(2) << i << " ] = " << setw(4) << z[i] << endl;
    cout << endl;
}

int Max(int* z, const int n)
{
    int max = z[0];
    for (int i = 1; i < n; i++)
        if (z[i] > max)
            max = z[i];
    return max;
}

int Sum(int* z, const int n,int k,int sum)
{
    for (int i = 0; i < n; i++)
    {
        if (z[i] > 0)
            k = i;
    }
    sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += z[i];
    }
    return sum;
}

int Compress(int* z,const int n,int a,int b,int i)
{
    int j=0;
    for (int i = 0; i < n; i++)
    {
        if (abs(z[i]) < a || abs(z[i]) > b)
            z[i - j] = z[i];
        else
            j++;
    }
    for (i = n - j; i < n; i++)
    {
        z[i] = 0;
    }
    return z[i];
}

int main()
{
    srand((unsigned)time(NULL));
    int n;
    int Low = -10;
    int High = 10;
    cout << "n = "; cin >> n;
    int* z = new int[n];
    int a,b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    Create(z, n, Low, High);
    Print(z, n);
    cout << "max = " << Max(z, n) << endl;    
    cout << "S = " << Sum(z,n,0,0) << endl;
    Compress(z, n, a, b, 0);
    Print(z, n);
    delete[] z;
    return 0;
}