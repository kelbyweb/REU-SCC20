//
//  p0.cpp
//  Initial "best-case" prototype
//  100-0 distribution: "police chase"
//  Generates coordinate data & stores the output into a csv file
//
//  Kelby Webster
//  7/14/20
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

// Option menu
void displayMenu() {

    cout << "\n  **************************************************************" << endl;
    cout << "      Please select an option: (1, 2, or 3)" << endl;
    cout << "      1. Use randomly generated numbers for initial coordinates" << endl;
    cout << "      2. Input specific numbers for initial coordinates" << endl;
    cout << "      3. Exit program" << endl;
    cout << "  ***************************************************************" << endl;
}


// Generates & prints to csv
void pick(int x, int y) {
       ofstream outputFile; // file pointer
       outputFile.open("data.csv", ios::app); // creates a new file
       
       srand((unsigned)time(0)); // generating the seed
       // creates random coordinate from range (0,0) to (4096, 4096)
       double r;
       cout << "Initial coordinates: (" << x << "," << y << ")" << endl;
       
       // starting loop on "tick"
       for(int i = 0; i <= 10000; i++ )
       {
          // generating the random probabilty
          r = (double)rand() / ((double)RAND_MAX);
           
          // A region
          if ((1792 <= x) & (x <= 2304) & (1792 <= y) & (y <= 2304)) {
                cout << "(" << x << ", " << y << ")" << endl;
                cout << "ALERT! Boat in A region! " << endl;
                exit(0);
            }
           
          // B region top
          if ((1536 <= x) & (x <= 2560) & (2305 <= y) & (y <= 2560)) {
             if ((0 < r) & (r <= 0.999)) {
                   y = y - 1;
                   cout << "(" << x << ", " << y << ")" << endl;
                   }
              }
           
          // B region left
          if ((1536 <= x) & (x <= 1791) & (1792 <= y) & (y <= 2304)) {
             if ((0 < r) & (r <= 0.999)) {
                    x = x + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                    }
              }
           
          // B region right
          if ((2305 <= x) & (x <= 2560) & (1792 <= y) & (y <= 2304)) {
             if ((0 < r) & (r <= 0.999)) {
                    x = x - 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                    }
             }
           
          // B region bottom
          if ((1536 <= x) & (x <= 2560) & (1536 <= y) & (y <= 1791)) {
             if ((0 < r) & (r <= 0.999)) {
                    y = y + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                    }
             }
                    
          // C region top
          if ((1024 <= x) & (x <= 3072) & (2561 <= y) & (y <= 3072)) {
             if ((0 < r) & (r <= 0.999)) {
                    y = y - 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                    }
              }
           
          // C region left
          if ((1024 <= x) & (x <= 1535) & (1536 <= y) & (y <= 2560)) {
             if ((0 < r) & (r <= 0.999)) {
                    x = x + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                    }
              }
           
          // C region right
          if ((2561 <= x) & (x <= 3072) & (1536 <= y) & (y <= 2560)) {
             if ((0 < r) & (r <= 0.999)) {
                    x = x - 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                    }
              }
           
          // C region bottom
          if ((1024 <= x) & (x <= 3072) & (1024 <= y) & (y <= 1535)) {
             if ((0 < r) & (r <= 0.999)) {
                    y = y + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                    }
              }
           
          // D region top
          if ((0 <= x) & (x <= 4096) & (3073 <= y) & (y <= 4096)) {
             if ((0 < r) & (r <= 0.999)) {
                    y = y - 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                    }
              }
           
          // D region left
          if ((0 <= x) & (x <= 1023) & (0 <= y) & (y <= 3072)) {
             if ((0 < r) & (r <= 0.999)) {
                    x = x + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                    }
              }

          // D region right
          if ((3073 <= x) & (x <= 4096) & (1024 <= y) & (y <= 3072)) {
             if ((0 < r) & (r <= 0.999)) {
                    x = x - 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                    }
              }
           
          // D region bottom
          if ((0 <= x) & (x <= 4096) & (0 <= y) & (y <= 1023)) {
             if ((0 < r) & (r <= 0.999)) {
                    y = y + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                    }
              }
           
          // reaching out of bounds/negative values
          if ((x < 0) || (x > 4096) || (y < 0) || (y > 4096)) {
              cout << "Out of bounds. Ending program..." << endl;
              exit(0); // end on last viable coordinate
              }
                   
           outputFile << x << ", " << y << endl; // print to csv
       }
       outputFile.close(); // successfully made csv
}


int main()
    {
        // Initialize variables
        int option;
        int x, y;
    
        // initial menu display
        displayMenu();

        // Get user input for option
        cin >> option;
        
            if(option == 1) {
                // Generating the seed
                srand((unsigned)time(0));
                // creates random coordinates from range (0,0) to (4096, 4096)
                x = rand() % 4096;
                y = rand() % 4096;
                cout << "Option chosen: Randomly generated values" << endl;
                cout << "Coordinates are: (" << x << ", " << y << ")" << endl;
                pick(x, y);
               }
               else if (option == 2) {
                   cout << "Option chosen: User generated values" << endl;
                   cout <<"Enter the initial status/starting point:" << endl;
                   cout << "X value: ";
                   cin >> x;
                   cout << "Y value: ";
                   cin >> y;
                   cout <<"\nChosen coordinates are: (" << x << ", " << y << ")" << endl;
                   pick(x, y);
               }
               else if (option == 3) {
                   cout << "Exiting program..." << endl;
                   exit(0);
               }
               else if (option != 1 && option != 2 && option != 3) {
                   // input validation check
                   cout << "Invalid input... please try again." << endl;
               }
        
    return 0;
}
