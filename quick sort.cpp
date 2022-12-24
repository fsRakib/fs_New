#include<bits/stdc++.h>
using namespace std;
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=0; j<high; j++)
    {                          ////////////////////
        if(arr[j]<pivot)      /////Placing/////////
            i++;             /////Smaller/////////
        //swap               //////element////////
       int temp=arr[i];     //////Before/////////
        arr[i]=arr[j];      ///////pivot/////////
        arr[j]=temp;        ////////////////////
       
    }
    i++;                 /////Placing////////
   int temp=arr[i];     //////PIVOT///////
    arr[i]=pivot;       ////////in//////////
    arr[high]=temp;     ///Right Place//////
   
    return i; //------------->> Pivot Index////
}
void quicksort(int arr[], int low, int high)
{
    /*  low --> Starting index,
        high --> Ending index */
    if(low<high)
    {
        int pivdx=partition(arr, low, high);
        quicksort(arr, low, pivdx-1);
        quicksort(arr, pivdx+1, high);
    }
}
int main()
{
    int n;
    cin >>n;
    int arr[100];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    quicksort(arr, 0, n - 1);
     for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
