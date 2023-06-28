#include <stdio.h>
#include <math.h>

int main(){

    //User input for initial cost of project and declaration of initial cost variable
    double initialCost;
    printf("Enter the initial cost of the project: $");
    scanf("%lf", &initialCost);
    initialCost *= -1;

    //User input for annuity and declaration of annuity variable
    double annuity;
    printf("\nEnter the annuity of the project: $");
    scanf("%lf", &annuity);

    //User input and declaration for interest
    double interest;
    printf("\nEnter the interest rate in %%:");
    scanf("%lf", &interest);
    interest /= 100;

    //User input and declaration for years
    int years;
    printf("\nEnter the lifespan of the project in years:");
    scanf("%d", &years);

    /*Declared another variable for years equivalent to the start number of years and
     * this variable would be used for the present value function later which is why it is a float*/
    double initialYears = years;

    //Declared a counter variable for the payback period in years
    int paybackPeriod = 0;

    //Set an initial cost variable equivalent to the user input to use for while loop that determines pay back period
    double initialCost1 = initialCost;

    /*Loop that determines the payback period in years by breaking out when the initial cost is greater than 0
     *and adding 1 for everytime the loop runs*/
    while (initialCost1 < 0){
        initialCost1 += initialCost1 *interest;
        initialCost1 += annuity;
        paybackPeriod += 1;
    }
    /*Loop that determines the future value by breaking out when the years reach 0
     *and subtracting 1 for everytime the loop runs*/
    while (years > 0) {
        initialCost += initialCost * interest;
        initialCost += annuity;
        years -= 1;
    }

    //Function that converts the future value to the present value and prints this value on the screen
    double presentValue;
    presentValue = initialCost/pow((1+interest),initialYears);
    if (presentValue > 0){
        printf("\nPresent worth of the project = $%0.2lf\n", presentValue);
    }else
        printf("\nPresent worth of the project = -$%0.2lf\n", (presentValue * -1));


    /*Conditional statement to determine if the project is economically feasible or not based on if the present
     *value is positive or negative*/
    if (presentValue > 0)
        printf("The project is economically feasible.\n");

    else if (presentValue < 0)
        printf("The project is not economically feasible.\n");

    //Prints the payback period based on the value of the payback function
    printf("The payback period for this project is %d years.\n", paybackPeriod);



}
