#include <iostream>


const int MAXROW = 20;
const int MAXCOL = 60;

void instructions()
 /* Pre: None 
  * Post: Instructions for using the Life program have been printed.
  */
{
    std::cout << "Welcome to Conway's game of Life" << std::endl;    
    std::cout << "This game uses a grid of size "
        << MAXROW << " by " << MAXCOL << " in which" << std::endl;    
    std::cout << "each cell can be occupied by an organism or not." << std::endl;    
    std::cout << "The occupied cells change from generation to generation" << std::endl;    
    std::cout << "according to the number of neighboring cells which are alive." << std::endl;    
}

bool user_says_yes()
{
    int c;
    bool initial_response = true;
    do {
        if (initial_response)
            std::cout << " (y,n) " << std::flush;
        else
            std::cout << "Respond with either y or n:" << std::flush;
        do { // ignore whitespace
            c = std::cin.get();\
        } while (c == '\n' || c == ' ' || c == '\t');
        initial_response = false;
    } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
    return (c == 'y' || c == 'Y');
}

