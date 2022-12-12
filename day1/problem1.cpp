#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int sumOfVector(vector<int> v){
    int sum = 0;
    for(int value : v){
        sum += value;
    }
    return sum;
}

int main(){
    int i = 0;
    string val;
    vector<int> v;
    map<int, vector<int>> map;
    map[0] = v;
    while(getline(cin, val)){
        if(val.length() == 1){
            i++;
            vector<int> s;
            map[i] = s;
        } else {
            map[i].push_back(stoi(val));
        }
    }

    int result = 0;
    for(int j = 0; j < i; j++){
        int temp = sumOfVector(map[j]);
        if(temp > result){
            result = temp;
        }
    }

    cout << result << endl;
}