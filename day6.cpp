#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int day6(int N){
    // part A: N=4
    // part B: N=14
    cout << "day6" << endl;
    string fname = "/home/frank/CLionProjects/adventofcode/input_files/day6.txt";

    ifstream datastream(fname);

    string packet_so_far;
    int pos = 0;
    while(datastream.good()) {
        char symbol = datastream.get();
        pos++;
        int i = packet_so_far.find(symbol);
        if (i != string::npos) {
            //remove in string up until the symbol after the offending one
            packet_so_far = packet_so_far.substr(i+1, packet_so_far.length());
        }
        // add symbol to packet
        packet_so_far += symbol;

        if(packet_so_far.length() == N) {
            // we found our marker!
            cout << "marker is " << packet_so_far << " at location " << pos << endl;
            break;
        }
    }


    return 0;
}