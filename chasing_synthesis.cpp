//
//  chasing_synthesis.cpp
//  Generates circling data & store the output generated into a csv file
//
//  Kelby Webster
//  6/26/20
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;
int main()
    {
        
        srand((unsigned)time(0));// Generating the seed
        int x = rand() % 4096;// creates random coordinate from range (0,0) to (4096, 4096)
        int y = rand() % 4096;
        //int total = 0;
        double r;
        cout << "Initial coordinates: (" << x << "," << y << ")" << endl;
        for(int i = 0; i <= 10000; i++ )
        {
            
            r = (double)rand() / ((double)RAND_MAX);// generating the random probabilty
            // starting loop on "tick"
            
            // B region
            if ((2560 <= x) & (x <= 1536)&(2560 <= y) &(y <= 1536))
            {
                if ((0 < r) & (r <= 0.55))
                {
                    x = x + 1;
                    y = y + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
                if ((0.55 < r) & (r <= 0.6))
                {
                    y = y + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
                if ((0.6 < r) & (r <= 0.65))
                {
                    x = x - 1;
                    y = y + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
                if ((0.65 < r) & (r <= 0.7))
                {
                    x = x - 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
                if((0.7 < r) & (r  <= 0.75))
                {
                    cout << "(" << x << ", " << y << ")" << endl;
                }
                if((0.75 < r) & (r <= 0.8))
                {
                    x = x + 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
                if((0.8 < r) & (r <= 0.85))
                {
                    x = x - 1;
                    y = y - 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
                if((0.85 < r) & (r <= 0.9))
                {
                    y = y - 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
                if((0.9 < r) & (r <= 0.95))
                {
                    x = x + 1;
                    y = y - 1;
                    cout << "(" << x << ", " << y << ")" << endl;
                }
            }

                // invisible
                if((0.96 <= r) & (r < 1.00))
                cout << "not visible" << endl;
                
                // located in C region
                if ((x < 3072) & (x > 1023) & (y < 3072) & (y > 1023))
                {
                    cout << "(" << x << ", " << y << ")" << endl;
                }
            
                // located in A region
                if ((x < 2304) & (x > 1792) & (y < 2304) & (y > 1792))
                {
                    cout << "(" << x << ", " << y << ")" << endl;
                    cout << "ALERT! Boat in A region! " << endl;
                    exit(0);
                }
        }
    return 0;
}
