#ifndef PROGRESSION_H
#define PROGRESSION_H

typedef struct Progression {
    int level;
    int experience;
    int experienceToNextLevel;
} Progression;

void InitProgression(Progression* progression);
void GainExperience(Progression* progression, int amount);
void LevelUp(Progression* progression);
void UnlockContent(Progression* progression);

#endif // PROGRESSION_H
