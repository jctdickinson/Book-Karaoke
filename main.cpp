/*
 Book Karaoke Mersenne Twister beta v1.1
 By JCT Dickinson © 2016 February 2
 https://www.github.com/JCTDickinson
 
 Using Xcode 7.2.1
 
 */


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <random>
#include <cctype>

// Splash screen
void splash();
// Prompts user to press <ENTER> to continue
void pressEnter();
// Portable screen-clearing function that identifies user's system
void clearScreen();
// Portable input validation function
void isValid(std::string& str, int& x, std::string valid, std::string invalidMessage);
// Portable random number generator function
int generateRandNum(const int& x, const int& n);



int main()
{
    
    char continu = 'Y';                             // Captures choice to continue running, or quit
    
    do
    {
        int numBooks = 0;                           // For number of books
        std::string strNumBooks;                    // User input for number of books; to be converted to int numBooks
        std::string input;                          // User input for vector books
        std::vector<std::string> books;             // Holds input
        
        splash();
        
        while (1)
        {
            std::cout << "How many books have been nominated?" << std::endl;
            isValid(strNumBooks, numBooks, "1234567890", "That is not a number. Try again.");
            std::cout << "You have entered " << numBooks << " for the number of nominations." << std::endl;
            std::cout << "Is this correct? Enter 'Y' to continue, or anything else to retry." << std::endl;
            std::cin >> continu;
            if (toupper(continu) != 'Y')
            {
                std::cin.ignore(INT_MAX, '\n');
                clearScreen();
                continue;
                
            }
            else
            {
                std::cin.ignore(INT_MAX, '\n');
                clearScreen();
                break;
            }
        }
        
        
        while (1)
        {
            for (int i = 0; i < numBooks; i++)
            {
                std::cout << "Please enter the name of book " << (i + 1) << "." << std::endl;
                getline(std::cin, input);
                books.push_back(input);
            }
            
            std::cout << "You have entered the following books:" << std::endl;
            
            for (int i = 0; i < books.size(); i++)
            {
                std::cout << (i + 1) << ". " << books[i] << std::endl;
            }
            std::cout << "Is this correct? Enter 'Y' to continue, or anything else to retry." << std::endl;
            std::cin >> continu;
            if (toupper(continu) != 'Y')
            {
                books.clear();
                std::cin.ignore(INT_MAX, '\n');
                clearScreen();
                continue;
            }
            else
            {
                std::cin.ignore(INT_MAX, '\n');
                clearScreen();
                break;
            }
        }
        
        std::cout << "Let's roll the dice..." << std::endl;
        std::cout << "Just kidding. Dice are for losers. This program uses a Mersenne Twister, "
        << "which gets much closer to true randomness than dice would." << std::endl;
        std::cout << "...\n...\n..." << std::endl;
        std::cout << "Okay. We have a winner. Continue when you're ready." << std::endl;
        pressEnter();
        
        // For debugging use myvector.at(range1, range2)
        // Throws std::out_of_range error
        std::cout << books[generateRandNum(0, (numBooks - 1))] << " is your new book. I hope it doesn't suck." << std::endl;
        
        std::cout << "Would you like to run the program again? Enter 'Y' to continue, or anything else to quit." << std::endl;
        std::cin >> continu;
        if (toupper(continu) != 'Y')
        {
            std::cout << "Goodbye." << std::endl;
            break;
        }
        else
        {
            books.clear();
            std::cin.ignore(INT_MAX, '\n');
            clearScreen();
        }
        
    }while (toupper(continu) == 'Y');
    
    
    return 0;
}

void splash()
{
    // Small slant ASCII font from http://patorjk.com/software/taag
    std::cout << "   ___            __     __ __                   __" << std::endl;
    std::cout << "  / _ )___  ___  / /__  / //_/__ ________ ____  / /_____ " << std::endl;
    std::cout << " / _  / _ \\/ _ \\/  '_/ / ,< / _ `/ __/ _ `/ _ \\/  '_/ -_)" << std::endl;
    std::cout << "/____/\\___/\\___/_/\\_\\ /_/|_|\\_,_/_/  \\_,_/\\___/_/\\_\\__/" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Book Karaoke Mersenne Twister beta v1.1" << std::endl;
    std::cout << "By JCT Dickinson © 2016" << std::endl;
    std::cout << "https://www.github.com/JCTDickinson" << std::endl << std::endl;
    
    pressEnter();
    clearScreen();
    
    std::cout << "Welcome to the Book Karaoke Mersenne Twister." << std::endl << std::endl;
    std::cout << "This program will take a list of nominated books and choose one at random as the winner." << std::endl << std::endl;
    
    pressEnter();
    clearScreen();
}

// Standard function
void pressEnter()
{
    std::cout << "Press <ENTER> to continue." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// From http://stackoverflow.com/questions/228617/how-do-i-clear-the-console-in-both-windows-and-linux-using-c
// Note: Although "TERM environment variable not set." may display if run through an IDE terminal; code is valid
void clearScreen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

// Completely modular function
void isValid(std::string& str, int& x, std::string valid, std::string invalidMessage)
{
    while (1)
    {
        getline(std::cin, str);
        if (str.find_first_not_of(valid) != std::string::npos || str.length() == 0)
        {
            std::cout << invalidMessage << std::endl;
            continue;
        }
        else
            break;
    }
    x = atoi(str.c_str());       // Converts string to int
}

// Completely modular function for randomizing numbers
int generateRandNum(const int& x, const int& n)
{
    static std::random_device randNum;                                  // Obtain random number from hardware
    static std::mt19937 twister(randNum());                             // Seed generator via standard mersenne_twisting_engine
    static std::uniform_int_distribution<int> distr;                    // Type of distribution
    
    distr.param(std::uniform_int_distribution<int>::param_type(x, n));  // Range
    return distr(twister);
}