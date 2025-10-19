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

int searchDroneByName(string& name){
    
}