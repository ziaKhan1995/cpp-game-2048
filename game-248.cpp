#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iomanip>

using namespace  std;
// Keys  defined are here
// values are picked from ASCII  table
#define END    79
#define KEY_UP 72

#define KEY_DOWN 80

#define KEY_LEFT 75

#define KEY_RIGHT 77
#define ESCAPE 27
///


int big_board[4][4] = { 0 };// 4*4 array board on which tiles lies
const int maximum = 2048;
static int step;
static int user_score;

int random_index_generate() { // function  to geneerate random numbers
	int random_index = rand() % 4;
	return random_index;
}

int new_random_element() {
	int random_element = rand() % 9;
	random_element = (random_element == 0) ? 4 : 2;// ternary operator condition
	return random_element;
}
//win or lose checking
int is_win() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (big_board[i][j] == maximum) {
				return 1;
			}
		}
	}
	return 0;
}//end of is_win function  body

int game_over() {  // in case if user lose the game , game_over function
	int is_game_over = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (big_board[i][j] == 0 || big_board[i][j + 1] == 0 || big_board[i][j] == big_board[i][j + 1]) {
				is_game_over = 0;
				break;
			}
		}
	}

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 3; i++) {
			if (big_board[i][j] == 0 || big_board[i + 1][j] == 0 || big_board[i][j] == big_board[i + 1][j]) {
				is_game_over = 0;
				break;
			}
		}
	}
	return is_game_over;
}//end of game_over function body

void display_Top_Text_On_game() { // function to display top text , rules etc
	cout << "****\nStart the game 2048\n\t\t\t****\n\n";
	cout << "Rules of the game:" << endl;
	cout << "Press the directional arrow keys for moving the tiles in a certain direction" << endl;/* To
	prompt user which keys are used to move the tile*/
	cout << "Use your arrow keys to move the tiles. When two tiles with the ";
	cout << "same number touch, they merge into one!\n";// prompt user to press any key
	cout << "Join the numbers and get to the 2048 tile!\n";//end of game or user victory stage
	cout << "Press [[ Escape ]] key for restarting the game\n";
	cout << "Press [[ End ]] key to exit the game\n\n";
	cout << "When borad is full or after certain time game_over function will be called \n\n";
}
//show game big_board
void display() {
	int index_i1, index_j1, index_i2, index_j2;
	//test duplication
	while (1) {
		index_i1 = random_index_generate();
		index_j1 = random_index_generate();
		index_i2 = random_index_generate();
		index_j2 = random_index_generate();
		if (index_i1 == index_i2 && index_j1 == index_j2) {
			continue;
		}
		else
			break;
	}
	//initialize the game
	system("cls");
	display_Top_Text_On_game();
	if (step == 0) {
		/*cout << "****\nStart the game 2048\n\t\t\t****\n\n";
		cout << "Rules of the game:" << endl;
		cout << "Press the directional arrow keys for moving the tiles in a certain direction" << endl;/* To 
	    prompt user which keys are used to move the tile///
		cout << "Use your arrow keys to move the tiles. When two tiles with the ";
		cout << "same number touch, they merge into one!\n";// prompt user to press any key
		cout << "Join the numbers and get to the 2048 tile!\n";//end of game or user victory stage
		cout << "Press [[ Escape ]] key for restarting the game\n";
		cout << "Press [[ End ]] key to exit the game\n\n";
		cout << "When borad is full or after certain time game_over function will be called \n\n";
		*/
		for (int i = 0; i < 4; i++) {
			cout << "|-----------------------|" << endl;
			for (int j = 0; j < 4; j++) {
				cout << "|";
				if (i == index_i1 && j == index_j1) {
					big_board[i][j] = 2;
					cout << "  " << 2 << "  ";// creating space between tiles
				}
				else if (i == index_i2 && j == index_j2) {
					int temp = new_random_element();
					big_board[i][j] = temp;
					cout << "  " << temp << "  ";
				}
				else
					cout << "     ";
			}
			cout << "|" << endl;// These will appear as tiles
		}
		cout << "|-----------------------|" << endl;//The | willl only appear in as last tiles and - in the mid 
	}
	//redisplay
	else {
		for (int i = 0; i < 4; i++) {
			cout << "|-----------------------|" << endl;
			for (int j = 0; j < 4; j++) {
				cout << "|";
				if (big_board[i][j] != 0) {
					if (big_board[i][j] == 1024 || big_board[i][j] == 2048)
						cout << " " << big_board[i][j];
					if (big_board[i][j] == 128 || big_board[i][j] == 256 || big_board[i][j] == 512)
						cout << " " << big_board[i][j] << " ";
					if (big_board[i][j] == 16 || big_board[i][j] == 32 || big_board[i][j] == 64)
						cout << "  " << big_board[i][j] << " ";
					if (big_board[i][j] == 2 || big_board[i][j] == 4 || big_board[i][j] == 8)
						cout << "  " << big_board[i][j] << "  ";
				}
				else
					cout << "     ";
			}
			cout << "|" << endl;
		}
		cout << "|-----------------------|" << endl;
	}

}
///

////
//insert random element
void add_element() {
	int index_i3, index_j3;
	int flag = 0;
	while (1) {
		if (flag == 1)break;
		index_i3 = random_index_generate();
		index_j3 = random_index_generate();
		if (big_board[index_i3][index_j3] == 0) {
			big_board[index_i3][index_j3] = new_random_element();
			flag = 1;
		}
	}
}

//move functions of tiles
void move_left_the_tiles() { /*declaration and definition of a function which move the tiles 
							   left to add*/
	int flag = 0;
	for (int i = 0; i < 4; i++) {
		int n = 0;
		int previous = 0;
		for (int j = 0; j < 4; j++)
		{
			if (n == big_board[i][j] && n != 0) {
				big_board[i][previous] = 2 * n;
				big_board[i][j] = 0;
				user_score += 2 * n;
				n = 0;
				flag++;
				continue;
			}
			if (big_board[i][j] != 0) {
				n = big_board[i][j];
				previous = j;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 3; k++) {
				if (big_board[i][k] == 0 && big_board[i][k + 1] != 0) {
					big_board[i][k] = big_board[i][k] ^ big_board[i][k + 1];  //Bitwise XOR	 ^	Left to right
					big_board[i][k + 1] = big_board[i][k] ^ big_board[i][k + 1];
					big_board[i][k] = big_board[i][k] ^ big_board[i][k + 1];
					flag++;
				}
			}
		}
	}
	if (flag != 0) {
		add_element();
		step++;
	}
	display();
}

void move_right_the_tiles() {  /*declaration and definition of a function which move the tiles 
							   toward right to add*/
	int flag = 0;
	for (int i = 0; i < 4; i++) {
		int n = 0;
		int previous = 0;
		for (int j = 3; j >= 0; j--)
		{
			if (n == big_board[i][j] && n != 0) {
				big_board[i][previous] = 2 * n;
				big_board[i][j] = 0;
				user_score += 2 * n;
				n = 0;
				flag++;
				continue;
			}
			if (big_board[i][j] != 0) {
				n = big_board[i][j];
				previous = j;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 3; k > 0; k--) {
				if (big_board[i][k] == 0 && big_board[i][k - 1] != 0) {
					big_board[i][k] = big_board[i][k] ^ big_board[i][k - 1];
					big_board[i][k - 1] = big_board[i][k] ^ big_board[i][k - 1];
					big_board[i][k] = big_board[i][k] ^ big_board[i][k - 1];
					flag++;
				}
			}
		}
	}
	if (flag != 0) {
		add_element();
		step++;
	}
	display();
}

void move_up_the_tiles() {  /*declaration and definition of a function which move the tiles 
							   up to add*/
	int flag = 0;
	for (int i = 0; i < 4; i++) {
		int n = 0;
		int previous = 0;
		for (int j = 0; j < 4; j++)
		{
			if (n == big_board[j][i] && n != 0) {
				big_board[previous][i] = 2 * n;
				big_board[j][i] = 0;
				user_score += 2 * n;
				n = 0;
				flag++;
				continue;
			}
			if (big_board[j][i] != 0) {
				n = big_board[j][i];
				previous = j;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 3; k++) {
				if (big_board[k][i] == 0 && big_board[k + 1][i] != 0) {
					big_board[k][i] = big_board[k][i] ^ big_board[k + 1][i];  // ^ i bitwise exclusive OR operator for left to right
					big_board[k + 1][i] = big_board[k][i] ^ big_board[k + 1][i];
					big_board[k][i] = big_board[k][i] ^ big_board[k + 1][i];
					flag++;
				}
			}
		}
	}
	if (flag != 0) {
		add_element();
		step++;
	}
	display();
}

void move_down_the_tiles() {   /*declaration and definition of a function which move the tiles 
							   down to add*/
	int flag = 0;
	for (int i = 0; i < 4; i++) {
		int n = 0;
		int previous = 0;
		for (int j = 3; j >= 0; j--)
		{
			if (n == big_board[j][i] && n != 0) {
				big_board[previous][i] = 2 * n;
				big_board[j][i] = 0;
				user_score += 2 * n;
				n = 0;
				flag++;
				continue;
			}
			if (big_board[j][i] != 0) {
				n = big_board[j][i];
				previous = j;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 3; k > 0; k--) {
				if (big_board[k][i] == 0 && big_board[k - 1][i] != 0) {
					big_board[k][i] = big_board[k][i] ^ big_board[k - 1][i];
					big_board[k - 1][i] = big_board[k][i] ^ big_board[k - 1][i];
					big_board[k][i] = big_board[k][i] ^ big_board[k - 1][i];
					flag++;
				}
			}
		}
	}
	if (flag != 0) {
		add_element();
		step++;
	}
	display();
}

///
int main()

{ // main function body start
	
	cout << endl;
	//srand((unsigned)time(NULL));
	/* can also be written as  srand(time(0))
								it generate a random number , each time the program is being run.
								To use current time as seed is a statndard way to start with different initial value.
								*/
	
	int user_choice_for_pressing_keys;// user choice character for up , down , left and right moving
	char user_choice_for_restarting_game;
	char again_play_game;
	int question = 0;// Question user that user want sagain play the game or not 
	char exit_the_game;

	//initialize game board

	 display();     /* display function calling in main, of big_board on which ties lies.
				    Here Control will goes directly to display
					  function and execute what are inside the display function
				   */


	
		while (true) {  //Infinite while loop body start
			if (is_win() && !question) // in case if user win the game , calling of win function in main
			{
				question = !question;
				cout << step << " steps" << endl;
				cout << "Congratulation!!!YOU WIN!!!" << endl;
				cout << "Do you want to Continue  the game \n Enter (y/n) for yes/No" << endl;
				cin >> again_play_game;
				if (again_play_game == 'n')
					exit(1);// Abnormal termination of program 
			}
			if (game_over()) {    //when a certain  time/kbhits finish 
			  //gameover function calling in main which is defined befor main function
				cout << "~~~GAME OVER~~~\n Become loser" << endl;
				exit(2);
			}


			user_choice_for_pressing_keys = 0;

			switch ((user_choice_for_pressing_keys = _getch())) //user choice based menu display
			{  // switch body start
				  						
			       case KEY_UP:// when user press UP arrow key  //
				   //cout << "\n\n";
					// system("cls");			
				   move_up_the_tiles();/*calling of move_up_the_tiles funtion in main .
									   Here control will goes directly to move_up_the_tiles
						  function and execute what are inside move function
						 Here Control will goes directly to move-up function
						 */
				   

				   				  break;

			      case KEY_DOWN://when user press down arrow key
				    cout << "\n\n";
				    move_down_the_tiles(); // calling of move-down funtion in main 
					//Here Control will goes directly to move-down
									break;

			      case KEY_LEFT:
				    cout << "\n\n"; //calling of  funtion in main
				    move_left_the_tiles(); // Here Control will goes directly to move-left function
				                break;

			      case KEY_RIGHT://when user press key right
				     cout << "\n\n";
				     move_right_the_tiles(); //calling of move-right funtion in main
				             break;
				  case ESCAPE:
					  cout << "\n Do you want to restart the game \nEnter y/n : ";
					  cin >> user_choice_for_restarting_game;
					  if (user_choice_for_restarting_game == 'y')
					  {
						  
						  step = 0;// intial tep is zero
						  for (int i = 0; i < 4; i++) { // initializing array to zero for  reseting the game or new game
							  for (int j = 0; j < 4; j++) {
								  big_board[i][j] = 0;
							  }
						  }
						  user_score = 0;
						  main();
							  
						  }
					  break;
					  
				  case END:
					   cout << "Do you want to exit the game? y/n   ";
					  cin >> exit_the_game;
					  if (exit_the_game == 'y') {
						  cout << "Exit successfully";
						  exit(0);
					  }
			}// switch body end
			cout << "   User Score: " << user_score << endl;// score won by user
		}// while loop body end
	
	
	cout << "Hi programmer";
	system("pause");
	return 0;

} // main body closed
