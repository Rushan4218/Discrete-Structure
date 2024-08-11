/* Programs to perform operations with large integers by 
breaking down them into set of small integers. */

#include<stdio.h>
#include<string.h>
#define MAX 10000

void reverse(char *str, int len);
void add(char *num1, char *num2, char *result);

int main(){
	char num1[MAX], num2[MAX], result[MAX];
	
	printf("Enter first and second numbers: \n");
	scanf("%s%s",num1,num2);
	// For addition
	add(num1,num2,result);
	printf("Sum = %s", result);
	
}

void reverse(char *str, int len){
	int i,j,temp;
	i=0;
	j=len-1;
	while(i>j){
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
}

void add(char *num1, char *num2, char *result){
	int carry,sum,i;
	carry=0;
	i=0;
	int len1=strlen(num1);
	int len2=strlen(num2);
	reverse(num1,len1);
	reverse(num2,len2);
	
	while(i<len1 || i<len2){
		sum=carry+(num1[i]-'0')+(num2[i]-'0');
		result[i]=(sum%10)+'0';
		carry=sum/10;
		i++;
	}	
	if(carry){
		result[i]=carry+'0';
		i++;
	}
	result[i]='\0';
	reverse(result,i);
}
