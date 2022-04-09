// Question 1
#include<stdio.h>
 
void gauss( int a[10][10], int var );
void data(int a[10][10], int var);

//display augmented function
void displaymatrix(int a[10][10], int var)
{
	printf("\nThe Augmented Matrix:\n");
	
	for (int i=0; i<var; i++)
    {
    	printf("[  ");
        for (int j=0; j<var; j++)
        {
        	printf("%d  ", a[i][j]);
        }
        if(i==0)
 			printf("][ x ]=[ %d ]\n", a[i][var]);
 		if(i==1)
 			printf("][ y ]=[ %d ]\n", a[i][var]);
 		if(i==2)
 			printf("][ z ]=[ %d ]\n", a[i][var]);

    }
	
}

int main()
{
 
    int a[10][10], var=3;
 	printf("\nPlease enter according the order small box, medium box and large box : \n" );
 	printf("\nSmall box = x\nMedium box = y\nLarge box = z\n" );
 	data(a, var); //read data function
 	displaymatrix(a,var); //display augmented matrix function
    gauss(a, var);//Gauss Elimination function
    
    return 0;
}
//reading data into the array
void data(int a[10][10], int var)
{
	
	for (int i=0; i<var; i++)
    {

    	if(i==0)
        	printf("\nEquation for the number of oatmeal raisins\nPlease enter the value of:\n");
        	
 		else if(i==1)
 			printf("\nEquation for the number of chocolate chip\nPlease enter the value of:\n");
 			
 		else if(i==2)
 			printf("\nEquation for the number of shortbreads\nPlease enter the value of:\n");
        
        for (int j=0; j<var; j++)
        {
        	if(j==0)
	        	printf("x = ");
	        else if(j==1)
	        	printf("y = ");
	        else if(j==2)
	        	printf("z = ");
            scanf("%d", &a[i][j]);
        }
 
        printf("\nPlease enter the total number: ");
        scanf("%d", &a[i][var]);
    }
}
//Gauss Elimination method
void gauss(int a[10][10], int var)
{
 	int l;
 	
    for (int i=0; i<var; i++)
    {
        for (int j=0; j<=var; j++)
        {
            l = a[j][i];
 
            for (int k=0; k<=var; k++)
            {
                if (j!= i)
                a[j][k] = (a[i][i]*a[j][k])-(l*a[i][k]);
            }
        }
    }
 
    printf( "\nSolutions:" );
 
 	//to display the answer
    for (int i=0; i<var; i++)
    {
    	if(i==0)
    		printf("\nThe number of small box is %.0f\n", (float) a[i][var]/(float) a[i][i]);
    	else if(i==1)
    		printf("\nThe number of medium box is %.0f\n", (float) a[i][var]/(float) a[i][i]);
    	else if(i==2)
        	printf("\nThe number of large box is %.0f\n", (float) a[i][var]/(float) a[i][i]);
    }
}
