/*
	Implementing safe 2D and 3D array
*/

#include<bits/stdc++.h>
using namespace std;

class _1D{
	int *arr;
	int n;
	public:
		_1D(){
			cout << "Enter size of array: ";
			cin >> n;
			arr = new int[n];
		}
		int & operator[](int n){
			if(n < 0 || n > this->n){
				cout << "Index out of bound\n";
				exit(1);
			} else 
				return arr[n];
		}
};

class _2D{
	_1D *arr;
	int n;
	public:
		_2D(){
			cout << "Enter size of array: ";
			cin >> n;
			arr = new _1D[n];
		}
		_1D & operator[](int n){
			if(n < 0 || this->n){
				cout << "Index out of bound\n";
				exit(1);
			} else
				return arr[n];
		}
};

class _3D{
	_2D *arr;
	int n;
	public:
		_3D(){
			cout << "Enter size of array: ";
			cin >> n;
			arr = new _2D[n];
		}
		_2D & operator[](int n){
			if(n < 0 || n > this->n){
				cout << "Index out of bound\n";
				exit(1);
			} else 
				return arr[n];
		}
};

int main(){
	_1D arr;
	
	arr[10] = 10;
	cout << arr[10];
	
	_2D arr2;
	cin >> arr[10][10];
}
