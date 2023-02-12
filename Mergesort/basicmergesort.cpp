#include <iostream>
using namespace std;


void display(int* sorted_array, int size);
void merge(int* first_array, int size1, int* second_array, int size2, int* merge_array);

void display(int* sorted_array, int size)
{
    for(int i = 0; i < size; i++)
        cout << sorted_array[i] << " ";
    cout << endl;
}

void merge(int* first_array, int size1, int* second_array, int size2, int* merge_array)
{
    int index1 = 0;
    int index2 = 0;
    int index_m = 0;

    while(index1 < size1 && index2 < size2)
    {
        if(first_array[index1] < second_array[index2])
            merge_array[index_m++] = first_array[index1++];
        else
            merge_array[index_m++] = second_array[index2++];
    }
    while(index1 < size1)
        merge_array[index_m++] = first_array[index1++];
    while(index2 < size2)
        merge_array[index_m++] = second_array[index2++];
}


int main()
{
    int first_array[6] = {2, 4, 6, 8, 11, 13}, second_array[6] = {1, 2, 3, 5, 9, 15};
    int merge_array[12];

    cout << "=== First Array ===" << endl;
    display(first_array, 6);

    cout << "\n=== Second Array ===" << endl;
    display(second_array, 6);

    merge(first_array, 6, second_array, 6, merge_array);

    cout << "\n=== Array after mergesort ===" << endl;
    display(merge_array, 12);
    
    return 0;
}
