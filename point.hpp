#include <stdio.h>
#include <memory>


/*!
   \brief points : base element of trajectory
 */
class Point
{

public:
  Point(int t, int x, int y);
  /*Compute distance with an other point*/
  double distance(std::shared_ptr<Point> p);

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

private:
  int m_x; /*x component of point*/
  int m_y; /*y component of point*/
  int m_t; /*t component of point (time)*/
};