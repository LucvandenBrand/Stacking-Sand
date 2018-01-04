#include "painter.ih"

void Painter::paintGrid(Grid currentGrid, unsigned short cellSize)
{
  this->paintGrid(currentGrid, cellSize, Point2D(0, 0));
}
