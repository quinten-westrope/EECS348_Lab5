#include <stdio.h>

int main() {
    FILE * file;
    int i;
    int j;
    // array to store sales
    double sales[12];
    // months array
    char * months[] = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };
    
    // variables for sales report summary
    double totalSales = 0.0, averageSales;
    double maxSales, minSales;
    int maxMonth = 0, minMonth = 0;

    // opening input file with sales amounts
    file = fopen("sales.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    // reading from input file into the array
    for (i = 0; i < 12; i++) {
        fscanf(file, "%lf", &sales[i]);
    }

    // closing file
    fclose(file);

    // calculating total sales - min sales - max sales - average sales
    maxSales = minSales = sales[0];  // Initialize max and min with the first month's sales
    for (i = 0; i < 12; i++) {
        // summing total sales
        totalSales += sales[i]; 

        // updating max
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxMonth = i;
        }

        // updating min
        if (sales[i] < minSales) {
            minSales = sales[i];
            minMonth = i;
        }
    }
    
    // calculating average sales
    averageSales = totalSales / 12;


    // monthly sales report
    printf("\nMonthly Sales Report for 2024:\n");
    printf("\n"); 
    // formatting month and sales with proper spacing
    printf("%-12s %-6s\n", "Month", "Sales");
    for (i = 0; i < 12; i++) {
        printf("%-12s $%.2f\n", months[i], sales[i]);
    }
    

    // sales report summary
    printf("\nSales Summary Report:\n");

    printf("Minimum Sales:   $%.2f (%s)\n", minSales, months[minMonth]);
    printf("Maximum Sales:   $%.2f (%s)\n", maxSales, months[maxMonth]);
    printf("Average Sales:   $%.2f\n", averageSales);

    // six month moving report
    printf("\nSix-Month Moving Average Report:\n");

    for (i = 0; i <= 6; i++) {
        double mSum = 0.0;
        for (int j = i; j < i + 6; j++) {
            mSum += sales[j];
        }
        // displaying each moving average
        printf("%-8s->%-12s $%.2f\n", months[i], months[i + 5], mSum / 6);
    }
    


    // sales report highest to lowest
    printf("\nSales Report (Highest to Lowest):\n");
    printf("\n");
    // formatting month and sales with proper spacing
    printf("%-12s %-6s\n", "Month", "Sales");

    // sorting sales - months, using bubble sort
    for (i = 0; i < 12 - 1; i++) {
        for (j = 0; j < 12 - i - 1; j++) {
            if (sales[j] < sales[j + 1]) {
                // swaping sales
                double tempSales = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = tempSales;

                // swaping months
                char *tempMonth = months[j];
                months[j] = months[j + 1];
                months[j + 1] = tempMonth;
            }
        }
    }

    // sales in descending order
    for (i = 0; i < 12; i++) {
        printf("%-12s $%.2f\n", months[i], sales[i]);
    }

    return 0;
}