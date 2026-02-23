
#include <iostream>
#include <regex>
#include <set>

using namespace std;


void analyzeToken(const string& token) {
    set<string> keywords = {"False", "None", "True", "and", "as", "assert", "async",
                            "await", "break", "class", "continue", "def", "del", "elif",
                            "else", "except", "finally", "for", "from", "global", "if", 
                            "include", "in", "is", "lambda", "nonlocal", "not", "or", "pass", 
                            "raise", "return", "try", "while", "with", "yield"};

    // check keyword
    if (keywords.find(token) != keywords.end()) {
        cout << token << " is a Keyword" << endl;
    }

    // check constant
    else if (regex_match(token, regex("^[0-9]+(\\.[0-9]+)?$"))) {
        cout << token << " is a Constant" << endl;
    }

    // check identifier
    // letter/underscore/$, followed by letters/digits/underscores
    else if (regex_match(token, regex("^[a-zA-Z_$][a-zA-Z0-9_$]*$"))) {
        cout << token << " is an Identifier" << endl;
    }

    // Unidentified
    else {
        cout << token << " is Unidentified" << endl;
    }
}

int main() {
    string input = "+ hello in for if else while 9 +9 a$a9 $$$ /* if */ ";
    
    cout << "Input given: " << input << endl << endl;

    if (regex_match(input, regex("//.*"))){
        cout << "Input is a comment";
        return 0;
    }

    string word = "";
    bool inComment = false;

    for (char c : input) {
        if ( inComment && word == "*/" ){
            inComment = false;
            word = "";
        } else if (word == "/*"){
            inComment = true;
            word = "";

        } else if (word == "*/"){
            continue;

        } else if (isspace(c) && !word.empty() && !inComment) {
                analyzeToken(word);
                word = "";
                
        } else if (!isspace(c) && !inComment){
            word += c;
        }

    }

    if (!word.empty() && !inComment){
         analyzeToken(word);
    }

    return 0;
}