#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char Player_icon = 'X';
const char Pc_icon= 'O';

void resetBoard();
void printBoard();
int freesquares();
void PlayerPlay();
void PcPlay();
char winner();
void printWinner();

int main(){

    char winner = ' ';
    resetBoard();
    while(winner == ' ' && freesquares()!= 0){
    printBoard();
    PlayerPlay();
    PcPlay();
    }
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
void PcPlay(){

}