#include <stdio.h>
#include <stdlib.h>
float totalPercentage (float);
float marks (float, float);
float final (float, float, float);

int main () {
    float goalNeeded, grade, percent, totalGrade = 0, totalPercent = 0, goal;
    //loop until user enters 0
    while (grade != 0) {
        printf("Enter grade (0 to quit): ");
        scanf("%f", &grade);
        printf("Enter percentage (0 to quit): ");
        scanf("%f", &percent);
        totalGrade += marks(grade, percent);
        totalPercent += totalPercentage(percent);
    }
    if (totalPercent != 100){
        totalGrade = totalGrade/(totalPercent/100);
    }
    printf("Final grade: %.2f\n", totalGrade);
    printf("Total percentage: %.2f\n", totalPercent);
    printf("Final grade goal: ");
    scanf("%f", &goal);
    goalNeeded = final(goal, (100-totalPercent), totalGrade);
    if (totalPercent == 100) 
    printf ("Can't do final grades. You're at 100");
    else printf("You would need a %.2f on the remaining %.2f", goalNeeded, (100-totalPercent));
}

float totalPercentage (float p) {
    float val = 0;
    val += p;
    return val;
}

float final (float goal, float p, float g) {
    float need = 0;
    need = (goal - (1-(p/100)) * g)/(p/100);
return need;
}

//total marks. Division by 100 to get decimal value of percentage.
float marks (float g, float p) {
    float total = 0;
    total += (g * (p/100));
    return total;
}