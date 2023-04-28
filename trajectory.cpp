#include "trajectory.hpp"
#include <limits>

Trajectory::Trajectory()
{
}

void Trajectory::addPoint(Point *p)
{
    m_lisTrajPoints.insert(m_lisTrajPoints.begin(), p);
}

/*!
 * \fn  Trajectory::dispPoints
   \brief points of a trajectory : limited to 5 points
 */
void Trajectory::dispPoints()
{
    int counter = 0;
    for (const Point *p : m_lisTrajPoints)
    {

        printf("(%d,%d,%d) ", p->m_t, p->m_x, p->m_y);
        counter++;
        /*Display only the 5 first points*/
        if (counter > 5)
        {
            printf(" ... ");
            break;
        }
    }
    printf("\n");
}

/*!
 * \fn  Trajectory::dispInfos
   \brief display infos of trajectory : speed, length
 */
void Trajectory::dispInfos()
{
    printf("Trajectory :Id %d :spd %lf: lng %lf  ", m_Id, m_speed, m_length);
}

/*!
 * \fn Trajectory::computeLength
   \brief compute the length of the trahectory
 * \return the trajectory's length
 */
double Trajectory::computeLength()
{

    auto startP = m_lisTrajPoints.begin();
    for (auto it = m_lisTrajPoints.begin(); it != m_lisTrajPoints.end(); ++it)
    {
        m_length += (*it)->distance(*startP);
        startP = it;
    }
    return m_length;
}

/*!
 * \fn Trajectory::computeSpeed
   \brief compute average speed of a trajectory
 * \return the trahectory's average speed
 */
double Trajectory::computeSpeed()
{
    auto startP = m_lisTrajPoints.begin();
    auto endP = m_lisTrajPoints.end();
    endP--;

    int startTime = (*startP)->m_t;
    int endTime = (*endP)->m_t;

    if ((endTime - startTime) > 0)
    {
        m_speed = m_length / (endTime - startTime);
    }
    else
    {
        m_speed = std::numeric_limits<double>::infinity();
    }

    return m_speed;
}