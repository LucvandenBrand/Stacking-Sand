#include "blockmodel.ih"

Grid BlockModel::generateBlock()
{
  uniform_int_distribution<int> rangeBlocks(0, 3);
  discrete_distribution<unsigned short> rangeCells(d_cellAvailability.begin(), d_cellAvailability.end());

  Grid block(1, 1);
  switch(rangeBlocks(d_randomGenerator))
  {
    case 0: // Line
      block = Grid(1, 3);
      block.cell(Point2D(0,0), rangeCells(d_randomGenerator));
      block.cell(Point2D(0,1), rangeCells(d_randomGenerator));
      block.cell(Point2D(0,2), rangeCells(d_randomGenerator));
      break;
    case 1: // L
      block = Grid(2, 3);
      block.cell(Point2D(0,0), rangeCells(d_randomGenerator));
      block.cell(Point2D(0,1), rangeCells(d_randomGenerator));
      block.cell(Point2D(0,2), rangeCells(d_randomGenerator));
      block.cell(Point2D(1,2), rangeCells(d_randomGenerator));
      break;
    case 2: // Triangle
      block = Grid(3, 2);
      block.cell(Point2D(0,1), rangeCells(d_randomGenerator));
      block.cell(Point2D(1,1), rangeCells(d_randomGenerator));
      block.cell(Point2D(1,0), rangeCells(d_randomGenerator));
      block.cell(Point2D(2,1), rangeCells(d_randomGenerator));
      break;
    case 3: // Square
      block = Grid(2, 2);
      block.cell(Point2D(0,0), rangeCells(d_randomGenerator));
      block.cell(Point2D(1,0), rangeCells(d_randomGenerator));
      block.cell(Point2D(0,1), rangeCells(d_randomGenerator));
      block.cell(Point2D(1,1), rangeCells(d_randomGenerator));
      break;
  }

  return block;
}