#include<stdio.h>
// -----------pertition function-----------------------
int partition(int arr[], int low, int high)
{
    int pivot =arr[high];
    int i=low-1;

    for(int j=low; j<high; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            //swap
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    i++;
    int temp=arr[i];
    arr[i]=pivot;
    arr[high]=temp;
    return i;    //pivot index
}
//----------- Recursive function---------------------------
void quickSORT(int arr[], int low, int high)
{
    if(low<high)
    {
        int pidx=partition(arr, low, high);
        quickSORT(arr, low, pidx-1);
        quickSORT(arr, pidx+1, high);
    }
}
//---------------------------------------------------------//
int main()
{
    int n;
    scanf("%d",&n);
    int arr[100];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    quickSORT(arr, 0, n-1);
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    return 0;
}
