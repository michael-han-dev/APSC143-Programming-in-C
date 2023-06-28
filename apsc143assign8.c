#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function declaration
double functionE(double xValue);
double reimannSum(int interval, double lowerBound, double upperBound);
double taylorSeriesApprox(int terms, double lowerBound);
int factorial(int i);
double taylorRiemann(int interval, double lowerBound, double upperBound);
double error(int interval, double lowerBound, double upperBound);

int main(){

    //Ask user for the lower and upper bound
    double lowerBound;
    double upperBound;

    //Create a while loop that asks user for lower and upper bound and repeatedly ask them until lower bound is lower than upper bound
    while(1){
        printf("Enter the bounds to compute the Riemann Sum:\n");
        scanf("%lf", &lowerBound);
        scanf("%lf", &upperBound);

        //If lower bound is greater than the upper bound, print an error message, else break out of the loop
        if(lowerBound >= upperBound){
            printf("Lower bound cannot be greater than upper bound!\n");
        }else{
            break;
        }
    }

    //Print the riemann sum of the function with 5, 25, and 100 intervals by calling the riemann sum function
    printf("Riemann Sum with 5 intervals: %0.2lf\n", reimannSum(5,lowerBound, upperBound));
    printf("Riemann Sum with 25 intervals: %0.2lf\n", reimannSum(25,lowerBound, upperBound));
    printf("Riemann Sum with 100 intervals: %0.2lf\n", reimannSum(100,lowerBound, upperBound));

    printf("--------------------------------------------------------\n");

    //Print the taylor series approximation at the lower bound with 3, 5 and 10 terms by calling the taylor series approximation function
    printf("Taylor Series Approximation at x = %0.2lf with 3 terms: %0.2lf\n",lowerBound, taylorSeriesApprox(3,lowerBound));
    printf("Taylor Series Approximation at x = %0.2lf with 5 terms: %0.2lf\n",lowerBound, taylorSeriesApprox(5,lowerBound));
    printf("Taylor Series Approximation at x = %0.2lf with 10 terms: %0.2lf\n",lowerBound, taylorSeriesApprox(10,lowerBound));

    printf("--------------------------------------------------------\n");

    //Print the taylor series riemann sum with 5, 25, and 100 intervals by calling the taylorRiemann function
    printf("Taylor Series Riemann Sum with 5 intervals: %0.2lf\n", taylorRiemann(5, lowerBound, upperBound));
    printf("Taylor Series Riemann Sum with 25 intervals: %0.2lf\n", taylorRiemann(25, lowerBound, upperBound));
    printf("Taylor Series Riemann Sum with 100 intervals: %0.2lf\n", taylorRiemann(100, lowerBound, upperBound));

    printf("--------------------------------------------------------\n");

    //Print the error between the riemann sum and taylor series with 5, 25, and 100 intervals by calling the error function
    printf("Error in Riemann Sums with 5 intervals: %0.2lf%%\n", error(5, lowerBound, upperBound));
    printf("Error in Riemann Sums with 25 intervals: %0.2lf%%\n", error(25, lowerBound, upperBound));
    printf("Error in Riemann Sums with 100 intervals: %0.2lf%%\n", error(100, lowerBound, upperBound));
}

//FUNCTION DEFINITIONS
//Function of e^x^2
double functionE(double xValue){

    double xSquared = pow(xValue, 2);
    double e = exp(1);
    return pow(e,xSquared);
}

//Function of riemann sum
double reimannSum(int interval, double lowerBound, double upperBound){

    //Determine the range of the bounds
    double rangeBound = upperBound - lowerBound;

    //Determine the interval in which to increase by
    double intervalChange = rangeBound/interval;

    //create a value for the left sum riemann sum and set a count variable to the lower bound
    double leftSum = 0;
    double count = lowerBound;

    //Create for loop to set change the power
    for(int i = 0; i < interval; i++){

        //Call E function and set count as function input
        double x = functionE(count);

        //change the count interval by adding the interval change
        count += intervalChange;
        //Multiply the individual area to the left sum total
        leftSum += fabs(x*intervalChange);
    }

    return leftSum;

}

//Define the taylor series approximation function
double taylorSeriesApprox(int terms, double lowerBound){

    //Declare and set the taylor sum variable to zero, this variable is the one being returned
    double taylorSum = 0;
    for (int i = 0; i < terms; i++) {

        //Determine the taylor series of the function e^x^2 by squaring the lower bound and putting
        //it to the power of i, then dividing i factorial which calls from the factorial function
        taylorSum += (pow(fabs(pow(lowerBound, 2)), i) / factorial(i));

    }
    return taylorSum;
}

//Define the factorial function
int factorial(int i){

    //Set a variable to input i
    int factorialSum = i;
    //Start for loop at 1 minus the input variable and multiplying sequential elements to the total
    for(int j = i-1; 0 < j; j--){
        factorialSum *= j;

    }
    //If the factorial is 0, change it to 1 as 0! is equal to 1
    if(factorialSum == 0){
        factorialSum++;
    }
    return factorialSum;
}

//Define the taylor series riemann sum function
double taylorRiemann(int interval, double lowerBound, double upperBound){

    //Determine the range of the bounds
    double rangeBound = upperBound - lowerBound;
    //Determine the interval in which to increase by
    double intervalChange = rangeBound/interval;

    //create a value for the left sum riemann sum and set a count variable to the lower bound
    double leftSum = 0;
    double count = lowerBound;

    //Create a for loop to change the bound of the taylor series of 10 within and calculate the riemann sum of this series
    for(int i = 0; i < interval; i++){

        double x = taylorSeriesApprox(10,count);

        //Increase the count by the interval change to change the interval
        count += intervalChange;
        //Multiply the height by the interval change to determine area and add it to the left sum total.
        leftSum += fabs(x*intervalChange);
    }

    return leftSum;
}

//Declare error function
double error(int interval, double lowerBound, double upperBound){

    //Return the error which is defined as the taylor series riemann sum subtract the riemann sum all over the riemann sum multiplied by 100
    return ((taylorRiemann(interval, lowerBound, upperBound)-reimannSum(interval, lowerBound, upperBound))/ (reimannSum(interval, lowerBound, upperBound)))*100;
}

