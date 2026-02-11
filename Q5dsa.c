#include <stdio.h>

int main() {
    int prices[100], n, i;
    int minPrice, maxProfit = 0;

    printf("Enter number of days: ");
    scanf("%d", &n);

    printf("Enter prices:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    minPrice = prices[0];


    for (i = 1; i < n; i++) {
        
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
 
        else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    printf("Maximum Profit: %d\n", maxProfit);

    return 0;
}