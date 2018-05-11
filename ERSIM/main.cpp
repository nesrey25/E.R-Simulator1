//
//  main.cpp
//  ERSIM
//
//  Created by Nate Esrey on 5/11/18.
//  Copyright © 2018 Nate Esrey. All rights reserved.
//
//
//  main.cpp
//  E.R-Simulator
//
//  Created by Esrey on 5/6/18.
//  Copyright © 2018 Esrey Enterprises. All rights reserved.
//

#include <iostream>

int main() {
#include "EmergencyRoom.hpp"
#include "Menu.hpp"
#include <iostream>
#include <algorithm>
    
using namespace std;
    
int main() {
        
        cout << "Welcome to the Emergency Room simulator!\n\n";
        string prompt = "What would you like the arrival rate of patients to be (patients/hr): ";
        int rate = read_int(prompt, 1, 60);
        prompt = "How many doctors would you like there to be (1-20): ";
        int docs = read_int(prompt, 1, 20);
        prompt = "How many nurses would you like there to be (1-20): ";
        int nurses = read_int(prompt, 1, 20);
        
        EmergencyRoom theRoom(docs, nurses, rate); //create the emergency room, input number of doctors, nurses, and the apropriate rates from the simulation user
        
        long long int FINISHTIME = 7 * 24 * 60; //one week runtime, equivalent to 10,080 minutes of runtime
        
        while (theRoom.getTime() < FINISHTIME) { //run simulation to completion
            theRoom.update();
        }
        
        double averageWait = theRoom.getTotalWait() / theRoom.getNumTreated(); //calculate the average waiting time per patient that comes into the E.R.
        
        cout << "The average visit time for each patient was " << averageWait << " minutes.\n\n";
        
        /*MENU OPTIONS
        string    menu_string = "Would you like to: \n";
        menu_string += "   0 - See the list of patient names\n";
        menu_string += "   1 - Search for the details of a patient by name\n";
        menu_string += "   2 - Exit\n";
        menu_string += "Enter: ";
        
        while (true) {
            int choice = read_int(menu_string, 0, 2);
            if (choice == 2)
                //exit the menu
                break;
            else if (choice == 0)
                //List all the names provided
                theRoom.listNames();
            else {
                //Searches the "Hospital Records" for a particular name and outputs the records for that patient
                cout << "What name would you like to search for: ";
                string name;
                cin >> name;
                transform(name.begin(), name.end(), name.begin(), toupper);
                cout << theRoom.getRecord(name);
            }
        }
         */
        
    return 0;
    }
}
