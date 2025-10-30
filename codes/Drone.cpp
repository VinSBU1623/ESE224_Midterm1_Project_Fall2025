// Drone.cpp
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Drone.h"

#define MAX_TASKS 5

//Getters
string Drone::getName() {
    return name;
}
int Drone::getID() {
    return ID;
}
string* Drone::getTasks() {
    return task;
}
int* Drone::getInitPosition() {
    return init_position;
}
int (*Drone::getTaskPositions())[2] { //why is the asterik there?: because we are returning a pointer to an array of 2 integers
    return task_positions;
}

//Setters
void Drone::setName(string name) {
    this->name = name;     // use this-> to distinguish between class member and parameter, in this context: this->name refers to the member variable while name refers to the parameter
    // alternate: Drone::name = name;
}
void Drone::setID(int id) {
    ID = id;
}
void Drone::setTaskAtIndex(string taskName, int index) {
    if (index >= 0 && index < MAX_TASKS) { //we don't want index to be out of bounds
        task[index] = taskName;
    }
}
void Drone::setInitPositionAtIndex(int value, int index) {
    if (index == 0 || index == 1) { //we don't want index to be out of bounds
        init_position[index] = value;
    }
}
void Drone::setTaskPositionAtIndex(int x, int y, int index) {
    if (index >= 0 && index < MAX_TASKS) { //we don't want index to be out of bounds
        task_positions[index][0] = x;
        task_positions[index][1] = y;
    }
}

//Sorting methods
void Drone::sortByAscending() { //using selection sort
    for (int i = 0; i < MAX_TASKS - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < MAX_TASKS; j++) {
            if (task[j] < task[minIndex]) {
                minIndex = j;
            }
        }
        //swap
        if (minIndex != i) {
            string tempTask = task[i];
            task[i] = task[minIndex];
            task[minIndex] = tempTask;

            //also swap corresponding task positions
            int tempX = task_positions[i][0];
            int tempY = task_positions[i][1];
            task_positions[i][0] = task_positions[minIndex][0];
            task_positions[i][1] = task_positions[minIndex][1];
            task_positions[minIndex][0] = tempX;
            task_positions[minIndex][1] = tempY;
        }
    }
}

void Drone::sortByDescending() { //using selection sort
    for (int i = 0; i < MAX_TASKS - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < MAX_TASKS; j++) {
            if (task[j] > task[maxIndex]) {
                maxIndex = j;
            }
        }
        //swap
        if (maxIndex != i) {
            string tempTask = task[i];
            task[i] = task[maxIndex];
            task[maxIndex] = tempTask;

            //also swap corresponding task positions
            int tempX = task_positions[i][0];
            int tempY = task_positions[i][1];
            task_positions[i][0] = task_positions[maxIndex][0];
            task_positions[i][1] = task_positions[maxIndex][1];
            task_positions[maxIndex][0] = tempX;
            task_positions[maxIndex][1] = tempY;
        }
    }
}

void Drone::displayDrone() {
    cout << "Drone Name: " << name << endl;
    cout << "Drone ID: " << ID << endl;
    cout << "Initial Position: (" << init_position[0] << ", " << init_position[1] << ")" << endl;
    cout << "Tasks and their Positions:" << endl;
    for (int i = 0; i < MAX_TASKS; i++) {
        cout << "  Task " << (i + 1) << ": " << task[i] 
             << " at Position (" << task_positions[i][0] << ", " << task_positions[i][1] << ")" << endl;
    }
}

//Operator overloads
void Drone::operator<<(Drone& d2) { //copy all attributes of d2 into this object
    name = d2.name;
    ID = d2.ID;
    for (int i = 0; i < MAX_TASKS; i++) {
        task[i] = d2.task[i];
        task_positions[i][0] = d2.task_positions[i][0];
        task_positions[i][1] = d2.task_positions[i][1];
    }
    init_position[0] = d2.init_position[0];
    init_position[1] = d2.init_position[1];
}

void Drone::operator-(Drone& d2) {  //swap task and task position between objects (init position is excluded)
    for (int i = 0; i < MAX_TASKS; i++) {
        //swap tasks
        string tempTask = task[i];
        task[i] = d2.task[i];
        d2.task[i] = tempTask;

        //swap task positions
        int tempX = task_positions[i][0];
        int tempY = task_positions[i][1];
        task_positions[i][0] = d2.task_positions[i][0];
        task_positions[i][1] = d2.task_positions[i][1];
        d2.task_positions[i][0] = tempX;
        d2.task_positions[i][1] = tempY;
    }
}



/*
Each drone is like an employee in a company: it has an identity, an initial position, tasks, and task
positions. For a drone delivery system, storing these attributes (name, ID, tasks, init_position, task
positions) is crucial for organizing them and ensuring coordination. The Drone class encapsulates
this information, preparing the foundation for further operations like searching, sorting, and task
assignment.
Private attributes:
- string name //name of the drone
- int ID
- string tasks[5] // last 5 delivery tasks’ name
- int init_position[2] // (x, y) location in the area
- int task_positions[5][2] // delivery positions for each delivery task
Required methods:
• Getters/Setters → Simulate controlled access to drone information.
Getters & Setters for all private attributes
• Index-based Setters → Simulate precise updates to a specific task or
position.
setters for tasks/initial position/task positions with index
• Manual Sorting → Even though payloads are task names (strings),
sorting them alphabetically simulates how mission control systems may
normalize task lists, group similar tasks, and make human operators’ searches
or log inspections more efficient.
- sortByAscending(), sortByDescending() on attribute tasks (should not use
predefined sorting function from the standard library)
//note when you sort the task with their names, you also need to take care
about the task position so the pair(task name, task position) is consistent after
sorting
• Display → Simulate quick state inspection.
- void displayDrone() for all attributes
Operator overloads:
● operator<< → simulates copying a drone’s full configuration, useful for
backup, recovery, or deploying identical missions.
- operator<<(Drone& d2): copy all attributes of d2 into this object
● operator - → simulates task and task position swapping between drones,
reflecting real-world scenarios of mission handoffs or emergency
reassignment.
- operator-(Drone& d2): swap task and task position between objects(init position
is excluded)
*/