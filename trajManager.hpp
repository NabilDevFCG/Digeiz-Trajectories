#include "trajectory.hpp"
#include <list>
#include <string>


/*
 Class TrajManager
*/
class TrajManager
{

public:

  TrajManager ();
  ~TrajManager();
  
  void constructTrajectories(std::string Path);

  void addTrajectory(std::shared_ptr<Trajectory> trj);
  double diffLengthTrajectory(Trajectory *trj1, Trajectory *trj2);
  double diffSpeedTrajectory(Trajectory *trj1, Trajectory *trj2);


/* The attribute should be private,
and accessed by getters and setters, this is not
taken in consideration in this implementation*/

  /*Find trajectory by Id*/
  list<std::shared_ptr<Trajectory>>::iterator  findTrjById(int id,  int criteria);

  /*Find n closest length trajectories to a given trajectory*/
  list<std::shared_ptr<Trajectory>> findNClosestLengthTraj(int id, int n);
 /*Find n closest speed trajectories to a given trajectory*/
  list<std::shared_ptr<Trajectory>> findNClosestSpeedTraj(int id, int n);

  /*List of trajectories, 
  We could have used set to have 
  trajectories already sorted by length but
  we could have more than one Trajectory ith same length*/
  list <std::shared_ptr<Trajectory>> m_listTrajs;
  list <std::shared_ptr<Trajectory>> m_listTrajsSpeedSorted;

    
};