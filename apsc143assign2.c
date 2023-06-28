//Include Libraries
#include <stdio.h>
#include <math.h>

/* Program determines the number of students needed to carry a ThunderMugz through
 * an obstacle course and the time they will take from the mass of the box and the
 * throne given by the user */
int main(){

    // Declaring constants gravity and load that each student is able to carry
    float gravity = 9.8;
    int studentLoad = 300;

    // User input for mass of box and throne
    printf("Enter the mass of the box spring in kg:");
    int massBox;
    scanf("%d", &massBox);

    printf("Enter the mass of the throne in kg:");
    int massThrone;
    scanf("%d", &massThrone);


    //Determine the number of students needed to carry the mass of the ThunderMugz
    float studentNumber = ((massBox + massThrone)*gravity) / studentLoad;

    //Use condition statement to determine if there is extra mass using modulus and adding another student to carry the ThunderMugz
    if (((massBox + massThrone)*gravity) / studentLoad != 0)
    {
        studentNumber = floorf(studentNumber);
        studentNumber += 1;
    }
    //Calculate the total time.
    float time = (massBox + massThrone) * (4 - exp(0.1*(studentNumber)));

    //Calculate minutes and seconds based on the total time
    int minutes = time / 60;

    float seconds = fmod(time, 60);

    //Print the number of students able to carry the ThunderMugz.
    printf("\nThe ThunderMugz will need a minimum of %0.0f students to carry it.", studentNumber);

    //Print the time it takes to complete the ThunderMugz course.
    printf("\nIt will take %d minutes and %0.0f seconds to complete the ThunderMugz challenge.", minutes, seconds);
}