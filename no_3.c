/* Programs to implement fuzzy set operations */

#include<stdio.h>
#include<math.h>

float Max(float a, float b);
float Min(float a, float b);
float Not(float a);
void print(float set[], int n);

int main(){
	int i,n;
	float A[20],B[20];
	float maxVal[20], minVal[20], notValA[20], notValB[20];
	
	printf("Enter number of elements: ");
	scanf("%d",&n);
	
	printf("Enter elements of set A:\n");
	for(i=0; i<n; i++){
		scanf("%f",&A[i]);
	}
	
	printf("Enter elements of set B:\n");
	for(i=0; i<n; i++){
		scanf("%f",&B[i]);
	}
	
	for(i=0; i<n; i++){
		maxVal[i]=Max(A[i],B[i]);
		minVal[i]=Min(A[i],B[i]);
		notValA[i]=Not(A[i]);
		notValB[i]=Not(B[i]);
	}
	
	printf("Max value: \n");
	print(maxVal, n);

	printf("\nMin value: \n");
	print(minVal, n);
	
	printf("\nComplement of A: \n");
	print(notValA, n);
	
	printf("\nComplement of B: \n");
	print(notValB, n);

}

float Max(float a, float b){
	if(a>b)
		return a;
	else
		return b;
}

float Min(float a, float b){
	if(a<b)
		return a;
	else
		return b;
}

float Not(float a){
	return 1-a;
}

void print(float set[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%.2f\n",set[i]);
	}
}
