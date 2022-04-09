// Question 2
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

/* To display the conclusion sentences*/
void display(float x[SIZE], int n) {
	 /* Displaying Answer */ 
	printf("\nSolution:\n");
	for(int i = 1; i <= n; i++) {
	 	if(i == 1)
    		printf("\nThe volume of the solutions containing A (x) is %.1f cm3\n", x[i]);
    	else if(i == 2)
    		printf("\nThe volume of the solutions containing B (y) is %.1f cm3\n", x[i]);
    	else if(i == 3)
        	printf("\nThe volume of the solutions containing C (z) is %.1f cm3\n", x[i]);
	}
}

/* Applying Gauss Elimination */
void gauss(float a[SIZE][SIZE], int n) {
	float ratio, x[SIZE];
	for(int i = 1; i <= n - 1; i++) {
		if(a[i][i] == 0.0) {
			printf("Mathematical Error!");
			exit(1); // exit with error
		}
		for(int j = i + 1; j <= n; j++) {
			ratio = a[j][i]/a[i][i];
			   
			for(int k = 1; k <= n + 1; k++) {
			  	a[j][k] = a[j][k] - ratio * a[i][k];
			}
		}
	}		  
	 /* Obtaining Solution by Back Subsitution */
	x[n] = a[n][n + 1] / a[n][n];
	
	for(int i = n - 1; i >= 1; i--) {
		x[i] = a[i][n + 1];
		for(int j = i + 1; j <= n; j++) {
		  	x[i] = x[i] - a[i][j] * x[j];
		}
		x[i] = x[i] / a[i][i];
	}
	display(x,n); // function call to print conclusion sentences
}

/* Display Augmented Matrix*/
void displaymatrix(float a[SIZE][SIZE], int n) {
	printf("\nThe Augmented Matrix:\n");
	for(int i = 1; i <= n; i++) {
		printf("[  ");
		for(int j = 1; j <= n; j++){
			while(j != 4){
				printf("%.1f  ", a[i][j]);
				j++;
			}
			if(i == 1)
				printf("][ x ]=[ %.2f ]\n", a[i][j]);
			if(i == 2)
				printf("][ y ]=[ %.2f ]\n", a[i][j]);
			if(i == 3)
				printf("][ z ]=[ %.2f ]\n", a[i][j]);
		}
	}
}

/* 2. Reading Augmented Matrix 
 * Read data into the array
 */
void read(float a[SIZE][SIZE], int n)
{
	for(int i = 1; i <= n; i++) {
	 	if(i == 1)
        	printf("\nEquation of the proportion for ingredients A, B, C in solution 1\nPlease enter the value of:\n");
 		else if(i == 2)
 			printf("\nEquation of the proportion for ingredients A, B, C in solution 2\nPlease enter the value of:\n");
 		else if(i == 3)
 			printf("\nEquation of the proportion for ingredients A, B, C in solution 3\nPlease enter the value of:\n");	
		for(int j = 1; j <= n + 1; j++) {
			if(j == 1)
		        printf("x = ");
		    else if(j == 2)
		        printf("y = ");
		    else if(j == 3)
		        printf("z = ");
	        else if(j == 4)
		        printf("\nPlease enter the weight of chemical is produced(gram): ");
			//printf("a[%d][%d] = ",i,j);
			scanf("%f", &a[i][j]);
		}
	}
}

int main() {
	float a[SIZE][SIZE];
	int i, j, k, n = 3;
	/* 1. Reading number of variable */
	printf("\nPlease enter according the order A, B and C substance :\n" );
 	printf("\nIngredient A = x\nIngredient B = y\nIngredient C = z\n" );
 	read(a,n); // read data from array
 	displaymatrix(a,n); // display augmented matrix function
	gauss(a,n); // perform Gauss Elimination
	
	return(0);
}
