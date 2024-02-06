#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Function to compare two values for qsort
double critical_value;
int compare(const void *a, const void *b) {
    return (*(double*)a - *(double*)b);
}
void kolmogorov_test(double *data, int n) {
    // Sort the data
    qsort(data, n, sizeof(double), compare);
    // Calculate D+ and D-
    double D_plus = 0.0;
    double D_minus = 0.0;

    for (int i = 0; i < n; ++i) {
        double F_i = (double)(i + 1) / n;
        double D_i_plus = fabs((double)(i + 1) / n - data[i]);
        double D_i_minus = fabs(data[i] - (double)i / n);

        if (D_i_plus > D_plus) {
            D_plus = D_i_plus;
        }

        if (D_i_minus > D_minus) {
            D_minus = D_i_minus;
        }
    }
    // Calculate the test statistic D
    double D = (D_plus > D_minus) ? D_plus : D_minus;

    // Output the results
    printf("D = %f\n", D);
    printf("Critical value = %f\n", critical_value);

    if (D <= critical_value) {
        printf("The data follows a uniform distribution.\n");
    } else {
        printf("The data does not follow a uniform distribution.\n");
    }
}
int main() {
    int n;
    // Get the number of data points from the user
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    
    printf("\nEnter the critical value for comparison:");
    scanf("%lf",&critical_value);
    // Allocate memory for the data
    double *data = (double*)malloc(n * sizeof(double));
    // Get the data points from the user
    printf("Enter the data points:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &data[i]);
    }
    // Perform the Kolmogorov-Smirnov test
    kolmogorov_test(data, n);
    // Free allocated memory
    free(data);
    return 0;
}
