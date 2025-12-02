#include <string>
#include <iostream>
#include <set>
#include <cctype>

using namespace std;

int logic(string s1, string s2){
    set<char> test(s1.begin(), s1.end());
    set<char> test2(s2.begin(), s2.end());
    int sum = 0;
    for(char c : test2){
        if(test.find(c) != test.end()){
            if(islower(c)){
                int temp = ((int)c) - 96;
                sum += temp;
                cout << temp << endl;
            } else {
                int temp = ((int)c) - 38;
                sum += temp;
                cout << temp << endl;
            }
        }
    }
    return sum;
}

int main(){
    string line;
    int res = 0;
    while(getline(cin, line) ){
        string token = line.substr(0, line.length()/2);
        line.erase(0, line.length()/2);
        cout << token << "  " << line << endl;
        res += logic(token, line);
    }
    cout << res << endl;
}