#include <iostream>
using namespace std;

bool atLeastPresent(string &s, string &sub){
    if (s.size() < 3){
        return false;
    }

    for (auto k : s){
        if (k != '0' && k != '1'){
            return false;
        }
    }
    
    int i = 0;
    int j = 0;

    bool ans = true;

    while (i < s.size() && j < sub.size()){
        if (s[i] != sub[j]){
            j = -1;
            ans = false;
        }
        i++;
        j++;
    }

    if (j == sub.size()){
        ans = true;
    }

    return ans;
}

int main(){

    string sub = "000";
    while (1){
        string s = "";
        cout << "Enter Stirng: ";
        cin >> s;

        cout << "String is: ";
        if (atLeastPresent(s, sub)){
            cout << "Accepted" << endl << endl;
        } else {
            cout << "Rejected" << endl << endl;
        }
    }
}