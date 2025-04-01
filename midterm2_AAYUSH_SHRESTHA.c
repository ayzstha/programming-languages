#include <stdio.h>

// Prompt user for a positive integer and record it
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    // Check if the integer is positive and display it if it is    
    if (n <= 0) {
        printf("Please enter a positive number.\n");
    } else {
        printf("You entered the integer %d.\n", n);
        
        // Display each digit on its own line, starting with least significant digit
        int temp = n;
        
        // Handle the case if n is 0
        if (n == 0) {
            printf("0\n");
        }
        
        // Extract and print each digit
        while (temp > 0) {
            int digit = temp % 10; // Get the last digit
            
            // Print spaces before digit if it's not zero
            if (digit != 0) {
                for (int i = 0; i < digit; i++) {
                    printf(" ");
                }
            }
            
            // Print the digit
            printf("%d\n", digit);
            
            // Remove the last digit
            temp /= 10;
        }
    }
    
    // Prompt the user to enter a floating point number and record it
    double fp;
    printf("Enter a floating point number: ");
    scanf("%lf", &fp);
    
    // Display the floating point number 10 times with increasing decimal places
    printf("\nDisplaying the floating point number with increasing decimal places:\n");
    for (int i = 1; i <= 10; i++) {
        printf("%.*f\n", i, fp);
    }
    
    return 0;
}