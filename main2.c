#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int secretNumber, userGuess, chance;
    int attempts = 0, numSize = 100;
    int minRange_SecretNum, maxRange_SecretNum, boundaryDecision;
    srand(time(0));
    //generate secret number
    secretNumber = (rand() % numSize) + 1;
    printf("Secret Number : %d\n", secretNumber);
    printf("Guess the secret number in between 1 - %d\n",numSize);
    
    do{
        printf("Enter your guess : ");
        scanf("%d", &userGuess);
        attempts++;
        printf("Attempt : %d\n", attempts);
            if(userGuess < 1 || userGuess > numSize){
                printf("Invalid! Please guess between 1 - %d\n", numSize);
            }
            else{
                if(attempts == 1){
                    chance = numSize/4;

                    boundaryDecision = (chance * 3) + 1;// 1--Boundary(76)Decision--100, ito yung decision kung saan patungo yung range ng 25%
                    
                    if(secretNumber <= boundaryDecision){
                        maxRange_SecretNum = (secretNumber + (chance - 1));
                        printf("25%% range of secret num is between %d and %d\n", secretNumber, maxRange_SecretNum); 
                    }
                    else if(secretNumber >= boundaryDecision){
                        minRange_SecretNum = (secretNumber - (chance - 1));
                        printf("25%% range of secret num is between %d and %d\n", minRange_SecretNum, secretNumber); 
                    }
                    if(userGuess >= secretNumber && userGuess <= maxRange_SecretNum || userGuess <= secretNumber && userGuess >= minRange_SecretNum){
                        printf("You won with 25%% chance of probability\n");
                        break;
                    }
                }
            if(userGuess > secretNumber){
                printf("Lower\n\n");
            }
            else if(userGuess < secretNumber){
                printf("Higher\n\n");
            }
            }
        
    }while (userGuess != secretNumber && attempts != numSize);
    if(userGuess == secretNumber){
        printf("\n=========\n");
        printf("You won!"); 
        printf("\n=========\n");
        return 0;
        }
    else if(attempts == numSize) 
    printf("You've ran out of attempts");

return 0;
}