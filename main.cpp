#include <stdio.h>
#include <iostream>
#include "trajManager.hpp"

using namespace std;

int main(int arc, char *argv[])
{

    TrajManager tjrMnr;

    string sPathToDataFile = argv[1];

    /*Constructing trajectories from file*/
    tjrMnr.constructTrajectories(sPathToDataFile);

    int criteria;
    int trajectoryId;

    cout << "Sorted based on length" << endl;
    for (auto it = tjrMnr.m_listTrajs.begin(); it != tjrMnr.m_listTrajs.end(); ++it)
    {

        (*it)->dispInfos();
        (*it)->dispPoints();
    }

    cout << "Sorted based on speed" << endl;
    for (auto it = tjrMnr.m_listTrajsSpeedSorted.begin(); it != tjrMnr.m_listTrajsSpeedSorted.end(); ++it)
    {

        (*it)->dispInfos();
        (*it)->dispPoints();
    }
    cout << endl;
    cout << "You can find the closest trajectories to a chosen " << endl
         << "trajectory among the trajectories listed above" << endl
         << "base on 2 criterias, length or speed" << endl;
    cout << "Please chose criteria :" << endl
         << "1 ---------------------> length" << endl
         << "2 ---------------------> speed" << endl;
    cin >> criteria; // reads an integer from the keyboard

    list<Trajectory *> listClosestTraj;
    switch (criteria)
    {
    case 1:
        /* code */
        cout << "you have chosen "
             << "length" << endl;
        cout << "Please, chose the trajectory Id from the list above :";
        cin >> trajectoryId; // reads an integer from the keyboard
        cout << "You have cosen trajectory : " << trajectoryId << endl;
        listClosestTraj = tjrMnr.findNClosestLengthTraj(trajectoryId, 3);
        break;
    case 2:
        /* code */
        cout << "you have chosen "
             << "speed" << endl;
        cout << "Please, chose the trajectory Id from the list above : ";
        cin >> trajectoryId; // reads an integer from the keyboard
        cout << "You have cosen trajectory : " << trajectoryId << endl;
        listClosestTraj = tjrMnr.findNClosestSpeedTraj(trajectoryId, 3);
        break;

    default:
        break;
    }

    cout << "here are the closest trajectories based on criteria : " << criteria << endl;
    for (const Trajectory *id : listClosestTraj)
    {
        cout << "Traj Id  " << id->m_Id << "  it's speed  " << id->m_speed << "  it's length  " << id->m_length << endl;
    }

    return 0;
}