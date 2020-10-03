/* Operator Overloading by demonstrating Matric ADT*/

#include<bits/stdc++.h>
using namespace std;
class MATRIX{
	private:
		int row, col;
		int **M;
	public:
		MATRIX(int r=0, int c=0){
		row = r; col = c;
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
		friend MATRIX operator+(MATRIX M1, MATRIX M2);
		friend MATRIX operator*(MATRIX M1, MATRIX M2);
		friend MATRIX operator-(MATRIX M1, MATRIX M2);
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
MATRIX operator+(MATRIX M1, MATRIX M2){
	if(M1.row!=M2.row || M1.col != M2.col)
		cout << "Number of rows or column in both matrices missmatch. NOT ADDITIVE\n";
	else {
		int x,y;
		MATRIX temp(M1.row, M1.col);
		for(int i=0; i<M1.row; i++){
			for(int j=0; j<M1.col; j++){
				x = M1.getValue(i,j);
				y = M2.getValue(i,j);
				temp.setValue(i,j,x+y);
			}
		}
	return temp;
	}
}

MATRIX operator-(MATRIX M1, MATRIX M2){
	if(M1.row!=M2.row || M1.col != M2.col){
		cout << "Number of rows and columns in both matrices missmatch. NOT SUBTRACTIVE\n";
	}else{
		int x,y;
		MATRIX temp(M1.getRow(), M2.getCol());
		for(int i=0; i<M1.row; i++){
			for(int j=0; j<M1.col; j++){
				x = M1.getValue(i,j);
				y = M2.getValue(i,j);
				temp.setValue(i,j,x-y);
			}
		}
	return temp;
	}
}
MATRIX operator*(MATRIX M1, MATRIX M2){
	if(M1.getCol()!=M2.getRow())
		cout << "Both matrices are not multiplicative\n";
	else{
		int i,j,k,z=0;
			MATRIX temp(M1.getRow(),M2.getCol());
			for(i=0; i<M1.getRow(); i++){
				for(j=0; j<M2.getCol(); j++){
					z = 0;
					for(k=0; k<M1.getCol(); k++)
					z += M1.getValue(i,k)*M2.getValue(k,j)
					temp.setValue(i,j,z);
			}
		}
	return temp;
	}
}
int main(void){
MATRIX M1(2,2);
MATRIX M2(2,2);
MATRIX M3;
MATRIX M4;
cin >> M1 >> M2;
cout << endl << M1 << endl << M2;
M3 = M1*M2;
M4 = M1+M2;
cout << endl << M3;
cout << endl << M4;
}
