#include <stdio.h>
#include <math.h>

int main() {
    double loanamount, interestrate, timeyears, emi;
    int interesttype;
    
    printf("=== LOAN EMI CALCULATOR ===\n\n");
    
    // Input loan details
    printf("Enter loan amount: $");
    scanf("%lf", &loanamount);
    
    printf("Enter annual interest rate (%%): ");
    scanf("%lf", &interestrate);
    
    printf("Enter time period (in years): ");
    scanf("%lf", &timeyears);
    
    printf("\nSelect interest type:\n");
    printf("1. Simple Interest\n");
    printf("2. Compound Interest (compounded annually)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &interesttype);
    
    printf("CALCULATION RESULTS:\n");
    printf("====================\n");
    printf("Loan Amount: $%.2lf\n", loanamount);
    printf("Annual Interest Rate: %.2lf%%\n", interestrate);
    printf("Time Period: %.1lf years\n", timeyears);
    
    // Convert annual rate to monthly and years to months
    double monthlyrate = interestrate / 1200.0;  // 12 months * 100%
    double timemonth = timeyears * 12;
    
    // Nested decision structure
    if (loanamount <= 0) {
        printf("\nERROR: Loan amount must be positive!\n");
    } else if (interestrate <= 0) {
        printf("\nERROR: Interest rate must be positive!\n");
    } else if (timeyears <= 0) {
        printf("\nERROR: Time period must be positive!\n");
    } else {
        // Valid inputs, proceed with interest type selection
        if (interesttype == 1) {
            // Simple Interest EMI Calculation
            printf("Interest Type: Simple Interest\n");
            
            double total_interest = loanamount * (interestrate / 100) * timeyears;
            double total_amount = loanamount + total_interest;
            emi = total_amount / timemonth;
            
            printf("Total Interest: $%.2lf\n", total_interest);
            printf("Total Amount Payable: $%.2lf\n", total_amount);
            
        } else if (interesttype == 2) {
            // Compound Interest EMI Calculation
            printf("Interest Type: Compound Interest (Annual Compounding)\n");
            
            double total_amount = loanamount * pow(1 + (interestrate / 100), timeyears);
            double total_interest = total_amount - loanamount;
            
            // Standard EMI formula for compound interest
            if (monthlyrate > 0) {
                emi = (loanamount * monthlyrate * pow(1 + monthlyrate, timemonth)) / 
                      (pow(1 + monthlyrate, timemonth) - 1);
            } else {
                emi = loanamount / timemonth;  // Zero interest case
            }
            
            printf("Total Interest: $%.2lf\n", total_interest);
            printf("Total Amount Payable: $%.2lf\n", total_amount);
            
        } else {
            printf("\nERROR: Invalid interest type selected!\n");
            printf("Please choose either 1 or 2.\n");
            return 1;
        }
        
        // Display EMI result
        printf("MONTHLY INSTALLMENT (EMI)\n");
        printf("============================\n");
        printf("EMI: $%.2lf per month\n", emi);
        printf("Number of Installments: %.0lf months\n", timemonth);
        printf("Total Payment: $%.2lf\n", emi * timemonth);
        
        // Additional breakdown
        printf("\nPayment Breakdown:\n");
        printf("Principal per month: $%.2lf\n", loanamount / timemonth);
        printf("Interest per month: $%.2lf\n", emi - (loanamount / timemonth));
    }
    
    return 0;
}