#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int day3() {
    cout << "day3" << endl;
    string fname = "/home/frank/CLionProjects/adventofcode/input_files/day3.txt";
    ifstream stream(fname);
    string line;

    auto f_priority = [](char item){
        int item_i = int(item);
        if((item_i >= 97) && (item_i <= 122)) {
            return item_i - 96;
        } else {
            return item_i - 38;
        }
    };

    int sum_priorities = 0;
    while(getline(stream, line)) {
        vector<char> rucksack1 = vector(line.begin(), line.end()-(line.length()/2));
        sort(rucksack1.begin(), rucksack1.end());
        vector<char> rucksack2 = vector(line.begin()+(line.length()/2), line.end());
        sort(rucksack2.begin(), rucksack2.end());
        vector<char> intersections;
        set_intersection(rucksack1.begin(), rucksack1.end(),
                         rucksack2.begin(), rucksack2.end(),
                         back_inserter(intersections));
        sum_priorities += f_priority(intersections[0]);
    }

    cout << "sum of priorities of double items is " << sum_priorities << endl;

    // for part 2 we gonna rescan the whole file because the approach is different
    stream.close();
    stream.open(fname);

    bool stop = false;
    sum_priorities = 0;
    while(true) {
        // groups of three
        vector<vector<char>> rucksacks{};
        for(int i=0;i<3;i++){
            if(!getline(stream, line)){
                stop = true;
                break;
            }
            vector<char> V(line.begin(), line.end());
            sort(V.begin(), V.end());
            rucksacks.push_back(V);
        }
        if(stop){
            break;
        }
        vector<char> intersections, intersections2;
        set_intersection(rucksacks[0].begin(), rucksacks[0].end(),
                         rucksacks[1].begin(), rucksacks[1].end(),
                         back_inserter(intersections));
        sort(intersections.begin(), intersections.end());
        set_intersection(intersections.begin(), intersections.end(),
                         rucksacks[2].begin(), rucksacks[2].end(),
                         back_inserter(intersections2));
        sum_priorities += f_priority(intersections2[0]);
    }

    cout << "sum of priorities for badges is " << sum_priorities << endl;

    return 0;
}