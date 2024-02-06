#include <stdio.h>
#include <math.h>

#define MAX_CLASSES 10

// Function to perform chi-square test for uniformity
double chi_square_test(int observed[], int expected[], int num_classes) {
    double chi_square_statistic = 0.0;

    // Calculate chi-square statistic
    for (int i = 0; i < num_classes; i++) {
        chi_square_statistic += pow(observed[i] - expected[i], 2) / (double)expected[i];
    }

    return chi_square_statistic;
}

int main() {
    int num_classes;

    // Input the number of classes (categories or intervals)
    printf("Enter the number of classes: ");
    scanf("%d", &num_classes);

    if (num_classes <= 1 || num_classes > MAX_CLASSES) {
        printf("Error: Number of classes should be between 2 and %d.\n", MAX_CLASSES);
        return 1;  // Exit with an error code
    }

    // Input observed frequencies
    int observed[MAX_CLASSES];
    printf("Enter the observed frequencies for each class:\n");
    for (int i = 0; i < num_classes; i++) {
        printf("Class %d: ", i + 1);
        scanf("%d", &observed[i]);
    }

    // Calculate expected frequencies (assuming uniform distribution)
    int total_observed = 0;
    for (int i = 0; i < num_classes; i++) {
        total_observed += observed[i];
    }
    int expected[MAX_CLASSES];
    for (int i = 0; i < num_classes; i++) {
        expected[i] = total_observed / num_classes;
    }

    // Perform chi-square test
    double chi_square_statistic = chi_square_test(observed, expected, num_classes);

    // Compare with critical value (using chi-square distribution table)
    // For example, for a significance level of 0.05 with (num_classes - 1) degrees of freedom
    double critical_value;
    printf("Enter the critical value:");
    scanf("%lf",&critical_value);

    // Output the chi-square statistic
    printf("Chi-square statistic: %lf\n", chi_square_statistic);

    // Output the conclusion based on the comparison
    if (chi_square_statistic <= critical_value) {
        printf("The observed frequencies follow a uniform distribution (not rejected).\n");
    } else {
        printf("The observed frequencies do not follow a uniform distribution (rejected).\n");
    }

    return 0;
}
