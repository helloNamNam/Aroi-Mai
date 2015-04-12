#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void call(int, int, int); /*Function print player's position and events in board*/
int board(int, int); /* Function print board to play game */
int game(char[*], int); /* Function change turn and rolls die to send to function board */
int event(int *, int *, int *, int *, int, int); /* Function random event when player move on event square grid */
int main() /* Get mode to play or read the rules */
{
	char mode[1], confirm[1];
	int fp /* First player */, len;
	srand(time(0));
	printf("\n********************************************\n");
	printf("*    Welocome to Snake and Ladders game    *\n");
	printf("********************************************\n");
	printf("|                                          |\n");
	printf("|                === Mode ===              |\n");
	printf("|                                          |\n");
	printf("|             1. Single player             |\n");
	printf("|             2. Two players               |\n");
	printf("|             3. Read the rules            |\n");
	printf("|__________________________________________|\n\n");
	printf("please select mode to play or 'q' to exit : ");
	scanf("%s", mode); /* input mode to play game or exit */
	len = strlen(mode);
	while ((mode[0] != '1' && mode[0] != '2') || len > 1)
	{
		if (mode[0] == '3') /* Read the rules */
		{
			printf("\n=== Rules ===\n");
			printf("1) All players start on square grid 1 and have\n   four hearts if the player's hurt all\n   the player will lose.\n");
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
			scanf("%s", mode);
		}
		else if (mode[0] == 'q') /* Exit */
		{
			printf("Thank you for playing.\n");
			return 0;
		}
		else
		{
			printf("You don't understand english? please select mode '1', '2', '3' or 'q' : ");
			scanf("%s", mode);
			len = strlen(mode);
		}
	}
	printf("\nYou select mode %c\n", mode[0]);
	printf("please enter 'y' to start or 'n' to back to mainmenu : ");
	scanf(" %c", confirm); /* input confirm word to continue or back to main menu */
	while (confirm[0] != 'y' && confirm[0] != 'n')
	{
		printf("Can you understand human language? please enter 'y' to start or 'n' to back to mainmenu : ");
		scanf(" %c", confirm);
	}
	if (confirm[0] == 'n') /* Call function main again because player want to go to mainmenu */
	{
		main();
	}
	else
	{
	    processing_image(1);
		if (mode[0] == '1')
		{
			fp = rand() % 2;
			if (fp)
				printf("You are first player.");
			else
				printf("Bot is first player.");
		}
		else
		{
			fp = rand() % 2;
			if (fp)
				printf("Player A is first player.");
			else
				printf("Player B is first player.");
		}
		processing_image(2);
		game(mode, fp);
	}
}
int game(char mode[1], int fp)
{
	char dice[4], ch_char[1];
	int table[90] = {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 2, 0, 0, 2, 1, 0, 0, 2, 0, 0, 2, 0, 0, 1, 0, 0, 1, 2, 0, 0, 2, 0, 0, 1, 0, 0, 0, 2, 0, 2, 0, 0, 0, 1, 1, 2, 0, 2, 0, 1, 0, 0, 0, 2, 1, 0, 1, 1, 0, 2, 2, 2, 2, 2, 0};
	int tp = 0, tb = 1, point[2] = {0}, lp[2] = {4, 4}, walk, ch_a, ch_b, ch_c, i, len, evenbreak;
	srand(time(0));
	if (mode[0] == '1') /* Single player */
	{
		if (fp) /* player is first */
		{
			tp = 1;
			tb = 0;
		}
		board(point[0], point[1]);
		while (1)
		{
			evenbreak = 0;
			if (tp) /* Player's turn */
			{
				printf("\n\nIt's your turn please type 'Dice' to roll the dice\nlife point (");
				for (i = 1; i <= 4; ++i) /* Print life point */
				{
					if (lp[0] >= i)
						printf("*");
					else
						printf("-");
				}
				printf(") : ");
				scanf("%s", dice);
				while (strcmp(dice, "Dice") != 0) /* Loop for input 'Dice' */
				{
					printf("Incorrect! Please type 'Dice' to roll the dice : ");
					scanf("%s", dice);
				}
				processing_image(3);
				walk = rand() % 6 + 1;
				printf("Result : %d\n", walk);
				processing_image(4);
				point[0] += walk;
				board(point[0], point[1]);
				while (table[point[0]] != 0 && evenbreak == 0) /* Have an event */
				{
					if (table[point[0]] == 1) /* Good events */
					{
						ch_a = rand() % 20;
						ch_b = rand() % 20;
						ch_c = rand() % 20;
						printf("You have an events please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char); /* input char to select event */
						len = strlen(ch_char);
						while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
						{
							printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
							scanf("%s", ch_char);
							len = strlen(ch_char);
						}
						if (ch_char[0] == 'a') /* Select choice A */
						{
							printf("You select choice A.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_a, 0);
							if ((ch_a >= 15 && ch_a <= 19) || (ch_a >= 35 && ch_a <= 39))
							{
								evenbreak = 1;
							}
						}
						else if (ch_char[0] == 'b') /* Select choice B */
						{
							printf("You select choice B.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_b, 0);
							if ((ch_b >= 15 && ch_b <= 19) || (ch_b >= 35 && ch_b <= 39))
							{
								evenbreak = 1;
							}
						}
						else if (ch_char[0] == 'c') /* Select choice B */
						{
							printf("You select choice C.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_c, 0);
							if ((ch_c >= 15 && ch_c <= 19) || (ch_c >= 35 && ch_c <= 39))
							{
								evenbreak = 1;
							}
						}
					}
					else if (table[point[0]] == 2 && evenbreak == 0) /* Good and bad events */
					{
						ch_a = rand() % 40;
						ch_b = rand() % 40;
						ch_c = rand() % 40;
						printf("You have an events please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char); /* input char to select event */
						len = strlen(ch_char);
						while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
						{
							printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
							scanf("%s", ch_char);
							len = strlen(ch_char);
						}
						if (ch_char[0] == 'a') /* Select choice A */
						{
							printf("You select choice A.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_a, 0);
							if ((ch_a >= 15 && ch_a <= 19) || (ch_a >= 35 && ch_a <= 39))
							{
								evenbreak = 1;
							}
						}
						else if (ch_char[0] == 'b') /* Select choice B */
						{
							printf("You select choice B.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_b, 0);
							if ((ch_b >= 15 && ch_b <= 19) || (ch_b >= 35 && ch_b <= 39))
							{
								evenbreak = 1;
							}
						}
						else if (ch_char[0] == 'c') /* Select choice C */
						{
							printf("You select choice C.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_c, 0);
							if ((ch_c >= 15 && ch_c <= 19) || (ch_c >= 35 && ch_c <= 39))
							{
								evenbreak = 1;
							}
						}
					}
					else
					{
						point[0] = 0;
						board(point[0], point[1]);
					}
					if (point[0] >= 89 || lp[0] <= 0) /* If have win or lose player after event */
						break;
				}
				if (walk != 6) /* Change turn */
				{
					tp = 0;
					tb = 1;
				}
				if (point[0] >= 89 || lp[0] <= 0)
					break;
			}
			else /* Bot's turn */
			{
				printf("\n\nIt's Bot turn to roll the dice\nlife point (");
				for (i = 1; i <= 4; ++i)
				{
					if (lp[1] >= i)
						printf("*");
					else
						printf("-");
				}
				printf(")\n");
				processing_image(3);
				walk = rand() % 6 + 1;
				printf("\nResult : %d\n", walk);
				processing_image(4);
				point[1] += walk;
				board(point[0], point[1]);
				while (table[point[1]] != 0 && evenbreak == 0) /* Have an event */
				{
					if (table[point[1]] == 1)
					{
						ch_a = rand() % 20;
						printf("Bot have an events.\n");
						event(&point[0], &lp[0], &point[1], &lp[1], ch_a, 1);
						if ((ch_a >= 15 && ch_a <= 19) || (ch_a >= 35 && ch_a <= 39))
						{
							evenbreak = 1;
						}
					}
					else if (table[point[1]] == 2)
					{
						ch_a = rand() % 40;
						printf("Bot have an events.\n");
						event(&point[0], &lp[0], &point[1], &lp[1], ch_a, 1);
						if ((ch_a >= 15 && ch_a <= 19) || (ch_a >= 35 && ch_a <= 39))
						{
							evenbreak = 1;
						}
					}
					else
					{
						point[1] = 0;
						board(point[0], point[1]);
					}
					if (point[1] >= 89 || lp[1] <= 0) /* If have win or lose player after event */
						break;
				}
				if (walk != 6) /* Change turn */
				{
					tp = 1;
					tb = 0;
				}
				if (point[1] >= 89 || lp[1] <= 0) /* If have win or lose player after event */
					break;
			}
		}
		if (point[0] >= 89)
		{
			printf("The winner is Player!\nThank you for played.\n");
			return 0;
		}
		if (point[1] >= 89)
		{
			printf("The winner is Bot!\nThank you for played.\n");
			return 0;
		}
		if (lp[0] <= 0)
		{
			printf("The winner is Bot!\nThank you for played.\n");
			return 0;
		}
		if (lp[1] <= 0)
		{
			printf("The winner is Player!\nThank you for played.\n");
			return 0;
		}
	}
	else /* Two players */
	{
		if (fp) /* player is first */
		{
			tp = 1;
			tb = 0;
		}
		board(point[0], point[1]);
		while (1)
		{
			evenbreak = 0;
			if (tp) /* Player one's turn */
			{
				printf("Player one's turn please type 'Dice' to roll the dice\nlife point (");
				for (i = 1; i <= 4; ++i)
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
					scanf("%s", dice);
				}
				walk = rand() % 6 + 1;
				processing_image(3);
				printf("Result : %d\n", walk);
				processing_image(4);
				point[0] += walk;
				board(point[0], point[1]);
				while (table[point[0]] != 0 && evenbreak == 0) /* Have an event */
				{
					if (table[point[0]] == 1)
					{
						ch_a = rand() % 20;
						ch_b = rand() % 20;
						ch_c = rand() % 20;
						printf("You have an events please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char); /* input char to select event */
						len = strlen(ch_char);
						while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
						{
							printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
							scanf("%s", ch_char);
							len = strlen(ch_char);
						}
						if (ch_char[0] == 'a') /* Select choice A */
						{
							printf("You select choice A.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_a, 0);
							if ((ch_a >= 15 && ch_a <= 19) || (ch_a >= 35 && ch_a <= 39))
							{
								evenbreak = 1;
							}
						}
						else if (ch_char[0] == 'b') /* Select choice B */
						{
							printf("You select choice B.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_b, 0);
							if ((ch_b >= 15 && ch_b <= 19) || (ch_b >= 35 && ch_b <= 39))
							{
								evenbreak = 1;
							}
						}
						else if (ch_char[0] == 'c') /* Select choice B */
						{
							printf("You select choice C.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_c, 0);
							if ((ch_c >= 15 && ch_c <= 19) || (ch_c >= 35 && ch_c <= 39))
							{
								evenbreak = 1;
							}
						}
					}
					else if (table[point[0]] == 2)
					{
						ch_a = rand() % 40;
						ch_b = rand() % 40;
						ch_c = rand() % 40;
						printf("You have an events please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char); /* input char to select event */
						len = strlen(ch_char);
						while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
						{
							printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
							scanf("%s", ch_char);
							len = strlen(ch_char);
						}
						if (ch_char[0] == 'a') /* Select choice A */
						{
							printf("You select choice A.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_a, 0);
						}
						else if (ch_char[0] == 'b') /* Select choice B */
						{
							printf("You select choice B.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_b, 0);
						}
						else if (ch_char[0] == 'c') /* Select choice B */
						{
							printf("You select choice C.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_c, 0);
						}
					}
					else
					{
						point[0] = 0;
						board(point[0], point[1]);
					}
					if (point[0] >= 89 || lp[0] <= 0) /* If have win or lose player after event */
						break;
				}
				if (walk != 6) /* Change turn */
				{
					tp = 0;
					tb = 1;
				}
				if (point[0] >= 89 || lp[0] <= 0) /* If have win or lose player after event */
					break;
			}
			else /* Player two's turn */
			{
				printf("Player two's turn please type 'Dice' to roll the dice\nlife point (");
				for (i = 1; i <= 4; ++i)
				{
					if (lp[1] >= i)
						printf("*");
					else
						printf("-");
				}
				printf(") : ");
				scanf("%s", dice);
				while (strcmp(dice, "Dice") != 0)
				{
					printf("Incorrect! Please type 'Dice' to roll the dice : ");
					scanf("%s", dice);
				}
				walk = rand() % 6 + 1;
				processing_image(3);
				printf("Result : %d\n", walk);
				processing_image(4);
				point[1] += walk;
				board(point[0], point[1]);
				while (table[point[1]] != 0 && evenbreak == 0) /* Have an event */
				{
					if (table[point[0]] == 1)
					{
						ch_a = rand() % 20;
						ch_b = rand() % 20;
						ch_c = rand() % 20;
						printf("You have an events please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char); /* input char to select event */
						len = strlen(ch_char);
						while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
						{
							printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
							scanf("%s", ch_char);
							len = strlen(ch_char);
						}
						if (ch_char[0] == 'a') /* Select choice A */
						{
							printf("You select choice A.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_a, 1);
							if ((ch_a >= 15 && ch_a <= 19) || (ch_a >= 35 && ch_a <= 39))
							{
								evenbreak = 1;
							}
						}
						else if (ch_char[0] == 'b') /* Select choice B */
						{
							printf("You select choice B.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_b, 1);
							if ((ch_b >= 15 && ch_b <= 19) || (ch_b >= 35 && ch_b <= 39))
							{
								evenbreak = 1;
							}
						}
						else if (ch_char[0] == 'c') /* Select choice B */
						{
							printf("You select choice C.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_c, 1);
							if ((ch_c >= 15 && ch_c <= 19) || (ch_c >= 35 && ch_c <= 39))
							{
								evenbreak = 1;
							}
						}
					}
					else if (table[point[0]] == 2)
					{
						ch_a = rand() % 40;
						ch_b = rand() % 40;
						ch_c = rand() % 40;
						printf("You have an events please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char); /* input char to select event */
						len = strlen(ch_char);
						while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
						{
							printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
							scanf("%s", ch_char);
							len = strlen(ch_char);
						}
						if (ch_char[0] == 'a') /* Select choice A */
						{
							printf("You select choice A.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_a, 1);
						}
						else if (ch_char[0] == 'b') /* Select choice B */
						{
							printf("You select choice B.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_b, 1);
						}
						else if (ch_char[0] == 'c') /* Select choice B */
						{
							printf("You select choice C.\n");
							event(&point[0], &lp[0], &point[1], &lp[1], ch_c, 1);
						}
					}
					else
					{
						point[1] = 0;
						board(point[0], point[1]);
					}
					if (point[1] >= 89 || lp[1] <= 0) /* If have win or lose player after event */
						break;
				}
				if (walk != 6) /* Change turn */
				{
					tp = 1;
					tb = 0;
				}
				if (point[1] >= 89 || lp[1] <= 0) /* If have win or lose player after event */
					break;
			}
		}
		if (point[0] >= 89)
		{
			printf("The winner is Player one!\nThank you for played.\n");
			return 0;
		}
		if (point[1] >= 89)
		{
			printf("The winner is Player two!\nThank you for played.\n");
			return 0;
		}
		if (lp[0] <= 0)
		{
			printf("The winner is Player two!\nThank you for played.\n");
			return 0;
		}
		if (lp[1] <= 0)
		{
			printf("The winner is Player one!\nThank you for played.\n");
			return 0;
		}
	}
}
int board(int a, int b) /* Print board to play */
{
	int i;
	processing_image(1);
	printf("     ___ ___ ___ ___ ___ ___ ___ ___ ___ ___\n..> |");
	for(i = 80; i<=89; i++)
	{
		call(a, b, i);
	}
    processing_image(5);
	printf("\n.    ___ ___ ___ ___ ___ ___ ___ ___ ___ ___\n... |");
	for(i = 79; i>=70; i--)
	{
		call(a, b, i);
	}
	processing_image(5);
	printf(" <..\n     ___ ___ ___ ___ ___ ___ ___ ___ ___ ___    .\n..> |");
	for(i = 60; i<=69; i++)
	{
		call(a, b, i);
	}
	processing_image(5);
	printf(" ...\n.    ___ ___ ___ ___ ___ ___ ___ ___ ___ ___\n... |");
	for(i = 59; i>=50; i--)
	{
		call(a, b, i);
	}
	processing_image(5);
	printf(" <..\n     ___ ___ ___ ___ ___ ___ ___ ___ ___ ___    .\n..> |");
	for(i = 40; i<=49; i++)
	{
		call(a, b, i);
	}
	processing_image(5);
	printf(" ...\n.    ___ ___ ___ ___ ___ ___ ___ ___ ___ ___\n... |");
	for(i = 39; i>=30; i--)
	{
		call(a, b, i);
	}
	processing_image(5);
	printf(" <..\n     ___ ___ ___ ___ ___ ___ ___ ___ ___ ___    .\n..> |");
	for(i = 20; i<=29; i++)
	{
		call(a, b, i);
	}
	processing_image(5);
	printf(" ...\n.    ___ ___ ___ ___ ___ ___ ___ ___ ___ ___\n... |");
	for(i = 19; i>=10; i--)
	{
		call(a, b, i);
	}
	processing_image(5);
	printf(" <..\n     ___ ___ ___ ___ ___ ___ ___ ___ ___ ___    .\n    |");
	for(i = 0; i<=9; i++)
	{
		call(a, b, i);
	}
	printf(" ...\n");
	processing_image(5);
	return 0;
}
void call(int a, int b, int i) /* Print player's position and events in board */
{
	int table[90] = {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 2, 0, 0, 2, 1, 0, 0, 2, 0, 0, 2, 0, 0, 1, 0, 0, 1, 2, 0, 0, 2, 0, 0, 1, 0, 0, 0, 2, 0, 2, 0, 0, 0, 1, 1, 2, 0, 2, 0, 1, 0, 0, 0, 2, 1, 0, 1, 1, 0, 2, 2, 2, 2, 2, 0};
	if (i == a && i == b)
	{
		printf("A=B|");
	}
	else if(i == a)
	{
		printf("_A_|");
	}
	else if(i == b)
	{
		printf("_B_|");
	}
	else if (i == 89)
	{

		printf("fin|");
	}
	else if(table[i] == 1)
	{
		printf("^_^|");
	}
	else if(table[i] == 2)
	{
		printf("T^T|");
	}
	else if(table[i] == 3)
	{
		printf("OTZ|");
	}
	else if(table[i] == 0)
	{
		printf("___|");
	}
}
int event(int * pnt, int * life, int * pnt_b, int * life_b, int num, int player)
{
	int table[90] = {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 2, 0, 0, 2, 1, 0, 0, 2, 0, 0, 2, 0, 0, 1, 0, 0, 1, 2, 0, 0, 2, 0, 0, 1, 0, 0, 0, 2, 0, 2, 0, 0, 0, 1, 1, 2, 0, 2, 0, 1, 0, 0, 0, 2, 1, 0, 1, 1, 0, 2, 2, 2, 2, 2, 0};
	char ch_char[1];
	char event_ary[40][1000] = {"Liver pool is the winner, move up 5", "Crashed by taxi, move up 2", "Find warp potal, move up 3", "Get on Airport Rail Link, move up 1", "Ran away the dog, move up 3", "Meet bubble bee, move up 3", "Meet Pidove pokemon, Pidove use 'fly' skill!!!, move up 4", "Diarrhea, run to toilet, move up 5", "Fly with Iron man, move up 6", "Launch with armchair wheel, move up 3", "Barefoot on Ladkrabang country, move up 4", "Get free plane ticket, move up 5", "Ride little pony, move up 2", "Get on no.8 Happyland bus, move up 6", "Get A in Computer Programming(Really?, teacher said that), move up 1", "Meet kawaii loli, life become full", "Sleep in auditorium room, life inceased 1", "Eat yaaaaaaaaa!!!, life inceased 2", "Liver pool get chaimpion, life inceased 3", "Meet aunt and nothing happened.", "Steam on sale, be hurry to go home, move down 6", "Travel by high speed Ladkrabang train, move down 2", "\"You shall not passed!!!\", Gandalf said, move down 3", "Run away cockroach, move down 5", "Go on with Thai Postal, move down 4", "Digital gateway on sale, let buy, move down 3", "Stumble over top grass's leaf, move down 3", "Use IE in Compro test, It's very fast, move down 6", "Use time machine to buy kite cracker in past, move down 2", "Open wardrobe and go to Nania, move down 5", "Play internet with 3G Thai, It's very fast, move down 3", "Run back to see Com-pro score, move down 6", "Sampling error, move down 2", "Fall in rabbit hole and go to wonderland, move down 3", "Go to see Mario enlist in army, move down 4", "Crash by Nokia3310 falt form the sky, died _(:3 JL)_", "Snatched by snake, life decrease 1", "Sleep late because play game, life decrease 2", "Get warp 5 grid...but is Y-axis 555, life decrease 2", "Meet gay in Song-Kran festival, life decrease 1"};
	int ch_a, ch_b, ch_c, i, len;
	int upward[15] = {5, 2, 3, 1, 3, 3, 4, 5, 6, 3, 4, 5, 2, 6, 1};
	int addlp[5] = {4, 1, 2, 3, 0};
	int backward[15] = {-6, -2, -3, -5, -4, -3, -3, -6, -2, -5, -3, -6, -2, -3, -4};
	int reducelp[5] = {-4, -1, -2, -2, -1};
	srand(time(0));
	if (num < 15)
	{
		if (player == 0)
		{
			*pnt += upward[num];
			printf("%s\n", event_ary[num]);
			processing_image(4);
			board(*pnt, *pnt_b);
			while (table[*pnt] != 0) /* Have an event */
			{
				if (table[*pnt] == 1) /* Good events */
				{
					ch_a = rand() % 20;
					ch_b = rand() % 20;
					ch_c = rand() % 20;
					printf("You have an events please select choice 'a', 'b' or 'c' : ");
					scanf("%s", ch_char); /* input char to select event */
					len = strlen(ch_char);
					while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
					{
						printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char);
						len = strlen(ch_char);
					}
					if (ch_char[0] == 'a') /* Select choice A */
					{
						printf("You select choice A.\n");
						event(pnt, life, pnt_b, life_b, ch_a, 0);
					}
					else if (ch_char[0] == 'b') /* Select choice B */
					{
						printf("You select choice B.\n");
						event(pnt, life, pnt_b, life_b, ch_b, 0);
					}
					else if (ch_char[0] == 'c') /* Select choice B */
					{
						printf("You select choice C.\n");
						event(pnt, life, pnt_b, life_b, ch_c, 0);
					}
				}
				else if (table[*pnt] == 2) /* Good and bad events */
				{
					ch_a = rand() % 40;
					ch_b = rand() % 40;
					ch_c = rand() % 40;
					printf("You have an events please select choice 'a', 'b' or 'c' : ");
					scanf("%s", ch_char); /* input char to select event */
					len = strlen(ch_char);
					while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
					{
						printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char);
						len = strlen(ch_char);
					}
					if (ch_char[0] == 'a') /* Select choice A */
					{
						printf("You select choice A.\n");
						event(pnt, life, pnt_b, life_b, ch_a, 0);
					}
					else if (ch_char[0] == 'b') /* Select choice B */
					{
						printf("You select choice B.\n");
						event(pnt, life, pnt_b, life_b, ch_b, 0);
					}
					else if (ch_char[0] == 'c') /* Select choice B */
					{
						printf("You select choice C.\n");
						event(pnt, life, pnt_b, life_b, ch_c, 0);
					}
				}
				if (*pnt >= 89 || *life <= 0) /* If have win or lose player after event */
					return 0;
			}
			return 0;
		}
		else
		{
			*pnt_b += upward[num];
			printf("%s\n", event_ary[num]);
			processing_image(4);
			board(*pnt, *pnt_b);
			while (table[*pnt_b] != 0) /* Have an event */
			{
				if (table[*pnt_b] == 1) /* Good events */
				{
					ch_a = rand() % 20;
					ch_b = rand() % 20;
					ch_c = rand() % 20;
					printf("You have an events please select choice 'a', 'b' or 'c' : ");
					scanf("%s", ch_char); /* input char to select event */
					len = strlen(ch_char);
					while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
					{
						printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char);
						len = strlen(ch_char);
					}
					if (ch_char[0] == 'a') /* Select choice A */
					{
						printf("You select choice A.\n");
						event(pnt, life, pnt_b, life_b, ch_a, 1);
					}
					else if (ch_char[0] == 'b') /* Select choice B */
					{
						printf("You select choice B.\n");
						event(pnt, life, pnt_b, life_b, ch_b, 1);
					}
					else if (ch_char[0] == 'c') /* Select choice B */
					{
						printf("You select choice C.\n");
						event(pnt, life, pnt_b, life_b, ch_c, 1);
					}
				}
				else if (table[*pnt] == 2) /* Good and bad events */
				{
					ch_a = rand() % 40;
					ch_b = rand() % 40;
					ch_c = rand() % 40;
					printf("You have an events please select choice 'a', 'b' or 'c' : ");
					scanf("%s", ch_char); /* input char to select event */
					len = strlen(ch_char);
					while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
					{
						printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char);
						len = strlen(ch_char);
					}
					if (ch_char[0] == 'a') /* Select choice A */
					{
						printf("You select choice A.\n");
						event(pnt, life, pnt_b, life_b, ch_a, 1);
					}
					else if (ch_char[0] == 'b') /* Select choice B */
					{
						printf("You select choice B.\n");
						event(pnt, life, pnt_b, life_b, ch_b, 1);
					}
					else if (ch_char[0] == 'c') /* Select choice B */
					{
						printf("You select choice C.\n");
						event(pnt, life, pnt_b, life_b, ch_c, 1);
					}
				}
				if (*pnt_b >= 89 || *life_b <= 0) /* If have win or lose player after event */
					return 0;
			}
			return 0;
		}
	}
	else if (num < 20)
	{
		if (player == 0)
		{
			*life += addlp[num-15];
			printf("%s\n", event_ary[num]);
			processing_image(4);
			if (*life > 4)
				*life = 4;
			printf("\nYours life point (");
			for (i = 1; i <= 4; ++i) /* Print life point */
			{
				if (*life >= i)
					printf("*");
				else
					printf("-");
			}
			printf(")\n");
		}
		else
		{
			*life_b += addlp[num-15];
			printf("%s\n", event_ary[num]);
			processing_image(4);
			if (*life_b > 4)
				*life_b = 4;
			printf("\nYours life point (");
			for (i = 1; i <= 4; ++i) /* Print life point */
			{
				if (*life_b >= i)
					printf("*");
				else
					printf("-");
			}
			printf(")\n");
		}
		return 0;
	}
	else if (num < 35)
	{
		if (player == 0)
		{
			*pnt += backward[num-20];
			printf("%s\n", event_ary[num]);
			processing_image(4);
			board(*pnt, *pnt_b);
			while (table[*pnt] != 0) /* Have an event */
			{
				if (table[*pnt] == 1) /* Good events */
				{
					ch_a = rand() % 20;
					ch_b = rand() % 20;
					ch_c = rand() % 20;
					printf("You have an events please select choice 'a', 'b' or 'c' : ");
					scanf("%s", ch_char); /* input char to select event */
					len = strlen(ch_char);
					while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
					{
						printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char);
						len = strlen(ch_char);
					}
					if (ch_char[0] == 'a') /* Select choice A */
					{
						printf("You select choice A.\n");
						event(pnt, life, pnt_b, life_b, ch_a, 0);
					}
					else if (ch_char[0] == 'b') /* Select choice B */
					{
						printf("You select choice B.\n");
						event(pnt, life, pnt_b, life_b, ch_b, 0);
					}
					else if (ch_char[0] == 'c') /* Select choice B */
					{
						printf("You select choice C.\n");
						event(pnt, life, pnt_b, life_b, ch_c, 0);
					}
				}
				else if (table[*pnt] == 2) /* Good and bad events */
				{
					ch_a = rand() % 40;
					ch_b = rand() % 40;
					ch_c = rand() % 40;
					printf("You have an events please select choice 'a', 'b' or 'c' : ");
					scanf("%s", ch_char); /* input char to select event */
					len = strlen(ch_char);
					while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
					{
						printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char);
						len = strlen(ch_char);
					}
					if (ch_char[0] == 'a') /* Select choice A */
					{
						printf("You select choice A.\n");
						event(pnt, life, pnt_b, life_b, ch_a, 0);
					}
					else if (ch_char[0] == 'b') /* Select choice B */
					{
						printf("You select choice B.\n");
						event(pnt, life, pnt_b, life_b, ch_b, 0);
					}
					else if (ch_char[0] == 'c') /* Select choice B */
					{
						printf("You select choice C.\n");
						event(pnt, life, pnt_b, life_b, ch_c, 0);
					}
				}
				if (*pnt >= 89 || *life <= 0) /* If have win or lose player after event */
					return 0;
			}
			return 0;
		}
		else
		{
			*pnt_b += backward[num];
			printf("%s\n", event_ary[num]);
			processing_image(4);
			board(*pnt, *pnt_b);
			while (table[*pnt_b] != 0) /* Have an event */
			{
				if (table[*pnt_b] == 1) /* Good events */
				{
					ch_a = rand() % 20;
					ch_b = rand() % 20;
					ch_c = rand() % 20;
					printf("You have an events please select choice 'a', 'b' or 'c' : ");
					scanf("%s", ch_char); /* input char to select event */
					len = strlen(ch_char);
					while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
					{
						printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char);
						len = strlen(ch_char);
					}
					if (ch_char[0] == 'a') /* Select choice A */
					{
						printf("You select choice A.\n");
						event(pnt, life, pnt_b, life_b, ch_a, 1);
					}
					else if (ch_char[0] == 'b') /* Select choice B */
					{
						printf("You select choice B.\n");
						event(pnt, life, pnt_b, life_b, ch_b, 1);
					}
					else if (ch_char[0] == 'c') /* Select choice B */
					{
						printf("You select choice C.\n");
						event(pnt, life, pnt_b, life_b, ch_c, 1);
					}
				}
				else if (table[*pnt] == 2) /* Good and bad events */
				{
					ch_a = rand() % 40;
					ch_b = rand() % 40;
					ch_c = rand() % 40;
					printf("You have an events please select choice 'a', 'b' or 'c' : ");
					scanf("%s", ch_char); /* input char to select event */
					len = strlen(ch_char);
					while((ch_char[0] != 'a' && ch_char[0] != 'b' && ch_char[0] != 'c') || len > 1)
					{
						printf("You don't understand english? please select choice 'a', 'b' or 'c' : ");
						scanf("%s", ch_char);
						len = strlen(ch_char);
					}
					if (ch_char[0] == 'a') /* Select choice A */
					{
						printf("You select choice A.\n");
						event(pnt, life, pnt_b, life_b, ch_a, 1);
					}
					else if (ch_char[0] == 'b') /* Select choice B */
					{
						printf("You select choice B.\n");
						event(pnt, life, pnt_b, life_b, ch_b, 1);
					}
					else if (ch_char[0] == 'c') /* Select choice B */
					{
						printf("You select choice C.\n");
						event(pnt, life, pnt_b, life_b, ch_c, 1);
					}
				}
				if (*pnt_b >= 89 || *life_b <= 0) /* If have win or lose player after event */
					return 0;
			}
			return 0;
		}
	}
	else
	{
		if (player == 0)
		{
			*life += reducelp[num-35];
			printf("%s\n", event_ary[num]);
			processing_image(4);
			printf("\nYours life point (");
			for (i = 1; i <= 4; ++i) /* Print life point */
			{
				if (*life >= i)
					printf("*");
				else
					printf("-");
			}
			printf(")\n");
		}
		else
		{
			*life_b += reducelp[num-35];
			printf("%s\n", event_ary[num]);
			processing_image(4);
			printf("\nYours life point (");
			for (i = 1; i <= 4; ++i) /* Print life point */
			{
				if (*life_b >= i)
					printf("*");
				else
					printf("-");
			}
			printf(")\n");
		}
		return 0;
	}

}
int processing_image(int m)
{
    int i, j;
    switch(m){
        case 1:{ //arrow
            printf("\n          ...\n");
            for(i=0;i<30000000;i++);
            printf("          ...\n");
            for(i=0;i<30000000;i++);
            printf("          ...\n");
            for(i=0;i<30000000;i++);
            printf("          ...\n");
            for(i=0;i<30000000;i++);
            printf("        .......\n");
            for(i=0;i<30000000;i++);
            printf("          ...\n");
            for(i=0;i<30000000;i++);
            printf("           .\n\n");
            for(i=0;i<30000000;i++);}
            break;
        case 2:{ //3 dot
            printf(".");
            for(i=0;i<300000000;i++);
            printf(".");
            for(i=0;i<300000000;i++);
            printf(".\n\n");
            for(i=0;i<700000000;i++);
            break;
        }
        case 3:{
            for(i=0;i<300000000;i++);
            printf(".");
            for(i=0;i<300000000;i++);
            printf(".");
            for(i=0;i<300000000;i++);
            printf(".\n");
        }
        case 4:{
            for(i=0;i<1000000000;i++);
        }
        case 5:{
            for(i=0;i<50000000;i++);
        }
    }
    return 0;
}
