#include "point.hpp"
#include <vector>
#include <list>
#include <stdio.h>
#include <algorithm>

using namespace std;

/*Custom points comparer, to be used to sort points
 based on m_t attribute (time), because in data file 
 points could be not sorted */
struct pointCustomComparer
{

    bool operator()(const Point *p1, const Point *p2) const
    {
        return p1->getT() < p2->getT();
    }
};

/*!
   \brief class: Trajectory
 */
class Trajectory
{

public:
    Trajectory();
    /* Add point to trajectory*/
    void addPoint(Point *p);
    /* Display point of a trajectory*/
    void dispPoints();
    /* Display infos of a trajectory (speed, length)*/
    void dispInfos();
    /*Find trajectory by Id*/
    auto findTrjById(int id);
    /*Compute distance, somme of distance between points*/
    double computeLength();
    /*Compute average speed*/
    double computeSpeed();

    /* The attribute should be private,
    and accessed by getters and setters, this is not
    taken in consideration in this implementation*/

    /*List of points, components of a trajectory*/
    list<Point *> m_lisTrajPoints;
    /*custom points comparer*/
    pointCustomComparer pntsCustCmp;
    double m_speed;
    double m_length;
    int m_Id;
};