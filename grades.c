#include <stdio.h>
#include <stdlib.h>

/* calculate final grade */
float
final(float goal, float p, float g)
{
    return (goal - (1 - (p / 100)) * g) / (p / 100);
}

/* calculate weighted mark */
float
marks(float g, float p)
{
    return g * (p / 100);
}

int
main(int argc, char *argv[])
{

    float goalNeeded, grade, percent, totalGrade = 0, totalPercent = 0, goal;

    do {
        printf("Enter grade (0 to quit): ");
        scanf("%f", &grade);
        printf("Enter percentage (0 to quit): ");
        scanf("%f", &percent);
        totalGrade += marks(grade, percent);
        totalPercent += percent;
    } while (grade)

    if (totalPercent != 100)
        totalGrade = totalGrade / (totalPercent / 100);

    printf("Final grade: %.2f\nTotal percentage: %.2f\n", totalGrade, totalPercent);

    printf("Final grade goal: ");
    scanf("%f", &goal);
    goalNeeded = final(goal, (100 - totalPercent), totalGrade);
    
    if (totalPercent >= 100) 
        printf ("Can't do final grades. You're at 100");
    else
        printf("You would need a %.2f on the remaining %.2f", goalNeeded, (100 - totalPercent));

}
