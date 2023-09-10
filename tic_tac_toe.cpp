#include <bits/stdc++.h>
using namespace std; 

void displayBoard(const vector<vector<char>>& board){
      cout << board[0][0] << "|" << board[0][1] << "|" << board[0][2];  
      cout << "\n_ _ _\n"; 
      cout << board[1][0] << "|" << board[1][1] << "|" << board[1][2]; 
      cout << "\n_ _ _\n"; 
      cout << board[2][0] << "|" << board[2][1] << "|" << board[2][2]; 
      cout << endl; 
}

bool checkRow(const vector<char>& row){
    if(row[0] == row[1] && row[1] == row[2] && row[0] != ' ') return true; 
    return false; 
}

char checkColumn(const vector<vector<char>>& board){
    for(int i = 0; i<3; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return board[0][i]; 
    }

    return ' '; 
}

char checkDiagonal(const vector<vector<char>>& board){
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') return board[0][0]; 
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') return board[1][1]; 

    return ' '; 
}

char winner(const vector<vector<char>>& board){
     if(checkRow(board[0])) return board[0][0]; 
     if(checkRow(board[1])) return board[1][0]; 
     if(checkRow(board[2])) return board[2][0]; 
     char t1 = ' ', t2 = ' '; 
     t1 = checkColumn(board); t2 = checkDiagonal(board); 

     if(t1 != ' ') return t1; 
     if(t2 != ' ') return t2; 

     return ' '; 
     
}

bool boardFilled(const vector<vector<char>>& board){
    for(int i = 0; i<3; i++) for(int j = 0;  j<3; j++) if(board[i][j] == ' ') return false; 
    return true; 
}

int main(){
    vector<vector<char>> board(3, vector<char>(3, ' ')); 

    bool player = true; 

    while(!boardFilled(board)){
        displayBoard(board); 
        int x,y; 
        bool done = false;
        while(!done) 
    {  
        if(player){
            cout << "Player1's turn: " << endl << "Please enter the coordinates where you want to mark: "<<endl; 
            cin >> x >> y; 
            if(x <0 || y <0 || x >2 || y > 2 || board[x][y]!= ' ' ) 
            {cout << "Please enter valid cordinates" <<endl; continue;  }
            board[x][y] = 'X'; done = true; 
        }
        else{
            cout << "Player2's turn: " << endl << "Please enter the coordinates where you want to mark: "<<endl; 
            cin >> x >> y; 
            if(x <0 || y <0 || x >2 || y > 2 || board[x][y]!= ' ' ) 
            {cout << "Please enter valid cordinates" <<endl; continue;  }
            board[x][y] = 'O'; done = true; 
        }
    }
        char t= winner(board); 
        player = !player; 

        if(t == ' ') continue; 
        
        displayBoard(board); 
        if(t == 'X') cout << " Player 1 Won the match!!" << endl; else cout << "Player 2 Won the match!!" << endl; 
        break; 
    }     

    char t = winner(board); 

    if(t == ' '){ displayBoard(board);  cout << "It's a tie!!"; }

    return 0; 
}