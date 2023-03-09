#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char Player_icon = 'X';
const char Pc_icon= 'O';
char winner = ' ';
int checksquares;

void resetBoard();
void printBoard();
int freesquares();
void PlayerPlay();
void PcPlay();
char getWinner();
void printWinner(char);

int main(){

    char winner = ' ';
    resetBoard();
    while(winner == ' ' && freesquares()!= 0){
    printBoard();
    checksquares=freesquares();
    PlayerPlay();
    while(checksquares == freesquares()){
      PlayerPlay();
    }
    winner = getWinner();
    if(winner != ' ' || freesquares() == 0){
        break;
    }
    PcPlay();
    winner = getWinner();
    if(winner != ' ' || freesquares() == 0){
        break;
    }
    }
    printBoard();
    printWinner(winner);
    return 0;
}

void resetBoard(){

    for(int i = 0; i < 3; i++){
        for(int j=0; j<3;j++){
            board[i][j]= ' ';
        }       
    }
}
void printBoard(){
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
}

int freesquares(){
    int freespaces = 9;
        for(int i = 0; i < 3; i++){
            for(int j=0; j<3;j++){
                if(board[i][j]!= ' '){
                    freespaces--;
            };
        }       
    }
    return freespaces;    
}

void PlayerPlay()
{
   int x;
   int y;
    do
   {
      printf("Enter row (1-3): ");
      scanf("%d", &x);
      x--;
      if(x< 0 || x> 2){
        printf("Invalid Number\n");
        break;
      }
      printf("Enter column (1-3): ");
      scanf("%d", &y);
      y--;
      if(y< 0 || y> 2){
        printf("Invalid Number\n");
        break;
      }
      if(board[x][y] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         board[x][y] = Player_icon;
         break;
      }
   } while (board[x][y] != ' ' || x< 0 || x> 2 || y< 0 || y> 2);
}


char getWinner()
{  //check rows
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   //check columns
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   //check diagonals
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }
   return ' ';
}

void printWinner(char winner)
{
   if(winner == Player_icon)
   {
      printf("YOU WIN GG EZ!\n");
   }
   else if(winner == Pc_icon)
   {
      printf("YOU LOSE NOOB!\n");
   }
   else{
      printf("IT'S A TIE wich is the same as loosing lol!\n");
   }
}
void PcPlay()
{
   //creates a seed based on current time
   srand(time(0));
   int x;
   int y;
   if(freesquares() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } 
      while (board[x][y] != ' ');      
    board[x][y] = Pc_icon;
   }
   else
   {
      printWinner(' ');
   }
}