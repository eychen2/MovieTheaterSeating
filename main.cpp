#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include<unordered_map>
#include<map>

int numSeats = 200;
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("You have not entered the right amount of parameters\n");
        return 0;
    }
    ifstream input;
    input.open(argv[1]);
    string cheese;
    ofstream output;
    output.open("C:\\Users\\echen\\Downloads\\OptimalSeatings.txt");
    unordered_map<char, int> layout;
    char bestRow = 'A';
    while (bestRow != 'K') {
        layout[bestRow] = 0;
        ++bestRow;
    }
    bestRow--;
    int reserve;
    bool sat = false;
    bool canSit=true;
    while (bestRow >= 'A' && getline(input, cheese)) {
        string reservationNumber = cheese.substr(0, cheese.find(' '));
        int reserve = stoi(cheese.substr(cheese.find(' ') + 1, cheese.length()));
        string seatsReserved;
        if (reserve > numSeats)
            canSit=false;
        if (reserve == -1)
            break;
        for (char c = bestRow; c >= 'A'&&canSit; --c) {
            if (20 - layout[c] - reserve >= 0) {
                sat = true;
                for (unsigned int i = 0; i < reserve && layout[c] + i <= 20; ++i)
                    seatsReserved += c + to_string(layout[c] + i+1) + ", ";
                layout[c] += reserve + 3;
                if (layout[c] > 20)
                    numSeats -= 20;
                else
                    numSeats -= reserve + 3;
                break;
            }
        }
        if (layout[bestRow] >= 20)
            bestRow--;
        if (!sat&&canSit) {
            for (char c = bestRow; c >= 'A'; --c) {
                while (layout[c] < 20) {
                    if (reserve == 0) {
                        layout[c] += 3;
                        if (layout[c] > 20)
                            numSeats -= 23 - layout[c];
                        else
                            numSeats -= 3;
                        if (layout[bestRow] >= 20)
                            bestRow--;
                        break;
                    }
                    --reserve;
                    --numSeats;
                    seatsReserved += c + to_string(layout[c]+1) + ", ";
                    ++layout[c];
                }
                if (layout[bestRow] >= 20)
                    bestRow--;
                if (reserve <= 0)
                    break;
            }
        }
        sat = false;
        if(canSit)
            output << reservationNumber << " " << seatsReserved.substr(0, seatsReserved.length() - 2) << "\n";
        else
            output<<reservationNumber<<" Not enough seats"<<"\n";
        canSit=true;
    }
    output.close();
    printf("C:\\Users\\echen\\Downloads\\OptimalSeatings.txt");
}
