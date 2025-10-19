#ifndef DRONE_H
#define DRONE_H
#include <string>
using namespace std;

class Drone { 
    private:
        string name;    //name of the drone
        int ID;
        string task[5];             //last delivery tasks' name
        int init_position[2];       //(x,y) location in the area
        int task_positions[5][2];   //(x,y) location of last delivery tasks
    public:
        //Getters
        string getName();
        int getID();
        string* getTasks();         //  we need a pointer here to return the array
        int* getInitPosition();     //  we need a pointer here to return the array
        int (*getTaskPositions())[2]; //  we need a pointer here to return the 2D array

        //Setters
        void setName(string name);
        void setID(int id);
        void setTaskAtIndex(string taskName, int index);
        void setInitPositionAtIndex(int value, int index);
        void setTaskPositionAtIndex(int x, int y, int index);

        //Sorting methods
        void sortByAscending();
        void sortByDescending();

        //Display method
        void displayDrone();

        //Operator overloads
        void operator<<(Drone& d2); //copy all attributes of d2 into this object
        void operator-(Drone& d2);  //swap task and task position between objects (init position is excluded)
};
#endif


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