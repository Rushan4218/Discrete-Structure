/* Programs to implement
 Euclidean and Extended Euclidean algorithms. */
 
 #include<stdio.h>
 
 int gcd(int a, int b){
 	if(a==0)
 		return b;
 	return gcd(b%a, a);
 }
 
 int gcdEx(int a, int b, int *x, int *y){
 	int i,j, gcd;
 	if(a==0){
 		*x=0;
 		*y=0;
 		return b;
	 }
	 
	 gcd = gcdEx(b%a, a, &i, &j);
	 
	 *x = j-(b/a)*i;
	 *y = i;
	 
	 return gcd;
 }
 int main(){
 	int x,y;
 	int a,b,c;
 	int gcdExValue;
 	
 	printf("Enter two numbers: \n");
 	scanf("%d%d",&a,&b);
 	
 	c = gcd(a,b);
 	gcdExValue = gcdEx(a,b,&x,&y);
 	
 	printf("GCD = %d\n", c);
 	printf("Extended GCD = %d\n", gcdExValue);
 }