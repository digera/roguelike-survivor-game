#ifndef SCORING_H
#define SCORING_H

typedef struct Scoring {
    int score;
} Scoring;

void InitScoring(Scoring* scoring);
void UpdateScore(Scoring* scoring, int points);
int GetScore(Scoring* scoring);

#endif // SCORING_H
