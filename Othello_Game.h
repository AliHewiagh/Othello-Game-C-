/***************************|**************************|*****************************|
Program: Othello_Game.h
Course: Programming fundamental (TC03)(TT06).
Year:2015/26 Trimester 1
First Student:/
Name: SHUBAR_ABDUELHAKEM_G_ABDUSALAM.
ID: 1141327949
Email: hakeem95shubr@gmail.com
Phone: 0060126227977
Second Student:/
Name: ALI OMRAN ALI HEWAIGH.
ID: 1141327922.
Email: alihewaigh@gmail.com
Phone: 00601123159383
|***************************|**************************|*****************************/
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <windows.h>

using namespace std;

#define size 8

////////////////////////////////////////////////////////////////////////////////

//functions declaration

// To show starting screen of the game 
void main_screen();

// To show main menu
void main_menu();

//Intializes squares of the board
void intialize_board(char board[][size]);

// Makes X player moves 
int playX(char board[][size], char x, int y);

// Makes O player moves
int playO(char board[][size], char x, int y);

// Shows the board
int show_board(char board[][size]);

// Gives brief instructions of the game 
void help_screen();

///////////////////////////////////////////////////////

// Global variables declaration
// Sum of all players' moves 
int moves = 4;

// Shows X player's moves 
int X_moves = 2;

// Shows O player's moves
int O_moves = 2;

// determains players' turn
int turn = 0;
char option;


///////////////////////////////////////////////////////

int main()
{

	// takes menu choice
	char choice;

	// for wrong command of main manu
	int error;

	// Coordinates 
	char x;
	int y;


	// Takes squares of the board
	char board[size][size];

	// Show main screen 
  main_screen();

	do
	{
		
		// Show main menu
		main_menu();
		cin >> choice;
		error = 0;

		system("cls");

		// Determains your choice
		switch (choice)
		{
			
		case 'N': intialize_board(board);
			do
			{
				

				// Detemain players' turn
				if (turn == 0)
				{
					// Shows board to make moves
	                show_board(board);

					// Let X player make move
					playX(board, x, y);
						system("cls");
				}
				
				
				else
				{
					// Shows board to make moves
                  	show_board(board);

					// Let O player make move
					playO(board, x, y);
						system("cls");
				}

							
				if (option == 'Q')
					break;
				
			} while (moves < size*size);

			// Shows board to make moves
	         show_board(board);


			cout << endl << endl << endl;
			cout << "              ************** THE GAME IS OVER **************" << endl;
			cout << "              ****** THANK YOU FOR PLAYING THIS GAME *******" << endl;
			cout << "              ***************** GOOD BYE *******************" << endl << endl;
			break;
			system("cls");

			// Gives information of game       
		case 'H': help_screen();
			cin.ignore(99, '\n');
			break;
			system("cls");

			// Exit
		case 'Q':
			cout << endl << endl << endl;
			cout << "                ******** YOU HAVE QUIT THE GAME ********" << endl << endl;
			cout << "                **************  GOOD BYE  **************" << endl << endl;
			break;


			// Mistake
		default: cout << "\a";
			cout << endl << endl << endl;
			cout << "You entered an invalid choice" << endl;
			cout << "Your choice is: " << choice << endl;
			cout << "Please choose again" << endl << endl;
			error = 1;
			break;
		}
		if (option == 'Q')
			break;

		// return to main menu when the command is help or there is a wrong command
	} while ((error == 1) || (choice == 'H'));

	return 0;
}


/////////////////////////////////////////////////////
// Functions defination

/////////////////////////////////////////////////////
// Main screen

void main_screen()
{
	system("cls");
	cout << endl << endl << endl;
	cout << "       ##############################################       " << endl;
	cout << "       ##############################################       " << endl;
	cout << "       ##                                          ##       " << endl;
	cout << "       ##                                          ##       " << endl;
	cout << "       ##    <<<   WELCOME TO OTHELLO GAME  >>>    ##       " << endl;
	cout << "       ##                                          ##       " << endl;
	cout << "       ##                                          ##       " << endl;
	cout << "       ##        PLEASE PRESS ENTER TO START       ##       " << endl;
	cout << "       ##                                          ##       " << endl;
	cout << "       ##                GOOD LUCK                 ##       " << endl;
	cout << "       ##                                          ##       " << endl;
	cout << "       ##############################################       " << endl;
	cout << "       ##############################################       " << endl;
	cin.ignore(99, '\n');
	system("cls");
}


/////////////////////////////////////////////////////
// Main menu

void main_menu()
{
	
	cout << endl << endl << endl;
	cout << "                 Please choose an option:                   " << endl << endl;
	cout << "             #################################              " << endl;
	cout << "             #################################              " << endl;
	cout << "             ##                             ##              " << endl;
	cout << "             ##        1 - New game         ##              " << endl;
	cout << "             ##                             ##              " << endl;
	cout << "             ##        2 - Help             ##              " << endl;
	cout << "             ##                             ##              " << endl;
	cout << "             ##        3 - Quit             ##              " << endl;
	cout << "             ##                             ##              " << endl;
	cout << "             #################################              " << endl;
	cout << "             #################################              " << endl << endl;
	cout << "      ";
}

//////////////////////////////////////////////////////
//Intializes squares of the board

void intialize_board(char board[][size])
{

	

	for (int y = 7; y >= 0; --y)
	{
		


		for (int x = 0; x < 8; ++x)
		{

			// Makes board accept characters
			

			switch (x)
			{
				// 1st column
			case 0: board[y][x] = ' ';
				break;

				// 2nd column
			case 1: board[y][x] = ' ';
				break;

				// 3rd column
			case 2: board[y][x] = ' ';
				break;

				// 4th column 
			case 3: board[y][x] = ' ';
				break;

				// 5th column
			case 4: board[y][x] = ' ';
				break;

				// 6th column
			case 5: board[y][x] = ' ';
				break;

				// 7th column
			case 6: board[y][x] = ' ';
				break;

				// 8th column
			case 7: board[y][x] = ' ';
				break;

				// mistake
			default: cout << "\a";
				cout << endl << endl << endl;
				cout << endl << "Sorry, unexpected error accured" << endl;
				break;

			}
		}
	}


	// The start markets' places
	board[3][3] = 'X';
	board[3][4] = 'O';
	board[4][3] = 'O';
	board[4][4] = 'X';

	// Resets the moves and turn
	X_moves = 2;
	O_moves = 2;
	moves = 4;
	turn = 0;

}

//////////////////////////////////////////////////////////
// Gets X player's move

int playX(char board[][size], char x, int y)
{
	
	int error;

		// Enter command
		cin >> x >> y;

		if ((x >= 'a') && (x <= 'h') && (y >= 1) && (y <= 8))
		{
			// accepts characters starting with a

			x = static_cast<char>(x)-'a';

			// Checks if the square is empty
			if (board[y - 1][x] != ' ')
			{
				cout << "\a";
				cout << endl << endl << endl;
				cout << "The selected square is not empty" << endl << endl;
				cout << "Please choose again: " << endl << endl;

				// Shows board 
	             show_board(board);
				return playX(board, x, y);
				
			}
			else
			{
				
				// Makes moves
				board[y - 1][x] = 'X';

				// Changes moves and turn
				moves++;
				X_moves++;
				++turn;
			}
		}

		
		else
			if (x == 'n' || x == 'N')
			{
				// Pass to next player
				++turn;

			}
	
	
			else
				if (x == 'm' || x == 'M')
				{
					system("cls");

					do
					{
						// To return to main_menu
						cin.clear();
						cin.ignore(99, '\n');
						main_menu();
						cin >> option;
						error = 0;

						switch (option)
						{
							system("cls");
						case 'N': intialize_board(board);
							break;

							system("cls");
						case 'H':
							help_screen();
							break;

							system("cls");
						case 'Q':
							break;

							// Mistakes
						default: cout << "\a";
							cout << endl << endl << endl;
							cout << "You entred an invail choice" << endl;
							cout << "Your choice is: " << option << endl;
							cout << "Please choose again" << endl << endl;
							error = 1;
							break;

						}

				// return to main menu when the command is help or there is a wrong command
					} while ((error == 1) || (option == 'H'));

				}

		// Rwong command
				else
				{
			
					cin.clear();
					cin.ignore(99, '\n');
					return show_board(board);
					
				}

		
		

}

///////////////////////////////////////////////////////////////////
// Gets O player's move

int playO(char board[][size], char x, int y)
{
	
	int error;
	
	// Enter command
	cin >> x >> y;


	if ((x >= 'a') && (x <= 'h') && (y >= 1) && (y <= 8))
	{

		// accepts characters starting with a

		x = static_cast<char>(x)-'a';

		// Checks if the square is empty
		if (board[y - 1][x] != ' ')
		{
			cout << "\a";
			cout << endl << endl << endl;
			cout << "The selected square is not empty" << endl << endl;
			cout << "Please choose again: " << endl << endl;
			// Shows board 
	        show_board(board);
			return playO(board, x, y);
		}
		else
		{
			
			// Makes moves
			board[y - 1][x] = 'O';

			// Changes moves and turn
			moves++;
			O_moves++;
			--turn;
		}


	}

	else
		if (x == 'n' || x == 'N')
		{
			// Pass to next player
			--turn;

		}

		else
			if (x == 'm' || x == 'M')
			{
				system("cls");
				do
				{
					// To return to main_menu
					cin.clear();
					cin.ignore(99, '\n');
					main_menu();
					cin >> option;
					error = 0;
					switch (option)
					{

						system("cls");
					case 'N': intialize_board(board);
						break;

						system("cls");
					case 'H':
						help_screen();
						break;

						system("cls");
					case 'Q':
						break;

					default: cout << "\a";
						cout << endl << endl << endl;
						cout << "You entred an invail choice" << endl;
						cout << "Your choice is: " << option << endl;
						cout << "Please choose again" << endl << endl;
						error = 1;
						break;

					}

			// return to main menu when the command is help or there is a wrong command
				} while ((error == 1) || (option == 'H'));

			}

	// Rwong command
			else
			{
				
				cin.clear();
				cin.ignore(99, '\n');
				return show_board(board);

			}

	
}

//////////////////////////////////////////////////////////////
// Show the board

int show_board(char board[][size])
{
	
	int num = 8;
	
	cout << endl;
	cout << "    +---+---+---+---+---+---+---+---+" << endl;


	for (int r = 0; r < 8; ++r)
	{
		// Puts numbers of rows
		
		cout << "  " << num << " ";
		cout << "| ";
		--num;
		for (int c = 0; c < 8; ++c)
		{

			cout << board[num][c] << " | ";
		}

		cout << endl << "    +---+---+---+---+---+---+---+---+" << endl;
		
	}
	cout << "   ";
	for (char y = 'a'; y < 'i'; y++)
	{
		// Puts characters of columns
		cout << "   " << y;
	}

	cout << endl << endl << endl;

	// Shows the score of each player
	cout << "  Score:      " << " O =  " << O_moves << "      X =  " << X_moves << endl;

	// Shows the current player
	if (turn == 0)
	{
		cout << "  Current Player: X" << endl << endl;
	}
	else
	{
		cout << "  Current Player: O" << endl << endl;
	}

	cout << "  ==> ";

	return 0;

}


////////////////////////////////////////////////////////
// Gives brief instructions of the game

void help_screen()
{
	system("cls");

	cout << endl << endl; 
	cout << "                            HELP SCREEN                                   " << endl << endl << endl;
	cout << " Othello is a board game played on an 8x8 board using pieces that are" << endl;
	cout << " (X) on one side and (O) on the other." << endl << endl;
	cout << " Players take turns placing pieces on the board with their pieces ficing up." << endl << endl;
	cout << " The game starts whit four pieces placed on the center of the board the player" << endl;
	cout << " playing as back moves first players then alternate turns placing one pieces" << endl;
	cout << " on the board each turn." << endl <<endl;
	cout << " At the start of the game players are asked to write (N / New game) to start" << endl;
	cout << " playing or (H / Help) to get some information about the game or" << endl;
	cout << " (Q / Quit) to exit the game." << endl << endl;
	cout << " notice that all the commands must begine with a capital letter." << endl << endl;
	cout << " Players can choose squares on the board to move their pieces by typing" << endl;
	cout << " a letter for x coordinates and a number for y coordinates for example (f 4)" << endl << endl;
	cout << " For a move to be considered valid the players must choose an empty squares" << endl << endl;
	cout << " Player s can return to main menu by typing (menu) or they may pass turn to" << endl;
	cout << " next player if they type (next player)." << endl << endl << endl << endl; 

	cout << "      Please press enter to continue...";
	cout << endl << endl << endl;
	cin.ignore(99, '\n');

	
}
