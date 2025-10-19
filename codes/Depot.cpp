#include "Depot.h"
#include "Drone.h"
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;


void Depot::addDrone(Drone& d1){drones.push_back(d1);}
Drone& Depot::getDrone(int index){return drones.at(index);}