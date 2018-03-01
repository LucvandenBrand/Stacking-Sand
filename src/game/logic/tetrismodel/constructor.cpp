#include "tetrismodel.ih"

TetrisModel::TetrisModel() : d_grid(Grid(TETRIS_WIDTH, TETRIS_HEIGHT)),
                             d_score(0),
                             d_timeToWait(DELAY_LEVEL0)
{}
