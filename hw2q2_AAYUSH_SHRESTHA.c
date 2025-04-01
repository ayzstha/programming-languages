#include <stdio.h>

void printSquares(int n) {
    for (int i = 0; i < n; i++) {
        // Print filled square
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf(" "); // Space between squares
        
        // Print hollow square
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n"); // New line after each row
    }
}

int main() {
    int n;
    printf("Enter the side length: ");
    scanf("%d", &n);
    printSquares(n);
    return 0;
}