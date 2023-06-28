#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Define the change in time which is 0.01 seconds
#define delta 0.01

//Declare the reaction function with each compound as well as rate and time variables
void reaction(float nh3, float o2, float n2, float h2o, float rate, float time);

int main(){
    //User input for ammonia and oxygen concentrations
    float nh3, o2;
    printf("Enter initial ammonia and oxygen concentrations: \n");
    scanf("%f %f", &nh3, &o2);

    //Call the reaction function and put the user entered input for ammonia, oxygen and everything else to 0
    reaction(nh3, o2, 0,0,0,0);

}
//Define the reaction function
void reaction(float nh3, float o2, float n2, float h2o, float rate, float time){

    //set the rate from the equation 1 in the assignment
    rate = 0.0965*nh3* powf(o2,2);

    //If rate is <= 0.001 return the final molarities for each compound and print the time, then return void.
    if(rate <= 0.001){
        printf("Final Reaction Molarities:\n"
               "NH3: %.2f M\n"
               "O2:  %.2f M\n"
               "N2:  %.2f M\n"
               "H2O: %.2f M\n"
               "The reaction will take %.2f seconds to reach a rate of 0.001 M/s. \n",nh3, o2, n2, h2o, time);
        return;
    }

    //call the reaction function and change each rate according to equation 2 from the assignment as well as increment the time.
    reaction(nh3-4*delta*rate,o2-3*delta*rate,n2+2*delta*rate,h2o+6*delta*rate,rate, time + delta);

}