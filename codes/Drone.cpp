#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Drone { 
    private:
        string name;    //name of the drone
        int ID;
        string task[5];             //last delivery tasks' name
        int init_position[2];       //(x,y) location in the area
        int task_positions[5][2];   //(x,y) location of last delivery tasks
};