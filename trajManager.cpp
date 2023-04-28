#include "trajManager.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <list>


using namespace std;

/*Custom comparer to order Trajectories int
set based on m_length  attribute*/
struct TrajcustomLengthComparer
{

  bool operator()(const std::shared_ptr<Trajectory> tjr1, const std::shared_ptr<Trajectory> tjr2) const
  {
    return tjr1->m_length < tjr2->m_length;
  }
};

/*Custom comparer to order Trajectories int
set based on m_length  attribute*/
struct TrajcustomSpeedComparer
{

  bool operator()(const std::shared_ptr<Trajectory> tjr1, const std::shared_ptr<Trajectory> tjr2) const
  {
    return tjr1->m_speed < tjr2->m_speed;
  }
};

TrajManager::TrajManager()
{
}

TrajManager::~TrajManager()
{

  /*Freeing memory*/
  /*For all trajectories*/
  // for (auto it = m_listTrajs.begin(); it != m_listTrajs.end(); ++it)
  // {

    /*For all pointes in trajectory*/
    // for (auto ip = (*it)->getTrajectoryPoints().begin(); ip != (*it)->getTrajectoryPoints().end(); ip++)
    // {
    //   delete *ip;
    // }
    // delete *it;
  // }
}



/*!
 * \fn TrajManager::addTrajectory
   \brief add trajectory to trajectories list
   \param trj : trajectory to be added
 */
void TrajManager::addTrajectory(std::shared_ptr<Trajectory> trj)
{
  m_listTrajs.insert(m_listTrajs.begin(), trj);
}


/*!
 * \fn TrajManager::findTrjById
   \brief Find trajectory by Id
   \param Id : trajectory's Id
   \param criteria : criteria (speed, length)
   \return the ieterator index of found trajectory
 */
list<std::shared_ptr<Trajectory>>::iterator TrajManager::findTrjById(int id, int criteria)
{

  list<std::shared_ptr<Trajectory>>::iterator it;
  switch (criteria)
  {
  case 1:
    /* trajectory length based research*/
    it = find_if(m_listTrajs.begin(), m_listTrajs.end(),
                 [&](std::shared_ptr<Trajectory> const &p)
                 { return p->m_Id == id; });
    break;
  case 2:
    /* trajectory speed based research*/
    it = find_if(m_listTrajsSpeedSorted.begin(), m_listTrajsSpeedSorted.end(),
                 [&](std::shared_ptr<Trajectory> const &p)
                 { return p->m_Id == id; });
    break;

  default:
    break;
  }

  return it;
}

/*!
 * \fn TrajManager::findNClosestSpeedTraj
   \brief find n closest trajectories based on length
   \param Id : trajectory's Id
   \param n : number of closest trajectories
   \return list of n closest traectories based on length
 */
list<std::shared_ptr<Trajectory>> TrajManager::findNClosestLengthTraj(int id, int n)
{

  list<std::shared_ptr<Trajectory>>::iterator it = findTrjById(id, 1);
  list<std::shared_ptr<Trajectory>>::iterator itNext = next(it, 1);
  list<std::shared_ptr<Trajectory>>::iterator itPriv = prev(it, 1);

  list<std::shared_ptr<Trajectory>> n2ClosestTrajId;
  list<std::shared_ptr<Trajectory>> nClosestTrajId;

  for (int i = 0; i < n; i++)
  {

    if (itNext != m_listTrajs.end() )
    {
      n2ClosestTrajId.insert(n2ClosestTrajId.begin(), (*itNext));
      itNext = next(itNext, 1);
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (itPriv != m_listTrajs.end() )
    {
      n2ClosestTrajId.insert(n2ClosestTrajId.begin(), (*itPriv));
      itPriv = prev(itPriv, 1);
    }
  }

  double len = (*it)->m_length;
  /*Find the n closest trajectories*/
  for (int i = 0; i < n; i++)
  {
    auto closest_it = std::min_element(n2ClosestTrajId.begin(), n2ClosestTrajId.end(), [&](std::shared_ptr<Trajectory> a, std::shared_ptr<Trajectory> b)
                                       { return std::abs(a->m_length - len) < std::abs(b->m_length - len); });

    if(closest_it != n2ClosestTrajId.end() )
    {
        nClosestTrajId.insert(nClosestTrajId.begin(), (*closest_it));
        /*Erase the found trajctory*/
        n2ClosestTrajId.erase(closest_it);
    }

  }

  return nClosestTrajId;
}


/*!
 * \fn TrajManager::findNClosestSpeedTraj
   \brief find n closest trajectories based on speed
   \param Id : trajectory's Id
   \param n : number of closest trajectories
   \return list of n closest traectories based on speed
 */
list<std::shared_ptr<Trajectory>> TrajManager::findNClosestSpeedTraj(int id, int n)
{
    
  list<std::shared_ptr<Trajectory>>::iterator it = findTrjById(id, 2);
  list<std::shared_ptr<Trajectory>>::iterator itNext = next(it, 1);
  list<std::shared_ptr<Trajectory>>::iterator itPriv = prev(it, 1);

  list<std::shared_ptr<Trajectory>> n2ClosestTrajId;
  list<std::shared_ptr<Trajectory>> nClosestTrajId;

  for (int i = 0; i < n; i++)
  {

    if (itNext != m_listTrajsSpeedSorted.end() )
    {
      n2ClosestTrajId.insert(n2ClosestTrajId.begin(), (*itNext));
      itNext = next(itNext, 1);
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (itPriv != m_listTrajsSpeedSorted.end() )
    {
      n2ClosestTrajId.insert(n2ClosestTrajId.begin(), (*itPriv));
      itPriv = prev(itPriv, 1);
    }
  }

  double spd = (*it)->m_speed;
  /*Find the n closest trajectories*/
  for (int i = 0; i < n; i++)
  {
    auto closest_it = std::min_element(n2ClosestTrajId.begin(), n2ClosestTrajId.end(), [&](std::shared_ptr<Trajectory> a, std::shared_ptr<Trajectory> b)
                                       { return std::abs(a->m_speed - spd) < std::abs(b->m_speed - spd); });

    if(closest_it != n2ClosestTrajId.end() )
    {
        nClosestTrajId.insert(nClosestTrajId.begin(), (*closest_it));
        /*Erase the found trajctory*/
        n2ClosestTrajId.erase(closest_it);
    }

  }

  return nClosestTrajId;
    
}



/*!
 * \fn TrajManager::constructTrajectories
   \brief construct trajectories from a data file
   \param path : path to the data file 
 */
void TrajManager::constructTrajectories(std::string Path)
{

  /* This part is for parsing the data file and constructing trajectories.
  this could have been done in an other class for genericity.
  The file is parsed in one shoot, it could be a problem if the file is very
  huge, in this implementation, we don't consider this problem since the file size is limited
  */
  std::ifstream file(Path);
  std::string line;

  int inbreOfTrajectories;
  int inbrOfPnt;
  int itime;
  int ix;
  int iy;

  /*Open file and read the line,
  if multuple line, this should be adapted*/
  if (file.is_open())
  {

    std::getline(file, line);
    file.close();
  }

  std::stringstream stream(line);

  stream >> inbreOfTrajectories;
  //   printf("nbre of traj %d\n", inbreOfTrajectories);
  for (int inbrOfTraj = 0; inbrOfTraj < inbreOfTrajectories; inbrOfTraj++)
  {
    /*number of points in trajectory*/
    stream >> inbrOfPnt;

    std::shared_ptr<Trajectory> trj = std::shared_ptr<Trajectory>(new Trajectory());
    for (int inbreOfPnt = 0; inbreOfPnt < inbrOfPnt; inbreOfPnt++)
    {
      stream >> itime;
      stream >> ix;
      stream >> iy;

      // trj->addPoint(new Point(itime, ix, iy));
      trj->addPoint(std::shared_ptr<Point>(new Point(itime, ix, iy)));

      
    }
    /* Sotring point in trajectory based on time (m_t attribute) */
    trj->getTrajectoryPoints().sort(trj->pntsCustCmp);
    trj->m_Id = inbrOfTraj;

    trj->computeLength();

    trj->computeSpeed();

    /*Add trajectory to TrajManager*/
    this->addTrajectory(trj);
  }

  /*Sort trajectories based on length*/
  TrajcustomLengthComparer cpr;
  this->m_listTrajs.sort(cpr);

  /*Copy list of trajectories to a new list and sort it based on speed*/
  std::copy(m_listTrajs.begin(), m_listTrajs.end(), std::back_inserter(m_listTrajsSpeedSorted));

  /*Sort trajectories based on speed*/
  TrajcustomSpeedComparer cprSpeed;
  this->m_listTrajsSpeedSorted.sort(cprSpeed);
}


/*!
 * \fn TrajManager::diffLengthTrajectory
   \brief compute length difference between two trajectories
   \param trj1 : trajectory 1
   \param trj2 : trajectory 2
   \return length difference between two trajectories
 */
double TrajManager::diffLengthTrajectory(Trajectory *trj1, Trajectory *trj2)
{

  return abs(trj1->m_length - trj2->m_length);
}


/*!
 * \fn  TrajManager::diffSpeedTrajectory
   \brief compute speed difference between two trajectories
   \param trj1 : trajectory 1
   \param trj2 : trajectory 2
   \return speed difference between two trajectories
 */
double TrajManager::diffSpeedTrajectory(Trajectory *trj1, Trajectory *trj2)
{
  return abs(trj1->m_speed - trj2->m_speed);
}