#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    //Open the file
    FILE *fp;
    fp = fopen("payloads.txt", "r");

    //If file doesn't open, return NULL and notify file wasn't found
    if (fp == NULL) {
        printf("File not found.\n");
        exit(0);
    }
    //Determine number of rows in the file
    int rows;
    fscanf(fp, "%d", &rows);

    //If there are no rows in the file then return no payloads
    if(rows == 0){
        printf("No payloads in file.\n");
        exit(0);
    }

    //Create 2D array using malloc
    float** payloadInfo =  (float**) malloc(rows * 3 * sizeof(float));
    for (int i = 0; i < rows; ++i) {
        payloadInfo[i] = (float*) malloc(3 * sizeof(float));
    }

    //Print 2 introduction lines
    printf("Payload Data:\n");
    printf("Total Mass / Grade / Ore Value\n");

    //Read each line from the file, assign it to the 2D array then print it to the console with the correct spacing.
    for (int i = 0; i < rows; i++) {
            float massTotal, grade;
            fscanf(fp, "%f %f", &massTotal, &grade);
            payloadInfo[i][0] = massTotal;
            payloadInfo[i][1] = grade;
            payloadInfo[i][2] = roundf(massTotal * grade * 8500);  //Calculation for the ore cost
        printf("   %.0f      %.2f    $%.0f\n", massTotal, grade, payloadInfo[i][2]);
    }

    //Declare variables to be used for the bubble sorting of the payloadInfo 2D array
    int swapMade;
    float temp;

    //Bubble sort the payload data
    while(1){
        swapMade = 0;
        for(int i = 0; i< rows-1; i++){
            if(payloadInfo[i][2] < payloadInfo[i+1][2]) {
                temp = payloadInfo[i][2];
                payloadInfo[i][2] = payloadInfo[i+1][2];
                payloadInfo[i+1][2] = temp;
                swapMade = 1;
            }
        }
        if(!swapMade){
            break;
        }
    }
    //Create a file to write to
    FILE *fwrite;
    fwrite = fopen("ores.txt", "w");

    //Create the strings for the headers to be written to the ores.txt file
    char sortedString[] = {"Sorted Payload Data:"};
    char statsLine[] = {"Total Mass / Grade / Ore Value"};

    //Write the 2 strings from above to the file
    fprintf(fwrite, "%s\n", sortedString);
    fprintf(fwrite, "%s\n", statsLine);

    //Write the sorted payload information to the file
    for (int i = 0; i < rows; i++) {
        fprintf(fwrite, "   %0.0f       %0.2f    $%0.0f\n", payloadInfo[i][0], payloadInfo[i][1], payloadInfo[i][2]);
    }

    //Print the sorted payload data sorted from the highest ore value to the least ore value
    printf("Sorted Payload Data:\n");
    printf("Total Mass / Grade / Ore Value\n");
    for (int i = 0; i < rows; i++) {
        printf("   %.0f      %.2f    $%.0f\n", payloadInfo[i][0], payloadInfo[i][1], payloadInfo[i][2]);
    }
    free(); // WRITE SOMETHING TO FREE MEMORY
}






