#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    FILE *fp;
    char zero[5];
    fp = fopen("payloads.txt", "r");

    if (fp == NULL) {
        printf("File not found.\n");
        exit(0);
    }
    int rows;
    fscanf(fp, "%d", &rows);
    if(rows == 0){
        printf("No payloads in file.\n");
        exit(0);
    }

    int columns = 3;
    int count = 0;
    float oreGrade;

    float** payloadInfo =  malloc(rows * 3 * sizeof(float));
    for (int i = 0; i < rows; ++i) {

    }
            float unsortedPayload[7][3];
            printf("Payload Data:\n");
            printf("Total Mass / Grade / Ore Value\n");
            for (int i = 0; i < 7; i++) {
                fscanf(fp, "%f %f", unsortedPayload[i], unsortedPayload[i+1]);
                printf("%0.0f decimal is %0.2f\n", unsortedPayload[i][0], unsortedPayload[i][1]);
                oreGrade = unsortedPayload[i][0]*8500*unsortedPayload[i][1];
                unsortedPayload[i][2] = oreGrade;
                printf("   %0.0f      %0.2f    $%0.0f\n", unsortedPayload[i][0], unsortedPayload[i][1], unsortedPayload[i][2]);

//                if(count == 8){
//                    break;
//                }
//                oreGrade = 0;
//
//                for(int j = 0; j < 3; j++){
//                    if(j == 2) {
//                        break;
//                    }
//                    count++;
//
//                    if(count == 8){
//                        break;
//                    }
//                    fscanf(fp, "%f", &payloadInfo[i]);
//                    fscanf(fp, "%f", &payloadInfo[i+1]);
//                    oreGrade = payloadInfo[i]*8500*payloadInfo[i+1];

//                    printf("   %0.0f      %0.2f    $%0.0f\n", unsortedPayload[i][j], );




                //}
            }
        }




