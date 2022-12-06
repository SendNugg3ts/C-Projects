#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    const int MIN=1;
    const int MAX=100;
    int guess;
    int guesses= 1;
    int answer;

    srand(time(0));

    answer = (rand()%MAX)+MIN;
    do{
        printf("What is your guess?\n");
        scanf("%d",&guess);
        if(guess > answer){
            printf("Too High!\n");
        }
        else if(guess < answer){
            printf("Too Low\n");
        }else{
            printf("You are Correct!\n");
        }
        guesses++;

    }while (answer != guess);

    printf("You completed the challenge in: %d tries\n",guesses);

    return 0;
}