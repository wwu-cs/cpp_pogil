#include <iostream>

using namespace std;

const int NUM_ROWS = 3;
const int NUM_COLS = 3;

// initialize the game board to spaces
void initBoard(char board[][NUM_COLS], int rows);

// print the game board
void printBoard(char board[][NUM_COLS], int rows);

// prompt player `turn' for row/col of play
void getMove(char turn, int &row, int &col);

// check if single array is all the same char
bool isWinningRow(char row[], int size, char &winner);

// check if a board has a winning row/col/diagonal
bool isWinningBoard(char board[][NUM_COLS], int rows, char &winner);

int main() {
  char board[NUM_ROWS][NUM_COLS];
  char winner, playAgain;
  int row, col;
  do {
    char turn = 'O';
    initBoard(board, NUM_ROWS);
    do {
      if (turn == 'X')
        turn = 'O';
      else
        turn = 'X';
      printBoard(board, NUM_ROWS);
      do {
        getMove(turn, row, col);
        // Check if spot is taken
        if (board[row][col] != ' ') {
          cout << "That spot is already taken. Try again." << endl;
        }
      } while (board[row][col] != ' ');
      board[row][col] = turn;
    } while (!isWinningBoard(board, NUM_ROWS, winner));

    printBoard(board, NUM_ROWS);

    if (winner != 'D') {
      cout << "Congrats player " << winner << endl;
    } else {
      cout << "It's a draw!" << endl;
    }
    cout << "Play again (y/n)? ";
    cin >> playAgain;
  } while (playAgain == 'y');
  return 0;
}

// ---------------- IMPLEMENTATION ----------------
void initBoard(char board[][NUM_COLS], int rows) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      board[i][j] = ' ';
    }
  }
}

void printBoard(char board[][NUM_COLS], int rows) {
  cout << endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      // Print cell with padding to match width of 3
      cout << " " << board[i][j] << " ";

      // Print vertical separator if not the last column
      if (j < NUM_COLS - 1) {
        cout << "|";
      }
    }
    cout << endl;

    // Print horizontal separator line if not the last row
    if (i < rows - 1) {
      cout << "---+---+---" << endl;
    }
  }
  cout << endl;
}

void getMove(char turn, int &row, int &col) {
  while (true) {
    cout << "Player " << turn << ", enter row (0-2) and col (0-2): ";
    cin >> row >> col;
    // Validation: Check if input is within the array bounds
    if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS) {
      break; // Input is valid
    } else {
      cout << "Invalid input. Please use numbers between 0 and 2." << endl;
    }
  }
}

bool isWinningRow(char row[], int size, char &winner) {
  // Check if the first cell is not empty, and if all cells match
  if (row[0] != ' ' && row[0] == row[1] && row[1] == row[2]) {
    winner = row[0];
    return true;
  }
  return false;
}

bool isWinningBoard(char board[][NUM_COLS], int rows, char &winner) {
  // 1. Check Horizontal Rows
  for (int i = 0; i < rows; i++) {
    // We can pass the row directly because a 2D array is an array of arrays
    if (isWinningRow(board[i], NUM_COLS, winner)) {
      return true;
    }
  }
  // 2. Check Vertical Columns
  // We must build a temporary array because columns aren't contiguous in memory
  for (int j = 0; j < NUM_COLS; j++) {
    char columnArray[3];
    for (int i = 0; i < rows; i++) {
      columnArray[i] = board[i][j];
    }
    if (isWinningRow(columnArray, 3, winner)) {
      return true;
    }
  }
  // 3. Check Diagonals
  char diag1[3] = {board[0][0], board[1][1], board[2][2]};
  if (isWinningRow(diag1, 3, winner))
    return true;
  char diag2[3] = {board[0][2], board[1][1], board[2][0]};
  if (isWinningRow(diag2, 3, winner))
    return true;
  // 4. Check for Draw (Board Full)
  bool isFull = true;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      if (board[i][j] == ' ') {
        isFull = false;
        break; // Found an empty spot, game continues
      }
    }
  }
  if (isFull) {
    winner = 'D'; // D for Draw
    return true;  // Game over
  }
  return false; // Game continues
}