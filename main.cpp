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

int day2() {
    cout << "day2" << endl;
    ifstream stream("/home/frank/CLionProjects/adventofcodecpp/input_files/day2.txt");
    string line;

    int score = 0, score_2 = 0;
    while(getline(stream, line)) {
        istringstream iss(line);
        char opp_c, me_c;
        iss >> opp_c >> me_c;

        int me = int(me_c) - 88;
        int opp = int(opp_c) - 65;

        //vector of winning elements, each element wins of the element next to it
        // CBA
        // formula: f(i) -> (i%n+n)%n
        // A -> i=2, B -> i=1, C -> i=0 then if f(i+1) == opp then win, otherwise loss
        // or turn around ABC with mapping A->0, B -> 1, C->2 then f(i-1) == opp then win otherwise loss
        // in which 0 is rock 1 is paper 2 is scissors

        auto f = [](int i) { return (i%3+3)%3;};
        int wins_from = f(me-1);
        // score for game itself
        if(opp == wins_from){
            //win!
            score += 6;
        } else if (me == opp) {
            //draw
            score += 3;
        }

        // score for playing
        score += me + 1;

        // for part two me_c is actually the result of the round
        // then figure out what to do by using the same trick
        int me2;
        switch(me_c) {
            case 'X':
                // need to lose
                me2 = f(opp-1);
                break;
            case 'Y':
                // need to draw
                me2 = opp;
                score_2 += 3;
                break;
            case 'Z':
                // need to win
                me2 = f(opp+1);
                score_2 += 6;
                break;
        }

        score_2 += me2 + 1;

    }

    cout << "Score: " << score << endl;
    cout << "Score2: " << score_2 << endl;
    return 0;
}

int day3() {
    cout << "day3" << endl;
    ifstream stream("/home/frank/CLionProjects/adventofcodecpp/input_files/day3.txt");
    string line;

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

        int prio = int(intersections[0]);
        if((prio >= 97) && (prio <= 122)) {
            // lower case
            sum_priorities += prio - 96;
        } else {
            // upper case
            sum_priorities += prio - 38;
        }
    }

    cout << "sum of priorities of double items is " << sum_priorities << endl;

    return 0;
}


int main() {
    return day3();
}
