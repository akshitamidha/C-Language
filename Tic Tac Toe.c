/*
Preparing for the code

1. 1D Array of character type
2. Functions: (i) creating board  (ii) marking on board  (iii) check winner
*/

#include<stdio.h>
#include<conio.h>

char board[10]={'o','1','2','3','4','5','6','7','8','9'};

void drawboard()													//Function 1: Prepares the board for the Game
{
	
	printf("   |   |   \n");
	printf(" %c | %c | %c \n", board[1], board[2], board[3]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", board[4], board[5], board[6]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", board[7], board[8], board[9]);
	printf("   |   |   \n");	
}

void markonboard(int choice, char mark)								//Function 2: Takes the user input and places its mark on the board
{
	if(choice==1 && board[1]=='1')
		board[1]=mark;
	else if(choice==2 && board[2]=='2')
		board[2]=mark;
	else if(choice==3 && board[3]=='3')
		board[3]=mark;
	else if(choice==4 && board[4]=='4')
		board[4]=mark;
	else if(choice==5 && board[5]=='5')
		board[5]=mark;
	else if(choice==6 && board[6]=='6')
		board[6]=mark;
	else if(choice==7 && board[7]=='7')
		board[7]=mark;
	else if(choice==8 && board[8]=='8')
		board[8]=mark;
	else if(choice==9 && board[9]=='9')
		board[9]=mark;
	else
		printf("Invalid Move\n");
	
}


int checkwinner()												//Function 3: Checks rows, columns and diagonals for similarity and then declares the results for the game
{

	//check rows
	if(board[1]==board[2] && board[2]==board[3])
		return 1;
	
	else if(board[4]==board[5] && board[5]==board[6])
		return 1;
	
	else if(board[7]==board[8] && board[8]==board[9])
		return 1;
	
	//check columns
	else if(board[1]==board[4] && board[4]==board[7])
		return 1;
	
	else if(board[2]==board[5] && board[5]==board[8])
		return 1;
	
	else if(board[3]==board[6] && board[6]==board[9])
		return 1;
		
	//check diagonals
	else if(board[1]==board[5] && board[5]==board[9])
		return 1;
	
	else if(board[3]==board[5] && board[5]==board[7])
		return 1;
	
	else if (board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9')
		return 0;
		
	else
		return -1;
}


/*
1	(Game has been finished with a winner)
0	(Game has been finished with no winner)
-1	(Game is still in progress)
*/

int main()
{
	
	int choice, player=1,i;
	char mark;

	printf("\tTic Tac Toe\n");
	printf("Player-1 (X) -- Player-2 (O)\n");

	do
	{
		drawboard();
		player = (player%2)	?	1	:	2;													//As the game is only for two players so, irrespective of the user's input this allows to have our desired results
		printf("Player %d, enter a number: ", player);
		scanf("%d", &choice);
		
		mark = (player == 1) ?	'X'	: 'O';												//Depending on the chosen option the symbol is given
		markonboard(choice, mark);
		
		i=checkwinner();																//takes value from the return on the checkwinner() function and ends the loop accordingly
		player ++;
		
	}while(i == -1);
	
	drawboard();
	
	if(i == 1)																			//declares results based on the value recieved from the checkwinner() function and gives the output
		printf("Player %d has won the game", --player);
	else
		printf("It's a Tie");
	
	getch();
	return 0;
}
