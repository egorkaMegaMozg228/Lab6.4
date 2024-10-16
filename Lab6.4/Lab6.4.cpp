#include <iostream>
#include <iomanip>
#include <istream>
#include <vector>
#include <algorithm>
using namespace std;

void create(float* arr, int size)
{
    double MIN = -20;
    double MAX = 30;
    for (int i = 0; i < size; i++)
    {
        arr[i] = MIN + rand() * (MAX - MIN) / RAND_MAX;
    }
}

void Print(float* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(10) << arr[i];
    cout << endl;
}

int sum(float* arr, const int size)
{
    int n = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0) 
            n += arr[i];
        else
        {
            if (i == 0) return 0;
            n -= arr[i-1];
            break;
        }
        
    }
    return n;
}


float FindMax(float* arr, const int size) 
{
    int n_max = 0;

    for (int i = 0; i < size; i++)

        if (arr[i] > arr[n_max])

            n_max = i;
    return n_max;
}
void updateArray(float* arr, int size, float a1, float b1)
{
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < a1||arr[i]>b1)
        {
            arr[i] = 0;
        }
    }
}




int main()
{
    srand((unsigned)time(NULL));
    float a, b;
    int n;
    cout << "n = "; cin >> n;
    cout << endl;
    cout << "a = "; cin >> a;
    cout << endl;
    cout << "b = "; cin >> b;
    cout << endl;
    
    int size = n;
    float *arr = new float[n];
    int *tmp = new int[n];
    create(arr, size);
    Print(arr, size);
    cout << "sum = " << sum(arr, size) << endl;
    int q = FindMax(arr, size);
    
    cout << "max = " << arr[q] << endl;
    updateArray(arr, size, a, b);
    Print(arr, size);
    return 0;
}
