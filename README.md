# Digeiz-Trajectories

To build and test this program, please dowload the  Digeiz-Trajectories folder and follow these steps :


cd Digeiz-Trajectories
mkdir Build
cmake -S . -B Build/
cmake --build Build/
./Build/CPPDiz  dataFile.dat  (where  dataFile.dat is   small_trajectory.dat  or large_trajectory.dat)

The program will construct trajectories drom dat file
On the CLI you will see the list of trajectories with their Ids (Id if the index of trajectories based on creation time)

- Chose the criteria  and then chose the Id of trajectory to wich you want fo find the closest 3 trajectories based on the criteria you have chosen.
- On the CLI you will see the 3 closest trajectories

Launch again the program to try an other criteria and trajectory
