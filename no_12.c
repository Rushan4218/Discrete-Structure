/* Programs to implements some probabilistic and randomized algorithms. */

#include<stdio.h>

int main(){
	int a,c,m,n,q;
	int x,z;
	int i;
	
	printf("Enter the limit of the number: ");
	scanf("%d",&a);
	
	printf("input module m: ");
	scanf("%d",&m);
	
	printf("Enter constant: ");
	scanf("%d",&c);
	
	printf("Total: ");
	scanf("%d",&n);
	
	printf("Enter seed number: ");
	scanf("%d",&x);
	
	printf("random numbers: \n");
	for(i=0; i<n; i++){
		z=((x*a) + c) % m;
		printf("%d\t",z);
		x=z;
	}
	
	
}