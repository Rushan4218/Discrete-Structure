/* Programs to compute an, bn mod m, linear search etc by using recursion. */

#include<stdio.h>

int power(int b, int n);

int main(){
	int b,n,result;
	
	printf("Enter base number: ");
	scanf("%d",&b);
	
	printf("Enter power: ");
	scanf("%d",&n);
	
	result = power(b,n);
	printf("%d^%d = %d",b,n,result);
	
}

int power(int b, int n){
	if(n==0)
		return 1;
	else
		return (b*power(b,n-1));
}