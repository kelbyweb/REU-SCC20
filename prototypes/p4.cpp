//
//  p4.cpp
//  Fourth prototype
//  34-33-33 distribution
//  Generates coordinate data & stores the output into a csv file
//
//  Kelby Webster
//  7/10/20
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;
int main()
    {
        
        ofstream outputFile; // file pointer
        outputFile.open("data.csv", ios::app); // creates a new file
        
        srand((unsigned)time(0)); // generating the seed
        int x = rand() % 4096; // creates random coordinate from range (0,0) to (4096, 4096)
        int y = rand() % 4096;
        double r;
        cout << "Initial coordinates: (" << x << "," << y << ")" << endl;
        
        
        // starting loop on "tick"
        for(int i = 0; i <= 10000; i++ )
        {
            // generating the random probabilty
            r = (double)rand() / ((double)RAND_MAX);
            
            // A region
            if ((1792 <= x) & (x <= 2304) & (1792 <= y) & (y <= 2304))
                {
                    cout << "(" << x << ", " << y << ")" << endl;
                    cout << "ALERT! Boat in A region! " << endl;
                    exit(0);
                }

            // C region top
            if ((1024 <= x) & (x <= 3072) & (1024 <= y) &(y <= 1536))
            {
                if ((0 < r) & (r <= 0.34))
                {
                    y = y + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
                if ((0.34 < r) & (r <= 0.67))
                {
                    x = x + 1;
                    y = y + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
                if ((0.67 < r) & (r <= 0.99))
                {
                    x = x + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
            }
                
            // C region left
            if ((1024 <= x) & (x <= 1536) & (1024 <= y) &(y <= 3072))
            {
                if ((0 < r) & (r <= 0.34))
                {
                    x = x + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
                if ((0.34 < r) & (r <= 0.67))
                {
                    x = x + 1;
                    y = y + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
                if ((0.67 < r) & (r <= 0.99))
                {
                    x = x + 1;
                    y = y - 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
            }
                // C region right
                if ((2560 <= x) & (x <= 3072) & (1024 <= y) &(y <= 3072))
                {
                    if ((0 < r) & (r <= 0.34))
                    {
                        x = x - 1;
                        cout << "(" << x << ", " << y << ")" << endl;
                    }
                    if ((0.34 < r) & (r <= 0.67))
                    {
                        x = x - 1;
                        y = y - 1;
                        cout << "(" << x << ", " << y << ")" << endl;
                    }
                    if ((0.67 < r) & (r <= 0.99))
                    {
                        x = x - 1;
                        y = y + 1;
                        cout << "(" << x << ", " << y << ")" << endl;
                    }
                }
               
                  // C region bottom
                  if ((1024 <= x) & (x <= 3072) & (1536 <= y) &(y <= 3072))
                  {
                      if ((0 < r) & (r <= 0.34))
                      {
                          y = y - 1;
                          cout << "(" << x << ", " << y << ")" << endl;
                      }
                      if ((0.34 < r) & (r <= 0.67))
                      {
                          x = x - 1;
                          y = y - 1;
                          cout << "(" << x << ", " << y << ")" << endl;
                      }
                      if ((0.67 < r) & (r <= 0.99))
                      {
                          x = x - 1;
                          cout << "(" << x << ", " << y << ")" << endl;
                      }
                  }
 
                // B region top
                if ((1536 <= x) & (x <= 2560) & (1536 <= y) & (y <= 1791))
                {
                    if ((0 < r) & (r <= 0.34))
                    {
                        y = y + 1;
                        cout << "(" << x << ", " << y << ")" << endl;
                    }
                    if ((0.34 < r) & (r <= 0.67))
                    {
                        x = x + 1;
                        y = y + 1;
                        cout << "(" << x << ", " << y << ")" << endl;
                    }
                    if ((0.67 < r) & (r <= 0.99))
                    {
                        x = x + 1;
                        cout << "(" << x << ", " << y << ")" << endl;
                    }
                }
            
                // B region left
                if ((1536 <= x) & (x <= 2560) & (1536 <= y) &(y <= 2560))
                {
                    if ((0 < r) & (r <= 0.34))
                    {
                        x = x + 1;
                        cout << "(" << x << ", " << y << ")" << endl;
                    }
                    if ((0.34 < r) & (r <= 0.67))
                    {
                        x = x + 1;
                        y = y + 1;
                        cout << "(" << x << ", " << y << ")" << endl;
                    }
                    if ((0.67 < r) & (r <= 0.99))
                    {
                        x = x + 1;
                        y = y - 1;
                        cout << "(" << x << ", " << y << ")" << endl;
                    }
                }
            
                  // B region right
                  if ((1536 <= x) & (x <= 2560) & (1536 <= y) &(y <= 2560))
                  {
                      if ((0 < r) & (r <= 0.34))
                      {
                          x = x - 1;
                          cout << "(" << x << ", " << y << ")" << endl;
                      }
                      if ((0.34 < r) & (r <= 0.67))
                      {
                          x = x - 1;
                          y = y - 1;
                          cout << "(" << x << ", " << y << ")" << endl;
                      }
                      if ((0.67 < r) & (r <= 0.99))
                      {
                          x = x - 1;
                          y = y + 1;
                          cout << "(" << x << ", " << y << ")" << endl;
                      }
                  }
            
                    // B region bottom
                    if ((1536 <= x) & (x <= 2560) & (2304 <= y) &(y <= 2560))
                    {
                        if ((0 < r) & (r <= 0.34))
                        {
                            y = y - 1;
                            cout << "(" << x << ", " << y << ")" << endl;
                        }
                        if ((0.34 < r) & (r <= 0.67))
                        {
                            x = x - 1;
                            y = y - 1;
                            cout << "(" << x << ", " << y << ")" << endl;
                        }
                        if ((0.67 < r) & (r <= 0.99))
                        {
                            x = x - 1;
                            cout << "(" << x << ", " << y << ")" << endl;
                        }
                    }
            
                // D region top
                if ((0 <= x) & (x <= 4096) & (0 <= y) & (y <= 1024))
                {
                    if ((0 < r) & (r <= 0.34))
                    {
                        y = y + 1;
                        cout << "(" << x << ", " << y << ")" << endl;
                    }
                    if ((0.34 < r) & (r <= 0.67))
                    {
                        x = x + 1;
                        y = y + 1;
                        cout << "(" << x << ", " << y << ")" << endl;
                    }
                    if ((0.67 < r) & (r <= 0.99))
                    {
                        x = x + 1;
                        cout << "(" << x << ", " << y << ")" << endl;
                    }
                }
                    
                    // D region left
                    if ((0 <= x) & (x <= 1024) & (0 <= y) & (y <= 4096))
                    {
                       if ((0 < r) & (r <= 0.34))
                        {
                            x = x + 1;
                            cout << "(" << x << ", " << y << ")" << endl;
                        }
                        if ((0.34 < r) & (r <= 0.67))
                        {
                            x = x + 1;
                            y = y + 1;
                            cout << "(" << x << ", " << y << ")" << endl;
                        }
                        if ((0.67 < r) & (r <= 0.99))
                        {
                            x = x + 1;
                            y = y - 1;
                            cout << "(" << x << ", " << y << ")" << endl;
                        }
                    }
 
                     // D region right
                     if ((3072 <= x) & (x <= 4096) & (0 <= y) & (y <= 4096))
                     {
                         if ((0 < r) & (r <= 0.34))
                         {
                             x = x - 1;
                             cout << "(" << x << ", " << y << ")" << endl;
                         }
                         if ((0.34 < r) & (r <= 0.67))
                         {
                             x = x - 1;
                             y = y - 1;
                             cout << "(" << x << ", " << y << ")" << endl;
                         }
                         if ((0.67 < r) & (r <= 0.99))
                         {
                             x = x - 1;
                             y = y + 1;
                             cout << "(" << x << ", " << y << ")" << endl;
                         }
                     }
            
                    // D region bottom
                    if ((0 <= x) & (x <= 4096) & (3073 <= y) & (y <= 4096))
                    {
                        if ((0 < r) & (r <= 0.34))
                        {
                            y = y - 1;
                            cout << "(" << x << ", " << y << ")" << endl;
                        }
                        if ((0.34 < r) & (r <= 0.67))
                        {
                            x = x - 1;
                            y = y - 1;
                            cout << "(" << x << ", " << y << ")" << endl;
                        }
                        if ((0.67 < r) & (r <= 0.99))
                        {
                            x = x - 1;
                            cout << "(" << x << ", " << y << ")" << endl;
                        }
                    }
                    
            outputFile << x << ", " << y << endl; // print to csv
        }
        outputFile.close(); // successfully made csv
        
    return 0;
}
