#include <stdio.h>

void print(int n) {
    // Function to print truth table for n variables
    int total = 1 << n; // Total possible combinations (2^n)

    for (int i = 0; i < total; i++) {
        for (int j = n - 1; j >= 0; j--) {
            printf("%d ", (i >> j) & 1);
        }
        printf("\n");
    }
}

int main() {
    // Premises
    int p1, p2;

    // c
    int c;

    printf("Truth table for premises:\n");
    printf("Premise 1 | Premise 2\n");
    print(2); // Two premises

    printf("\nTruth table for c:\n");
    printf("c\n");
    print(1); // One c

    // Now, let's evaluate the validity of the argument
    printf("\nValidity of the argument:\n");

    for (int i = 0; i < 4; i++) {
        p1 = (i >> 1) & 1;
        p2 = i & 1;

        // Evaluate the c based on premises
        c = p1 && p2;

        printf("Premises: %d %d | c: %d | Valid: %s\n", p1, p2, c,
               (c) ? "Yes" : "No");
    }

    return 0;
}
