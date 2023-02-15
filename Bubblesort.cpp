#include <iostream>
#include <algorithm>
using namespace std;


void bubble_sort(int *arr, int size);
void print(int* arr, int size);

void bubble_sort(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

void print(int* arr, int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}



int main()
{
    int size;
    cout << "Insert size of an array : ";
    cin >> size;
    
    int* arr = new int[size];
    for(int i = 0; i < size; i++)
        arr[i] = rand() % 99 + 1;
    
    
    cout << "\nArray before bubble sort : ";
    print(arr, size);
    
    
    cout << "\nArray after bubble sort : ";
    bubble_sort(arr, size);
    print(arr, size);
    
    return 0;
}
