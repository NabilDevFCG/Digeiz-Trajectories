# Digeiz-Trajectories

To build and test this program, please dowload the  Digeiz-Trajectories folder and follow these steps :


cd Digeiz-Trajectories <br>
mkdir Build <br>
cmake -S . -B Build/ <br>
cmake --build Build/ <br>
./Build/CPPDiz  dataFile.dat  (where  dataFile.dat is   small_trajectory.dat  or large_trajectory.dat) <br>

The program will construct trajectories drom dat file <br> 
On the CLI you will see the list of trajectories with their Ids (Id if the index of trajectories based on creation time)<br>

- Chose the criteria  and then chose the Id of trajectory to wich you want fo find the closest 3 trajectories based on the criteria you have chosen.<br>
- On the CLI you will see the 3 closest trajectories<br>

Launch again the program to try an other criteria and trajectory<br>
