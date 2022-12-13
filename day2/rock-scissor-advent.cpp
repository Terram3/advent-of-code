#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum choice {X = 1, Y = 2, Z = 3};

int compareLogic(string fToken, string sToken){
    int a;
    char c2 = sToken[0];
    if(c2 == 'X'){
        a = X;
    } else if(c2 == 'Y') {
        a = Y;
    } else {
        a = Z;
    } 

    int res = 0;

    char c = fToken[0];
    switch (a){
        case X: {
            if(c == 'A'){
                res = X + 3;
            } else if(c == 'B'){
                res = X;
            } else {
                res = X + 6;
            }
            break;
        }
        case Y: {
            if(c == 'A'){
                res = Y + 6;
            } else if(c == 'B'){
                res = Y + 3;
            } else {
                res = Y;
            }
            break;
        }
        case Z: {
            if(c == 'A'){
                res = Z;
            } else if(c == 'B'){
                res = Z + 6;
            } else {
                res = Z + 3;
            }
            break;
        }
    }
    return res;
}

int compareLogic2(string fToken, string sToken){
    int a;
    char c = fToken[0];
    char c2 = sToken[0];
    if(c2 == 'X'){
        if(c == 'A'){
            a = Z;
        } else if(c == 'B'){
            a = X;
        } else {
            a = Y;
        }
    } else if(c2 == 'Y') {
        if(c == 'A'){
            a = X;
        } else if(c == 'B'){
            a = Y;
        } else {
            a = Z;
        }
    } else {
        if(c == 'A'){
            a = Y;
        } else if(c == 'B'){
            a = Z;
        } else {
            a = X;
        }
    } 

    int res = 0;

    switch (a){
        case X: {
            if(c == 'A'){
                res = X + 3;
            } else if(c == 'B'){
                res = X;
            } else {
                res = X + 6;
            }
            break;
        }
        case Y: {
            if(c == 'A'){
                res = Y + 6;
            } else if(c == 'B'){
                res = Y + 3;
            } else {
                res = Y;
            }
            break;
        }
        case Z: {
            if(c == 'A'){
                res = Z;
            } else if(c == 'B'){
                res = Z + 6;
            } else {
                res = Z + 3;
            }
            break;
        }
    }
    return res;
}

int main(){
    string line;
    string space = " ";
    int sum = 0, sum1 = 0;
    while(getline(cin, line) ){
        auto a = line.find(space);
        string fToken = line.substr(0, a);
        line.erase(0, a + space.length());
        sum += compareLogic(fToken, line);
        sum1 += compareLogic2(fToken, line);
    }
    cout << sum << endl;
    cout << sum1 << endl;
}
