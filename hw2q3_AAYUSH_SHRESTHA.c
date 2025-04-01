#include <stdio.h>

void calculateFuelEconomy() {
    char distUnit[20], fuelUnit[20];
    float distance, fuel;

    // Get units from user
    printf("Please enter the units for distance: ");
    scanf("%s", distUnit);
    printf("Please enter the units for fuel: ");
    scanf("%s", fuelUnit);

    // Get distance and fuel values
    printf("\nPlease enter the number of %s traveled: ", distUnit);
    scanf("%f", &distance);
    printf("Please enter the number of %s of fuel used: ", fuelUnit);
    scanf("%f", &fuel);

    // Calculate and display fuel economy
    printf("\n%.1f %s / %.1f %s = %.2f %s per %s.\n", 
           distance, distUnit, fuel, fuelUnit, 
           distance / fuel, distUnit, fuelUnit);
}

int main() {
    calculateFuelEconomy();
    return 0;
}
