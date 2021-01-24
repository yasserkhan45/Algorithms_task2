Q. Quick Sort Algo

#include<iostream>
using namespace std;

int partition(int arr[], int l, int r){

    int count = 0;
    for(int i = l + 1; i <= r; i++){
        if(arr[i] < arr[l]) count++;
    }
    int temp = arr[l + count];
    arr[l + count] = arr[l];
    arr[l] = temp;
    int pos = l + count;
    int i = l, j = r;
    while(i != pos && j != pos){
        if(arr[i] > arr[pos] && arr[j] <= arr[pos]){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        if(arr[i] <= arr[pos]) i++;
        if(arr[j] > arr[pos]) j--;
    }
    return pos;
}

void quickSort(int arr[], int l, int r){
    if(l >= r) return;
    int pos = partition(arr, l, r);
    quickSort(arr, l, pos - 1);
    quickSort(arr, pos + 1, r);
}

int main(){
    int arr[] = {5, 6, 7, 10, 11, 12, 12, 1, 16, -1, 10, 2, 0 };
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    cout<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<' ';
    }

    cout<<endl;
}
