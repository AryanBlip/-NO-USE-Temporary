#include <iostream>
using namespace std;

void myCode(){
    string num;
    cout << "Enter num: ";
    cin >> num;

    int state = 0;
    int finalState = 0;

    for (char digit : num){

        if (state == 0){
            if (digit == '1' || digit == '4' || digit == '7'){
                state = 1;
            } else if (digit == '2' || digit == '5' || digit == '8'){
                state = 2;
            }
        } else if (state == 1){
            if (digit == '1' || digit == '4' || digit == '7'){
                state = 2;
            } else if (digit == '2' || digit == '5' || digit == '8'){
                state = 0;
            }
        } else {
            if (digit == '1' || digit == '4' || digit == '7'){
                state = 0;
            } else if (digit == '2' || digit == '5' || digit == '8'){
                state = 1;
            }
        }

    }

    if (state == finalState){
        cout << "Accepted" << endl << endl;
    } else {
        cout << "Rejected" << endl << endl;
    }
}

int main(){
    while (1){
        myCode();
    }
}