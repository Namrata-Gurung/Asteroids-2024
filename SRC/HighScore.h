#ifndef _HIGHSCORE_H_
#define _HIGHSCORE_H_

#include <vector>
#include <string>

class HighScore 
{

public: 

	HighScore(const std::string &highScores = "scores.txt");
	virtual ~HighScore(void);

	
	// Save high scores to a text file 
	void SaveHighScore();

	// Add a new high score 
	void AddHighScore(int score);

	// Load high scores from a text file 
	void LoadHighScore();

	// List high scores from a vector 
	const std::vector<int>& ListHighScores() const;

private:
	
	//File
	std::string mScoresFile;
	
	//Vector to store high scores
	std::vector<int> mScores;
	
	//sort method declaration
	void SortHighScores();

	// Set a max number of high scores to keep
	const static size_t MAX_HIGH_SCORES = 5;

};


#endif
