#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define PI 3.14159

int main(void){

    int selector;
    double cateto1, cateto2, hipotenusa, alfa, beta;
    int opcionAngulo, opcionCateto;

    do{

        printf("1. Dos catetos\n2. Un cateto y un angulo\n\n");
        scanf("%d", &selector);
        system("cls");
        switch (selector)
        {
        case 1:
            printf("DOS CATETOS\n\n");
            do
            {

                printf("Ingresa el primer cateto: ");
                scanf("%lf", &cateto1);
                printf("Ingresa el segundo cateto: ");
                scanf("%lf", &cateto2);

                if(cateto1 <= 0 || cateto2 <= 0)
                    printf("Error no hay distancias negativas");
            }while(cateto1 <= 0 || cateto2 <= 0);

            //Calcular la hipotenusa
            hipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2));
            printf("Esta es la hipotenusa: %.2lf\n", hipotenusa);

            //Calcular angulo alfa
            alfa = atan((cateto2 / cateto1));
            alfa = alfa * (180 / PI);
            printf("Este es el angulo alfa: %.2lf\n", alfa);

            //Calcular angulo beta
            beta = atan((cateto1 / cateto2));
            beta = beta * (180 / PI);
            printf("Este es el angulo beta: %.2lf\n", beta);
            
            system("pause");
            system("cls");
            break;

        case 2:

            printf("UN CATETO Y UN ANGULO\n\n");
            do{
                printf("Que angulo desea ingresar?\n");
                printf("1. alfa\n2. beta\n\n");
                scanf("%d", &opcionAngulo);
                if(opcionAngulo == 1){

                    printf("Ingresa el angulo alfa: ");
                    scanf("%lf", &alfa);
                }else{

                    printf("Ingresa el angulo beta: ");
                    scanf("%lf", &beta);
                    alfa = beta;
                }

                printf("Que cateto desea ingresar?\n");
                printf("1. adyacente\n2. opuesto\n\n");
                scanf("%d", &opcionCateto);

                if(opcionCateto == 1){

                    printf("Ingresa el cateto adyacente: ");
                    scanf("%lf", &cateto1);
                }else{

                    printf("Ingresa el cateto opuesto: ");
                    scanf("%lf", &cateto2);
                    cateto1 = cateto2;
                }

                if (cateto1 < 0 || alfa < 0 || alfa > 90)
                    printf("Error de ingreso de datos\n\n");
            }while(cateto1 < 0 || alfa < 0 || alfa > 90);

            alfa = alfa * (PI / 180);

            //Calcular la hipotenusa
            hipotenusa = cateto1 / cos(alfa);
            printf("Este es la hipotenusa: %.2lf\n", hipotenusa);

            //Calcular cateto2
            cateto2 = sqrt(pow(hipotenusa, 2) - pow(cateto1, 2));
            printf("Este es el cateto 2: %.2lf\n", cateto2);

            //calcular angulo beta
            beta = atan(cateto1 / cateto2);
            beta = beta * (180 / PI);
            printf("Este es el angulo beta: %lf\n\n", beta); 

            system("pause");
            system("cls");
            break;
        case 3:
            printf("Saliendo...\n\n");
            system("pause");
            system("cls");
            break;
        default:
            break;
        }


    }while(selector != 3);


    return 0;
}