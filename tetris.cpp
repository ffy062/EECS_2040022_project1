#include <iostream>
#include <fstream>
using namespace std;

class game;

int main() {
    int row, col, pos;
    string type;
    
    cin >> row >> col;
    if(row > 40 || col > 15 || row < 1 || col < 1) {
        cout << "Invalid value of row or cloumn\n";
        return 1;
    }
    
    while(cin >> type && type != "End") {
        if(!(cin >> pos)) {
            cout << "Invalid operation\n";
            return 1;
        }
        if(type == "T1") {

        }
        else if(type == "T2") {

        }
        else if(type == "T3") {

        }
        else if(type == "T4") {

        }
        else if(type == "L1") {

        }
        else if(type == "L2") {

        }
        else if(type == "L3") {

        }
        else if(type == "L4") {

        }
        else if(type == "S1") {

        }
        else if(type == "S2") {

        }
        else if(type == "Z1") {

        }
        else if(type == "Z2") {

        }
        else if(type == "J1") {

        }
        else if(type == "J2") {

        }
        else if(type == "J3") {

        }
        else if(type == "J4") {

        }
        else if(type == "I1") {

        }
        else if(type == "I2") {

        }
        else if(type == "O") {

        }
        else {
            cout << "Invalid operation\n"
            continue;
        } 
    }

    return 0;
}

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
            for(int j = 0; j < col; ++j) {
                hori[i][j] = '0';
            }
        }
        cal = new int[row];
        for(int i = 0; i < row; ++i) {
            cal[i] = 0;
        }
    }

};