#include <iostream>
#include <cassert>
#include <math.h>
#include <stdlib.h>
#include <vector>


using namespace std;

// short integer random number generator from stdlib
int rand(void);
void merge_sort(vector<int>& mergeArray, int first, int last);
void merge(vector<int>& mergeArray, int first, int mid, int last);
void insert_sort(vector<int>& insertArray, int first, int last);

void quick_sort(vector<int>& quickArrary, int left, int right)
{
    int pivot, low, high, q;
    if(left >= right)
        return;
    pivot = left;
    low = left+1;
    high = right;
    while(low < high)
    {
        while(quickArrary[low] <= quickArrary[pivot] && low < right)
            low++;
        while(quickArrary[high] > quickArrary[pivot] && high > left)
            high--;
        if(low < high)
            swap(quickArrary[low], quickArrary[high]);
    }
    if(quickArrary[pivot] > quickArrary[high])
        swap(quickArrary[high], quickArrary[pivot]);
    q = high;
    quick_sort(quickArrary, left, q - 1);
    quick_sort(quickArrary, q + 1, right);
}

void merge_sort(vector<int>& mergeArray, int first, int last)
{
    int mid = (first + last) / 2;
    if(first >= last)
        return;
    merge_sort(mergeArray, first, mid);
    merge_sort(mergeArray, mid + 1, last);
    merge(mergeArray, first, mid, last);
}

void merge(vector<int>& mergeArray, int first, int mid, int last)
{
    vector<int> temp(mergeArray.size());
    int i = first, j = mid + 1, k = first;
    while(i <= mid && j <= last)
    {
        if(mergeArray[i] <= mergeArray[j])
            temp[k++] = mergeArray[i++];
        else
            temp[k++] = mergeArray[j++];
    }
    while(i <= mid)
        temp[k++] = mergeArray[i++];
    while(j <= last)
        temp[k++] = mergeArray[j++];
    
    
    for(int i = first; i <= last ; i++)
        mergeArray[i] = temp[i];
    
}

void insert_sort(vector<int>& insertArray, int first, int last)
{
    int i, j, value;
    for(i = first + 1; i < last; i++)
    {
        value = insertArray[i];
        for(j = i - 1; insertArray[j] > value && j >= 0; j--)
        {
                insertArray[j+1] = insertArray[j];
        }
        insertArray[j + 1] = value;
    }
}



int main()
{
  int size;

  cout << endl << " ----- quicksort/mergesort/insertion comparison ----- " << endl;
  cout << endl << "How many elements to sort: - ";  cin >> size;
  vector<int> quickArray(size);   // get array of right size
  vector<int> mergeArray(size);   // to hold a copy of random ints
  vector<int> insertArray(size);   // to hold a copy of random ints


  //  initialize the three vectors with size "size".


  //  ============ quicksort random integers  ===================
  // generate random numbers for quickArray using the method in t05.cpp
    srand((unsigned)time(NULL));
    quickArray.clear();
    for(int i = 0; i < size; i++)
    {
        int tmp = rand() % (size * 2);
        quickArray.push_back(tmp);
    }
  // copy the array for later use by mergesort and insterion sort
  for (int k=0; k< size ; k++)
  {
      mergeArray[k] = quickArray[k];
      insertArray[k] = quickArray[k];
  }
  

    
  cout << endl << "Quicksort of Integer data initially in random order" << endl;
    for (int k=0; k< size ; k++)
    {
        cout << quickArray[k] << " ";
    }
    puts("");


  
  // implement your quicksort here or call it as a function
  // ===================== Quicksort ======================
    clock_t q_start, q_end;
    q_start = clock();
  quick_sort(quickArray, 0, size - 1);
    q_end = clock();
    double q_time_taken = double(q_end - q_start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by quicksort is : " << fixed << q_time_taken << "sec" << endl;
  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << quickArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << quickArray[size-k] << ", " ;
  cout << endl << endl;

//    ============ mergesort random integers  ===================

  cout << endl << "Mergesort of Integer data initially in random order" << endl;
    for (int k=0; k< size ; k++)
    {
        cout << mergeArray[k] << " ";
    }
    puts("");



  // implement your mergesort here or call it as a function
  // ===================== Mergesort ======================

    clock_t m_start, m_end;
    m_start = clock();
    merge_sort(mergeArray, 0, size-1);
    m_end = clock();
    double m_time_taken = double(m_end - m_start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by MergeSort is : " << fixed << m_time_taken << "sec" << endl;

  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << mergeArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << mergeArray[size-k] << ", " ;
  cout << endl << endl;


  //  ============ insertion sort random integers  ===================

  cout << endl << "Insertion sort of Integer data initially in random order" << endl;
    for (int k=0; k< size ; k++)
    {
        cout << insertArray[k] << " ";
    }
    puts("");
  // implement your insertion sort here or call it as a function
  //   ===================== Insertion Sort ===============



    clock_t i_start, i_end;
    i_start = clock();
    insert_sort(insertArray, 0, size);
    i_end = clock();
    double i_time_taken = double(i_end - i_start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by MergeSort is : " << fixed << i_time_taken << "sec" << endl;




  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << insertArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << insertArray[size-k] << ", " ;
  cout << endl << endl;

    cout << "Time taken for Quick sort : " << q_time_taken << "sec" << endl;
    cout << "Time taken for Merge sort : " << m_time_taken << "sec" << endl;
    cout << "Time taken for Insert sort : " << i_time_taken << "sec" << endl;
//   20, 100, 200, 400, 800, 1600, 3200, 6400
}
