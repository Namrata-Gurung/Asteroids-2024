#include "HighScore.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include "ScoreKeeper.h"

using namespace std;

HighScore::HighScore(const string& filename)
    : mScoresFile("scores.txt") {
    LoadHighScore();
}

HighScore::~HighScore() {
    SaveHighScore();
}



void HighScore::AddHighScore(int score) {
    mScore.push_back(score);
    SortHighScores();
}

// saving the scores in the file scores.txt
void HighScore::SaveHighScore() {
    ofstream file(mScoresFile);
    if (file.is_open()) {
        for (int score : mScore ) {
            file << score << endl;
        }
        file.close();
    }
}

//Loading scores in the file 
void HighScore::LoadHighScore() {
    ifstream file(mScoresFile);
    if (file.is_open()) {
        int score;
        while (file >> score) {
            mScore.push_back(score);
        }
        file.close();
        SortHighScores();
    }
}

//sorting the scores
void HighScore::SortHighScores() {
    sort(mScore.begin(), mScore.end(), greater<int>());
}

// Return the scores 
const std::vector<int>& HighScore::ListHighScores() const {
    return mScore;
}