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
    
}