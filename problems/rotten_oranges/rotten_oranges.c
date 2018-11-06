// https://practice.geeksforgeeks.org/problems/rotten-oranges/0

#include <stdio.h>
#include <stdbool.h>

bool** resetFlag(int** matrix, bool** flag, int r, int c);
bool isInBounds(int rows, int cols, int i, int j);
bool canMakeMove(int** matrix, int rows, int cols, int i, int j);

int main() {

	int r = 0; // rows
	int c = 0; // columns

	scanf("%d", &r);
	scanf("%d", &c);

	int** matrix = (int**) malloc(sizeof(int*) * r);
	bool** flag = (bool**) malloc(sizeof(bool*) * r);

	int i, j, k, cnt = 0, n = 0;
	for(i = 0; i < r; i++) { 
		matrix[i] = (int*) malloc(sizeof(int) * c);
		flag[i] = (bool*) malloc(sizeof(bool) * c);

		for(j = 0; j < c; j++) { 
			scanf("%d", &n);
			matrix[i][j] = n;
			flag[i][j] = false;
			cnt += (matrix[i][j] == 1) ? 1 : 0;
		}
	}

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++) {
			printf("%d |", matrix[i][j]);
		}
		printf("\n");
	}

	printf("number of rows: %d\n", r);
	printf("number of cols: %d\n", c);
	printf("number of 1's: %d\n", cnt);

	for(i = 0; i < (r*c); i++) {
		for(j = 0; j < r; j++) {
			for(k = 0; k < c; k++) {
				if((matrix[j][k] == 2) && flag[j][k]) {
					if(canMakeMove(matrix, r, c, j-1, k)) { matrix[j-1][k] = 2; flag[j-1][k] = false; cnt--; }
					if(canMakeMove(matrix, r, c, j+1, k)) { matrix[j+1][k] = 2; flag[j+1][k] = false; cnt--; }
					if(canMakeMove(matrix, r, c, j, k-1)) { matrix[j][k-1] = 2; flag[j][k-1] = false; cnt--; }
					if(canMakeMove(matrix, r, c, j, k+1)) { matrix[j][k+1] = 2; flag[j][k+1] = false; cnt--; }
				}
			}
		}

		flag = resetFlag(matrix, flag, r, c);

		if(cnt == 0) { printf("steps: %d\n", i); break; }
	}

	if(cnt != 0) { printf("steps: -1\n"); }

	for(i = 0; i < r; i++) { free(matrix[i]); }
	free(matrix);
	

	return 0;
}

bool** resetFlag(int** matrix, bool** flag, int r, int c) {
	int i, j;

	for(i = 0; i < r; i++) {
		for(j = 0; j < c; j++) {
			flag[i][j] = matrix[i][j] == 2;
		}
	}

	return flag;
}

bool canMakeMove(int** matrix, int rows, int cols, int i, int j) {
	return isInBounds(rows, cols, i , j) && (matrix[i][j] == 1);
}


bool isInBounds(int rows, int cols, int i, int j) {
	return (0 <= i) && (i < rows) && (0 <= j) && (j < cols);
}
