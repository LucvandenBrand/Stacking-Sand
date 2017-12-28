#include "tetris.ih"

Tetris::Tetris()
{
  this->d_grid = new Grid(10, 20);
  *(this->d_grid->cell(Point2D(0,0))) = 4;
  *(this->d_grid->cell(Point2D(1,0))) = 4;
  *(this->d_grid->cell(Point2D(2,2))) = 4;
  *(this->d_grid->cell(Point2D(3,0))) = 4;
  *(this->d_grid->cell(Point2D(4,1))) = 4;

  *(this->d_grid->cell(Point2D(5,0))) = 4;
  *(this->d_grid->cell(Point2D(6,3))) = 4;
  *(this->d_grid->cell(Point2D(7,0))) = 4;
  *(this->d_grid->cell(Point2D(8,4))) = 4;
  *(this->d_grid->cell(Point2D(9,0))) = 4;
  this->d_tetrisMachine = new TetrisMachine(this->d_grid);
  this->d_tetrisBlock = new TetrisBlock(this->d_grid);
}
