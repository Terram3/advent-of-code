#include <string>
#include <iostream>
#include <set>
#include <cctype>

using namespace std;

int logic(string s1, string s2, string s3){
    set<char> test(s1.begin(), s1.end());
    set<char> test2(s2.begin(), s2.end());
    set<char> temp;
    set<char> test3(s3.begin(), s3.end());
    int sum = 0;
    for(char c : test2){
        if(test.find(c) != test.end()){
            temp.insert(c);
        }
    }
    for(char c : temp){
        if(test3.find(c) != test3.end()){
            if(islower(c)){
                int temp = ((int)c) - 96;
                sum += temp;
            } else if(isupper(c)) {
                int temp = ((int)c) - 38;
                sum += temp;
            }
        }
    }
    return sum;
}

/*
    if(islower(c)){
        int temp = ((int)c) - 96;
        sum += temp;
        cout << temp << endl;
    } else {
        int temp = ((int)c) - 38;
        sum += temp;
        cout << temp << endl;
    }
*/

int main(){
    string line, line2, line3;
    int res = 0;
    while(getline(cin, line) ){
        getline(cin, line2);
        getline(cin, line3);
        res += logic(line, line2, line3);
    }
    cout << res << endl;
}