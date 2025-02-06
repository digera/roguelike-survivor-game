#include "progression.h"

void InitProgression(Progression* progression) {
    progression->level = 1;
    progression->experience = 0;
    progression->experienceToNextLevel = 100;
}

void GainExperience(Progression* progression, int amount) {
    progression->experience += amount;
    while (progression->experience >= progression->experienceToNextLevel) {
        progression->experience -= progression->experienceToNextLevel;
        LevelUp(progression);
    }
}

void LevelUp(Progression* progression) {
    progression->level++;
    progression->experienceToNextLevel = 100 * progression->level;
    // Unlock new abilities or content based on the new level
    UnlockContent(progression);
}

void UnlockContent(Progression* progression) {
    // Define the logic for unlocking new content as the player progresses
    // This can include new abilities, items, or game features
    // Example:
    if (progression->level == 2) {
        // Unlock a new ability
    } else if (progression->level == 5) {
        // Unlock a new item
    }
}
