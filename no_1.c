/* Programs to implement set operations union, 
intersection, difference, and Cartesian product. */

#include <stdio.h>
#include <conio.h>
#define MAX 30

void create(int set[]);
void Union(int set1[], int set2[], int set3[]);
void intersec(int set1[], int set2[], int set3[]);
void difference(int set1[], int set2[], int set3[]);
int member(int set[], int x);
void print(int set[]);

int main(){
		
	int set1[MAX], set2[MAX], set3[MAX];
	int x, op;
	int i, n;
	
	set1[0]=set2[0]=set3[0]=0;
	printf("\nFor set one: ");
	create(set1);
	printf("\nFor set two: ");
	create(set2);
	
	
	// For Union
	Union(set1,set2,set3);
	printf("\nUnion= ");
	print(set3);

	
	// For Intersection
	intersec(set1, set2, set3);
	printf("\nIntersection= ");
	print(set3);
	
	// For Difference
	difference(set1,set2,set3);
	printf("\nDifference= ");
	print(set3);
	/*
	n=set3[0];
	for(i=1; i<n; i++){
		printf("%d\t", set3[i]);
	}	
	
	*/
}
	
void create(int set[]){
	int i,n,x;
	
	set[0] = 0;
	printf("\n Number Of Element: ");
	scanf("%d",&n);
	printf("Enter elements: \n");
	for(i=1;i<=n;i++)
		scanf("%d",&set[i]);
	set[0]=n;
}	


void print(int set[]){
	int i,n;
	n = set[0];
	printf("{");
	for(i=1; i<=n; i++){
		printf("%d",set[i]);
		if(i<n)
			printf(",");
		}
	printf("}");
}

void Union(int set1[], int set2[], int set3[]){
	int i,n;
	set3[0]=0;
	n=set1[0];
	
	/* Union of set1, set2 = set1 + (set2-set1) */
	for(i=0; i<=n; i++)
		set3[i]=set1[i];
		
	n=set2[0];
	for(i=1; i<=n; i++){
		if(!member(set3,set2[i]))
			set3[++set3[0]]=set2[i];
	}
}

int member(int set[], int x){
	int i,n;
	n=set[0];
	for(i=1; i<=n; i++){
		if(x==set[i])
			return (1);
	}
	return (0);
}

void intersec(int set1[], int set2[], int set3[]){
	int i,n;
	set3[0]=0;
	n=set1[0];
	
	for(i=1; i<=n; i++){
		if(member(set2,set1[i]))
			set3[++set3[0]]=set1[i];
	}
}

void difference(int set1[], int set2[], int set3[]){
	int i,n;
	set3[0]=0;
	n=set1[0];
	for(i=1; i<=n; i++){
		if(!member(set2, set1[i]))
			set3[++set3[0]]=set1[i];
	}
}