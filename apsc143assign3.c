//Include Libraries
#include <math.h>
#include <stdio.h>

int main(){

     //User input for time
     float time;
     printf("Enter time in seconds: \n");
     scanf("%f", &time);

     //AC Output Voltage
     float voltageTotal = 8 * cosf(M_PI*time);

     //Set voltage of bulb to 0 to start
     float  voltagebulb = 0;


     //Print out if the voltage is positive, negative or 0
     if (voltageTotal < 0)
         printf("Source voltage is negative");
     else if(voltageTotal > 0)
         printf("Source voltage is positive");
     else
         printf("Source voltage is 0");

    //Determine if the voltage is below 0.7V which closes switch 1
    if (voltageTotal < -0.7) {
        printf("\nSwitch 1 is closed");
        printf("\nThe Voltage of the bulb is %0.2f V", voltagebulb);
        printf("\nThe bulb is not on");
    }

    //Determine if the voltage is above 6.4V which closes switch 2
    else if (voltageTotal > 6.4) {
        printf("\nSwitch 2 is closed");
        printf("\nThe Voltage of the bulb is %0.2f V", voltagebulb);
        printf("\nThe bulb is not on");
    }
    //If the voltage falls within range calculate the voltage running through the bulb
    else{
        float voltagebulb = voltageTotal / 10 * 8;
        printf("\nThe Voltage of the bulb is %0.2f V", voltagebulb);
        if (voltagebulb > 1 && voltagebulb < 5.2) {
            printf("\nThe bulb is on");
        }
        else{
            printf("\nThe bulb is not on");
        }
    }
}