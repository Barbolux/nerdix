#include <iostream>
using namespace std;



int main()
{

	//Menu
	//Want to play Tic Tac Toe
	//Player Chooses Yes or No
	//Game Starts and Displays Board
	//Menu Choice

	int MenuChoice;

	//Board Variables
	char Square1('1');
	char Square2('2');
	char Square3('3');
	char Square4('4');
	char Square5('5');
	char Square6('6');
	char Square7('7');
	char Square8('8');
	char Square9('9');

	//Player Variable
	int PlayerTurn(1);

	//Whether the game is over or not in the while loop
	bool GameOverDecider(true);

	//Main Menu

	cout << "\tWould you like to play some TIC-TAC-TOE today?" << endl;
	cout << endl << endl;
	cout << "\t(1)Game Start(2 players required)" << endl;
	cout << "\t(2)Quit Game" << endl;
	cout << endl;
	cout << "Choice( 1 or 2):";
	cin >> MenuChoice;
	if (MenuChoice == 1){
		do {
			//Player Variable
			int PlayerTurn(1);

			//Whether the game is over or not in the while loop
			bool GameOverDecider(true);
			
			//Main Game Board
			cout << "       " << Square1 << "  |  " << Square2 << "  |  " << Square3 << endl;
			cout << "     -----+-----+-----" << endl;
			cout << "       " << Square4 << "  |  " << Square5 << "  |  " << Square6 << endl;
			cout << "     -----+-----+-----" << endl;
			cout << "       " << Square7 << "  |  " << Square8 << "  |  " << Square9 << endl;
			cout << "     -----+-----+-----" << endl;

			//Set Player Marker, Player 1 uses X and Player 2 uses O
			char PlayerMarker;
			if (PlayerTurn = 1){
				PlayerMarker = 'X';
			}else{
				PlayerMarker = 'O';
			}

			//Start the game, asking for each Player for a move

			//Bool Variable in order to check if the move is valid
			bool ValidTurn;
			//Run a do while loop to check if their hasn't been a square filled in or 
			do{
				//Char Variable to get next move
				char CurrentMove;

				cout << "Player" << PlayerTurn << "'s turn, set move on what square: " << endl;
				cin >> CurrentMove;
				ValidTurn = true;

				//If Statment Checking if the move is invalid
				//If the move equals 1-9 and a number, and if no one has marked the space yet
				//Checks Each Square
				if (CurrentMove == '1' && Square1 == '1') {
					Square1 = PlayerMarker;
				} else if (CurrentMove == '2' && Square1 == '2') {
					Square2 = PlayerMarker;
				} else if (CurrentMove == '3' && Square1 == '3') {
					Square3 = PlayerMarker;
				} else if (CurrentMove == '4' && Square1 == '4') {
					Square4 = PlayerMarker;
				} else if (CurrentMove == '5' && Square1 == '5') {
					Square5 = PlayerMarker;
				} else if (CurrentMove == '6' && Square1 == '6') {
					Square6 = PlayerMarker;
				} else if (CurrentMove == '7' && Square1 == '7') {
					Square7 = PlayerMarker;
				} else if (CurrentMove == '8' && Square1 == '8') {
					Square8 = PlayerMarker;
				} else if (CurrentMove == '9' && Square1 == '9') {
					Square9 = PlayerMarker;
				} else {
					cout << "Invalid Move, make another one:" << endl;
					ValidTurn = false;
				}
			} while(!ValidTurn);


			// GameOverDecider Bool Variable now set to false, showing the game is over

			GameOverDecider = false;
			
			// New Bool variable
			bool WinGame = true;

			//Win Condition that's through either square 1, 4, and 7 or 1, 2, and 3

			if(Square1 != '1'){
				//1, 2, and 3

				if (Square2 == Square1 && Square3 == Square1) {
					GameOverDecider = true;
				}
				//1, 4, and 7

				if (Square4 == Square1 && Square7 == Square1) {
					GameOverDecider = true;
				}
			}
	
			//Win Condition that's through either square 3, 6, and 9 or 7, 8, and 9 

			if(Square1 != '9'){
				//3, 6, and 9

				if (Square3 == Square9 && Square6 == Square9) {
					GameOverDecider = true;
				}
				//7, 8, and 9

				if (Square7 == Square9 && Square8 == Square9) {
					GameOverDecider = true;
				}
			}

			//Win Conditions through the middle square, 4 conditions
			
			if(Square1 != '5'){
				//1, 5, and 9
				if (Square1 == Square5 && Square9 == Square5) {
					GameOverDecider = true;
				}
				//2, 5, and 8
				if (Square2 == Square5 && Square8 == Square5) {
					GameOverDecider = true;
				}
				//4, 5, and 6
				if (Square4 == Square5 && Square6 == Square5) {
					GameOverDecider = true;
				}
				//3, 5, and 7
				if (Square3 == Square5 && Square7 == Square5) {
					GameOverDecider = true;
				}
			}
				
			//Check if their are draws
			if (Square1 != '1' && Square2 != '2' && Square3 != '3' && 
				Square4 != '4' && Square5 != '5' && Square6 != '6' && 
				Square7 != '7' && Square8 != '8' && Square9 != '9' && !GameOverDecider){
					GameOverDecider = true;
					WinGame = false;

			if(GameOverDecider){
				if(WinGame){
					cout << "Player " << PlayerTurn << " totally wins!" << endl;
				}
				//Print the result board
				cout << "       " << Square1 << "  |  " << Square2 << "  |  " << Square3 << endl;
				cout << "     -----+-----+-----" << endl;
				cout << "       " << Square4 << "  |  " << Square5 << "  |  " << Square6 << endl;
				cout << "     -----+-----+-----" << endl;
				cout << "       " << Square7 << "  |  " << Square8 << "  |  " << Square9 << endl;
				cout << "     -----+-----+-----" << endl;

				//Choice to whether to play the game again

				cout << "\tGame Over!" << endl;
				cout << "\tWant to play again?(Y/N)?: ";
				char PlayAgain;
				cin >> PlayAgain;

				//Clears Board Back to the original numbers
				if(PlayAgain = 'y'){
					GameOverDecider = false;
					Square1 = '1';
					Square2 = '2';
					Square3 = '3';
					Square4 = '4';
					Square5 = '5';
					Square6 = '6';
					Square7 = '7';
					Square8 = '8';
					Square9 = '9';
				}
				PlayerTurn = 1;
			} else {
				// If the game is still going on, alternate the players turns
				if (PlayerTurn == 1){
					PlayerTurn = 2;
				} else {
					PlayerTurn = 1;
				}
			}
		
		// End of Main Do While Loop
		} while (!GameOverDecider);

		
	//End of Menu Choice If Statement
	} else(MenuChoice == 2) {
		cout << "Ok....." << endl;
		}

	system ("pause"); 
	return 0;
	
}
