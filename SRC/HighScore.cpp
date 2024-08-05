#include "HighScore.h"
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

HighScore::HighScore(const string& filename)
    : mScoresFile("scores.txt") {
    LoadHighScore();
}

HighScore::~HighScore() {
    SaveHighScore();
}



void HighScore::AddHighScore(int score) {
    mScores.push_back(score);
    SortHighScores();
}

// saving the scores in the file scores.txt
void HighScore::SaveHighScore() {
    ofstream file(mScoresFile);
    if (file.is_open()) {
        for (int score : mScores) {
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
            mScores.push_back(score);
        }
        file.close();
        SortHighScores();
    }
}

//sorting the scores
void HighScore::SortHighScores() {
    sort(mScores.begin(), mScores.end(), greater<int>());
}

// Return the scores 
const std::vector<int>& HighScore::ListHighScores() const {
    return mScores;
}
