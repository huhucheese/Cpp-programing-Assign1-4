#include <iostream>
#include <map>
#include <regex>

using namespace std;

int main(){
    string str, cmd;
    map<string, int> words;

    while (cin >> str && str != "^"){
        str = regex_replace(str, regex("[.|,|:|;]"), "");
        auto search = words.find(str);
        if ( search != words.end() ) words[str]++;
        else words.insert({str, 1});
    }

    cout << "words: " << words.size() << endl;

    while (true){
        cin >> cmd;
        if(cmd == "QUIT") {
            cout << "Bye!" << endl;
            break;
        } else {
            auto search = words.find(cmd);
            if ( search != words.end() )
                cout << search -> first << ": " << search ->second << endl;
            else cout << "No result." << endl;
        }
    }

    return 0;
}