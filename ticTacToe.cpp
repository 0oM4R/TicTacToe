#include <bits/stdc++.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
char square [10]= {'0', '1','2','3','4','5','6','7','8','9'};
int checkValid(int choice);
int checkwin();
void board();
int main() {
    int player = 1, choice,win;
    char mark;
    do {
        board();
        player=(player % 2 ) ? 1 : 2;
        cout<< "Player number "<<player<<", Select a number: ";
        cin>>choice;
        mark=(player == 1) ? 'X' : 'O';
        int played = checkValid(choice);
        if(played>0){
            square[played]=mark;
        }else{
            cout << "Invalid Input!\n";
            cout << "press Enter to choose a new  number\n";
            player--;
            cin.ignore();
            cin.get();
        }
        win= checkwin();
        player++;
    } while (win==-1);
    board();
    if(win==1){
        cout<<"==>Player "<<--player<<" win ";
        return 0;
    }else {
        cout << "==>\aGame draw";

        return 0;
    }
}
int checkValid(int choice){
    if (choice == 1 && square[1] == '1')
        return 1;
    else if (choice == 2 && square[2] == '2')
        return 2;
    else if (choice == 3 && square[3] == '3')
        return 3;
    else if (choice == 4 && square[4] == '4')
        return 4;
    else if (choice == 5 && square[5] == '5')
        return 5;
    else if (choice == 6 && square[6] == '6')
        return 6;
    else if (choice == 7 && square[7] == '7')
        return 7;
    else if (choice == 8 && square[8] == '8')
        return 8;
    else if (choice == 9 && square[9] == '9')
        return 9;
    else{
        return -1;
    }
}
int checkwin(){
    for(int i=1;i<=7;i+=3){
        if(square[i]==square[i+1] && square[i+1]==square[i+2]) {
            cout<<i;
            return 1;
        }//this statement is for chek the horizontal lines 1,2,3 or 4,5,6 or 7,8,9
    }
    for(int i=1;i<=3;i++){
        if(square[i]==square[i+3] && square[i+3]==square[i+6]) {
            return 1;
        }//this statement is for chek the vertical lines 1,2,3 or 4,5,6 or 7,8,9
        if (square[1] == square[5] && square[5] == square[9]){
            return 1;
        }else if (square[3] == square[5] && square[5] == square[7]) {
            return 1;
        }
        else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                 && square[4] != '4' && square[5] != '5' && square[6] != '6'
                 && square[7] != '7' && square[8] != '8' && square[9] != '9') {
            return 0;
        }else
            return -1;

    }
}
void board()
{
    if (system("CLS")) system("clear");
    //cout << string(50, '\n');
    cout << "\n\tTic Tac Toe\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;


    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}
