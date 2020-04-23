#include <stdio.h>
#include <stdlib.h>

/* weighted mark calculation */
#define WMARK(g, p) g * (p / 100)

/* final mark calculation  */
#define FINAL(goal, p, g) (goal - (1 - (p / 100)) * g) / (p / 100)

int
main(int argc, char *argv[])
{

    float goalNeeded, grade = 0, percent = 0, totalGrade = 0, totalPercent = 0, goal;

    do {
        printf("Enter grade (0 to quit): ");
        scanf("%f", &grade);
        if (grade) {
            printf("Enter percentage (0 to quit): ");
            scanf("%f", &percent);
        }
        totalGrade += WMARK(grade, percent);
        totalPercent += percent;
    } while (grade);

    if (totalPercent != 100)
        totalGrade = totalGrade / (totalPercent / 100);

    printf("Final grade: %.2f\nTotal percentage: %.2f\n", totalGrade, totalPercent);

    printf("Final grade goal: ");
    scanf("%f", &goal);
    goalNeeded = FINAL(goal, (100 - totalPercent), totalGrade);
    
    if (totalPercent >= 100) 
        printf ("Can't do final grades. You're at 100\n");
    else
        printf("You would need a %.2f on the remaining %.2f\n", goalNeeded, (100 - totalPercent));

}
