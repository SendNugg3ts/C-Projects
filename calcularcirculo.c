#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    const double PI = 3.14159;
    double r;
    double perimetro;
    double area;
    char choice[100];
    printf("\nQueres calcular area ou perimetro?\n");
    scanf("%s",&choice);
    if(strcmp(choice ,"perimetro")== 0){
        printf("\nQual é o raio do circulo?\n");
        scanf("%lf",&r);
        perimetro = 2  * PI * r;
        printf("O perimetro do circulo é: %.3lf\n",perimetro);
    }
    else if(strcmp(choice ,"area")== 0){
        printf("\nQual é o raio do circulo?\n");
        scanf("%lf",&r);
        area= PI *r*r;
        printf("A area do circulo é: %.3lf\n",area);
    }else{
        printf("Escreveste errado.\n");
        printf("%s",choice);
    }

    return 0;
}