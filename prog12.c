#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define n 4

int board[n];
void printsolution(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i]==j)
                printf("q");
            else
              printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

bool issafe(int row,int col){
    for(int i=0;i<row;i++){
        if(board[i]==col||abs(board[i]-col)==abs(i-row))
            return false;
    }
     return true;
}


void solveNqueen(int row){
    if(row==n){
        printsolution();
        return;
    }
    for(int col=0;col<n;col++){
        if(issafe(row,col)){
            board[row]=col;
            solveNqueen(row+1);
        }
    }
}

int main(){
    printf("solution for %d-queens problem:\n\n",n);
    solveNqueen(0);
    return 0;
}