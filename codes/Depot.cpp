#include "Depot.h"
#include "Drone.h"
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;


void Depot::addDrone(Drone& d1){drones.push_back(d1);}
Drone& Depot::getDrone(int index){return drones.at(index);}
void Depot::sortByName(){
    for (int i = 0; i < drones.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < drones.size(); j++) {
            if (drones[j].getName() < drones[minIndex].getName()) {
                minIndex = j;
            }
        }
        //swap
        if (minIndex != i) {
            Drone temp = drones[i];
            drones[i] = drones[minIndex];
            drones[minIndex] = temp;           
        }
    }
}

void Depot::sortByID(){
    for (int i = 0; i < drones.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < drones.size(); j++) {
            if (drones[j].getID() < drones[minIndex].getID()) {
                minIndex = j;
            }
        }
        //swap
        if (minIndex != i) {
            Drone temp = drones[i];
            drones[i] = drones[minIndex];
            drones[minIndex] = temp;           
        }
    }
}

void Depot::sortByPosition(){
    for (int i = 0; i < drones.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < drones.size(); j++) {
            // if (drones[j].get() < drones[minIndex].getInitPosition()) { //NEED TO FIND CLOSEST DRONE
            //     minIndex = j;
            // }
        }
        //swap
        if (minIndex != i) {
            Drone temp = drones[i];
            drones[i] = drones[minIndex];
            drones[minIndex] = temp;           
        }
    }
}

int Depot::searchDroneByName(string& name){
    int left = 0;
    int right = drones.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (drones[mid].getName() == name){
            return mid;
        }
        else if (drones[mid].getName() < name){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int Depot::searchDroneByID(int id){
    int left = 0;
    int right = drones.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (drones[mid].getID() == id){
            return mid;
        }
        else if (drones[mid].getID() < id){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
void Depot::swapDroneData(int index1, int index2){
    // Models real-time mission handoff—two drones exchange tasks& task positions
    drones[index1] - drones[index2];
    
}



/*
A drone fleet cannot be managed one by one—it requires a central control hub (Depot) to oversee
the group. In this project, the Depot class acts as a manager. It handles batch operations like
sorting, searching, and reordering drones. This mirrors real-world logistics centers, where drones
are queued, reassigned, or shuffled to meet changing delivery needs.
Private attributes:
vector<Drone> drones
Methods:
● void addDrone(Drone& d1)
Simulates onboarding a new drone into the fleet.
● Drone& getDrone(int index)
Provides controlled access to a specific drone’s record so dispatch or diagnostics
can read/update its state safely. This function returns a drone object purely;
however, the corresponding menu should print out the drone’s information.
● void sortByName() //manually, ascending
Alphabetical rosters help dispatchers quickly locate drones.
● void sortByID() //manually, ascending
● void sortByPosition() //manually, ascending by distance from origin
Prioritizes drones physically closest to a hub/warehouse for rapid launch or
immediate redeployment to nearby tasks.
Note: Sort the vector of drones by name/ID/position(ascending order,
assuming the distance is between the origin and the initial position of the
drone). Do not use vector class functions to sort automatically. You can
choose your sorting algorithm.
● int searchDroneByName(string& name) // binary search
● int searchDroneByID(int id) // binary search
Faster lookup during an urgent operation. When found, print out the index of the
first found drone; otherwise, return -1, and print out an error message to the
terminal. //note when performing binary search, the array should be pre-sorted. In
the menu, perform sorting first, then searching. Name comparison is
case-sensitive. If names tie, break ties by ID ascending.
● void swapDroneData(int index1, int index2)
Models real-time mission handoff—two drones exchange tasks& task positions
● void copyDrone(int index1, int index2)
Clones a proven configuration from a “template” drone to another unit for quick,
consistent deployment.
//hint swap and copy operations can be one-line coding
● void insertDroneTask(int droneidx, int taskidx, string& task, int task_pos[2])
Precisely updates a single task/slot (e.g., replace drone#2 task #3
task_position(x,y) with an urgent delivery) without rebuilding the whole routine.
● void sortDroneDataAscending(int idx)
Inside one drone, alphabetically ordering task names for quick human review or
export, again, task positions should be consistent after sorting.
● void sortDroneDataDescending(int idx)
● void randomizeOrder() // (manual shuffle, don’t use preexisting library
function, you might want to use std::swap)
Simulates the dynamic reassignment of drones in scheduling. In emergencies, the
control center may reshuffle the fleet order to avoid always assigning missions to
the same subset of drones first.
● void printAllNames()
Acts like a roster or roll call. Operators need a quick way to see which drones are
currently in the depot, identified by their names.
● void writeDepotToFile() // write to Depot.txt
Write the current state of the fleet into a log or configuration file. This allows the
system to restore drone information on restart and provides records for tracking or
reporting purposes.

*/