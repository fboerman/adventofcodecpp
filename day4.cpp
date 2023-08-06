#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <regex>

using namespace std;

int day4() {
    cout << "day4" << endl;
    string fname = "/home/frank/CLionProjects/adventofcode/input_files/day4.txt";
    ifstream stream(fname);
    string line;

    auto f_within = [](int a, int b, int c) {
        //check a <= c <= b
        return (c >= a) && (c <= b);
    };

    int count_fully_contained = 0, count_overlapping = 0;
    while(getline(stream, line)) {
        vector<int> coords;
        smatch sm;

        regex_search(line, sm, regex(R"(([0-9]+)\-([0-9]+)\,([0-9]+)\-([0-9]+))"));
        for(int i=1;i<sm.size();i++){ //skip first because its the whole match
            coords.push_back(std::stoi(sm[i].str().c_str()));
        }

        if(
                f_within(coords[0], coords[1], coords[2]) && f_within(coords[0], coords[1], coords[3]) ||
                f_within(coords[2], coords[3], coords[0]) && f_within(coords[2], coords[3], coords[1])
                ){
            count_fully_contained++;
        }

        if(
                f_within(coords[0], coords[1], coords[2]) || f_within(coords[0], coords[1], coords[3]) ||
                f_within(coords[2], coords[3], coords[0]) || f_within(coords[2], coords[3], coords[1])
                ){
            count_overlapping++;
        }

    }

    cout << count_fully_contained << " pairs fully contained" << endl;
    cout << count_overlapping << " pairs overlapping" << endl;

    return 0;
}