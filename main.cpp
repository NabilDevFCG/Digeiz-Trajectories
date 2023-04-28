#include <stdio.h>
#include <iostream>
#include "trajManager.hpp"

using namespace std;

int main(int arc, char *argv[])
{

    TrajManager tjrMnr;


    /*Constructing trajectories from file*/
    tjrMnr.constructTrajectories("small_trajectory.dat");


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


    return 0;
}