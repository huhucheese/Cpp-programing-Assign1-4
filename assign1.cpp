#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int main(){
    string type;
    int icount = 0, lcount = 0, fcount = 0, dcount = 0;

    while(true){
        cin >> type;

        for(auto& c : type)
            if(60 <= c and c <= 90) c += 32;

        //transform(begin(type), type.end(), type.begin(), [](unsigned char c){ return tolower(c);});//

        if(type == "quit") break;

        if(type == "int") {
            cout << numeric_limits<int>::max() << " " << numeric_limits<int>::min() << endl;
            icount += 1;
        } else if (type == "long") {
            cout << numeric_limits<long>::max() << " " << numeric_limits<long>::min() << endl;
            lcount += 1;
        } else if (type == "float") {
            cout << numeric_limits<float>::max() << " " << numeric_limits<float>::min() << endl;
            fcount += 1;
        } else if (type == "double") {
            cout << numeric_limits<double>::max() << " " << numeric_limits<double>::min() << endl;
            dcount += 1;
        } else {
            cout << "Invalid Command" << endl;
        }
    }
    

    cout << "=== the number of types ===" << endl;
    cout << "int: " << icount << endl;
    cout << "long: " << lcount << endl;
    cout << "float: " << fcount << endl;
    cout << "double: " << dcount << endl;

    return 0;
}
