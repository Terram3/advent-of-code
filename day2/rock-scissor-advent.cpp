#include <vector>
#include <string>
#include <iostream>

using namespace std;

int compareLogic(string fToken, string sToken){
    int a, b, res;
    if(fToken == "A"){
        a = 1;
    } else if(fToken == "B") {
        a = 2;
    } else {
        a = 3;
    } 

    switch (a)
    {
    case 1:
        if(sToken == "X"){
            res = a + 3;
        } else if(sToken == "Y"){
            res = a;
        } else {
            res = a + 6;
        }
        break;
    case 2:
        if(sToken == "X"){
            res = a + 6;
        } else if(sToken == "Y"){
            res = a + 3;
        } else {
            res = a;
        }
        break;
    case 3:
        if(sToken == "X"){
            res = a;
        } else if(sToken == "Y"){
            res = a + 6;
        } else {
            res = a + 3;
        }
        break;
    }
    return res;
}

int main(){
    string line;
    string space = " ";
    int sum = 0;
    while(getline(cin, line) ){
        auto a = line.find(space);
        string fToken = line.substr(0, a);
        line.erase(0, a + space.length());
        cout << fToken << "    " << line << endl;
        sum += compareLogic(fToken, line);
    }
    cout << sum << endl;
}