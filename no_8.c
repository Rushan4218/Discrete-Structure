#include <stdio.h>
int main() {
    int choice;
    
    printf("Choose a logical operation:\n");
    printf("1. AND\n");    printf("2. OR\n");
    printf("3. IMPLIES\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);
   // Print header for the selected truth table
    switch (choice) {
        case 1:
            printf("R | U | R AND U\n");
            break;
        case 2:
            printf("R | U | R OR U\n");
            break;
        case 3:
            printf("R | U | R IMPLIES U\n");
            break;
        default:
            printf("Invalid choice\n");
            return 1; // Exit with an error code
	}
    
    printf("----------\n");

    // Loop through all possible combinations of R and U
    for (int R = 0; R <= 1; R++) {
        for (int U = 0; U <= 1; U++) {
            int result;

            // Evaluate the selected logical operation
            switch (choice) {
                case 1:
                    result = R && U; // AND
                    break;
                case 2:
                    result = R || U; // OR
                    break;
                case 3:
                    result = (!R) || U; // IMPLIES
                    break;
            }

            // Print the current row of the truth table
            printf("%d | %d | %d\n", R, U, result);
        }
    }

    return 0;
}


