//A Simple Space-filling 2-D Animated AI Code
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
  
const int LENGTH=8;    // set floor dimensions
int floor[LENGTH][LENGTH] = {0};    //array for values on floor
  
void displayFloor();
 
int  chooseRobotMove(int curRow, int curCol);
int rowChange[]={-1,-1,-1, 0,0, 1,1,1}; // Robot has 8 Moves,
int colChange[]={ 0,-1, 1,-1,1,-1,0,1}; // one in each direction
bool isOnFloor(int rowLoc, int colLoc); 
 
int main() {
  srand((unsigned)time(NULL));
  //place robot at random 
  int robotcurRow=rand()% LENGTH;
  int robotcurCol=rand()% LENGTH; 
  floor[robotcurRow][robotcurCol]=1;  
      
  displayFloor();
  cout << "Set your window height, then begin ROBOT-AI (Hit any key)"; int x; cin>> x;  
  
  int chooseRow,chooseCol; // used to store upcoming move
  while(true){
    //robot's Move
    int move = chooseRobotMove(robotcurRow,robotcurCol);
    if (move != -1) {
      chooseRow = robotcurRow + rowChange[move];
      chooseCol = robotcurCol + colChange[move];
    }
    else {
      cout << "Teleporting" <<endl;
      chooseRow=rand()% LENGTH;
      chooseCol=rand()% LENGTH;
    }     
    floor[chooseRow][chooseCol]= 1;    // mark as current visit
    floor[robotcurRow][robotcurCol]= -1; //mark as previously visited
    robotcurRow=chooseRow; robotcurCol=chooseCol;
    displayFloor();
            
  }
  cout << "ALL DONE - Goodbye"<< endl;
}
  
bool isOnFloor(int rowLoc, int colLoc){     
  return (rowLoc >=0 && rowLoc < LENGTH  &&
          colLoc>=0 && colLoc< LENGTH);
}
  
int chooseRobotMove(int curRow, int curCol){  
  for (int i=0 ; i < LENGTH; ++ i) {
    int row = curRow + rowChange[i];
    int col = curCol + colChange[i];
    if (isOnFloor(row,col) && floor[row][col] != -1) return i;
    }
  return -1;
}
  
void displayFloor (){
//a hacked function to display chess floor with labels on columns and rows
  cout << "\n     ";    //start table by skipping line and aligning column label
  for (int i = 0; i < LENGTH; ++i) cout << i << "   ";    cout<< endl; //display column labels
  for (int crow = 0; crow < LENGTH; ++crow) { //display current row
    for (int i = 0; i < LENGTH*4.5; ++i) cout<< "-"; 
    cout << endl;    //next line for start of table values
    for (int j = 0; j <= LENGTH; ++j) cout << "   |"; cout<< endl;
    cout << crow ;
    if (crow <10) cout << "  |"; else cout << " |";    //display row labels
    for (int ccol = 0; ccol < LENGTH; ++ccol) {
      if (floor[crow][ccol] == 0) cout<<"  ";
      else if(floor[crow][ccol]==1) cout << " R";
      else if(floor[crow][ccol]==-1) cout << " @";
      else cout << "  ";
      //output table values
      if (floor[crow][ccol] > 9)
        cout << "|";
      else cout << " |";
    }//end for data
    cout<< endl;
    for (int j = 0; j <= LENGTH; ++j) cout << "   |"; cout<< endl;
  }// end for crow    
  for (int l = 0; l < LENGTH*4.5; ++l) cout<< "-";    cout << endl;
  const int DELAY=20000; // set delay for animation 
  for(int k =0;k<DELAY; k++) for(int j=0;j<DELAY;j++); //wait 
}//END displayFloor function
