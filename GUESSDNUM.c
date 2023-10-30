#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



//SUCA SUCA SUCA BYYYYLATT!!!!!!!!
//HINDI NA HARDCODED YUNG 25%, MEANING DI PARA DI SUMABOG YUNG 25% CHANCE OF WINNING KAPAG INIBA YUNG SIZE/LIMITATION NG PAGHUHULAAN
//EXAMPLE; THE DEFAULT IS GUESS BETWEEN 1-100 AND WE KNOW THAT 25% OF 100 IS 25.
//NOW, IF THE GUESS NUMBER IS BETWEEN 1-120 THE VALUE 25% WILL BE CHANGE AUTOMATICALLY ACCORDINGLY TO IT SIZE (120).
//AND YUNG 25% NG 120 AY 30.!!!!!!!!!


//REMOVE THE SINGLE-LINE COMMENT FOR DEMO :))

int main()
{

int attempt = 0, chance, userguess, secretnum, maxsecretnum, minsecretnum, numsize, numsizetransfer;

srand(time(0));

    printf("Enter your preferred limit size of guessing (e.g 50): ");
    scanf("%i", &numsize);
    secretnum = (rand() % numsize)+1;

    printf("Guess the secret number between 1-%i\n\n", numsize);
    //printf("%i\n", secretnum);
    while(attempt != 100){
        printf("Enter your guess : ");
        scanf("%i", &userguess);
        attempt++;
        if(userguess < 1 || userguess > numsize){
            printf("Invalid! Please guess only between 1-%i\n\n", numsize);
        }
        else{
            if(attempt == 1){
                numsizetransfer = numsize;
                maxsecretnum = (numsizetransfer/4) * 3;
                minsecretnum = (numsizetransfer/4) * 1;
                //printf("25%%: %i\n", minsecretnum);
                minsecretnum = (numsize - minsecretnum);
                //printf("75%%: %i\n", maxsecretnum);
                /*printf("25%%: %i\n", minsecretnum);*/

                if(secretnum <= maxsecretnum){
                    maxsecretnum = secretnum + numsize/4;
                    //printf("max : %i\n", maxsecretnum);
                }
                else if(secretnum >= minsecretnum && secretnum <= numsize){
                    minsecretnum = (secretnum - numsize/4);
                    //printf("min : %i\n", minsecretnum);
                }
                if(userguess <= maxsecretnum && userguess >= secretnum || userguess >= minsecretnum && userguess <= secretnum){
                    printf("You have won with the 25% chance of winning!");
                }
            }
            if(userguess == secretnum){
                printf("You won!\n"); break;
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
