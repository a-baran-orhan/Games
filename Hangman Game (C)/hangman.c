#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>					
#include <time.h>
#include <string.h>

void title(void);					// Hangman Title
void menus(void);					// Main Menu
void diffChoice(void);					// 1. Play Game
void tutorial(void);					// 2. How to Play
void credits(void);						// 3. Credits
void gameLogic(int diff);			// Hangman game logic
void hangman(int stepCounter);		// Printing hangmans as the wrong letters pressed
void ingameTitle(void);
void bye(void);


int main(void)
{
	system("cls||clear");
    title();
    menus();
    
    int isQuit = 0;
    
    while(isQuit == 0)					// Gets an input until the user quit
    {    	
		char option = getch();			// Main Menu input

    	printf("%c \n", option);
    	
		switch(option)
		{
			case '1':
				diffChoice();
				break;
			case '2':
				tutorial();
				break;
			case '3':
				credits();
				break;
			case 'Q':
			case 'q':
				system("cls||clear");
	    		bye();
				puts("\n\nUser quit!");
				isQuit = 1;
				return 0;
			case 'Z':
			case 'z':
				system("cls||clear");
    			title();
    			menus();
				break;
			default:
				puts("\nWrong input");
				break;
					
		}
	}
}

void title(void)
{
    printf(
    "\n""  ""***""          ""    ***"  
    "\n""  "" ***""         ""   ***"
    "\n""  ""  ***""        ""  ***"
    "\n""  ""   ***""       "" ***""          ""**"    "        ""**""**""      **""      ""****"  "     ""**""*""      *""**""        **""        "    "**""**""      **"
    "\n""  ""  *****""******""*****""        ""**""**"  "       ""**"" **""     **""    ""**""   ***""   ""**"" *""    *"" **""       **""**""       "  "**"" **""     **"
    "\n""  ""  *****""******""*****""       ""**""  ""**""      ""**""  **""    **""   ""**"  "          ""**""  *""  *""  **""      **""  **""      "  "**""  **""    **"
    "\n""  ""   ***""       "" ***""       ""**""**""****""     ""**""   **""   **""  ""**""     ****""  ""**"  "   **""   **""     **""**""****""     ""**""   **""   **"
    "\n""  ""  ***""        ""  ***""     ""**""      ""**""    ""**""    **""  **""   ""**""      ***"" ""**"    "        **""    **""      **""    "  "**""    **""  **"
    "\n""  "" ***""         ""   ***""   ""**""        ""**""   ""**""     **"" **""    ""**""    ***""  ""**"    "        **""   **""        **""   "  "**""     **"" **"
    "\n""  ""***""          ""    ***"" ""**""          ""**""  ""**""      **""**""      ""****"  "     ""**"    "        **""  **""          **""  "  "**""      **""**");
    puts("\n\n");
}

void menus(void)
{
    printf("\t\t\t\t\t\t"     "1. Play Game!"
    "\n\n\n\n" "\t\t\t\t\t\t" "2. How To Play"
    "\n\n\n\n" "\t\t\t\t\t\t" "3. Credits"
    "\n\n\n\n" "\t\t\t\t\t\t" "PRESS 'Q' TO QUIT!"
    "\n\n");
}

void diffChoice(void)
{
	system("cls||clear");
    title();
    
    puts("Difficulty\n");
    
    puts("1. Easy" "\n2. Medium" "\n3. Hard"
		 "\n\n\n\n" "|| Press z to go back ||");
    
    int isBack = 0;
    
	while(isBack == 0)
	{	
		char choice = getch();			// Difficulty choice input

		switch(choice)
	    {
			case '1':
				system("cls||clear");
				puts("Easy");
				ingameTitle();
				gameLogic(1);
				isBack = 1;
				break;
	      	case '2':
	      		system("cls||clear");
	      		puts("Medium");
	      		ingameTitle();
	      		gameLogic(2);
				isBack = 1;
				break;
	      	case '3':
	      		system("cls||clear");
	      		puts("Hard");
	      		ingameTitle();
	      		gameLogic(3);
	      		isBack = 1;
	        	break;
	        case 'z':
	        case 'Z':
				system("cls||clear");
	    		title();
	    		menus();
	    		isBack = 1;
				break;
	        default:
	        	puts("\nWrong input_diff");
				break;
	    }
	}
}


void tutorial(void)
{
    system("cls||clear");
    title();
	puts("How to Play\n\n");
	printf("** In Hangman, you have to guess the correct word!"
	"\n\n"   "** Press a letter on your keyboard to reveal the letters in the given word."
	"\n\n"   "** You have as many lives as the word has letters."
	"\n\n"   "** DO NOT press the correct letter twice or more, otherwise you will lose lives!"
	"\n\n"   "** For the maximum score you have to guess maximum words."
	"\n\n"   "** Have fun!"
	"\n\n\n"   "|| Press z to go back ||");
}

void credits(void)
{
	system("cls||clear");
    title();
    puts("Credits\n\n");
    printf("ELE122 Computers and Programming II - 2019/20 Spring Term Project"
	"\n\n" "** Adem Baran Orhan 21947531 **"
	"\n\n" "** Eren Karadag 21947311 **"
	"\n\n\n"   "|| Press z to go back ||");
}

void bye(void)
{
	printf(
	"\n"	"  **""******"
	"\n"	"  **""     ***"
	"\n"	"  **""       ***"
	"\n"	"  **""      ***""   **""      **""    **""****""    **""*""      *""**""        **"  "        **""**""      **"
	"\n"	"  **""    ***""      **""    **""    **"  "         **"" *""    *"" **""       **""**""       **"" **""     **"
	"\n"	"  **""*****""         **""  **""    **"  "          **""  *""  *""  **""      **""  **""      **""  **""    **"
	"\n"	"  **""     ***""       **""**""     **""***""       **""   **"  "   **""     **""******""     **""   **""   **"
	"\n"	"  **""       ***""      **"  "      **"  "          **"    "        **""    **""      **""    **""    **""  **"
	"\n"	"  **""     ***""        **"  "       **"  "         **"    "        **""   **""        **""   **""     **"" **"
	"\n"	"  **""******""          **"  "        **""****""    **"    "        **""  **""          **""  **""      **""**");
}

void hangman(int stepCounter)
{	
	switch(stepCounter)
	{
		case 1:
			printf(" ______      \n");
			printf(" |/      \n");
			printf(" |      \n");
			printf(" |     \n");
			printf(" |     \n");
			printf(" |      \n");
			printf("_|_____      \n");
			break;
			
		case 2:		
			printf(" ______      \n");
			printf(" |/   |  \n");
			printf(" |   ( ) \n");
			printf(" |     \n");
			printf(" |     \n");
			printf(" |      \n");
			printf("_|_____      \n");
			break;

		case 3:	
		    printf(" ______      \n");
			printf(" |/   |  \n");
			printf(" |   ( ) \n");
			printf(" |    |  \n");
			printf(" |    | \n");
			printf(" |      \n");
			printf("_|_____      \n");		
			break;
			
		case 4:
			printf(" ______      \n");
			printf(" |/   |  \n");
			printf(" |   ( ) \n");
			printf(" |   /|  \n");
			printf(" |    |  \n");
			printf(" |      \n");
			printf("_|_____      \n");
			break;		
		
		case 5:	
			printf(" ______      \n");
			printf(" |/   |  \n");
			printf(" |   ( ) \n");
			printf(" |   /|\\ \n");
			printf(" |    |  \n");
			printf(" |      \n");
			printf("_|_____      \n");
			break;
		
		case 6:
			printf(" ______      \n");
			printf(" |/   |  \n");
			printf(" |   ( ) \n");
			printf(" |   /|\\ \n");
			printf(" |    |  \n");
			printf(" |   /  \n");
			printf("_|_____      \n");
			break;
			
		case 7:
			printf(" ______      \n");
			printf(" |/   |  \n");
			printf(" |  (X_X) \n");
			printf(" |   /|\\ \n");
			printf(" |    |  \n");
			printf(" |   / \\ \n");
			printf("_|_____      \n");	
			printf("GAME OVER\n\a");
			break;
	}
}

void ingameTitle(void)
{
	printf("----------------------------------------------------------\n");
	printf("|   *   *   ( )   *   *  ****   *     *   (X)    *   *   |\n");
	printf("|   *****  / | \\  **  *  *      **   **  / | \\   **  *   |\n");
	printf("|   *   *    |    * * *  *  **  * * * *    |     * * *   |\n");
	printf("|   *   *  /   \\  *  **  *****  *  *  *  /   \\   *  **   |\n");
	printf("----------------------------------------------------------\n");	
	puts("\n\n");
}

void gameLogic(int diff)
{
	srand((unsigned int) time(NULL));
	
	char words[100][10];
	int line = 0;
	
	char input[128];
	
	FILE *filePtr = fopen("word_list.txt","r");
	
	while (fgets(input, 127, filePtr))
	{
	    sscanf(input, "%s", words[line]);
//		printf("%s", input);
	    line++;
	}
	
	fclose(filePtr);
	
	int randIndex = 0;
	
	int is = 0;
	int random = 0;
	
	while (is == 0)
	{
	    int a = rand() % line;
	    
    	switch (diff)
    	{
    		case 1:
    			if (strlen(words[a]) == 3)
    			{
    				randIndex = a;
    				is = 1;
    			}
    			break;
    		case 2:
    			if (strlen(words[a]) == 5)
    			{
    				randIndex = a;
    				is = 1;
    			}
    			break;
    		case 3:
    			if (strlen(words[a]) == 7)
    			{
    				randIndex = a;
    				is = 1;
    			}
    			break;
    	}
    	random++;
	}
	printf("Randomised %d times\n", random);
	/*printf("The word is: %s\n", words[randIndex]); */
	
	unsigned long wordLength = strlen(words[randIndex]);

	printf("Length: %lu\n", wordLength);
	
	int correct = 0;
	int falseLetter = 0;
	int oldCorrect = 0;
	
	printf("Guess a letter: \n"
		   " ");
	
	while (correct < wordLength && falseLetter < wordLength)
	{
	    char guess[8];
	    char temp[8];
	    
        for (int i = 0; i < wordLength; i++)
	    {
	    	if(temp[i] == words[randIndex][i])
			{
	    		printf("%c ", words[randIndex][i]);
			}
	    	else
	    	{
	    		printf("_ ");
			}
	    }
	    
	    puts("");
	    fgets(guess, 8, stdin);
	    
	//  printf("%c \n", guess[0]);
	    oldCorrect = correct;
	    
	    for (int i = 0; i < wordLength; i++)
	    {
	        if (guess[0] == words[randIndex][i] && temp[i] != guess[0])
	        {
	            temp[i] = guess[0];				// checking a letter whether it's reguessed
	            correct++;
	        }
	    }
	    
	    printf("Your score:%d\n\n", correct);
	    
		for (int i = 0; i < wordLength; i++)
		{
			if (oldCorrect == correct)
			{
				falseLetter++;
				if (diff == 1)
				{										// Hangman printing sequences
					hangman((3*falseLetter) - 2);		// 1, 4, 7					// Easy
				}
				else if (diff == 2)
				{
					hangman(falseLetter+2);				// 3, 4, 5, 6, 7			// Medium
				}
				else if (diff == 3)
				{
					hangman(falseLetter);				// 1, 2, 3, 4, 5, 6, 7		// Hard
				}
				break;
			}
		}
	}
	
//	printf("falseletter is: %d", falseLetter);
	
	if (wordLength == falseLetter)
	{
		puts("LOL, you can't even beat this simple game!\n");
	}
	else
	{
		puts("Congrats, You won!\n");
	}
	
	printf("The word was: %s\n", words[randIndex]);

	puts("Do you want to play again? Y / N\n");
	
	int k = 0;
	
	while (k == 0)				// Gets an input until Y or N case is satisfied
	{
		char yn = getch();		// Yes or No input - if the user wants to play again or not
		
		switch(yn)
		{
			case 'y':
			case 'Y':
				k = 1;
				diffChoice();
				break;
			case 'n':
			case 'N':
				k = 1;
				system("cls||clear");
				title();
				menus();
				break;
			default:
				puts("Wrong input_yn");
				break;
		}
	}
}
