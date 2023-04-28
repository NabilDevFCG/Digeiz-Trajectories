#include <stdio.h>

/*!
   \brief points : base element of trajectory
 */
class Point
{

public:
  Point(int t, int x, int y);
  /*Compute distance with an other point*/
  double distance(Point *p);

  int getT()const
  {
    return m_t;
  }
  int getX()const
  {
    return m_x;
  }
  int getY()const
  {
    return m_y;
  }

  /* The attribute should be private,
  and accessed by getters and setters, this is not
  taken in consideration in this implementation*/
private:
  int m_x;
  int m_y;
  int m_t;
};