/* Programs for representing relations, testing its properties, and testing equivalence. */

#include<stdio.h>
#include<stdlib.h>

int isRef(int mat[100][100], int n);
int isSym(int mat[100][100], int n);

int main(){
	int i,j;
	int m,n;
	int mat[100][100];
	
	printf("Enter row and column: ");
	scanf("%d%d",&m,&n);
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("matrix[%d][%d] = ",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	
	printf("\nChecking for Reflexive:\n");
	if(isRef(mat,n))
		printf("The relation is reflexive.\n");
	else
		printf("The relation is not-reflexive.\n");
		
	printf("\nChecking for Symmetry:\n");
	if(isSym(mat,n))
		printf("The relation is symmetric.\n");
	else
		printf("The relation is not-symmetric.\n");
			
}

int isRef(int mat[100][100], int n){
	int i;
	for(i=0; i<n; i++){
		if(mat[i][i]!=1)
			return 0;	
	}
	return 1;
}
int isSym(int mat[100][100], int n){
	int i,j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(mat[i][j]!=mat[j][i])
				return 0;
		}
		return 1;
	}
}
