#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 
#define N 4

int path_exists(int mat[][N], int rows, int cols) {
	int res = 0;
	if (rows == N - 1 && cols == N - 1)     //Exit condition - stop when you found the left bottom corner. 
		return mat[N - 1][N - 1];		//return the left bottom corner value - 0 -> no path is found, 1 -> path was found

	if (mat[rows][cols] == 1)			// check if the value is 1 and we should continue look for path
	{
		//check if we get 1 in the right cell & check the matrix boundries. 
		if (((cols + 1) < N) && (path_exists(mat, rows, cols + 1) == 1)) return 1;
		//check if we got 1 in the diagonal cell & check the matrix boundries. 
		if (((cols + 1) < N) && ((rows + 1) < N) & (path_exists(mat, rows + 1, cols + 1) == 1)) return 1;
		//check if we got 1 in the bottom cell & check the matrix boundries. 
		if (((rows + 1) < N) && (path_exists(mat, rows + 1, cols) == 1)) return 1;
	}

	//in case we didn't found a path to continue to - return 0.
	return 0;
}

void main()
{
	int result = 0, rows = 0, cols = 0;
	int mat[][N] = { 0 };
	printf("please insert matrix values (only 0 or 1):\n");
	for (int i = 0; i < N; i++)     //input of rows
		for (int j = 0; j < N; j++) {    //input of cols
			do {
				scanf_s("%d", &mat[i][j]);    //this loop check valid input - only 1 or 0
				if (mat[i][j] != 0 && mat[i][j] != 1)
					puts("Wrong input, please try again\n");
			} while (mat[i][j] != 0 && mat[i][j] != 1);
		}
	result = path_exists(mat, rows, cols);
	if (result)
		puts("\nPath was found!!!");    //path_exists return 1
	else
		puts("\nSorry, No path was found!!!");     //path_exists return 0
	system("pause");
}
