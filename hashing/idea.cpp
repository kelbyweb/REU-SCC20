//
//  idea.cpp
//  10% evenly distrubuted  to each corresponding option
//  Creates an ordered map using the combination of map and vector
//  Generates coordinate data & stores the output into a csv file
//
//  Kelby Webster
//  8/4/20
//

#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// define coordinate (x, y) as struct
struct coordinate {
    double x;
    double y;
    coordinate(double x, double y) {
        this->x = x;
        this->y = y;
    }
    // operator definition
    bool operator == (const coordinate &other) const {
        return (x == other.x && y == other.y);
    }
};


// Custom hash function to enable coordinate struct to be a key in a hash map
namespace std {
    template <>
    struct hash<coordinate> {
        std::size_t operator()(const coordinate& c) const {
            using std::size_t;
            using std::hash;
            return ((hash<double>()(c.x) ^ (hash<double>()(c.y) << 1)));
        }
    };
}

// Function prototypes
void displayMenu(void);
void pick(int x, int y);

int main() {
    
    // Initialize variables
    int option;
    int x, y;
    
    // initial menu display
    displayMenu();
    
        // Get user input for option
        cin >> option;
        if(option == 1) {
            srand((unsigned)time(0)); // Generating the seed
            // creates random coordinate values from range of (0,0) to (1023,1023)
            x = rand() % 4096;
            y = rand() % 4096;
            cout << "Option chosen: Randomly generated values " << endl;
            cout << "Coordinates are: (" << x << ", " <<  y << ") " << endl;
            pick(x, y);

           }
           else if (option == 2) {
               cout << "Option chosen: User generated values " << endl;
               cout << "Enter the initial status/starting point:  " << endl;
               cout << "X value: ";
               cin >> x;
               cout << "Y value: ";
               cin >> y;
               cout << "Coordinates are: (" << x << ", " <<  y << ") " << endl;
               pick(x, y);
           }
           else if (option == 3) {
               cout << "   Exiting program... " << endl;
               exit(0);
           }
           else if (option != 1 && option != 2 && option != 3)
           {
               cout << "Invalid input... please try again. " << endl;
           }
        
        return 0;
}

void pick(int x, int y) {
    
    ofstream outputFile; // file pointer
    outputFile.open("data.csv", ios::app); // creates a new file
    // store points in unordered set
    unordered_set<pair<int, int>> points;
    
    // starting loop on "tick"
    for (int i = 0; i < 10000; i++) {
        
    // instantiate a coordinate object & set it to be the current point
    pair<int, int> currentPoint = make_pair(x, y);
        coordinate c(x, y);
        hash<coordinate> h;
        
        //h.size_t = 5000;
    
    // creates random probability
    float prob = (float)rand() / (float)RAND_MAX;

        // set the location to be random option from 0-8
        int location = rand() % 9;
        
        // each 10% gets equal probability
        switch (location) {
            case 0: {
             if (prob <= 0.1) {
                    x = x - 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.1 && prob <= 0.2) {
                    x = x - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.2 && prob <= 0.3) {
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.3 && prob <= 0.4) {
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.4 && prob <= 0.5) {
                    x = x + 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.5 && prob <= 0.6) {
                    x = x - 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.6 && prob <= 0.7) {
                    x = x + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.7 && prob <= 0.8) {
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.8 && prob <= 0.9) {
                    x = x + 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.9 && prob <= 0.999){
                    cout << "Invisible " << endl;
                   }
            break;
         }
            case 1: {
             if (prob <= 0.1) {
                    x = x - 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.1 && prob <= 0.2) {
                    x = x - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.2 && prob <= 0.3) {
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.3 && prob <= 0.4) {
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.4 && prob <= 0.5) {
                    x = x + 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.5 && prob <= 0.6) {
                    x = x - 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.6 && prob <= 0.7) {
                    x = x + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.7 && prob <= 0.8) {
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.8 && prob <= 0.9) {
                    x = x + 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.9 && prob <= 0.999){
                    cout << "Invisible " << endl;
                   }
            break;
         }
            case 2: {
             if (prob <= 0.1) {
                    x = x - 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.1 && prob <= 0.2) {
                    x = x - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.2 && prob <= 0.3) {
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.3 && prob <= 0.4) {
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.4 && prob <= 0.5) {
                    x = x + 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.5 && prob <= 0.6) {
                    x = x - 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.6 && prob <= 0.7) {
                    x = x + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.7 && prob <= 0.8) {
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.8 && prob <= 0.9) {
                    x = x + 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.9 && prob <= 0.999){
                    cout << "Invisible " << endl;
                   }
            break;
         }
            case 3: {
             if (prob <= 0.1) {
                    x = x - 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.1 && prob <= 0.2) {
                    x = x - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.2 && prob <= 0.3) {
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.3 && prob <= 0.4) {
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.4 && prob <= 0.5) {
                    x = x + 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.5 && prob <= 0.6) {
                    x = x - 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.6 && prob <= 0.7) {
                    x = x + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.7 && prob <= 0.8) {
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.8 && prob <= 0.9) {
                    x = x + 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.9 && prob <= 0.999){
                    cout << "Invisible " << endl;
                   }
            break;
            }
            case 4: {
             if (prob <= 0.1) {
                    x = x - 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.1 && prob <= 0.2) {
                    x = x - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.2 && prob <= 0.3) {
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.3 && prob <= 0.4) {
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.4 && prob <= 0.5) {
                    x = x + 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.5 && prob <= 0.6) {
                    x = x - 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.6 && prob <= 0.7) {
                    x = x + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.7 && prob <= 0.8) {
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.8 && prob <= 0.9) {
                    x = x + 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.9 && prob <= 0.999){
                    cout << "Invisible " << endl;
                   }
            break;
            }
            case 5: {
             if (prob <= 0.1) {
                    x = x - 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.1 && prob <= 0.2) {
                    x = x - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.2 && prob <= 0.3) {
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.3 && prob <= 0.4) {
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.4 && prob <= 0.5) {
                    x = x + 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.5 && prob <= 0.6) {
                    x = x - 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.6 && prob <= 0.7) {
                    x = x + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.7 && prob <= 0.8) {
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.8 && prob <= 0.9) {
                    x = x + 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.9 && prob <= 0.999){
                    cout << "Invisible " << endl;
                   }
            break;
            }
            case 6: {
             if (prob <= 0.1) {
                    x = x - 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.1 && prob <= 0.2) {
                    x = x - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.2 && prob <= 0.3) {
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.3 && prob <= 0.4) {
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.4 && prob <= 0.5) {
                    x = x + 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.5 && prob <= 0.6) {
                    x = x - 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.6 && prob <= 0.7) {
                    x = x + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.7 && prob <= 0.8) {
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.8 && prob <= 0.9) {
                    x = x + 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.9 && prob <= 0.999){
                    cout << "Invisible " << endl;
                   }
            break;
            }
            case 7: {
             if (prob <= 0.1) {
                    x = x - 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.1 && prob <= 0.2) {
                    x = x - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.2 && prob <= 0.3) {
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.3 && prob <= 0.4) {
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.4 && prob <= 0.5) {
                    x = x + 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.5 && prob <= 0.6) {
                    x = x - 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.6 && prob <= 0.7) {
                    x = x + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.7 && prob <= 0.8) {
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.8 && prob <= 0.9) {
                    x = x + 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.9 && prob <= 0.999){
                    cout << "Invisible " << endl;
                   }
            break;
            }
            case 8: {
             if (prob <= 0.1) {
                    x = x - 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.1 && prob <= 0.2) {
                    x = x - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.2 && prob <= 0.3) {
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.3 && prob <= 0.4) {
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.4 && prob <= 0.5) {
                    x = x + 1;
                    y = y - 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.5 && prob <= 0.6) {
                    x = x - 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.6 && prob <= 0.7) {
                    x = x + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.7 && prob <= 0.8) {
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.8 && prob <= 0.9) {
                    x = x + 1;
                    y = y + 1;
                    cout <<  "(" << x << ", " << y << ") " << endl;
             } else if (prob > 0.9 && prob <= 0.999){
                    cout << "Invisible " << endl;
                   }
            break;
            }
        } // switch
        
        // place entries in table & check for repetitions
        unordered_set<pair<int, int>>::iterator it = points.find(currentPoint);
        if (it == points.end()) {
            // currentPoint not found, insert & add to CSV
            points.insert(currentPoint);
            outputFile << x << ", " << y << endl;
        } else {
            // currentPoint found, do not add (collision)
        }
        
    } // for
}



void displayMenu() {
    // Option menu
    cout << "\n  ************************************************************** " << endl;
    cout << "      Please select an option: (1, 2, or 3)  " << endl;
    cout << "      1. Use randomly generated numbers for initial state values  " << endl;
    cout << "      2. Input specific numbers for initial state values  " << endl;
    cout << "      3. Exit program  " << endl;
    cout << "  *************************************************************** " << endl;
}
