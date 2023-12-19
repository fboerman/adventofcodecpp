#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int day1() {
    cout << "day1" << endl;
    ifstream stream("/home/frank/CLionProjects/adventofcodecpp/input_files/day1.txt");
    string line;
    int calibration_value = 0;
    while(getline(stream, line)) {
        vector<char> n;
        for(char& c : line){
            if(int(c) >= 48 && int(c) <= 57) {
                if(n.size() < 2) {
                    n.push_back(c);
                } else {
                    n[1] = c;
                }

            }
        }
        if(n.size() == 1){
            n.push_back(n[0]);
        }
        std::cout << string(n.begin(), n.end()) << std::endl;
        calibration_value += atoi(string(n.begin(), n.end()).c_str());
    }

    cout << "The calibration number is " << calibration_value << endl;


    return 0;
}