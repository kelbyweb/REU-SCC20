//
//  time_driven.c
//  Synthesis program to get starting point & set trajectory
//
//  Kelby Webster & Thomas Knepshield
//  6/4/20
//
//TODO: counter, display last state


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>  // for srand call
#include <math.h> // for pow & sqrt


// Function prototype
void displayMenu(void);
double distance(int x, int y);
void pick(int x, int y);
void probability(float prob, int x, int y);

int main() {
    
    // Initialize variables
    bool stop = false;
    int option;
    int x, y;
    
    while(!stop){
    displayMenu();
    // Get user input for option
    scanf("%d", &option);
        if(option == 1) {
            srand((unsigned)time(0));// Generating the seed
            // creates random coordinate values from range of (0,0) to (1023,1023)
            x = rand() % 1023;
            y = rand() % 1023;
            printf("Option chosen: Randomly generated values\n");
            printf("Coordinates are: (%d, %d)\n", x, y);
            pick(x, y);
            break;
        }
        else if (option == 2) {
            printf("Option chosen: User generated values\n");
            printf("Enter the initial status/starting point: \n");
            printf("X value: ");
            scanf("%d", &x);
            printf("Y value: ");
            scanf("%d", &y);
            printf("Chosen coordinates are: (%d, %d)\n", x, y);
            pick(x, y);
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

    double distance(int x, int y) {
        return (sqrt((pow(x, 2)) + (pow(y, 2))));
        
    }

 //I dont think we need this but I left it here just in case
void probability(float prob, int x, int y) {
        
        int cases[2];
        if (prob <= 0.5500) {
            cases[0] = x - 1;
            cases[1] = y - 1;
        } else if (prob > 0.5500000 && prob <= 0.6000000) {
            cases[0] = x;
            cases[1] = y - 1;
        } else if (prob > 0.6000000 && prob <= 0.6500000) {
            cases[0] = x + 1;
            cases[1] = y - 1;
        } else if (prob > 0.6500000 && prob <= 0.7000000) {
            cases[0] = x - 1;
            cases[1] = y;
        } else if (prob > 0.7000000 && prob <= 0.7500000) {
            cases[0] = x;
            cases[1] = y;
        } else if (prob > 0.7500000 && prob <= 0.8000000) {
            cases[0] = x + 1;
            cases[1] = y;
        } else if (prob > 0.8000000 && prob <= 0.8500000) {
            cases[0] = x - 1;
            cases[1] = y + 1;
        } else if (prob > 0.8500000 && prob <= 0.9000000) {
            cases[0] = x;
            cases[0] = y + 1;
        } else if (prob > 0.9000000 && prob <= 0.9500000) {
            cases[0] = x + 1;
            cases[1] = y + 1;
        } else {
            printf("Invisible\n");
            cases[0] = x;
            cases[1] = y;
        }

        printf("(%d,", cases[0]);
        printf(" %d)\n", cases[1]);
    }

    


    void pick(int x, int y) {

    //int go = 0; signals to stop when coordinates reach out of range
        while (x != 0 && y != 0) { //Replaced with time later if needed
        //I removed go because I think this would work better

        // creates random probability
        float prob = (float)rand() / (float)RAND_MAX; //I think he wanted it to be floating point values
        printf("Probability is: %f\n", prob);

            double cases[9];

            cases[0] = distance(x - 1, y - 1);

            cases[1] = distance(x, y - 1);

            cases[2] = distance(x + 1, y - 1);

            cases[3] = distance(x - 1, y);

            cases[4] = distance(x, y);

            cases[5] = distance(x + 1, y);

            cases[6] = distance(x - 1, y + 1);

            cases[7] = distance(x, y + 1);

            cases[8] = distance(x + 1, y + 1);

            double min = cases[0];
            int location = 0;

            for (int i = 1; i < 8; i++) {
                if (cases[i] < min) {
                    min = cases[i];
                    location = i;
                }
            }
        
          
               
            switch (location) {
                case 0:
                 if (prob <= 0.5500) {
                    x = x - 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.5500000 && prob <= 0.6000000) {
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.6000000 && prob <= 0.6500000) {
                    x = x + 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.6500000 && prob <= 0.7000000) {
                    x = x - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.7000000 && prob <= 0.7500000) {
          
                } else if (prob > 0.7500000 && prob <= 0.8000000) {
                    x = x + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
              } else if (prob > 0.8000000 && prob <= 0.8500000) {
                    x = x - 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.8500000 && prob <= 0.9000000) {
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.9000000 && prob <= 0.9500000) {
                    x = x + 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else {
                    printf("Invisible\n");
              }
                    break;
                case 1:
                 if (prob <= 0.5500) {
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.5500000 && prob <= 0.6000000) {
            x = x - 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.6000000 && prob <= 0.6500000) {
                    x = x + 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.6500000 && prob <= 0.7000000) {
                    x = x - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.7000000 && prob <= 0.7500000) {
          
                } else if (prob > 0.7500000 && prob <= 0.8000000) {
                    x = x + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
              } else if (prob > 0.8000000 && prob <= 0.8500000) {
                    x = x - 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.8500000 && prob <= 0.9000000) {
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.9000000 && prob <= 0.9500000) {
                    x = x + 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else {
                    printf("Invisible\n");
              }
                case 2:
                 if (prob <= 0.5500) {
                    x = x + 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.5500000 && prob <= 0.6000000) {
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.6000000 && prob <= 0.6500000) {
                    x = x - 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.6500000 && prob <= 0.7000000) {
                    x = x - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.7000000 && prob <= 0.7500000) {
          
                } else if (prob > 0.7500000 && prob <= 0.8000000) {
                    x = x + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
              } else if (prob > 0.8000000 && prob <= 0.8500000) {
                    x = x - 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.8500000 && prob <= 0.9000000) {
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.9000000 && prob <= 0.9500000) {
                    x = x + 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else {
                    printf("Invisible\n");
              }
                    break;
                case 3:
                 if (prob <= 0.5500) {
                     x = x - 1;
                     printf("(%d, %d)\n", x, y);
                     break;
                } else if (prob > 0.5500000 && prob <= 0.6000000) {
                     y = y - 1;
                     printf("(%d, %d)\n", x, y);
                     break;
                } else if (prob > 0.6000000 && prob <= 0.6500000) {
                     x = x + 1;
                     y = y - 1;
                     printf("(%d, %d)\n", x, y);
                     break;
             } else if (prob > 0.6500000 && prob <= 0.7000000) {
                     x = x - 1;
                     y = y - 1;
                   printf("(%d, %d)\n", x, y);
                   break;
             } else if (prob > 0.7000000 && prob <= 0.7500000) {
          
                } else if (prob > 0.7500000 && prob <= 0.8000000) {
                    x = x + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
              } else if (prob > 0.8000000 && prob <= 0.8500000) {
                    x = x - 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.8500000 && prob <= 0.9000000) {
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.9000000 && prob <= 0.9500000) {
                    x = x + 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else {
                    printf("Invisible\n");
              }
                    break;
                case 4:
                 if (prob <= 0.5500) {
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.5500000 && prob <= 0.6000000) {
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.6000000 && prob <= 0.6500000) {
                    x = x + 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.6500000 && prob <= 0.7000000) {
                    x = x - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.7000000 && prob <= 0.7500000) {
                  x = x - 1;
                    y = y - 1;
                } else if (prob > 0.7500000 && prob <= 0.8000000) {
                    x = x + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
              } else if (prob > 0.8000000 && prob <= 0.8500000) {
                    x = x - 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.8500000 && prob <= 0.9000000) {
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.9000000 && prob <= 0.9500000) {
                    x = x + 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else {
                    printf("Invisible\n");
              }
                    break;
                case 5:
                 if (prob <= 0.5500) {
                    x = x + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.5500000 && prob <= 0.6000000) {
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.6000000 && prob <= 0.6500000) {
                    x = x + 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.6500000 && prob <= 0.7000000) {
                    x = x - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.7000000 && prob <= 0.7500000) {
          
                } else if (prob > 0.7500000 && prob <= 0.8000000) {
                    x = x - 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
              } else if (prob > 0.8000000 && prob <= 0.8500000) {
                    x = x - 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.8500000 && prob <= 0.9000000) {
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.9000000 && prob <= 0.9500000) {
                    x = x + 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else {
                    printf("Invisible\n");
              }
                    break;
                case 6:
                 if (prob <= 0.5500) {
                    x = x - 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.5500000 && prob <= 0.6000000) {
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.6000000 && prob <= 0.6500000) {
                    x = x + 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.6500000 && prob <= 0.7000000) {
                    x = x - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.7000000 && prob <= 0.7500000) {
          
                } else if (prob > 0.7500000 && prob <= 0.8000000) {
                    x = x + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
              } else if (prob > 0.8000000 && prob <= 0.8500000) {
                    x = x - 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.8500000 && prob <= 0.9000000) {
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.9000000 && prob <= 0.9500000) {
                    x = x + 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else {
                    printf("Invisible\n");
              }
                    break;
                case 7:
                 if (prob <= 0.5500) {
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.5500000 && prob <= 0.6000000) {
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.6000000 && prob <= 0.6500000) {
                    x = x + 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.6500000 && prob <= 0.7000000) {
                    x = x - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.7000000 && prob <= 0.7500000) {
          
                } else if (prob > 0.7500000 && prob <= 0.8000000) {
                    x = x + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
              } else if (prob > 0.8000000 && prob <= 0.8500000) {
                    x = x - 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.8500000 && prob <= 0.9000000) {
                    x = x - 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.9000000 && prob <= 0.9500000) {
                    x = x + 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else {
                    printf("Invisible\n");
              }
                    break;
                case 8:
                 if (prob <= 0.5500) {
                    x = x + 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.5500000 && prob <= 0.6000000) {
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
                } else if (prob > 0.6000000 && prob <= 0.6500000) {
                    x = x + 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.6500000 && prob <= 0.7000000) {
                    x = x - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.7000000 && prob <= 0.7500000) {
          
                } else if (prob > 0.7500000 && prob <= 0.8000000) {
                    x = x + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
              } else if (prob > 0.8000000 && prob <= 0.8500000) {
                    x = x - 1;
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.8500000 && prob <= 0.9000000) {
                    y = y + 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else if (prob > 0.9000000 && prob <= 0.9500000) {
                    x = x - 1;
                    y = y - 1;
                    printf("(%d, %d)\n", x, y);
                    break;
             } else {
                    printf("Invisible\n");
              }
                    break;

            } // switch
              

        } // while
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


