#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
			if(j>i){
			
			cout<<arr[i][j]<<" ";
		}
		else{
			cout<<" "<<" ";
		}
		}
		cout<<endl;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=i;j++){
//			if(j>i){
			
			cout<<arr[i][j]<<" ";
//		}
//		else{
//			cout<<" "<<" ";
//		}
		}
		cout<<endl;
	}
	return 0;
}

