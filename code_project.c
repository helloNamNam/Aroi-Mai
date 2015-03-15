#include <stdio.h>
#include <string.h>
int board(int[*]); /* Function print board to play game */
int game(char, int); /* Function change turn and rolls die to send to function board */
int event(int[*]); /* Function random event when player move on event square grid */
int main() /* Get mode to play or read the rules */
{
	char mode[1], confirm[1];
	int fp /* First player */;
	printf("\n********************************************\n");
	printf("*    Welocome to Snake and Ladders game    *\n");
	printf("********************************************\n\n");
	printf("=== Mode ===\n\n");
	printf("1. Single player\n");
	printf("2. Two players\n");
	printf("3. Read the rules\n\n");
	printf("please select mode to play or 'q' to exit : ");
	scanf(" %c", &mode); /* input mode to play game or exit */
	while (mode[0] != '1' && mode[0] != '2')
	{
		if (mode[0] == '3') /* Read the rules */
		{
			printf("\n=== Rules ===\n");
			printf("1) All players start on square grid 1 and have\n   three hearts if the player's hurt all\n   the player will lose.\n");
			printf("2) Takes turns to roll a single dice to move \n   by the number of squares indicated by \n   the dice roll.\n");
			printf("3) If, on completion of a move, a player is\n   lands on event grid <\?\?\?>, the player\n   must move up or down follow the event.\n");
			printf("4) If a player rolls a 6, the player take\n   another turn; otherwise play passes to the\n   next player in turn.\n");
			printf("5) The player who is first go to the last\n   square is the winner.\n");
			printf("=== End ===\n");
			printf("\n=== Mode ===\n\n");
			printf("1. Single player\n");
			printf("2. Two players\n");
			printf("3. Read the rules\n\n");
			printf("please select mode to play or 'q' to exit : ");
			scanf(" %c", &mode);
		}
		else if (mode[0] == 'q') /* Exit */
		{
			printf("Thank you for playing.\n");
			return 0;
		}
		else
		{
			printf("You don't understand english? please select mode '1', '2', '3' or 'q' : ");
			scanf(" %c", &mode);
		}
	}
	printf("\nYou select mode %c\n", mode[0]);
	printf("please enter 'y' to start or 'n' to back to mainmenu : ");
	scanf(" %c", &confirm); /* input confirm word to continue or back to main menu */
	while (confirm[0] != 'y' && confirm[0] != 'n')
	{
		printf("Can you understand human language? please enter 'y' to start or 'n' to back to mainmenu : ");
		scanf(" %c", &confirm);
	}
	if (confirm[0] == 'n') /* Call function main again because player want to go to mainmenu */
	{
		main();
	}
	else
	{
		if (mode[0] == '1')
		{
			fp = rand() % 2;
			if (fp)
				printf("You are first player.\n");
			else
				printf("Bot is first player.\n");
		}
		else
		{
			fp = rand() % 2;
			if (fp)
				printf("Player A is first player.\n");
			else
				printf("Player B is first player.\n");
		}
		game(mode, fp);
	}
}
int game(char mode[1], int fp)
{
	char dice[4];
	int table[90] = {0};
	int tp = 0, tb = 1, point[2] = {0}, lp[2] = {4}, walk, e_type;
	if (mode[0] == '1') /* Single player */
	{
		if (fp) /* player is first */
		{
			tp = 1;
			tb = 0;
		}
		board(point);
		while (1)
		{
			if (tp) /* Player's turn */
			{
				printf("It's your turn please type 'Dice' to roll the dice\nlife point (");
				for (i = 1; i < 4; ++i)
				{
					if (lp[0] >= i)
						printf("*");
					else
						printf("-");
				}
				printf(") : ");
				scanf("%s", dice);
				while (strcmp(dice, "Dice") != 0)
				{
					printf("Incorrect! Please type 'Dice' to roll the dice : ");
				}
				walk = rand() % 6 + 1;
				printf("Result : %d\n", walk);
				point[0] += walk;
				board(point);
				while (table[point[0]]) /* Have an event */
				{
					e_type = rand() % 10;
					if ()
						point[0] = event(e_type);
					else
						lp[0] = event(e_type);
					if (point[0] >= 89 || lp[0] == 0) /* If have win or lose player after event */
						break;
				}
				if (walk != 6) /* Change turn */
				{
					tp = 0;
					tb = 1;
				}
			}
			else /* Bot's turn */
			{
				printf("It's Bot turn to roll the dice\nlife point (");
				for (i = 1; i < 4; ++i)
				{
					if (lp[1] >= i)
						printf("*");
					else
						printf("-");
				}
				printf(")");
				walk = rand() % 6 + 1;
				printf("Result : %d\n", walk);
				point[1] += walk;
				board(point);
				if (walk != 6) /* Change turn */
				{
					tp = 1;
					tb = 0;
				}
			}
		}
	}
	else /* Two players */
	{
	}
}