#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//WARNING NOTICE! I USED INT FOR 25% CHANCE ACTUALLY EVERYTHING SINCE IT IS AN SCHOOL ACTIVITY!!!!!

//SUCA SUCA SUCA BYYYYLATT!!!!!!!!
//HINDI NA HARDCODED YUNG 25%, MEANING DI PARA DI SUMABOG YUNG 25% CHANCE OF WINNING KAPAG INIBA YUNG SIZE/LIMITATION NG PAGHUHULAAN
//EXAMPLE; THE DEFAULT IS GUESS BETWEEN 1-100 AND WE KNOW THAT 25% OF 100 IS 25.
//NOW, IF THE GUESS NUMBER IS BETWEEN 1-120, THE VALUE 25% WILL BE CHANGE AUTOMATICALLY ACCORDINGLY TO ITS SIZE (120).
//AND YUNG 25% OF 120 AY 30.!!!!!!!!

//REMOVE ALL SINGLE-LINE COMMENTS BELOW FOR DEMO :))

/*int rematt(int x)
DISABLED MUNA!
{
 int remainingAttempts = remainingAttempts - x;

}
*/
int main()
{

int attempt = 0, userguess, secretnum, maxsecretnum, minsecretnum, numsize;
float chance;

srand(time(0));

    printf("Enter your preferred limit size of guessing (e.g 50): ");
    scanf("%i", &numsize);
    secretnum = (rand() % numsize) +1;
    printf("Secret Number : %i\n", secretnum); //REMOVE TO REVEAL THE SECRET NUMBER
    printf("Guess the secret number between 1-%i\n\n", numsize);
    
    while(attempt != numsize){
        printf("Enter your guess : ");
        scanf("%i", &userguess);
        attempt++;
        /*DISABLED, under construction!
        printf("\nAttempt Counter : %i\n", attempt); 
        remainingAttempts = rematt(attempt);
         printf("\t\t\t\tremaining attempts %i", remainingAttempts);
        */
        if(userguess < 1 || userguess > numsize){
            printf("Invalid! Please guess only between 1-%i\n\n", numsize);
        }
        else{
            if(attempt == 1){
                chance = (numsize/4);
                maxsecretnum = (ceil(chance) * 3);
                printf("75%%: %i\n", maxsecretnum); 
                minsecretnum = (floor(chance) * 1);
                printf("25%%: %i\n", minsecretnum); 
                minsecretnum = (numsize - minsecretnum);
                /*printf("25%%: %i\n", minsecretnum); NEW BOUNDARY, DON'T MIND THIS*/ 

                if(secretnum <= maxsecretnum){
                    maxsecretnum = secretnum + (numsize / 4);
                    //printf("max : %i\n", maxsecretnum);
                }
                else if(secretnum >= minsecretnum && secretnum <= numsize){
                    minsecretnum = secretnum - (numsize / 4);
                    //printf("min : %i\n", minsecretnum);
                }
                if(userguess <= maxsecretnum && userguess >= secretnum || userguess >= minsecretnum && userguess <= secretnum){
                    printf("You have won with 25%% chance of winning!");
                    break;
                }
            }
            if(userguess == secretnum){
                printf("You won!\n");
                printf("Total attempts : %i", attempt);
                break;
            }
            else if(userguess < secretnum){
                printf("Try again. Higher!\n\n");
            }
            else if(userguess > secretnum){
                printf("Try again. Lower!\n\n");
            }
        }
    }

return 0;
}
