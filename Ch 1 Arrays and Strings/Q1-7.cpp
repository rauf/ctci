#include<iostream>
#include<ctype.h>
#include<malloc.h>
#include<string.h>

using namespace std;


void rowZero(int **arr, int row, int n) {

	for (int i = 0; i < n; ++i){
		arr[row][i] = 0;
	}

}


void colZero(int **arr, int col, int n) {

	for (int i = 0; i < n; ++i){
		arr[i][col] = 0;
	}

}


void zero(int n, int **arr) {

	int row[n], col[n];

	for (int i = 0; i < n; ++i){
		row[i] = 0;
		col[i] = 0;
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n ; ++j)
		{
			if(arr[i][j] == 0){
				row[i] = 1;;
				col[j] = 1;
			}
		}
	}

/*
	for (int i = 0; i < n; ++i){
		if(row[i]) 	rowZero(arr, i, n);
		if(col[i])	colZero(arr, i, n);
	}
*/

/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n ; ++j)
		{
			if(row[i] || col[j]){
				arr[i][j] = 0;
			}
		}
	}
*/


}




int main() {

	int n = 8;

	int **p = new int*[n];

	for (int i = 0; i < n; ++i)
		p[i] = new int[n];
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			p[i][j] = 1  + j;
		

	p[0][1] = 0;
	p[0][5] = 0;
	p[3][3] = 0;

	zero(n, p);

	for (int i = 0; i < n; ++i)
	{
		cout << endl;
		for (int j = 0; j < n; ++j)
		{
			cout << "  " << p[i][j];

		}
	}

}
