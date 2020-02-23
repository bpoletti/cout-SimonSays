using namespace std;
#include <iostream.h>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>









int kbhit(); //waits for keyboard input then returns true
void Green(); //displays a board lit as green
void Blue();//displays a board lit blue
void Yellow();//displays a yellow lit yellow
void Red();//displays a red lit screen
void ClearBoard();//a board with no light
void FrowningFace(); // displays a sad face because the user has lost
void SetupBoard();// the board's introduction screen
void TypingText(string message, int speed);//a typewriter effect that causes text to appear char by char
void GameSetup(int& displayTime, int& multiplier, int&numPlayers);//sets up the game with options provided by player
void SwitchCase(int input, int sleepTime, char& val);//this is the controller of the game that directs traffic and decides the display on the screen
// player struct and sorting configs - a struct is like a cup that holds different values in it.
struct playerInfo{
string name;
double score;
}; 

bool acompare(playerInfo lhs, playerInfo rhs);// compares two values of a struct and directs the sort function to compare the "score value"
void AppendScores(string playerName,int playerScore);

bool acompare(playerInfo lhs, playerInfo rhs) { return lhs.score < rhs.score; }// compares two values of a struct

//appends and displays high scores!!	
void AppendScores(string playerName,int playerScore){
	

	ifstream inFS1;// stream file type

	playerInfo array[5];

//open file
	inFS1.open("scores.txt");
if(inFS1.is_open()){ //check if it opened
	int i=0;
// read
	while (!inFS1.eof()){
	inFS1 >> array[i].name;
	inFS1 >> array[i].score;
++i;
	}

	sort(array, array +5, acompare); // sort

//add a new score
int newScore = playerScore;
string userName = playerName;
playerInfo newP;//
newP.score = newScore;//
newP.name = userName;//

if(newScore > array[0].score){
//int temp = newScore;
for(int k =1; k<5; ++k){
if(newScore >= array[k].score){
	array[k-1] = array[k];
}
else if(newScore < array[k].score){
	array[k-1] = newP;
break;
}
if((k==4) && (newScore >= array[k].score)) {
	array[4] = newP;
}
}}
//print out the table
//sort(array, array +5, acompare); // sort
for( int j =0; j<5; ++j){
cout << array[j].name << " " << array[j].score << endl;
}

inFS1.close(); // close txt file
ofstream oFS;
oFS.open("scores.txt", std::ofstream::out | std::ofstream::trunc);
oFS.close();
oFS.open("scores.txt");

//write table
for( int m =0; m<5; ++m){
oFS << array[m].name << " " << array[m].score << endl;
}
oFS.close();
return;
}
}
// end high score appending



///
void Green() {
	cout << "------------------------------------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-      GGGG      -                 -" << endl;
	cout << "-     G    G     -                 -" << endl;
	cout << "-    G           -                 -" << endl;
	cout << "-    G   GGGG    -                 -" << endl;
	cout << "-    G     GG    -                 -" << endl;
	cout << "-     G     G    -                 -" << endl;
	cout << "-      GGGGG     -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "------------------------------------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "------------------------------------" << endl;
	return;
}
void Blue() {

	cout << "------------------------------------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "------------------------------------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -     BBBB        -" << endl;
	cout << "-                -     B   B       -" << endl;
	cout << "-                -     B   B       -" << endl;
	cout << "-                -     BBBB        -" << endl;
	cout << "-                -     B   B       -" << endl;
	cout << "-                -     B   B       -" << endl;
	cout << "-                -     BBBB        -" << endl;
	cout << "-                -                 -" << endl;
	cout << "------------------------------------" << endl;
	return;
}
void Yellow() {
	cout << "------------------------------------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "------------------------------------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-    Y       Y   -                 -" << endl;
	cout << "-     Y     Y    -                 -" << endl;
	cout << "-      Y   Y     -                 -" << endl;
	cout << "-       YYY      -                 -" << endl;
	cout << "-        Y       -                 -" << endl;
	cout << "-        Y       -                 -" << endl;
	cout << "-        Y       -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "------------------------------------" << endl;
	return;
}
void ClearBoard() {
	cout << "------------------------------------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "------------------------------------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "------------------------------------" << endl;
	return;
}

void Red() {
	
	cout << "------------------------------------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -      RRRR       -" << endl;
	cout << "-                -      R   R      -" << endl;
	cout << "-                -      R   R      -" << endl;
	cout << "-                -      RRRR       -" << endl;
	cout << "-                -      RR         -" << endl;
	cout << "-                -      R R        -" << endl;
	cout << "-                -      R  R       -" << endl;
	cout << "-                -                 -" << endl;
	cout << "------------------------------------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "------------------------------------" << endl;
	return;
}
void FrowningFace(){				
	cout << "------------------------------------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-    OOOOOOO     -      OOOOOOO    -" << endl;
	cout << "-    OOOOO O      -     OOOOO O    -" << endl;
	cout << "-    OOO   O      -     OOO   O    -" << endl;
	cout << "-    OOOOOOO      -     OOOOOOO    -" << endl;
	cout << "-                  -               -" << endl;
	cout << "-                  -               -" << endl;
	cout << "-                  -               -" << endl;
	cout << "------------------------------------" << endl;
	cout << "-                                  -" << endl;
	cout << "-                                  -" << endl;
	cout << "-       OOOOOOOOOOOOOOOOOOOO       -" << endl;
	cout << "-      OOO                OOO      -" << endl;
	cout << "-     OOO                  OOO     -" << endl;
	cout << "-    OOO                    OOO    -" << endl;
	cout << "-   OOO                      OOO   -" << endl;
	cout << "-  OOO                        OOO  -" << endl;
	cout << "-                                  -" << endl;
	cout << "------------------------------------" << endl;

}

void TypingText(string message, int speed) {					//a function that is used to display text like a typewritter from an string
	int x = 0;
	while (message[x] != '\0') {						//runs until there are no more char left
	cout << message[x] << flush;						//flush refreshes the terminal one letter at a time
	usleep(speed); 								//Takes the input to display text faster or slower
	x++;	
	}
}
void SetupBoard() {								//A function that sets up the interface with animations
system("tput reset");
	TypingText("---------------------------------------\n-  SSS  III MMM   MMM  OOOO  NN     N -\n- S      I  M  M M  M O    O N N    N -\n- S      I  M  M M  M O    O N  N   N -\n- S      I  M  M M  M O    O N  N   N -\n-  SSS   I  M   M   M O    O N  N   N -\n-     S  I  M       M O    O N   N  N -\n-     S  I  M       M O    O N    N N -\n-     S  I  M       M O    O N    N N -\n-  SSS  III M       M  OOOO  N    N N -\n---------------------------------------\n-  SSS       A    Y         Y   SSS   -\n- S        A   A   Y       Y   S      -\n- S       A     A   Y     Y    S      -\n- S       A     A    Y   Y     S      -\n-  SSS   A       A    YYY       SSS   -\n-     S  A AAAAA A     Y           S  -\n-     S  A       A     Y           S  -\n-     S A         A    Y           S  -\n-  SSS  A         A    Y        SSS   -\n---------------------------------------\n", 10000);

	usleep(1000000);
	system("tput reset");

	cout << "----------------------------------------" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "----------------------------------------" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "----------------------------------------" << endl;
	usleep(500000);								//flashes the board
	system("tput reset");
	cout << "--------------------------------------" << endl;
	cout << "-  SSS   III MMM   MMM  OOOO  NN     N -" << endl;
	cout << "- S       I  M  M M  M O    O N N    N -" << endl;
	cout << "- S       I  M  M M  M O    O N  N   N -" << endl;
	cout << "- S       I  M  M M  M O    O N  N   N -" << endl;
	cout << "-  SSS    I  M   M   M O    O N  N   N -" << endl;
	cout << "-     S   I  M       M O    O N   N  N -" << endl;
	cout << "-     S   I  M       M O    O N    N N -" << endl;
	cout << "-     S   I  M       M O    O N    N N -" << endl;
	cout << "-  SSS   III M       M  OOOO  N    N N -" << endl;
	cout << "----------------------------------------" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "----------------------------------------" << endl;
	usleep(1000000);							//flashes the board
	system("tput reset");
	cout << "--------------------------------------" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "-                                      -" << endl;
	cout << "----------------------------------------" << endl;
	cout << "-  SSS       A     Y         Y   SSS   -" << endl;
	cout << "- S        A   A    Y       Y   S      -" << endl;
	cout << "- S       A     A    Y     Y    S      -" << endl;
	cout << "- S       A     A     Y   Y     S      -" << endl;
	cout << "-  SSS   A       A     YYY       SSS   -" << endl;
	cout << "-     S  A AAAAA A      Y           S  -" << endl;
	cout << "-     S  A       A      Y           S  -" << endl;
	cout << "-     S A         A     Y           S  -" << endl;
	cout << "-  SSS  A         A     Y        SSS   -" << endl;
	cout << "----------------------------------------" << endl;
	usleep(1000000);							//flashes the board
	system("tput reset");
	cout << "--------------------------------------" << endl;
	cout << "-  SSS   III MMM   MMM  OOOO  NN     N -" << endl;
	cout << "- S       I  M  M M  M O    O N N    N -" << endl;
	cout << "- S       I  M  M M  M O    O N  N   N -" << endl;
	cout << "- S       I  M  M M  M O    O N  N   N -" << endl;
	cout << "-  SSS    I  M   M   M O    O N  N   N -" << endl;
	cout << "-     S   I  M       M O    O N   N  N -" << endl;
	cout << "-     S   I  M       M O    O N    N N -" << endl;
	cout << "-     S   I  M       M O    O N    N N -" << endl;
	cout << "-  SSS   III M       M  OOOO  N    N N -" << endl;
	cout << "----------------------------------------" << endl;
	cout << "-  SSS       A     Y         Y   SSS   -" << endl;
	cout << "- S        A   A    Y       Y   S      -" << endl;
	cout << "- S       A     A    Y     Y    S      -" << endl;
	cout << "- S       A     A     Y   Y     S      -" << endl;
	cout << "-  SSS   A       A     YYY       SSS   -" << endl;
	cout << "-     S  A AAAAA A      Y           S  -" << endl;
	cout << "-     S  A       A      Y           S  -" << endl;
	cout << "-     S A         A     Y           S  -" << endl;
	cout << "-  SSS  A         A     Y        SSS   -" << endl;
	cout << "----------------------------------------" << endl;
	usleep(1000000);
	return;
}
void StartScreen(){								//A function that waits for the user to press enter before starting the game
  cout << "------------------------------------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "--------Press Enter to Play---------" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "-                -                 -" << endl;
	cout << "------------------------------------" << endl;
return;
}
int kbhit() {
	struct timeval tv; //timeval is a structure associated with <ctime>
	fd_set fds;
	tv.tv_sec = 0;// the tv_sec member keeps track of time interval in seconds
	tv.tv_usec = 0;// the tv_usec keeps track of time in microseconds. they are used together for precision
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0, it adds this as a descriptor for fds
	select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);// this allows the program to run while it waits for user input. it give the function 0 waiting time for STDIN_FILENO which is like 'cin'
	return FD_ISSET(STDIN_FILENO, &fds);// returns nonzero if the input is what we want
}




void GameSetup(int& displayTime, int& multiplier, int& numPlayer){ 				//Introduction that displays the home screen
	system("tput reset");
	TypingText("        GG.RR\n    GGGGGG.RRRRRR\n   GGGGGGG.RRRRRRR\n  GGGGGGGG.RRRRRRRR\n GGGGGGG     RRRRRRR\nGGGGGGG       RRRRRRR\n ------ SIMON ------\nYYYYYYY       BBBBBBB\n YYYYYYY     BBBBBBB\n  YYYYYYYY.BBBBBBBB\n   YYYYYYY.BBBBBBB\n     YYYYY.BBBBB\n        YY.BB\n",10000);
	usleep(200000);

cout << endl;

	TypingText("Hi! Welcome to Simon Says! \nType the letters in the sequence which they appear in,\nthen press enter. \nThe sequence gets longer every round.\nIf the sequence does not match, you lose.  \n\nSelect Difficulty: \nEnter 'e' for easy, 'm' for medium, 'h' for hard\n",50000);							//A couple lines of text that explains the intrucitons to the user
	//string user_input;
	char difficulty; 
	while ( (difficulty != 'e') && (difficulty != 'm') &&(difficulty != 'h') ){
	
		cin >> difficulty; 						//ask for difficulty level
			if(difficulty <97){ difficulty = difficulty +32;}	// converts to lowercase
		
		if((difficulty != 'e') && (difficulty != 'm') &&(difficulty != 'h') ){		//checks if the user's input is valid or not
			cout << "I don't recognize your input. Simon Says try again" << endl;	//if not valid displays this message
			}

		}
			switch(difficulty){		//A switch statement that sets the speed of the game and the multiplier based on difficulty
				case 'e': 
				displayTime = 1000000;
				multiplier = 10;
				
				break;
				case 'm': 
				displayTime = 0500000;
				multiplier = 12;
				
				break;
				case 'h': 
				displayTime = 0250000;
				multiplier = 14;
				
				break;
			}
	
//ask for amount of players
	cout << "How many Players are playing? 1 or 2?"<< endl;

while ( (numPlayer != 1) && (numPlayer != 2) ){
	
		cin >> numPlayer; 						//ask for difficulty level

		if((numPlayer != 1) && (numPlayer != 2) ){
			cout << "I don't recognize your input. Simon Says try again" << endl;			
		}
		if (!cin.good()) {
			cin.clear(); 					//clears the input
			cin.ignore(1,'\n');				//ignores the previous input
		}
	

	}

	
	return;
}



void SwitchCase(int input, int sleepTime, char& val){				//A function that displays the random colors onto the board

	system("tput reset");
	ClearBoard();
	usleep(sleepTime);
	system("tput reset");
	switch(input) {				
		case 0: Green();	//displays green on board
		val = 'g';
		break;
		case 1: Blue();		//displays blue on board
		val = 'b';
		break;
		case 2: Yellow();	//displays yellow on board
		val = 'y';
		break;
		case 3: Red();		//displays red on board
		val = 'r';
		break;
	}
	usleep(sleepTime);
	system("tput reset");
	//system("clear");
	ClearBoard();
	return;
}


int main() {

	while(!kbhit()){
	system("tput reset");
	StartScreen();
	usleep(1000000);
	system("tput reset");
	ClearBoard();
	usleep(1000000);
	}
SetupBoard();
//we set up the game based on options provided by user
	int numPlayer = 0;
	int sleepTime = 0;
	int multiplier;
	GameSetup(sleepTime, multiplier, numPlayer);	 	//sets up the game interface
	usleep(2000000); 
char input;


while (input != 'q'){		//checks if the users wants to quit by inputting q
//game starts here
for(int z=1; z<= numPlayer; ++z){
string playerName;
system("tput reset");
cout << "Player " << z << " enter your first name (no spaces):" << endl;	//ask for player number's name
cin >> playerName;
cout << "Get Ready..."<< endl;
usleep(3000000);								//A delay to make sure the player is ready to play




	//your information
	int track = 0;
	int round = 1;
	int score = 0;
	//char matchVal = '?';
	char userIn = '?';
	int seed = time(0);
	
	do{
		srand (seed);				//generates a random seed based on time
		int matchOrder[round] = {};
		char matchArr[round] = {};
		for(int j=0 ; j < round ; ++j){
			matchOrder[j]= rand()%4;	//randomizes the order of the letters based on the seed
		}
  
		for(int k=0 ; k < round ; ++k){
		SwitchCase(matchOrder[k], sleepTime, matchArr[k]); ////////////////testing
		}
		cout << "You are on round " << round << endl	<< "Your input should be "<< round << " characters long"<< endl;
		  
		for (int i =0; i < round; ++i){
			// SwitchCase(rand()%4 , sleepTime, matchVal); ////////////////testing
			cin >> userIn;
			if( userIn<97){ userIn = userIn +32;}// converts to lowercase  
			if ( userIn == matchArr[i]){
			  ++ score;
			  
			}  
			else if (userIn != matchArr[i]){
				track = 9;			//breaks out of the loop and ends the game
				break;
			}//if

			 
			//for i
			}// do
		++ round;
	} while (track != 9);

score = (round-1) * multiplier;	//calculates the score based on the round and difficulty
	system("tput reset");
	FrowningFace();		//displays when the user looses
	TypingText("We have found a mistake in your input, the game has ended\nYour score is: ",50000);  
	cout << score << endl; //displays the score multiplied by the multiplier
	

cout << endl<< endl << endl;
cout << "** HighScores **"<< endl;
AppendScores(playerName,score);		//displays the Highscores list
usleep(500000);

cout << endl << "Enter 'p' to continue, or 'q' to quit:"<< endl;	//ask if the user would like to quit or continue
do{
cin >> input;
if(input<97){ input = input +32;}// converts to lowercase
}while((input != 'p') && (input != 'q'));



if(input == 'q'){++z;}
}//ends game for a player
}


	return 0;
}

 
  
	
	
 



