/* Programs to generate permutations and combinations. */

#include<stdio.h>
long permutation(int n, int r);
long combination(int n, int r);

int main(){
	int n,r;
	long p, c;
	printf("Enter value of n and r: \n");
	scanf("%d%d",&n,&r);
	
	p = permutation(n,r);
	c = combination(n,r);
	
	printf("Permutation P(%d, %d) = %ld\n",n,r,p);
	printf("Combination C(%d, %d) = %ld",n,r,c);
}

long permutation(int n, int r){
	int i;
	long f1,f2;
	f1=f2=1;
	for(i=1; i<=n; i++){
		f1=f1*i;
	}
	for(i=1; i<=(n-r); i++){
		f2=f2*i;
	}
	
	return f1/f2;
}

long combination(int n, int r){
	int i;
	long f1,f2,f3;
	f1=f2=f3=1;
	for(i=1; i<=n; i++){
		f1=f1*i;
	}
	for(i=1; i<=(n-r); i++){
		f2=f2*i;
	}
	for(i=1; i<=r; i++){
		f3=f3*i;
	}
	return f1/(f2*f3);
}