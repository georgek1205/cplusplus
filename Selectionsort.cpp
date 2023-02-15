#include <iostream>
#include <algorithm>

using namespace std;

void print(int* arr, int size);
void selection_sort(int* arr, int size);


void selection_sort(int* arr, int size)
{
    int minIdx;
    for(int i = 0; i < size - 1; i++)
    {
        minIdx = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
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
    selection_sort(arr, size);
    print(arr, size);
    cout << endl;
    
    return 0;
}
