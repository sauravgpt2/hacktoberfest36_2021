/* Friend Function */

#include<bits/stdc++.h>
using namespace std;

using namespace std;
class MATRIX{
	private:
		int row, col;
		int **M;
	public:
		MATRIX(int r=0, int c=0):row(r), col(c){
		M = new int *[r];
		for(int i=0; i<r;i++)
			M[i] = new int[c];
}
		void setValue(int i, int j, int k){ M[i][j] = k;}
		int getValue(int i, int j){ return M[i][j];}
		void setRow(int r){ row = r;}
		void setCol(int c){ col = c;}
		int getRow(){ return row;}
		int getCol(){ return col;}
		friend ostream & operator<<(ostream&out, MATRIX&M);
		friend istream & operator>>(istream&in, MATRIX&M);
};
istream & operator>>(istream&in, MATRIX&M){
	cout << "Enter elements: \n"; int x;
	for(int i=0; i<M.row; i++){
		for(int j=0; j<M.col; j++){
			cin >> x;
			M.setValue(i,j,x);
		}
	}
	return in;
}
ostream & operator<<(ostream&out, MATRIX&M){
	for(int i=0; i<M.row; i++){
		for(int j=0; j<M.col; j++)
			out << M.getValue(i,j) << " ";
			out << endl;
	}
	return out;
}


int main(){
	MATRIX M(2,3);
	cin >> M;
	cout << M; 
}
