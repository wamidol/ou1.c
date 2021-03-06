/*
 * Programmeringsteknik med C och Matlab
 * Fall 2018
 * Assignment 1

 * File:         ou1.c
 * Description:  A simple implementation of a shopping assistant with a
 *               currency converter.
 * Author:       Mikolaj Wagner
 * CS username:  c18mwj
 * Date:         10/10
 * Input:        Price of a unspecific number of items and the choice of a
 *               specific exchange rate.
 * Output:       Prints the menu, prints the sum of the diffrent items bought,
 *               and prints the sum in Swedish currency and the chosen currency.
 * Limitations:  No validation of input. 
 */



#include <stdio.h>

int main()
{
    int choice;
    double exRate = 1, goods = 0, sum = 0;

    /*Titel*/
    printf("Your shopping assistant\n");

    /*Repeating the menubar showing up after every case*/
    do
    {
        /*Menu of the diffrent choices the user can make*/
        printf("\n1. Set exchange rate in SEK (current rate: %.2lf)\n", exRate);
        printf("2. Read prices in the foreign currency\n");
        printf("3. End\n\n");
        printf("Give your choice (1 - 3): ");

        /*Read user choices*/
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:     /*Let user write in a value for the exchange rate*/
                printf("\nGive exchange rate: ");
                scanf("%lf", &exRate);
            break;

            case 2:     /*Letting user add items if no more items end it with a number under 0*/
                sum = 0;           /*Updating sum*/
                printf("\n");
                do
                {
                printf("Give price (finish with < 0): ");
                scanf("%lf", &goods);
                if (goods >= 0)     /*Adding all positive values for sum together*/
                {
                sum = sum + goods;
                }
                }
                while ( goods >= 0);
                printf("\nSum in foreign currency: %.2lf\n", sum);     /*Printing out the sum in foreign currency and Swedish currency*/
                printf("Sum in SEK: %.2lf\n", sum * exRate);
              break;


              case 3:     /*Terminate the program*/
                printf("\nEnd of program!\n\n");
              break;


              default:     /*The user have chosen a wrong number*/
                 printf("\nNot a valid choice!\n");
              break;
          }
     } while(choice != 3);


      return 0;
}
