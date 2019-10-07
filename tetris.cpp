#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;

class block;
class game;

class block{
    private:
        bool error;
        int shape[4][5];
        int pos_x, pos_y;
        // string type;
    public:
        block(string type = "\0", int pos_x = 0):pos_x(pos_x),pos_y(1) {
            error = false;
            for(int i = 1; i < 4; ++i) {
                shape[i][0] = -1;
            }
            if(type == "T1") {
                shape[0][0] = 1;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = -1;
                shape[2][0] = 1;
                shape[2][1] = -1;
            }
            else if(type == "T2") {
                shape[0][0] = 1;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = 2;
                shape[1][3] = -1;
            }
            else if(type == "T3") {
                shape[0][0] = 0;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = -1;
                shape[2][0] = 0;
                shape[2][1] = -1; 
            }
            else if(type == "T4") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = 2;
                shape[0][3] = -1;
                shape[1][0] = 1;
                shape[1][1] = -1;
            }
            else if(type == "L1") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = 2;
                shape[0][3] = -1;
                shape[1][0] = 0;
                shape[1][1] = -1;
            }
            else if(type == "L2") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = -1;
                shape[1][0] = 1;
                shape[1][1] = -1;
                shape[2][0] = 1;
                shape[2][1] = -1;
            }
            else if(type == "L3") {
                shape[0][0] = 2;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = 2;
                shape[1][3] = -1;
            }
            else if(type == "L4") {
                shape[0][0] = 0;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = -1;
                shape[2][0] = 0;
                shape[2][1] = 1;
                shape[2][2] = -1;
            }
            else if(type == "S1") {
                shape[0][0] = 0;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = -1;
                shape[2][0] = 1;
                shape[2][1] = -1;
            }
            else if(type == "S2") {
                shape[0][0] = 1;
                shape[0][1] = 2;
                shape[0][2] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = -1;
            }
            else if(type == "Z1") {
                shape[0][0] = 1;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = -1;
                shape[2][0] = 0;
                shape[2][1] = -1;
            }
            else if(type == "Z2") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = -1;
                shape[1][0] = 1;
                shape[1][1] = 2;
                shape[1][2] = -1;
            }
            else if(type == "J1") {
                shape[0][0] = 0;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = 2;
                shape[1][3] = -1;
            }
            else if(type == "J2") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = -1;
                shape[1][0] = 0;
                shape[1][1] = -1;
                shape[2][0] = 0;
                shape[2][1] = -1;
                shape[3][0] = 0;
                shape[3][1] = -1;
            }
            else if(type == "J3") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = 2;
                shape[0][3] = -1;
                shape[1][0] = 2;
                shape[1][1] = -1;
            }
            else if(type == "J4") {
                shape[0][0] = 1;
                shape[0][1] = -1;
                shape[1][0] = 1;
                shape[1][1] = -1;
                shape[2][0] = 0;
                shape[2][1] = 1;
                shape[2][2] = -1;
            }
            else if(type == "I1") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = 2;
                shape[0][3] = 3;
                shape[0][4] = -1;
            }
            else if(type == "I2") {
                shape[0][0] = 0;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = -1;
                shape[2][0] = 0;
                shape[2][1] = -1;
                shape[3][0] = 0;
                shape[3][1] = -1;
            }
            else if(type == "O") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = -1;
            }
            else {
                error = true;
            } 

        }
        bool error_check() {
            return error;
        }
        

};

class game {
    private:
    int row, col;
    char** hori;
    int* cal;

    public:
    game(int row = 0, int col = 0):row(row), col(col) {
        hori = new char*[row];
        for(int i = 0; i < row; ++i) {
            hori[i] = new char[col];
            memset(hori[i], '0', col);
        }
        cal = new int[row];
        for(int i = 0; i < row; ++i) {
            cal[i] = 0;
        }
    }
    void fall(string type, int pos) {
        block next(type, pos);
        if(next.error_check()) {
            cout << "Invalid block type\n";
            return;
        }
    }
    void show() {
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                cout << hori[i][j];
        
            }
            cout << endl;
        }
    }
    void eliminate(int row_d) {
        delete hori[row_d];
        for(int i = row_d; i > 0; --i) {
            hori[i] = hori[i - 1];
            cal[i] = cal[i - 1];
        }
        hori[0] = new char[col];
        cal[0] = 0;
        memset(hori[0], '0', col);
    }
    int check_full(int pos) {
        int val = -1;
        for(int i = 0; i < 4; ++i) {
            if(cal[pos - i] == col) {
                eliminate(pos - i);
                val = i;
            }
        }
        return val;
    }
};

int main() {
    int row, col, pos;
    string type;
    
    cin >> row >> col;
    if(row > 40 || col > 15 || row < 1 || col < 1) {
        cout << "Invalid value of row or cloumn\n";
        return 1;
    }
    
    game tetris(row, col);

    while(cin >> type && type != "End") {
        if(!(cin >> pos) || pos < 1) {
            cout << "Invalid operation\n";
            return 1;
        }
        tetris.fall(type, pos);
    }

    return 0;
}