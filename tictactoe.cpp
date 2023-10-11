//Jazveer Kaler
//October 5th
//TicTacToe

#include <iostream>
#include <cstring>

using namespace std;

//functions
void resetBoard(int board[3][3]);
void printBoard(int board[3][3]);
bool checkWin(int board[3][3], int player);
bool checkTie(int board[3][3]);

int main () {

  //initializing variables
  int board[3][3];
  char input[10];
  int TurnX = 0;
  int TurnO = 1;
  int turn = TurnX;
  int winsX = 0;
  int winsO = 0;
  int moves = 0;

  bool playing = true;
  resetBoard(board);
  
  while (playing == true) {
    while (checkWin(board, 1) == false && checkWin(board, 2) == false && checkTie(board) == false) {
      printBoard(board);
      cout << "Where do you want to play?" << endl;
      
      //get input
      cin.get(input, 11);
      cin.get();
      int length = strlen(input);
      input[length] = '\0';

      //troubleshooting invalid input
      if (strlen(input) != 2) {
        cout << "Re-enter input" << endl;
        input[0] = 0;
      }
      else if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') {
        cout << "Re-enter input" << endl;
        input[0] = 0;
      }
      else if (input[1] != '1' && input[1] != '2' && input[1] != '3') {
        cout << "Re-enter input" << endl;
        input[0] = 0;
      }
        
      //valid input 
      else {
        int row;
        int col;
        if (input[0] == 'a') {
          row = 0;
        }
        else if (input[0] == 'b') {
          row = 1;
        }
        else if (input[0] == 'c') {
          row = 2;
        }
        if (input[1] == '1') {
          col = 0;
        }
        else if (input[1] == '2') {
          col = 1;
        }
        else if (input[1] == '3') {
          col = 2;
        }
        
       //putting piece on board and checking if a move is valid
       if (board[row][col] == 0) {
          if (turn == TurnX) {
            board[row][col] = 1;
            turn = TurnO;
            moves++;
          }
          else {
            board[row][col] = 2;
            turn = TurnX;
            moves++;
          }
        }
        else
          cout << "invalid move" << endl;
      }
      
    }
    //x wins
    if (checkWin(board, 1) == true && checkTie(board) == false) {
      cout << "X Wins!" << endl;
      winsX++;
      turn = TurnX;
      cout << "X wins: " << winsX << "   O wins: " << winsO << endl;
    }
    //o wins
    else if (checkWin(board, 2) == true && checkTie(board) == false) {
      cout << "O Wins!" << endl;
      ++winsO;
      cout << "X wins: " << winsX << "   O wins: " << winsO << endl;
    }
    //tie
    else if (checkTie(board) == true) {
      cout << "Tie!" << endl;
      cout << "X wins: " << winsX << "   O wins: " << winsO << endl;
    }
    
    char playAgain[2];
    cout << "Would you like to play again? y or n" << endl;
    cin.get(playAgain, 2);
    cin.get();
    playAgain[1] = '\0';
    if (playAgain[0] == 'y') {
      cout << "New game" << endl;
      playAgain[0] = 0;
      resetBoard(board);
      playing = true;
    }
    else
      playing = false;
  }
}
  
//print board function
//converts numbers to charcters 
//0 = blank, 1 = X, 2 = O
void printBoard(int board[3][3]) {
  cout << " \t1\t2\t3" << endl;
  int count = 0;
  char output[100];
  for(int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      
      if (row == 0 && col == 0) {
	      output[count] = 'a';
        output[count+1] = '\t';
      	count = count+2;
      }
        
      else if (row == 1 && col == 0) {
      	output[count] = 'b';
      	output[count+1] = '\t';
      	count = count+2;
      }
        
      else if (row == 2 && col == 0) {
      	output[count] = 'c';
      	output[count+1] = '\t';
      	count = count+2;
      }
      
      if (board[row][col] == 0) {
      	output[count] = '\t';
      	count++;
      }
        
      else if(board[row][col] == 1) {
      	output[count] = 'X';
      	output[count+1] = '\t';
      	count = count+2;
      }
        
      else if(board[row][col] == 2) {
      	output[count] = 'O';
      	output[count+1] = '\t';
      	count = count+2;
      }
      
      if (col == 2 && row != 2) {
      	output[count] = '\n';
      	count++;
      }
      
    } 
  }
  output[count] = '\0';
  cout << output << endl;
}

//reset board function
void resetBoard(int board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = 0;
    }
  }
}

//check for ties
bool checkTie(int board[3][3]) {
  int moves = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != 0)
	       moves++;
      if (moves == 9 && checkWin(board, 1) == false && checkWin(board, 2) == false) 
	       return true;
    }
  }
  return false;
}

//check for wins
bool checkWin(int board[3][3], int player) {
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player)
    return true;
  if (board[1][0] == player && board[1][1] == player && board[1][2] == player) 
    return true;
  if (board[2][0] == player && board[2][1] == player && board[2][2] == player)
    return true;
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player)
    return true;
  if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
    return true;
  if (board[0][2] == player && board[1][2] == player && board[2][2] == player)
    return true;
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) 
    return true;
  if (board[2][0] == player && board[1][1] == player && board[0][2] == player) 
    return true;
  else
    return false;
}