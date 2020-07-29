//
//  Data compression using Golomb exponential sequence
//  golomb.c
//
//  by Kelby Webster
//  6/12/20
//
//

#include <stdio.h>
#include <stdbool.h>
#include <time.h>   // for srand call
#include <stdlib.h> // for exit()
#include <math.h>   // for pow()

// Function prototypes
void displayMenu(void);
double distance(int x, int y);
void pick(int x, int y);
void printGolomb(int n);

int main(void) {
    // Initialize variables
    int option;
    int x, y;
    char runAgain = 'Y';
    bool stop = false;
    
    // initial menu display
    displayMenu();
    
    do {
    // Get user input for option
    scanf("%d", &option);
        if(option == 1) {
            srand((unsigned)time(0)); // Generating the seed
            // creates random coordinate values from range of (0,0) to (1023,1023)
            x = rand() % 1023;
            y = rand() % 1023;
            printf("Option chosen: Randomly generated values\n");
            printf("Coordinates are: (%d, %d)\n", x, y);
            pick(x, y);
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
           }
           else if (option == 3) {
               printf("   Exiting program...\n");
               exit(0);
           }
           else if (option != 1 && option != 2 && option != 3)
           {
               printf("Invalid input... please try again.\n");
           }
        
        // ask user to run again
        printf("  Would you like to run the program again? \n  (Enter Y for yes or N for no):\n");
        scanf("%c", &runAgain);
        switch(runAgain) {
            case 'Y':
            case 'y':
                displayMenu();
                break;
            case 'N':
            case 'n':
                stop = true;
                printf("  Exiting program...\n");
                exit(0);
            }
    } while(stop == false);
    return 0;
}


double distance(int x, int y) {
     return (sqrt((pow(x, 2)) + (pow(y, 2))));
 }
 

// Print the first n term
// of Golomb Sequence
void printGolomb(int n)
{
    int dp[n + 1];
  
    // base cases
    dp[1] = 1;
  
    // Finding and printing first
    // n terms of Golomb Sequence.
    // 1/2^n
    for (int i = 2; i <= n; i++)
    {
//        dp[i] = 1 + dp[i - dp[dp[i - 1]]];
        dp[i] = dp[i] + (1 << dp[i]);
        dp[i] = 1/dp[i];

    }
}



 void pick(int x, int y) {
     while (x != 0 && y != 0) { // signals when boat out of range

     // creates random probability
     float prob = (float)rand() / (float)RAND_MAX;
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
     
        // Golomb = special case of geometric distribution
        // parameters: x, y
        // PDF: p(n) = 1/2^n
         switch (location) {
             case 0:
              if (prob <= 0.5000) {
                 x = x - 1;
                 y = y - 1;
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.5000000 && prob <= 0.55000) {
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.55000 && prob <= 0.60000) {
                 x = x + 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.60000 && prob <= 0.650000) {
                 x = x - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.650000 && prob <= 0.700000) {
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.700000 && prob <= 0.750000) {
                 x = x + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
           } else if (prob > 0.750000 && prob <= 0.800000) {
                 x = x - 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.800000 && prob <= 0.850000) {
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.850000 && prob <= 0.900000) {
                 x = x + 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else {
                 printf("Invisible\n");
           }
                 break;
             case 1:
              if (prob <= 0.5000) {
                 y = y - 1;
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.5000000 && prob <= 0.55000) {
                 x = x - 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.55000 && prob <= 0.60000) {
                 x = x + 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.60000 && prob <= 0.650000) {
                 x = x - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.650000 && prob <= 0.700000) {
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.700000 && prob <= 0.750000) {
                 x = x + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
           } else if (prob > 0.750000 && prob <= 0.800000) {
                 x = x - 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.800000 && prob <= 0.850000) {
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.850000 && prob <= 0.900000) {
                 x = x + 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else {
                 printf("Invisible\n");
           }
             case 2:
              if (prob <= 0.5000) {
                 x = x + 1;
                 y = y - 1;
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.5000000 && prob <= 0.55000) {
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.55000 && prob <= 0.60000) {
                 x = x - 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.60000 && prob <= 0.650000) {
                 x = x - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.650000 && prob <= 0.700000) {
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.700000 && prob <= 0.750000) {
                 x = x + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
           } else if (prob > 0.750000 && prob <= 0.800000) {
                 x = x - 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.800000 && prob <= 0.850000) {
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.850000 && prob <= 0.900000) {
                 x = x + 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else {
                 printf("Invisible\n");
           }
                 break;
             case 3:
              if (prob <= 0.5000) {
                  x = x - 1;
                  printf("(%d, %d)\n", x, y);
                  break;
             } else if (prob > 0.5000000 && prob <= 0.55000) {
                  y = y - 1;
                  printGolomb(x);
                  printGolomb(y);
                  printf("(%d, %d)\n", x, y);
                  break;
             } else if (prob > 0.55000 && prob <= 0.60000) {
                  x = x + 1;
                  y = y - 1;
                  printGolomb(x);
                  printGolomb(y);
                  printf("(%d, %d)\n", x, y);
                  break;
          } else if (prob > 0.60000 && prob <= 0.650000) {
                  x = x - 1;
                  y = y - 1;
                  printGolomb(x);
                  printGolomb(y);
                  printf("(%d, %d)\n", x, y);
                  break;
          } else if (prob > 0.650000 && prob <= 0.700000) {
                  printGolomb(x);
                  printGolomb(y);
                  printf("(%d, %d)\n", x, y);
                  break;
             } else if (prob > 0.700000 && prob <= 0.750000) {
                 x = x + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
           } else if (prob > 0.750000 && prob <= 0.800000) {
                 x = x - 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.800000 && prob <= 0.850000) {
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.850000 && prob <= 0.900000) {
                 x = x + 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else {
                 printf("Invisible\n");
           }
                 break;
             case 4:
              if (prob <= 0.5000) {
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.5000000 && prob <= 0.55000) {
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.55000 && prob <= 0.60000) {
                 x = x + 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.60000 && prob <= 0.650000) {
                 x = x - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.650000 && prob <= 0.700000) {
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.700000 && prob <= 0.750000) {
                 x = x + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
           } else if (prob > 0.750000 && prob <= 0.800000) {
                 x = x - 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.800000 && prob <= 0.850000) {
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.850000 && prob <= 0.900000) {
                 x = x + 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else {
                 printf("Invisible\n");
           }
                 break;
             case 5:
              if (prob <= 0.5000) {
                 x = x + 1;
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.5000000 && prob <= 0.55000) {
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.55000 && prob <= 0.60000) {
                 x = x + 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.60000 && prob <= 0.650000) {
                 x = x - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.650000 && prob <= 0.700000) {
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.700000 && prob <= 0.750000) {
                 x = x - 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
           } else if (prob > 0.750000 && prob <= 0.800000) {
                 x = x - 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.800000 && prob <= 0.8500000) {
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.850000 && prob <= 0.900000) {
                 x = x + 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else {
                 printf("Invisible\n");
           }
                 break;
             case 6:
              if (prob <= 0.5000) {
                 x = x - 1;
                 y = y + 1;
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.5000000 && prob <= 0.55000) {
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.55000 && prob <= 0.60000) {
                 x = x + 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.60000 && prob <= 0.650000) {
                 x = x - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.650000 && prob <= 0.700000) {
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.700000 && prob <= 0.750000) {
                 x = x + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
           } else if (prob > 0.750000 && prob <= 0.800000) {
                 x = x - 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.800000 && prob <= 0.850000) {
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.850000 && prob <= 0.900000) {
                 x = x + 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else {
                 printf("Invisible\n");
           }
                 break;
             case 7:
              if (prob <= 0.5000) {
                 y = y + 1;
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.5000000 && prob <= 0.55000) {
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.55000 && prob <= 0.60000) {
                 x = x + 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.60000 && prob <= 0.650000) {
                 x = x - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.650000 && prob <= 0.700000) {
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.700000 && prob <= 0.750000) {
                 x = x + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
           } else if (prob > 0.750000 && prob <= 0.800000) {
                 x = x - 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.800000 && prob <= 0.850000) {
                 x = x - 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.850000 && prob <= 0.990000) {
                 x = x + 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else {
                 printf("Invisible\n");
           }
                 break;
             case 8:
              if (prob <= 0.5000) {
                 x = x + 1;
                 y = y + 1;
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.5000000 && prob <= 0.55000) {
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.55000 && prob <= 0.60000) {
                 x = x + 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.60000 && prob <= 0.650000) {
                 x = x - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.650000 && prob <= 0.700000) {
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
             } else if (prob > 0.700000 && prob <= 0.750000) {
                 x = x + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
           } else if (prob > 0.750000 && prob <= 0.800000) {
                 x = x - 1;
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.800000 && prob <= 0.850000) {
                 y = y + 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else if (prob > 0.850000 && prob <= 0.900000) {
                 x = x - 1;
                 y = y - 1;
                 printGolomb(x);
                 printGolomb(y);
                 printf("(%d, %d)\n", x, y);
                 break;
          } else {
                 printf("Invisible\n");
           }
                 break;

         }
           
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
