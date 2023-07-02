#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> // For getch() function

void intro_screen()
{
	 printf("					==============================================\n");
    printf("					         Welcome to the Number Guessing Game!  \n");
    printf("					==============================================\n");
    printf("\n");
 	printf("					  ____        _   _   _                 \n");
    printf("					 |  _ \\      | | | | | |                \n");
    printf("					 | |_) | __ _| |_| |_| | _____      __ \n");
    printf("					 |  _ < / _` | __| __| |/ _ \\ \\ /\\ / / \n");
    printf("					 | |_) | (_| | |_| |_| |  __/\\ V  V /  \n");
    printf("					 |____/ \\__,_|\\__|\\__|_|\\___| \\_/\\_/   \n");
    printf("\n");
    printf("					Press any key to continue...");
    //printf("Welcome to the Number Guessing Game!\n");
    //printf("Press any key to continue...");
    getch();
    system("cls"); 
}

int level_choosing()
{
    int level;
    printf("					Choose the difficulty level:					\n");
    printf("					+------------------------------+\n");
    printf("					        Difficulty Menu        					\n");
    printf("					-------------------------------					\n");
    printf("					  1.        Easy               					\n");
    printf("					  2.        Medium             					\n");
    printf("					  3.        Hard               \n");
    printf("					  4.        Exit               					\n");
    printf("					+------------------------------+					\n");
    printf("					Enter your choice: ");
    scanf("%d", &level);
	system("cls");
    return level;
}


int generate_random_number(int level)
{
    int min, max;

    switch (level)
    {
    case 1:
        min = 1;
        max = 100;
        break;
    case 2:
        min = 100;
        max = 1000;
        break;
    case 3:
        min = 1;
        max = 10000;
        break;
    default:
        break;
    }

    srand(time(NULL));
    int random_number = (rand() % (max - min + 1)) + min;
    return random_number;
}

void game_screen(int level, int number)
{
    
    
    int min ,max;
    switch (level)
    {
        case 1: // Easy
            //max_attempts = 10;
            min=1;
            max=100;
            enterINgame(min,max,level,10,number);
            break;
        case 2: // Medium
        
            
             min=100;
             max=1000;
            enterINgame(min,max,level,7,number);
            break;
        case 3: // Hard
            //max_attempts = 5;
             min=1;
             max=10000;
            enterINgame(min,max,level,5,number);
            break;
        default:
            //max_attempts = 0;
            break;
    }
}
void enterINgame(int,int,int,int,int);
void enterINgame(int min,int max,int level,int max_attempts,int number)
{
	int guess, attempts = 0;

    printf("					==============================================\n");
    printf("					               Guess the Number!              \n");
    printf("					==============================================\n\n");
    printf("					Guess the Number Between %d to %d\n",min,max);
    printf("					Level: %d\n", level);
    printf("					Total Attempts: %d\n\n", max_attempts);
    
    do
    {
        printf("\n					Enter your guess: ");
        scanf("					%d", &guess);
        attempts++;

        if (guess < number)
            printf("					Too low! Try a higher number.\n");
        else if (guess > number)
            printf("					Too high! Try a lower number.\n");
        else
        {
            printf("					==============================================\n");
            printf("					          Congratulations! You won!           \n");
            printf("					==============================================\n\n");
            printf("					You guessed the correct number in %d attempts.\n", attempts);
            break;
        }

        // Check if the maximum attempts have been reached
        if (attempts >= max_attempts)
        {
            printf("					==============================================\n");
            printf("					          Out of attempts! Game over!         \n");
            printf("					==============================================\n\n");
            printf("					The number was %d.\n", number);
            break;
        }

        printf("					Attempts remaining: %d\n", max_attempts - attempts);

    } while (attempts < max_attempts);
    

    printf("\n					Press any key to exit...");
    getch();
    system("cls");
}



int main()
{
    int level, number;

    intro_screen();
    level = level_choosing();

    if (level == 4)
    {
        exit(0);
    }

    number = generate_random_number(level);
    game_screen(level, number);

    return 0;
}
