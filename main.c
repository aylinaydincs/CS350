#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int point;
    char name[100];
} Option;

int isInIt(char* name, Option ptr[], int size){
    for(int i=0; i<size; i++){
        if(ptr[i].point == 0)
            break;
        if(strcmp(ptr[i].name, name) == 0)
            return i;
    }
    return -1;
}
bool isUnique(){
int count = 0;

if(count==1)
    return true;
else if (count==2)
    return false;
}

int tracker = 0;
void isSomebodyChoose(Option option[], Option ptr[], int size){
    for(int i =0; i<size; i++){
        if ((isInIt(option[i].name, ptr, size * 5) != -1))
            ptr[isInIt(option[i].name, ptr, size * 5)].point += option[i].point;
        else if (isInIt(option[i].name, ptr, size * 5) == -1) {
            ptr[tracker].point = option[i].point;
            strcpy(ptr[tracker].name, option[i].name);
            tracker += 1;
        }
    }
}

int findFinal(Option ptr[], int size){
    int biggestPoint = 0;
    int index = 0;
    for(int i=0; i<size; i++){
        if(ptr[i].point > biggestPoint){
            biggestPoint = ptr[i].point;
            index = i;
        }
        else if(ptr[i].point == 0)
            break;
    }
    return index;
}

int main() {
    const int threshHold = 6;
    int numOfPlayer = 0;
    int topChoices= 0;

    printf("Welcome to What2Eat program!\n Please specify the number of player: \n");
    scanf("%d", &numOfPlayer);

    Option pointsOfMeals[numOfPlayer * 5];
    Option pointsOfMealsAboveThresh[numOfPlayer * 5];
    Option final[numOfPlayer * 5];

    printf("Let's start first round: \n");
    Option one,two,three,four,five;
    one.point = 5;
    two.point = 4;
    three.point = 3;
    four.point = 2;
    five.point = 1;

    for(int i=0; i < numOfPlayer; i++){
        printf("Please player %d enter five meal preferences most desired to least \n",i+1);
        scanf("%s %s %s %s %s", &one.name, &two.name, &three.name, &four.name, &five.name);
        Option personal[5]={one,two,three,four,five};
        isSomebodyChoose(personal, pointsOfMeals, numOfPlayer * 5);
    }

    for(int i=tracker; i < numOfPlayer * 5; i++){
        pointsOfMeals[i].point = 0;
    }

    tracker = 0;
    printf("These meals chose most : \n");
    for(int i=0; i < (numOfPlayer * 5); i++){
        if(pointsOfMeals[i].point >= threshHold){
            topChoices = 1;
            printf("%s : %d \n", pointsOfMeals[i].name, pointsOfMeals[i].point);
            pointsOfMealsAboveThresh[tracker] = pointsOfMeals[i];
            tracker += 1;
        }
    }
    for(int i=tracker; i < numOfPlayer * 5; i++){
        pointsOfMealsAboveThresh[i].point = 0;
    }

    tracker = 0;

    if(topChoices==0)
        printf("You are eating at home/dorm today! \n");

    else{
        printf("Second step: \n");
        for (int i = 0; i < numOfPlayer; i++) {
            printf("We decreased the list. Let's choose in this list \n", i + 1);
            Option six;
            Option last[1]={six};
            scanf("%s", six.name);
            six.point = pointsOfMealsAboveThresh[isInIt(six.name, pointsOfMealsAboveThresh, numOfPlayer * 5)].point;
            isSomebodyChoose(last, final, numOfPlayer * 5);
        }

        for (int i = tracker; i < numOfPlayer * 5; i++)
            final[i].point = 0;

        char *finalMeal = final[findFinal(final, numOfPlayer * 5)].name;
        printf("You will eat today %s \n", finalMeal);
    }

    return 0;
}

