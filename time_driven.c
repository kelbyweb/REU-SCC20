//
//  time_driven.c
//  Synthesis program to get starting point & set trajectory
//
//  Kelby Webster
//  6/3/20
//
//TODO: counter, display last state


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>  // for srand call

// Declare struct for holding coordinates as a pair
struct coordinatePair {
    
    int x;
    int y;
    
};


// Function prototype
void loop(struct coordinatePair current);
void displayMenu(void);

int main() {
    
    // Initialize variables
    bool stop = false;
    int option;
    struct coordinatePair currentPair;
    
    while(!stop){
    displayMenu();
    // Get user input for option
    scanf("%d", &option);
        if(option == 1) {
            srand((unsigned)time(0));// Generating the seed
            // creates random coordinate values from range of (0,0) to (1023,1023)
            currentPair.x = rand() % 1023;
            currentPair.y = rand() % 1023;
            printf("Option chosen: Randomly generated values\n");
            printf("Coordinates are: (%d, %d)\n", currentPair.x, currentPair.y);
            loop(currentPair);
            break;
        }
        else if (option == 2) {
            printf("Option chosen: User generated values\n");
            printf("Enter the initial status/starting point: \n");
            printf("X value: ");
            scanf("%d", &currentPair.x);
            printf("Y value: ");
            scanf("%d", &currentPair.y);
            printf("Chosen coordinates are: (%d, %d)\n", currentPair.x, currentPair.y);
            loop(currentPair);
            break;
        }
        else if (option == 3) {
            printf("Exiting program...\n");
            exit(0);
        }
        else if (option != 1 && option != 2 && option != 3)
        {
            printf("Invalid input... please try again.");
        }
     }
        
        return 0;
}



       // Function for randomly generated (x, y)
    void loop(struct coordinatePair current) {
        
        // Initial status
        // The boat is in given initial location/position (x, y)
        int x = current.x;
        int y = current.y;
        printf("\nCurrent state: (%d, %d)\n", x, y);
        
        srand((unsigned)time(0));// Generating the srand seed
        double r; // for generating random probability
        // Based on the probabilities generated by the random number,the next position of the boat is decided
        
        // 1. Initiate for loop on tick to generate data
        for(int i = 0; i <= 10000; i++ )//using loop to generate data up to 10,000
            {
                r = (double)rand()/ ((double)RAND_MAX); // generating the random probability range [0, 1]
        
        // 2. Check system status
        // At every point, find distance from each of the next options to adversary boat
                
                
        // case b11: (767,0) to (1023, 255) = 0001
        if ((767 <= x) & (x <= 1023)&(0 <= y) &(y <= 255)) {
            if ((0 < r) & (r <= 0.55)) {
                x = x + 1;
                y = y + 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if ((0.55 < r) & (r <= 0.6)) {
                y = y + 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if ((0.6 < r) & (r <= 0.65)) {
                x = x - 1;
                y = y + 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if ((0.65 < r) & (r <= 0.7)) {
                x = x - 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if((0.7 < r) & (r  <= 0.75)) {
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if((0.75 < r) & (r <= 0.8)) {
                x = x + 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if((0.8 < r) & (r <= 0.85)) {
                x = x - 1;
                y = y -1;
               printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if((0.85 < r) & (r <= 0.9)) {
                y = y - 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if((0.9< r) & (r <= 0.95)) {
                x = x + 1;
                y = y - 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
        }
                
                
        // case b14: (767,255) to (1023, 511) = 0011
        if ((767 <= x) & (x <= 1023)&(255 <= y) &(y <= 511)) {
           if ((0 < r) & (r <= 0.55)) {
                x = x + 1;
                y = y + 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if ((0.55 < r) & (r <= 0.6)) {
                y = y + 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if ((0.6 < r) & (r <= 0.65)) {
                x = x - 1;
                y = y + 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if ((0.65 < r) & (r <= 0.7)) {
                x = x - 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if((0.7 < r) & (r  <= 0.75)) {
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if((0.75 < r) & (r <= 0.8)) {
                x = x + 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if((0.8 < r) & (r <= 0.85)) {
                x = x - 1;
                y = y -1;
               printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if((0.85 < r) & (r <= 0.9)) {
                y = y - 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
            if((0.9< r) & (r <= 0.95)) {
                x = x + 1;
                y = y - 1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
            }
        }
                
        // case b41: (767,511) to (1023, 767) = 1011
        if ((767 <= x) & (x <= 1023)&(511 <= y) &(y <= 767)) {
            if ((0 < r) & (r <= 0.55)) {
                x = x + 1;
                y = y + 1;
                printf("%d,", x); printf("%d,", y); printf(", b4\n");
            }
            if ((0.55 < r) & (r <= 0.6)) {
                y = y + 1;
                printf("%d,", x); printf("%d,", y); printf(", b4\n");
            }
            if ((0.6 < r) & (r <= 0.65)) {
                x = x - 1;
                y = y + 1;
                printf("%d,", x); printf("%d,", y); printf(", b4\n");
            }
            if ((0.65 < r) & (r <= 0.7)) {
                x = x - 1;
                printf("%d,", x); printf("%d,", y); printf(", b4\n");
            }
            if((0.7 < r) & (r  <= 0.75)) {
                printf("%d,", x); printf("%d,", y); printf(", b4\n");
            }
            if((0.75 < r) & (r <= 0.8)) {
                x = x + 1;
                printf("%d,", x); printf("%d,", y); printf(", b4\n");
            }
            if((0.8 < r) & (r <= 0.85)) {
                x = x - 1;
                y = y -1;
               printf("%d,", x); printf("%d,", y); printf(", b4\n");
            }
            if((0.85 < r) & (r <= 0.9)) {
                y = y - 1;
                printf("%d,", x); printf("%d,", y); printf(", b4\n");
            }
            if((0.9< r) & (r <= 0.95)) {
                x = x + 1;
                y = y - 1;
                printf("%d,", x); printf("%d,", y); printf(", b4\n");
            }
        }
                
        // case b44: (767,767) to (1023, 1023) = 1010
        if ((767 <= x) & (x <= 1023)&(767 <= y) &(y <= 1023)) {
            if ((0 < r) & (r <= 0.55)) {
                  x = x + 1;
                  y = y + 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if ((0.55 < r) & (r <= 0.6)) {
                  y = y + 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if ((0.6 < r) & (r <= 0.65)) {
                  x = x - 1;
                  y = y + 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if ((0.65 < r) & (r <= 0.7)) {
                  x = x - 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if((0.7 < r) & (r  <= 0.75)) {
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if((0.75 < r) & (r <= 0.8)) {
                  x = x + 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if((0.8 < r) & (r <= 0.85)) {
                  x = x - 1;
                  y = y -1;
                 printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if((0.85 < r) & (r <= 0.9)) {
                  y = y - 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if((0.9< r) & (r <= 0.95)) {
                  x = x + 1;
                  y = y - 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
        }
                
        // case b43: (511,767) to (767, 1023) = 1100
        if ((511 <= x) & (x <= 767)&(767 <= y) &(y <= 1023)) {
             if ((0 < r) & (r <= 0.55)) {
                  x = x + 1;
                  y = y + 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if ((0.55 < r) & (r <= 0.6)) {
                  y = y + 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if ((0.6 < r) & (r <= 0.65)) {
                  x = x - 1;
                  y = y + 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if ((0.65 < r) & (r <= 0.7)) {
                  x = x - 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if((0.7 < r) & (r  <= 0.75)) {
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if((0.75 < r) & (r <= 0.8)) {
                  x = x + 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if((0.8 < r) & (r <= 0.85)) {
                  x = x - 1;
                  y = y -1;
                 printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if((0.85 < r) & (r <= 0.9)) {
                  y = y - 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
              if((0.9< r) & (r <= 0.95)) {
                  x = x + 1;
                  y = y - 1;
                  printf("%d,", x); printf("%d,", y); printf(", b4\n");
              }
        }
                
        // case b34: (255,767) to (511, 1023) = 1001
        if ((255 <= x) & (x <= 511)&(767 <= y) &(y <= 1023))
        {
           if ((0 < r) & (r <= 0.55)) {
                  x = x + 1;
                  y = y + 1;
                  printf("%d,", x); printf("%d,", y); printf(", b3\n");
              }
              if ((0.55 < r) & (r <= 0.6)) {
                  y = y + 1;
                  printf("%d,", x); printf("%d,", y); printf(", b3\n");
              }
              if ((0.6 < r) & (r <= 0.65)) {
                  x = x - 1;
                  y = y + 1;
                  printf("%d,", x); printf("%d,", y); printf(", b3\n");
              }
              if ((0.65 < r) & (r <= 0.7)) {
                  x = x - 1;
                  printf("%d,", x); printf("%d,", y); printf(", b3\n");
              }
              if((0.7 < r) & (r  <= 0.75)) {
                  printf("%d,", x); printf("%d,", y); printf(", b3\n");
              }
              if((0.75 < r) & (r <= 0.8)) {
                  x = x + 1;
                  printf("%d,", x); printf("%d,", y); printf(", b3\n");
              }
              if((0.8 < r) & (r <= 0.85)) {
                  x = x - 1;
                  y = y -1;
                 printf("%d,", x); printf("%d,", y); printf(", b3\n");
              }
              if((0.85 < r) & (r <= 0.9)) {
                  y = y - 1;
                  printf("%d,", x); printf("%d,", y); printf(", b3\n");
              }
              if((0.9< r) & (r <= 0.95)) {
                  x = x + 1;
                  y = y - 1;
                  printf("%d,", x); printf("%d,", y); printf(", b3\n");
              }
        }
                
        // case b33: (0,767) to (255, 1023) = 0111
        if ((0 <= x) & (x <= 255)&(767 <= y) &(y <= 1023)) {
            if ((0 < r) & (r <= 0.55)) {
                   x = x + 1;
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if ((0.55 < r) & (r <= 0.6)) {
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if ((0.6 < r) & (r <= 0.65)) {
                   x = x - 1;
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if ((0.65 < r) & (r <= 0.7)) {
                   x = x - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if((0.7 < r) & (r  <= 0.75)) {
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if((0.75 < r) & (r <= 0.8)) {
                   x = x + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if((0.8 < r) & (r <= 0.85)) {
                   x = x - 1;
                   y = y -1;
                  printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if((0.85 < r) & (r <= 0.9)) {
                   y = y - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if((0.9< r) & (r <= 0.95)) {
                   x = x + 1;
                   y = y - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
        }
                
        // case b32: (0,511) to (255, 767) = 1000
        if ((0 <= x) & (x <= 255)&(511 <= y) &(y <= 767)) {
            if ((0 < r) & (r <= 0.55)) {
                   x = x + 1;
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if ((0.55 < r) & (r <= 0.6)) {
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if ((0.6 < r) & (r <= 0.65)) {
                   x = x - 1;
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if ((0.65 < r) & (r <= 0.7)) {
                   x = x - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if((0.7 < r) & (r  <= 0.75)) {
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if((0.75 < r) & (r <= 0.8)) {
                   x = x + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if((0.8 < r) & (r <= 0.85)) {
                   x = x - 1;
                   y = y -1;
                  printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if((0.85 < r) & (r <= 0.9)) {
                   y = y - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
               if((0.9< r) & (r <= 0.95)) {
                   x = x + 1;
                   y = y - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b3\n");
               }
        }
                
        // case b23: (0,255) to (255, 511) = 0110
        if ((0 <= x) & (x <= 255)&(255 <= y) &(y <= 511)) {
            if ((0 < r) & (r <= 0.55)) {
                   x = x + 1;
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if ((0.55 < r) & (r <= 0.6)) {
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if ((0.6 < r) & (r <= 0.65)) {
                   x = x - 1;
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if ((0.65 < r) & (r <= 0.7)) {
                   x = x - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.7 < r) & (r  <= 0.75)) {
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.75 < r) & (r <= 0.8)) {
                   x = x + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.8 < r) & (r <= 0.85)) {
                   x = x - 1;
                   y = y -1;
                  printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.85 < r) & (r <= 0.9)) {
                   y = y - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.9< r) & (r <= 0.95)) {
                   x = x + 1;
                   y = y - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
        }
                
        // case b22: (0,0) to (255, 255) = 0100
        if ((0 <= x) & (x <= 255)&(0 <= y) &(y <= 255)) {
             if ((0 < r) & (r <= 0.55)) {
                   x = x + 1;
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if ((0.55 < r) & (r <= 0.6)) {
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if ((0.6 < r) & (r <= 0.65)) {
                   x = x - 1;
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if ((0.65 < r) & (r <= 0.7)) {
                   x = x - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.7 < r) & (r  <= 0.75)) {
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.75 < r) & (r <= 0.8)) {
                   x = x + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.8 < r) & (r <= 0.85)) {
                   x = x - 1;
                   y = y -1;
                  printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.85 < r) & (r <= 0.9)) {
                   y = y - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.9< r) & (r <= 0.95)) {
                   x = x + 1;
                   y = y - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
        }
                
        // case b21: (255,0) to (511, 255) = 0101
        if ((255 <= x) & (x <= 511)&(0 <= y) &(y <= 255)) {
                     if ((0 < r) & (r <= 0.55)) {
                   x = x + 1;
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if ((0.55 < r) & (r <= 0.6)) {
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if ((0.6 < r) & (r <= 0.65)) {
                   x = x - 1;
                   y = y + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if ((0.65 < r) & (r <= 0.7)) {
                   x = x - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.7 < r) & (r  <= 0.75)) {
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.75 < r) & (r <= 0.8)) {
                   x = x + 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.8 < r) & (r <= 0.85)) {
                   x = x - 1;
                   y = y -1;
                  printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.85 < r) & (r <= 0.9)) {
                   y = y - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
               if((0.9< r) & (r <= 0.95)) {
                   x = x + 1;
                   y = y - 1;
                   printf("%d,", x); printf("%d,", y); printf(", b2\n");
               }
        }
                
        // case b12: (511,0) to (767, 255) = 0010
        if ((511 <= x) & (x <= 767)&(0 <= y) &(y <= 255)) {
            if ((0 < r) & (r <= 0.55)) {
                 x = x + 1;
                 y = y + 1;
                 printf("%d,", x); printf("%d,", y); printf(", b1\n");
             }
             if ((0.55 < r) & (r <= 0.6)) {
                 y = y + 1;
                 printf("%d,", x); printf("%d,", y); printf(", b1\n");
             }
             if ((0.6 < r) & (r <= 0.65)) {
                 x = x - 1;
                 y = y + 1;
                 printf("%d,", x); printf("%d,", y); printf(", b1\n");
             }
             if ((0.65 < r) & (r <= 0.7)) {
                 x = x - 1;
                 printf("%d,", x); printf("%d,", y); printf(", b1\n");
             }
             if((0.7 < r) & (r  <= 0.75)) {
                 printf("%d,", x); printf("%d,", y); printf(", b1\n");
             }
             if((0.75 < r) & (r <= 0.8)) {
                 x = x + 1;
                 printf("%d,", x); printf("%d,", y); printf(", b1\n");
             }
             if((0.8 < r) & (r <= 0.85)) {
                 x = x - 1;
                 y = y -1;
                printf("%d,", x); printf("%d,", y); printf(", b1\n");
             }
             if((0.85 < r) & (r <= 0.9)) {
                 y = y - 1;
                 printf("%d,", x); printf("%d,", y); printf(", b1\n");
             }
             if((0.9< r) & (r <= 0.95)) {
                 x = x + 1;
                 y = y - 1;
                 printf("%d,", x); printf("%d,", y); printf(", b1\n");
             }
        }
            
                
        // 3. Make a decision
        // Pick one of the 10 options/cases based on probability
        //invisible
        // 4. Update system status
        // Convert initial into detection/coordinates of newly selected option
        // 5. Check for exceptions
        // If we are in the A region, do not move, or if it is invisible
        if((0.94 <= r) & (r < 1.00))
            printf("Not visible/invisible\n");
                
        if ((x < 0) & (x > 1023) & (y < 0) & (y > 1023)) {
            printf("%d,", x); printf("%d,", y); printf(", C\n"); //in C
            exit(0);
        }
        if ((x < 767) & (x > 255) & (y < 767) & (y > 255)) {
            printf("Boat approaching A\n");
            exit(0);
        }
        
        // 6. End loop
        }

    }


void displayMenu() {
    // Option menu
    printf("\n  **************************************************************\n");
    printf("      Please select an option: (1, 2, or 3) \n");
    printf("      1. Use randomly generated numbers for initial state values \n");
    printf("      2. Input specific numbers for initial state values \n");
    printf("      3. Exit program \n");
    printf("  ***************************************************************\n");
}


