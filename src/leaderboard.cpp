#include "leaderboard.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

void InitLeaderboard(Leaderboard* leaderboard) {
    leaderboard->scores.clear();
}

void AddScore(Leaderboard* leaderboard, int score) {
    leaderboard->scores.push_back(score);
    std::sort(leaderboard->scores.begin(), leaderboard->scores.end(), std::greater<int>());
    if (leaderboard->scores.size() > 10) {
        leaderboard->scores.pop_back();
    }
}

void DisplayLeaderboard(Leaderboard* leaderboard) {
    std::cout << "Leaderboard:" << std::endl;
    for (size_t i = 0; i < leaderboard->scores.size(); ++i) {
        std::cout << i + 1 << ". " << leaderboard->scores[i] << std::endl;
    }
}

void SaveLeaderboard(Leaderboard* leaderboard, const char* filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (size_t i = 0; i < leaderboard->scores.size(); ++i) {
            file << leaderboard->scores[i] << std::endl;
        }
        file.close();
    }
}

void LoadLeaderboard(Leaderboard* leaderboard, const char* filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        leaderboard->scores.clear();
        int score;
        while (file >> score) {
            leaderboard->scores.push_back(score);
        }
        file.close();
        std::sort(leaderboard->scores.begin(), leaderboard->scores.end(), std::greater<int>());
    }
}
