#include <stdio.h>
#include <ctype.h>

int main (){
    char questions[][100]={"1.What is Lipe favorite food?",
    "2.What is Lipe mom name?",
    "3.What is Lipe favorite programming language?"};
    char options[][100]={"A.Francesinha","B.Lasanha","C.Carbonara","D.Arroz de pato",
                           "A.Joana","B.Maria","C.Carla","D.Daniela",
                           "A.C++ ","B.C ","C.Javascript ","D.Python "};
    char answers[10]={'A','B','B'};
    int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);
    char guess;
    int score=0;
    printf("\n*******************\n");
    printf("QUIZ ABOUT LIPE\n");
    printf("*******************\n");
    for(int i=0;i<numberOfQuestions;i++){
        printf("%s\n",questions[i]);

        for(int j = (i*4);j < (i*4)+4;j++){
            printf("\n%s",options[j]);
        };
        printf("\nguess: ");
        scanf("%c",&guess);
        scanf("%c"); // clear new line from input
        guess= toupper(guess);
        if(guess == answers[i]){
            printf("Correct\n");
            score++;
        }else{
            printf("Wrong\n");
        };

    };
    printf("FINAL SCORE: %d/%d\n",score,numberOfQuestions);

    
    return 0;
}