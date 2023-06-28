#include <stdio.h>

int main() {
    //Have the user enter the number of limestones
    int numLimestones;
    printf("Enter the number of limestones to compare:");
    scanf("%d", &numLimestones);

    //Create a 2D array with the rows of limestones based on user input with 3 columns to store porosity, conductivity, and specfic gravity
    double LimestoneArray[numLimestones][3];

    //Declare variables for porosity, conductivity, and specific gravity as well as the flow rate which will be used later in the program
    double porosity;
    double conductivity;
    double specificGravity;
    double flowRate;

    //For loop to fill up the 2D array with the required limestone information based on user input.
    for (int row = 0; row < numLimestones; row++) {
        printf("\nEnter the porosity %%, hydraulic conductivity (m/s), and specific gravity for Limestone %d:", row+1);
        scanf("%lf" "%lf" "%lf", &porosity, &conductivity, &specificGravity);
        LimestoneArray[row][0] = porosity;
        LimestoneArray[row][1] = conductivity;
        LimestoneArray[row][2] = specificGravity;
    }

    //This variable helps keep track of which stone is used for the lowest specific gravity print statement. It loops with the counter.
    int stoneNumber;

    //Declare and set the variable equal to the starting lowest specific gravity to the first row third column of the 2D array.
    double minSG = LimestoneArray[0][2];

    //For loop to determine the lowest specfic gravity.
    for (int row = 1; row < numLimestones; row++){
        if (minSG > LimestoneArray[row][2]) {
            minSG = LimestoneArray[row][2];
            printf("%lf", minSG);
            stoneNumber = row+1;
        }
    }
    //Print the lowest specific gravity determined from loop above.
    printf("\nThe limestone with the lowest specific gravity is Limestone %d with a specific gravity of %0.4lf", stoneNumber, minSG);

    printf("\nFlow velocities:");

    //Declare the highest flow rate variable and set it equal to the first row conductivity value inserted into the Darcy's law equation.
    double maxFlowRate = LimestoneArray[0][1]*0.725*1200*1000000;

    //Declare the highest porosity variable and set it equal to the first row porosity value.
    double maxPorosity = LimestoneArray[0][0];

    //Declare a counter for both the flow rate and porosity stones to keep count of which stone had the highest of each value.
    int flowRateStone;
    int porosityStone;

    //For loop to determine the flowrate and porosity.
    for(int row = 0; row < numLimestones; row++){

        //Flowrate variable using the conductivity value from the 2D array located by the row number and middle column inserted into Darcy's Law equation.
        flowRate = LimestoneArray[row][1]*0.725*1200*1000000;

        //If statement to determine if the current flow rate is less than the new flow rate value, if it is then proceed to change the value of maxFlowRate
        //and keep track of which stone using the counter made.
        if (maxFlowRate < flowRate) {
            maxFlowRate = flowRate;
            flowRateStone = row;
        }
        //If statement to determine if the current porosity is less than the new porosity, if it is then proceed to change the value of maxPorosity
        //and keep track of which stone using the counter made.
        if (maxPorosity < LimestoneArray[row][0]) {
            maxPorosity = LimestoneArray[row][0];
            porosityStone = row;
        }
        //Variable of stonenumber helps with the print statement for each flowrate.
        stoneNumber = row+1;

        //Print the flowrate of each stone as the counter loops.
        printf("\nLimestone %d: %0.2lf cm^3/s", stoneNumber, flowRate);

    }
    //Determine if the 2 counters from the above for loop are equal, print statements accordingly.
    if (porosityStone == flowRateStone){
        printf("\nThe rock with the highest porosity has the highest flow velocity.");
    }else
        printf("\nThe rock with the highest porosity does not have the highest flow velocity.");
}