/*
Exercise 2
a. Implement functions for insertion sort, quicksort, heapsort and mergesort 
that input an array of integers and sort it.
b. Write a program that generates random integer arrays (hint: use seed 
appropriately to avoid generating same sequences) of lengths 10, 100, 1000, 
10,000, 100,000, 1000,000, and then sorts each using each of the sorting 
functions from (a), and measures the time. The program will repeat this 
process 30 times and will compute the average execution time for 
each (arraysize,sorting-function)  pair, over these 30 iterations. 
Finally, the program will output all these numbers in a readable 
format, e.g., as a table.
c. Are your computed numbers reasonable given your knowledge of 
the asymptotic complexity of each sorting algorithm? Explain.
*/

#include <iostream>
using namespace std;

//Insertionsort

void InsertionSort(int arr[], int length)
{
  int j;
  int temp;
  for(int i = 1; i < length; i++)
  {
    j = i;
    while(j > 0 && arr[j-1] > arr[j])
    {
      temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
      j--;
    }
  }
}

//Quicksort

void QuickSort(int arr[], int beg, int end)
{
  int i = beg;
  int j = end;
  int pivot = arr[(beg+end) / 2];
  int temp;
  
  while(i <= j)
  {
    while(arr[i] < pivot)
    {
      i++;
    }
    while(arr[j] > pivot)
    {
      j--;
    }
    if(i <= j)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }
  
  if(beg < j)
  {
    QuickSort(arr,beg,j);
  }
  if(i < end)
  {
    QuickSort(arr,i,end);
  }
}

//HeapSort
void swap(int &a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

int leftChild(int a)
{
  return 2 * a + 1;
}

void bubbleDown(int arr[], int a, int b)
{
  int child;
  int temp;
  for(temp = arr[a]; leftChild(a) < b; a = child)
  {
    child = leftChild(a);
    if(child != b - 1 && arr[child] < arr[child + 1])
    {
      child++;
    }
    if(temp < arr[child])
    {
      arr[a] = arr[child];
    }
    else
    {
      break;
    }
    arr[a] = temp;
  }
}

void HeapSort(int arr[], int length)
{
  for(int i = length/2; i >= 0; i--)
  {
    bubbleDown(arr, i, length);
  }
  
  for(int j = length - 1; j > 0; j--)
  {
    swap(arr[0], arr[j]);
    bubbleDown(arr, 0, j);
  }
}

//MergeSort

void merge(int arr[], int low, int mid, int high)
{
  int temp[10];
  int a = low;
  int b = low;
  int c = mid + 1;
  
  while(a <= mid && c <= high)
  {
    if(arr[a] < arr[c])
    {
      temp[b] = arr[a];
      a++;
      b++;
    }
    else
    {
      temp[b] = arr[c];
      b++;
      c++;
    }
  }
  
  while(a <= mid)
  {
    temp[b] = arr[a];
    a++;
    b++;
  }
  
  while(c <= high)
  {
    temp[b] = arr[c];
    b++;
    c++;
  }
  
  int i = low;
  while(i <= high)
  {
    arr[i] = temp[i];
    i++;
  }
  
}

void MergeSort(int arr[], int low, int high)
{
  if(low < high)
  {
    int mid = (low + high)/2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}


//Main function/Test Harness
int main()
{
  int size = 10;
  int array[size];
  array[0] = 0;
  array[1] = 2;
  array[2] = 20;
  array[3] = 6;
  array[4] = 52;
  array[5] = 17;
  array[6] = 0;
  array[7] = -1;
  array[8] = 30;
  array[9] = 99;
  
  //InsertionSort(array, size);
  //QuickSort(array,0,size-1);
  HeapSort(array, size);  //not working
  //MergeSort(array, 0, size);
  for(int i = 0; i < size; i++)
  {
    cout << array[i] << endl;
  }
}
