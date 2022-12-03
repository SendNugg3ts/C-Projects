#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    const double PI = 3.14159;
    double r;
    double perimetro;
    double area;
    char choice;
    printf("\nQueres calcular area ou perimetro?");
    scanf("%c",&choice);
    if(strcmp(choice,"perimetro")==0){
        printf("\nQual é o raio do circulo?");
        scanf("%lf",&r);
        perimetro = 2  * PI * r;
        printf("O perimetro do circulo é: %.3lf\n",perimetro);
    }
    else if(strcmp(choice,"area")==0){
        printf("\nQual é o raio do circulo?");
        scanf("%lf",&r);
        area= PI *r*r;
        printf("A area do circulo é: %.3lf\n",area);
    }else{
        printf("Escreveste errado.");
    }

    return 0;
}