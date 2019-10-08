#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;

#define debug

class block;
class game;

class block{
    friend game;
    private:
        bool error;
        int shape[4][5];
        int pos_x, pos_y, len;
        // string type;
    public:
        block(string type = "\0", int pos_x = 0):pos_x(pos_x-1),pos_y(1) {
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
                len = 3;
            }
            else if(type == "T2") {
                shape[0][0] = 1;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = 2;
                shape[1][3] = -1;
                len = 2;
            }
            else if(type == "T3") {
                shape[0][0] = 0;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = -1;
                shape[2][0] = 0;
                shape[2][1] = -1;
                len = 3;
            }
            else if(type == "T4") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = 2;
                shape[0][3] = -1;
                shape[1][0] = 1;
                shape[1][1] = -1;
                len = 2;
            }
            else if(type == "L1") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = 2;
                shape[0][3] = -1;
                shape[1][0] = 0;
                shape[1][1] = -1;
                len = 2;
            }
            else if(type == "L2") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = -1;
                shape[1][0] = 1;
                shape[1][1] = -1;
                shape[2][0] = 1;
                shape[2][1] = -1;
                len = 3;
            }
            else if(type == "L3") {
                shape[0][0] = 2;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = 2;
                shape[1][3] = -1;
                len = 2;
            }
            else if(type == "L4") {
                shape[0][0] = 0;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = -1;
                shape[2][0] = 0;
                shape[2][1] = 1;
                shape[2][2] = -1;
                len = 3;
            }
            else if(type == "S1") {
                shape[0][0] = 0;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = -1;
                shape[2][0] = 1;
                shape[2][1] = -1;
                len = 3;
            }
            else if(type == "S2") {
                shape[0][0] = 1;
                shape[0][1] = 2;
                shape[0][2] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = -1;
                len = 2;
            }
            else if(type == "Z1") {
                shape[0][0] = 1;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = -1;
                shape[2][0] = 0;
                shape[2][1] = -1;
                len = 3;
            }
            else if(type == "Z2") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = -1;
                shape[1][0] = 1;
                shape[1][1] = 2;
                shape[1][2] = -1;
                len = 2;
            }
            else if(type == "J1") {
                shape[0][0] = 0;
                shape[0][1] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = 2;
                shape[1][3] = -1;
                len = 2;
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
                len = 3;
            }
            else if(type == "J3") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = 2;
                shape[0][3] = -1;
                shape[1][0] = 2;
                shape[1][1] = -1;
                len = 2;
            }
            else if(type == "J4") {
                shape[0][0] = 1;
                shape[0][1] = -1;
                shape[1][0] = 1;
                shape[1][1] = -1;
                shape[2][0] = 0;
                shape[2][1] = 1;
                shape[2][2] = -1;
                len = 3;
            }
            else if(type == "I1") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = 2;
                shape[0][3] = 3;
                shape[0][4] = -1;
                len = 1;
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
                len = 4;
            }
            else if(type == "O") {
                shape[0][0] = 0;
                shape[0][1] = 1;
                shape[0][2] = -1;
                shape[1][0] = 0;
                shape[1][1] = 1;
                shape[1][2] = -1;
                len = 2;
            }
            else {
                error = true;
            }

        }
        bool error_check() {
            return error;
        }
        bool check_empty() {
            for(int i = 0; i < 4; ++i) {
                if(shape[i][0] != -1) {
                    return false;
                }
            }
            return true;
        }
        bool check_empty(int idx) {
            return shape[idx][0] == -1 ? true : false;
        }
        void pop(int idx) {
            for(int i = 0; i < 4; ++i) {
                shape[idx][i] = shape[idx][i + 1];
            }
            shape[idx][4] = -1;
            return;
        }
};

class game {
    private:
    int row, col;
    char** hori;
    int* cal, *height;

    public:
    game(int row = 0, int col = 0):row(row), col(col) {
        int i;

        hori = new char*[row];
        for(i = 0; i < row; ++i) {
            hori[i] = new char[col];
            memset(hori[i], '0', col * sizeof(char));
        }
        cal = new int[row];
        for(i = 0; i < row; ++i) {
            cal[i] = 0;
        }
        height = new int[col];
        for(i = 0; i < col; ++i) {
            height[i] = row - 1;
        }
    }
    int fall(block& next, int pos) {
        int touch =  row, tmp;

        for(int i = 0; i < 4; ++i) {
            if(next.shape[i][0] != -1) {
                tmp = height[next.pos_x + i] + next.shape[i][0];
                if(touch > tmp) {
                    touch = tmp;
                    #ifdef debug
                        cout << "change touch:" << touch << endl;
                    #endif // debug
                }
            }
        }
        next.pos_y = touch;
        for(int i = 0; i < 4; ++i) {
            int j = 0;
            while(next.shape[i][j] != -1) {
                hori[next.pos_y - next.shape[i][j]][next.pos_x + i] = '1';
                #ifdef debug
                    cout << "new block " <<next.pos_y - next.shape[i][j]  << " " << next.pos_x + i << endl;
                #endif // debug
                cal[next.pos_y - next.shape[i][j]]++;
                height[next.pos_x + i] = next.pos_y - next.shape[i][j] - 1;
                j++;
            }
        }
        return next.pos_y;

    }
    void show() {
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                cout << hori[i][j];
            }
            cout << endl;
        }
        #ifdef debug
            for(int i = 0; i < row; ++i) {
                cout << cal[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < col; ++i) {
                cout << height[i] << " ";
            }
            cout << endl;
        #endif // debug
    }
    void eliminate(int row_d) {
        int i;
        #ifdef debug
            cout << "delete row" << row_d << endl;
        #endif // debug
        delete hori[row_d];

        for(i = row_d; i > 0; --i) {
            hori[i] = hori[i - 1];
            cal[i] = cal[i - 1];
        }
        hori[0] = new char[col];
        cal[0] = 0;
        memset(hori[0], '0', col);
        for(i = 0; i < col; ++i) {
            if(height[i] <= row_d) {
                height[i]++;
            }

        }
    }
    void check_full(int pos) {
        #ifdef debug
            cout << "check full start position: " << pos << endl;
        #endif // debug
        for(int i = 0, j = 0; i < 4; ++i, ++j) {
            #ifdef debug
                cout << "position: " << pos - j << " number: " << cal[pos - j] << endl;
            #endif // debug
            if(cal[pos - j] == col) {
                eliminate(pos - j);
                --j;
            }
        }
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    int row, col, pos, stop;
    string type;
    ifstream myfile;
    myfile.open("tetris.data.txt");

    myfile >> row >> col;
    if(row > 40 || col > 15 || row < 1 || col < 1) {
        cout << "Invalid value of row or cloumn\n";
        return 1;
    }

    game tetris(row, col);
    #ifdef debug
        tetris.show();
    #endif // debug

    while(myfile >> type && type != "End") {
        if(!(myfile >> pos) || pos < 1) {
            cout << "Invalid operation\n";
            return 1;
        }
        #ifdef debug
            cout << type << " " << pos << endl;
        #endif // debug
        block next(type, pos);
        if(next.error_check()) {
            cout << "Invalid block type\n";
            return 1;
        }
        stop = tetris.fall(next, pos);
        tetris.check_full(stop);
        #ifdef debug
            tetris.show();
        #endif // debug
    }
    myfile.close();

    return 0;
}
