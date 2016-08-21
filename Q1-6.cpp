#include<iostream>
#include<ctype.h>
#include<malloc.h>
#include<string.h>

using namespace std;


void rotate (int n, int **arr) {

	int row = n, col = n;

	if(n % 2 != 0) col+=1;

	for (int i = 0; i < col/2; ++i)
	{
		for (int j = 0; j < row/2 ; ++j)
		{
			int temp =  arr[i][j];
			arr[i][j] = arr[n-1-j][i];
			arr[n-1-j][i] = arr[n-1-i][n-1-j];
			arr[n-1-i][n-1-j] = arr[j][n - 1 -i];
			arr[j][n - 1 -i] = temp;
		}
	}
}


int main() {

	int n = 8;

	int **p = new int*[n];

	for (int i = 0; i < n; ++i)
		p[i] = new int[n];
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			p[i][j] = n * i +j;
		
	rotate(n, p);

	for (int i = 0; i < n; ++i)
	{
		cout << endl;
		for (int j = 0; j < n; ++j)
		{
			cout << "  " << p[i][j];

		}
	}

}
