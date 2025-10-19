#include "Drone.h"
#include "Depot.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main () {
    ifstream infile("Drone.txt");
    if(!infile){
        cout << "Error opening file!" << endl;
        return 1;
    }

    Depot depot;
    string line;
    while(getline(infile, line)){
        // Process each line and add to depot
    }

    //user inferface menu options
    cout << "Menu Options:" << endl;
    cout << "1. Sort Drones By Name\n2.Sort Drones By ID\n3.Sort Drones By Position\n4. Randomize Drone Order\n5. Add Drone\n6. Retrieve a drone\n7. Search Drone By name\n8. Search Drone by ID\n9.Write Depot to file\n10. Swap Drone Data\n11. Insert Drone Task\n12. Copy-Paste Drone\n13. Display All Drones' names\n14. Sort Drone Data Ascending\n15. Sort Drone Data Descending\n16. Exit" << endl;
    cout << "Enter a number value choice: " << endl;
    int choice;
    cin >> choice;

    switch (choice){
        case 1: // Sort Drones By Name
            break;
        case 2: // Sort Drones By ID
            break;
        case 3: // Sort Drones By Position
            break;
        case 4: // Randomize Drone Order
            break;
        case 5: // Add Drone
            break;
        case 6: // Retrieve a drone
            break;
        case 7: // Search Drone By name
            break;
        case 8: // Search Drone by ID
            break;
        case 9: // Write Depot to file
            break;
        case 10: // Swap Drone Data
            break;
        case 11: // Insert Drone Task
            break;
        case 12: // Copy-Paste Drone
            break;
        case 13: // Display All Drones' names
            break;
        case 14: // Sort Drone Data Ascending
            break;
        case 15: // Sort Drone Data Descending
            break;
        case 16: // Exit
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
    }
    infile.close();

}