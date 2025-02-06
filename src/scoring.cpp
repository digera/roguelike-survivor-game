#include "scoring.h"

void InitScoring(Scoring* scoring) {
    scoring->score = 0;
}

void UpdateScore(Scoring* scoring, int points) {
    scoring->score += points;
}

int GetScore(Scoring* scoring) {
    return scoring->score;
}
