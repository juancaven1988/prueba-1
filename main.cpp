#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jugada (int);
int tirada ();

int main()
{
    srand(time(NULL));

    int balance = 1000, apuesta, point = 0;
    char continuar;

    do
    {
        printf("Su dinero es : %d\n Realice una apuesta:  ", balance);
        scanf("%d", &apuesta);

        while ( apuesta > balance)
        {

            printf("No dispone de ese dinero\n Realize una apuesta menor: ");
            scanf("%d", &apuesta);
        }


        while ((continuar != 'n' || continuar != 'N' )&& point < 13)
        {
            point = jugada(point);
            switch (point)
            {

            case 13:
                balance = balance + apuesta;
                printf("Felicitaciones ha ganado\n");
                break;
            case 14:
                balance = balance - apuesta;
                printf("Lo sentimos ha perdido\n");
                break;
            }
            fflush(stdin);
            if (point < 13)
            {
                printf("Lanzar los dados nuevamente (s/n): ");
                scanf("%c", &continuar);
                if (continuar == 'n' || continuar == 'N')
                    balance = balance - apuesta;
            }
        }
        if (point > 12)
        {
            point = 0;


            if (balance > 0)
            {
                fflush(stdin);
                printf("Su dinero es : %d\n", balance);
                printf("Desea continuar apostando (s/n): ");
                scanf("%c", &continuar);
            }
        }
        else
        {

        }

    }
    while (balance > 0 && (continuar == 's' || continuar == 'S'));

    if(balance == 0)
        printf("HA PERDIDO TODO SU DINERO");
    else
        printf("Se ha retirado con $%d", balance);


}



int tirada ()
{

    int dado1, dado2, suma;
    dado1 = 1 + rand()%6;
    dado2 = 1 + rand()%6;
    suma = dado1 + dado2;
    printf("La tirada es %d + %d = %d\n", dado1, dado2, suma);


    return suma;
}


int jugada (int point)
{

    int roll;

    roll = tirada();

    if (point == 0)
    {

        switch (roll)
        {

        case 7:
        case 11:
            point = 13;
            return point;
            break;
        case 2:
        case 3:
        case 12:
            point = 14;
            return point;
            break;
        default:
            point = roll;
            printf("Su punto es : %d\n", point);
            return point;
        }
    }

    else
    {
        if ( roll == point)
            return 13;
        else if (roll == 7)
            return 14;
        else
        {
            printf("Su punto es : %d\n", point);
            return point;
        };
    }

}

