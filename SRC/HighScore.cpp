#include "BoundingSphere.h"
#include "GUILabel.h"
#include "Explosion.h"
#include "HighScore.h"

// PUBLIC INSTANCE CONSTRUCTORS ///////////////////////////////////////////////

/** Constructor. Takes arguments from command line, just in case. */
Asteroids::Asteroids(int argc, char* argv[])
	: GameSession(argc, argv)
	Asteroids::Asteroids(int argc, char* argv[])
	: GameSession(argc, argv), mHighScore("scores.txt")
{
	mLevel = 0;
	mAsteroidCount = 0;


	@@ - 279, 6 + 280, 20 @@ void Asteroids::CreateGUI()
		shared_ptr<GUIComponent> start_msg_component
		= static_pointer_cast<GUIComponent>(mStartMsgLabel);
	mGameDisplay->GetContainer()->AddComponent(start_msg_component, GLVector2f(0.5f, 0.4f));

	// high score label
	// Create a new GUILabel and wrap it up in a shared_ptr
	mHighScoreLabel = shared_ptr<GUILabel>(new GUILabel(""));
	// Set the horizontal alignment of the label to GUI_HALIGN_CENTER
	mHighScoreLabel->SetHorizontalAlignment(GUIComponent::GUI_HALIGN_CENTER);
	// Set the vertical alignment of the label to GUI_VALIGN_MIDDLE
	mHighScoreLabel->SetVerticalAlignment(GUIComponent::GUI_VALIGN_MIDDLE);
	// Set the visibility of the label to false (hidden)
	mHighScoreLabel->SetVisible(false);
	// Add the GUILabel to the GUIContainer  
	shared_ptr<GUIComponent> high_score_component
		= static_pointer_cast<GUIComponent>(mHighScoreLabel);
	mGameDisplay->GetContainer()->AddComponent(high_score_component, GLVector2f(0.5f, 0.5f));
}

void Asteroids::OnScoreChanged(int score)

@@ - 289, 6 + 304, 9 @@ void Asteroids::OnScoreChanged(int score)
// Get the score message as a string
std::string score_msg = msg_stream.str();
mScoreLabel->SetText(score_msg);

//update the scores text file
mHighScore.AddHighScore(score);
}

void Asteroids::OnPlayerKilled(int lives_left)

@@ - 312, 6 + 330, 9 @@ void Asteroids::OnPlayerKilled(int lives_left)
	else
	{
		SetTimer(500, SHOW_GAME_OVER);
		//the high score methods 
		updateHighScore();
		displayHighScore();
	}
}


@@ - 327, 4 + 348, 21 @@ shared_ptr<GameObject> Asteroids::CreateExplosion()
return explosion;
}

// score table methods 
// score table methods 

void Asteroids::updateHighScore() {
	int currentScore = mScoreKeeper.GetScore();
	mHighScore.AddHighScore(currentScore);
	mHighScore.SaveHighScore();
}

void Asteroids::displayHighScore() {
	const auto& scores = mHighScore.ListHighScores();
	std::ostringstream hs_stream;
	hs_stream << "High Scores: \n";
	for (auto score : scores) {
		hs_stream << score << "\n";
	}
	mHighScoreLabel->SetText(hs_stream.str());
	mHighScoreLabel->SetVisible(true);
}