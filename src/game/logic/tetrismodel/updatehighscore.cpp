#include "tetrismodel.ih"

void TetrisModel::updateHighScore()
{
  char* basePath = SDL_GetPrefPath(NAME_COMPANY, NAME_PRODUCT);
  if (basePath != nullptr)
  { // We have access to the save location.
    string savePath = string(basePath) + string(NAME_SAVE);
    free(basePath);

    // Load a previous save if it exists.
    ifstream saveInFile(savePath);
    if (saveInFile.good())
      saveInFile >> d_highScore;
    saveInFile.close();

    // Update to highest score.
    d_highScore = max(d_highScore, d_score);

    // Save the highest score.
    ofstream saveOutFile(savePath);
    saveOutFile << d_highScore;
    saveOutFile.close();
  }
  else
    cout << "Could not save the score." << endl;

}