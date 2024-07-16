#include <iostream>
using namespace std;

void draw(char board[9]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i * 3 + j];
            if (j < 2) {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}

bool outcome(char board[9], char player){
    for (int i = 0; i < 3; i++) {
        if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) {
            return true;
        }
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true; 
        }
    }
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }
    return false;
}

int main(){
    char board[9]{};
    char player = 'X';
    int turn;
    draw(board);

    while(true){
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> turn;
        
        if (turn < 1 || turn > 9 || board[turn-1] == 'X' || board[turn-1] == 'O') {
            cout << "Invalid" << endl;
            break;
        }

        board[turn-1] = player;

        draw(board);

        if (outcome(board, player)) {
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        bool draw = true;
        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {
                draw = false;
                break;
            }
        }
        if (draw) {
            cout << "It's a draw!" << endl;
            break;
        }

        if (player == 'X'){
            player = 'O';
        }
        else{
            player = 'X';
        }
    }

    return 0;
}
