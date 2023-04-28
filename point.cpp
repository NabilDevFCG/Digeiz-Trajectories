#include "point.hpp"
#include <cmath>

/*!
   \brief points : base element of trajectory
   \fn Point::Point() : init points attribute
 */
Point::Point(int t, int x, int y)
{
    m_t = t;
    m_x = x;
    m_y = y;
}

/*!
 * \fn Point::distance
   \brief compute distance between two points Point
 * \return the distance between two points
 */
double Point::distance(Point *p)
{

    /*Distnance between 2 points A and B, d(A,B)=√(x2−x1)2+(y2−y1)2*/
    double distance = sqrt((p->m_x - this->m_x) * (p->m_x - this->m_x) + (p->m_y - this->m_y) * (p->m_y - this->m_y));
    return distance;
}
