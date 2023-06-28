#include <string.h>
#include <stdio.h>

//Michael Han, 20347013
//Assignment 6 - Strings
//Due November 3, 2022

int main(){

    //Declare an array to hold acronyms, and an array to hold words.
    char acronymArray[10][10];
    char wordArray[10][50];

    //Determine number of acronyms that user wants
    int acronymNum;
    printf("Enter number of acronyms to add to the database:\n");
    scanf("%d", &acronymNum);
    getchar();

    //Variable used in for loop to keep track of the letter index
    int letterCount = 0;

    for(int i = 0; i < acronymNum; i++) {

        //Set letter count to 0 to refresh letter count
        letterCount = 0;

        //Ask user for a string that the user wants converted to an acronym
        printf("Enter the string to convert into an acronym:\n");
        fgets(wordArray[i], 50, stdin);

        //Converts last character to NULL value
        if (wordArray[i][strlen(wordArray[i]) - 1] == '\n') {
            wordArray[i][strlen(wordArray[i]) - 1] = '\0';
        }
        //loop that goes through the characters of the string user wants converted to acronym
        for (int j = 0; j < strlen(wordArray[i]); j++) {
            char wordChar = wordArray[i][j];

            //Skips empty space if there is a sentence
            if(acronymArray[i][j] == ' '){
                continue;
            }

            //Determines if first character is between A and Z in ascii and appends it to the acronym array of index i
            if(j == 0){
                if (wordArray[i][j] <= 'Z' && wordArray[i][j] >= 'A'){
                    acronymArray[i][letterCount] = wordChar;
                    letterCount++;
                    acronymArray[i][letterCount] = '\0';
                }
            }

            //Determines if sequential characters are between A and Z in ascii and appends it to the acronym array of index i.
            else if(wordArray[i][j] <= 'Z' && wordArray[i][j] >= 'A') {
                if (j != 0){

                    //Determines if there is a space before the character
                    if (wordArray[i][j - 1] == ' ') {
                        acronymArray[i][letterCount] = wordChar;
                        letterCount++;
                        acronymArray[i][letterCount] = '\0';
                    }
                }
            }

        }
        //Print the acronym of the inputted string
        printf("Acronym of \"%s\" is \"%s\".\n", wordArray[i], acronymArray[i]);
    }

    //Variable to determine if the input corresponded to anything within the stored array. 1 for true, 0 for false.
    int returned = 0;

    //While loop for the matching of acronyms to words or to exit the program.
    while(1){

        //Set returned to 0 at the top of the loop as string has not matched to anything yet.
        returned = 0;

        //Declare an array to store inputted string that will be compared to see if it matches anything within the arrays.
        char correspondArray[1][50];
        printf("Enter the acronym of the string you would like to see, or enter 0 to exit:\n");
        fgets(correspondArray[0], 50, stdin);

        //Converts newline character to NULL
        if (correspondArray[0][strlen(correspondArray[0]) - 1] == '\n') {
            correspondArray[0][strlen(correspondArray[0]) - 1] = '\0';
        }

        //if "0" is entered, exit the program
        if(strcmp(correspondArray[0], "0") == 0){
            break;
        }

        //If anything else if entered, assumes user does not want to exit program and so will try and match string to something stored in the arrays.
        else{
            for(int i = 0; i < 1; i++){
                for (int j = 0; j < acronymNum; j++) {

                    //Compares inputted string to the word array to determine if an acronym needs to be printed.
                    if (strcmp(correspondArray[0], wordArray[j]) == 0) {
                        printf("The corresponding string to \"%s\" is \"%s\".\n", correspondArray[0], acronymArray[j]);
                        returned = 1;
                        break;
                    }

                    //Compares inputted string to the acronym array to determine if a word needs to be printed.
                    else if (strcmp(correspondArray[0], acronymArray[j]) == 0) {
                        printf("The corresponding string to \"%s\" is \"%s\".\n", correspondArray[0], wordArray[j]);
                        returned = 1;
                        break;
                    }
                }

                //If neither of the above is successful, returned will remain 0 and this assumes no match has been found.
                if(returned == 0){
                    printf("No match found.\n");
                }
            }
        }
    }

    return 0;
}