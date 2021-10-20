#include<iostream>
#include<vector>

using namespace std;


// Partition func tries to put pivot element at its correct position.
int partition(vector<int>&arr,int s,int e){

    int pivot=arr[e];              // taking last element as pivot
    int i=s-1;

    for(int j=s;j<e;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);


    return i+1;

}

void quickSort(vector<int>&arr,int s,int e){
    // Base case
    if(s>=e){
        // then no or one elements
        return;
    }
    // Recursive case
    int p=partition(arr,s,e);      // let p be the pivot element
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);

}

int main(){

    int n;cin>>n;
    vector<int>arr(n);   
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    quickSort(arr,0,(n-1));

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

}
