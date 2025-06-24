#include <string>
#include <iostream>
#include <vector>

using namespace std;

int fullOverlaps(vector<int> firstList, vector<int> secList){
    if(firstList[0] <= secList[0] && firstList[1] >= secList[1]){
        return 1;
    } else if(firstList[0] >= secList[0] && firstList[1] <= secList[1]){
        return 1;
    }
    return 0;
}

vector<int> createListFromString(string list){
    string delim = "-";
    int split = list.find(delim);
    int first = stoi(list.substr(0, split));
    int second = stoi(list.substr(split+1, list.length()));
    vector<int> vec;
    vec.push_back(first);
    vec.push_back(second);
    return vec;
}

int main(){
    string line;
    string delim = ",";
    int res = 0;
    while(getline(cin, line)){
        int delimSpot = line.find(delim);
        string firstList = line.substr(0, delimSpot);
        string secList = line.substr(delimSpot+1, line.length());
        vector<int> first = createListFromString(firstList);
        vector<int> second = createListFromString(secList);
        res += fullOverlaps(first, second);
    }
    printf("Result: %d\n", res);
    return 1;
}