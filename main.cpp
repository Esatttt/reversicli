#include <iostream>

using namespace std;

    char validletters[12];
    int boardSize = 0;
    int differ[8][2] = {{-1, -1}, {-1,  0}, {-1,  1},{ 0, -1},{ 0,  1},{ 1, -1}, { 1,  0}, { 1,  1}};
    bool islettervalid(char x);
    int chartonum(char x);

int main(){
    cout << "Welcome, please enter the number of rows and columns (8 / 10 / 12): ";
    cin >> boardSize;
    
    while(boardSize != 8 && boardSize != 10 && boardSize != 12){
        cout << "Please enter the number of rows and columns (8 / 10 / 12): ";
        cin >> boardSize;
    }

    char letters[12] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};
        for(int i = 0; i < boardSize; i++){
        validletters[i] = letters[i];
        }

    char board[boardSize][boardSize];

    for(int x = 0; x < boardSize; x++){
        for(int y = 0; y < boardSize; y++){
        board[x][y] = '.';
    }
    }

    board[boardSize/2][boardSize/2] = 'o';
    board[boardSize/2-1][boardSize/2-1] = 'o';
    board[boardSize/2][boardSize/2-1] = 'x';
    board[boardSize/2-1][boardSize/2] = 'x';

    bool gamestart = true;

    int userable[144][2];
    int compable[144][3];
    int combablen = 0;
    int passcount = 0;

    while(gamestart){

        //BOARD PRESS
        if(boardSize == 8){
            cout << "  abcdefgh";
        } else if(boardSize == 10) {
            cout << "  abcdefghij";
        } else if(boardSize == 12) {
            cout << "  abcdefghikl";
        }
        cout << endl;
        for(int x = 0; x < boardSize; x++){
        cout << x;
        if(x < 10){cout << " ";}    
        for(int y = 0; y < boardSize; y++){
        cout << board[x][y];
        } cout << endl;}


        int userablen = 0; int compablen = 0;

        //USER CHECK SYSTEM    
        for(int x = 0; x < boardSize ; x++){
            for(int y = 0; y < boardSize ; y++){
            if(board[x][y] == 'o'){
                int newpoint[2] = {x,y};
                for(int i = 0; i < 8; i ++){
                    newpoint[0] = x, newpoint[1] = y;
                    newpoint[0] = x + differ[i][0];
                    newpoint[1] = y + differ[i][1];
                    int skip = 0;
                    if(newpoint[0]>=boardSize || newpoint[0] <0 || newpoint[1]>=boardSize || newpoint[1] <0 ){
                        continue;
                    }   
                    while(board[newpoint[0]][newpoint[1]] == 'x'){
                        if((newpoint[0] + differ[i][0]) >= boardSize || (newpoint[0] + differ[i][0]) < 0 || (newpoint[1] + differ[i][1]) >= boardSize || (newpoint[1] + differ[i][1]) < 0){
                            break;
                        }
                        newpoint[1] = newpoint[1] + differ[i][1];
                        newpoint[0] = newpoint[0] + differ[i][0];
                        skip++;
                    }   
                    if(board[newpoint[0]][newpoint[1]] == '.'){
                        if(skip>0){
                        userable[userablen][0] = newpoint[0];
                        userable[userablen][1] = newpoint[1];
                        userablen++;
                        }
                    }
                }
            }
        
        }
        }
        if(userablen > 0){
        passcount = 0;
        //INPUT CHECK
        bool validmove = false;
        char xletter = 'z'; int yu = -1; int xu;

        while(validmove == false){
        cout << "Enter your move (xy format, letter and number): ";
        cin >> xletter >> yu;

        if(0<=yu && yu<boardSize && islettervalid(xletter)){
        xu = chartonum(xletter);
        for(int i = 0; i < userablen; i++){
            if(userable[i][0] == yu && userable[i][1]==xu){
                validmove = true;}
        }
    }
    } board[yu][xu] = 'o';



    //USER EATING
    for(int i = 0; i < 8; i++){
    bool willeat = false;
    int place[2];
    place[0] = yu + differ[i][0];
    place[1] = xu + differ[i][1];
    while(place[0] < boardSize && place[1] < boardSize && place[0] >= 0 && place[1] >= 0){
        if (board[place[0]][place[1]] == 'x') {
            place[0] = place[0] + differ[i][0];
            place[1] = place[1] + differ[i][1];
            willeat = true;
        } else if(board[place[0]][place[1]] == 'o' && willeat){
            int xi = xu; int yi = yu;
            while(xi != place[1] || yi != place[0]){
                board[yi][xi] = 'o';
                xi = xi+differ[i][1]; yi = yi + differ[i][0];
            }
            break;
        } else {break;}
    }
}
    } else {passcount++;}
    //COMPUTER CHECK SYYSTEM
        for(int x = 0; x < boardSize ; x++){
            for(int y = 0; y < boardSize ; y++){
            if(board[x][y] == 'x'){
                int newpoint[2] = {x,y};
                for(int i = 0; i < 8; i ++){
                    newpoint[0] = x, newpoint[1] = y;
                    newpoint[0] = x + differ[i][0];
                    newpoint[1] = y + differ[i][1];
                    int skip = 0;
                    if(newpoint[0]>=boardSize || newpoint[0] <0 || newpoint[1]>=boardSize || newpoint[1] <0 ){
                        continue;
                    }     
                    while(board[newpoint[0]][newpoint[1]] == 'o'){
                        if((newpoint[0] + differ[i][0]) >= boardSize || (newpoint[0] + differ[i][0]) < 0 || (newpoint[1] + differ[i][1]) >= boardSize || (newpoint[1] + differ[i][1]) < 0){
                            break;  
                        }
                        newpoint[1] = newpoint[1] + differ[i][1];
                        newpoint[0] = newpoint[0] + differ[i][0];
                        skip++;
                    }   
                    if(board[newpoint[0]][newpoint[1]] == '.'){
                        if(skip>0){
                        compable[compablen][0] = newpoint[0];
                        compable[compablen][1] = newpoint[1];
                        compable[compablen][2] = skip;
                        compablen++;
                        }
                    }
                }
            }   
        }
    }

    if(compablen > 0){
        passcount = 0;


    //COMPUTER AI
    int bestmovei = 0; int bestmove = 0;
    for(int i = 0; i < compablen; i++){
        if(compable[i][2] > bestmove){
            bestmove = compable[i][2];
            bestmovei = i;
        }
    }

    
    //COMPUTER MOVE
    board[compable[bestmovei][0]][compable[bestmovei][1]] = 'x';

    //COOMPUTER EATING
    int xc = compable[bestmovei][1];
    int yc = compable[bestmovei][0];


    for(int i = 0; i < 8; i++){
    bool willeat = false;
    int place[2];

    place[0] = yc + differ[i][0];
    place[1] = xc + differ[i][1]; 
    while(place[0] < boardSize && place[1] < boardSize && place[0] >= 0 && place[1] >= 0){
        if (board[place[0]][place[1]] == 'o') {
            place[0] = place[0] + differ[i][0];
            place[1] = place[1] + differ[i][1];
            willeat = true;
        } else if(board[place[0]][place[1]] == 'x' && willeat){
            int xi = xc; int yi = yc;
            while(xi != place[1] || yi != place[0]){
                board[yi][xi] = 'x';
                xi = xi+differ[i][1]; yi = yi + differ[i][0];
            }
            break;
        } else {break;}
    }
}
} else{passcount++;}

    if(passcount > 1){
    gamestart = false;
    }
    }

    int userScore = 0;
    int compScore = 0;
    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize; y++) {
            if (board[x][y] == 'o') userScore++;
            if (board[x][y] == 'x') compScore++;
        }
}
    if(userScore > compScore){
        cout << "Win" << endl;
    }else if(userScore < compScore){
        cout << "Lose" << endl;
    } else{cout << "Draw" << endl;}

    cout << "User: " << userScore << endl;
    cout << "Computer: " << compScore << endl;


}

bool islettervalid(char x){
        int num = sizeof(validletters) / sizeof('a');
        for(int i = 0; i < num; i++){
            if(validletters[i] == x){
                return true;
            }
        }
        return false;
    }

int chartonum(char x){
    if(islettervalid(x)){
        for(int i = 0; i <boardSize; i++){
            if(validletters[i]==x){
                return i;
            }
        }
    }
    return -1;
}    
