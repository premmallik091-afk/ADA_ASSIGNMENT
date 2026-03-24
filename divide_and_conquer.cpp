
#include <iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x) {
    if (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void merge(int arr[], int l, int m, int r) {
    int i=l, j=m+1, k=0;
    int temp[100];

    while(i<=m && j<=r)
        temp[k++] = (arr[i]<arr[j]) ? arr[i++] : arr[j++];

    while(i<=m) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];

    for(int i=0;i<k;i++) arr[l+i]=temp[i];
}

void mergeSort(int arr[], int l, int r) {
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void quickSort(int arr[], int l, int r) {
    if(l>=r) return;
    int pivot=arr[l], i=l, j=r;

    while(i<j){
        while(arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[l],arr[j]);

    quickSort(arr,l,j-1);
    quickSort(arr,j+1,r);
}

int main() {
    int arr[5]={5,2,4,1,3};

    mergeSort(arr,0,4);
    for(int i=0;i<5;i++) cout<<arr[i]<<" ";

    cout<<"\nBinary Search (4): "<<binarySearch(arr,0,4,4);

    return 0;
}
