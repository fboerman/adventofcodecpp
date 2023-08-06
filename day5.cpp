#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <regex>

using namespace std;

int day5(bool cratemover9001){// false is part A, true is part B
    cout << "day5" << endl;
    string fname = "/home/frank/CLionProjects/adventofcode/input_files/day5.txt";

    ifstream stream(fname);
    string line;
    vector<vector<char>> stacks{};

    while(getline(stream, line)) {
        if(line.length() == 0){
            // we are done parsing the initial stacks
            break;
        }
        for(int i=1; i<line.length();i+=4){
            int c = (int)i/4;
            if(stacks.size() < c+1){
                stacks.emplace_back();
            }
            if((line[i] == ' ') || ((line[i] >= '1') && line[i] <= '9')){
                // either the last line or no crate at this position
                continue;
            }
            vector<char>* L = &(stacks[c]);
            L->insert(L->begin(), line[i]);
        }
    }

    while(getline(stream, line)) {
        if(line.length() == 0){
            continue;
        }

        smatch sm;
        regex_search(line, sm, regex(R"(move ([0-9]+) from ([0-9]+) to ([0-9]+))"));
        int n = stoi(sm[1].str().c_str());
        int i_from = stoi(sm[2].str().c_str())-1;
        int i_to = stoi(sm[3].str().c_str())-1;
        if(!cratemover9001){
            //part A
            for(int i=0; i<n;i++){
                stacks[i_to].push_back(stacks[i_from].back());
                stacks[i_from].pop_back();
            }
        } else {
            //part B
            int N = stacks[i_from].size();
            for(int i=0; i<n;i++){
                stacks[i_to].push_back(stacks[i_from][N-n+i]);
            }
            for(int i=0; i<n;i++){
                stacks[i_from].pop_back();
            }
        }

    }
    cout << "top crates are ";
    for(int i=0;i<stacks.size();i++){
        cout << stacks[i].back();
    }
    cout << endl;

    return 0;
}