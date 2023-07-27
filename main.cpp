#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <arrow/api.h>
#include <vector>

using namespace std;

int day1() {
    cout << "day1" << endl;
    ifstream stream("/home/frank/CLionProjects/adventofcode/input_files/day1.txt");
    string line;
    vector<int> elves = {};

    int max_calories = 0;
    int current_calories = 0;
    while(getline(stream, line)) {
        if(!line.empty()) {
            istringstream iss(line);
            int calories;
            iss >> calories;
            current_calories += calories;
        } else {
            if(current_calories>max_calories){
                max_calories = current_calories;
            }
            elves.push_back(current_calories);
            current_calories = 0;
        }
    }

    cout << "maximum calories is " << max_calories << endl;

    sort(elves.begin(), elves.end(), greater<int>());
    cout << "sum of top 3 is " << reduce(elves.begin(), elves.begin() + 3) << endl;


    return 0;
}


int main() {
    return day1();
}
