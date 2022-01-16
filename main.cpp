//과제 4
#include "shape.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<unique_ptr<Rectangle>> rvec; vector<unique_ptr<Circle>> cvec;

    while(true) {
        string cmd; cin >> cmd;
        transform(begin(cmd), end(cmd), begin(cmd),  [](char& c){return tolower(c);} );
        Command c = getCommand(cmd);

        switch(c){ //RECT, CIRCLE, PRINT, SUM, SORT, CLEAR, QUIT, INVALID
            case RECT:
                rvec.emplace_back(make_rectangle());
                break;

            case CIRCLE:
                cvec.emplace_back(make_circle());
                break;

            case CLEAR:
                rvec.clear(); cvec.clear();
                break;

            case PRINT:
                for_each(rvec.begin(), rvec.end(), [](auto& r){ cout << "Rectangle:\t" << r->width << "\t" << r->height << "\t" << r->area << endl;} );
                for_each(cvec.begin(), cvec.end(), [](auto& c){ cout << "Circle:\t\t" << c->radius << "\t" << c->area << endl;});
                break;

            case SUM: {  //vector 이용한 새 코드
                vector<double> sum;

                for(auto& r : rvec){
                    sum.push_back(r->area);
                }
                for(auto& c : cvec){
                    sum.push_back(c->area);
                }

                cout << accumulate(sum.begin(), sum.end(), 0) << endl;
                break;

            }
            case SORT:
                sort(rvec.begin(), rvec.end(),[](unique_ptr<Rectangle>& first, unique_ptr<Rectangle>& second){ return first->area > second->area; });
                sort(cvec.begin(), cvec.end(), [](unique_ptr<Circle>& first, unique_ptr<Circle>& second){ return first->area > second->area; });
                break;

            case QUIT:
                return 0;

            case INVALID:
                cout << "Invalid Command" << '\n';
                break;
        }
    }
}