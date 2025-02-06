#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <vector>

typedef struct Leaderboard {
    std::vector<int> scores;
} Leaderboard;

void InitLeaderboard(Leaderboard* leaderboard);
void AddScore(Leaderboard* leaderboard, int score);
void DisplayLeaderboard(Leaderboard* leaderboard);
void SaveLeaderboard(Leaderboard* leaderboard, const char* filename);
void LoadLeaderboard(Leaderboard* leaderboard, const char* filename);

#endif // LEADERBOARD_H
