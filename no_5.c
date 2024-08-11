/* Programs to implement binary integer 
addition, multiplication, and division. */

#include<stdio.h>
int add(int a, int b);
int multi(int a, int b);
int div(int a, int b);

int main(){
	int x,y;
	printf("Enter two binary numbers: ");
	scanf("%d%d",&x,&y);
	
	printf("Add = %d\nMultiply = %d\nDivide = %d\n", add(x,y),multi(x,y),div(x,y));
	
}


int add(int a, int b){
	int carry = 0, result = 0, bit, base = 1;

    while (a > 0 || b > 0 || carry) {
        int bitA = a % 10;
        int bitB = b % 10;

        int sum = bitA + bitB + carry;
        bit = sum % 2;
        carry = sum / 2;

        result = result + bit * base;
        base *= 10;

        a /= 10;
        b /= 10;
    }

    return result;
}

int multi(int a, int b) {
    int result = 0, base = 1;

    while (b > 0) {
        int bitB = b % 10;
        
        if (bitB == 1) {
            result = add(result, a);
        }

        a = a * 10;
        b /= 10;
    }

    return result;
}

int div(int a, int b) {
    int quotient = 0;

    while (a >= b) {
        int temp = a;
        int tempDivisor = b;
        int count = 1;

        while (temp >= (tempDivisor << 1)) {
            tempDivisor <<= 1;
            count <<= 1;
        }

        a -= tempDivisor;
        quotient += count;
    }

    return quotient;
}