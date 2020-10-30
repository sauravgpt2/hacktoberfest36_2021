// C++ program to print a n x n spiral matrix 
// spiral from center
#include <bits/stdc++.h> 
using namespace std; 

// Prints spiral matrix of size n x n containing 
// numbers from 1 to n x n 
void printSpiral(int n) 
{ 
	for (int i = 0; i < n; i++) 
	{ 
		for (int j = 0; j < n; j++) 
		{ 
			// x stores the layer in which (i, j)th 
			// element lies 
			int x; 

			// Finds minimum of four inputs 
			x = min(min(i, j), min(n-1-i, n-1-j)); 

			// For upper right half 
			if (i <= j) 
				printf("%d\t ", (n-2*x)*(n-2*x) - (i-x) 
					- (j-x)); 

			// for lower left half 
			else
				printf("%d\t ", (n-2*x-2)*(n-2*x-2) + (i-x) 
					+ (j-x)); 
		} 
		printf("\n"); 
	} 
} 

// Driver code 
int main() 
{ 
	int n;
	cin >> n;
	// print a n x n spiral matrix in O(1) space 
	printSpiral(n); 

	return 0; 
} 
