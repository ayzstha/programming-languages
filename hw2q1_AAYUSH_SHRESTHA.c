#include <stdio.h>

void printDiamond(int n) {
    int i, j;
    // For upper half of diamond
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++)
            printf(" ");
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }
    // For lower half of diamond
    for (i = n - 2; i >= 0; i--) {
        for (j = 0; j < n - i - 1; j++)
            printf(" ");
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows (must be positive): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive number\n");
        return 1;
    }
    
    printDiamond(n);
    return 0;
}
