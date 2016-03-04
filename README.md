This program was created for use by members of Book Karaoke. The program captures captures a user-defined list of books and records them to std::vectorstd::string books. It then generates a random number within appropriate range via a Mersenne Twister (std::mt19937; C++ 11 compliant) and declares corresponding element in std::vectorstd::string books to be the winner.

Information on Mersenne Twister https://en.wikipedia.org/wiki/Mersenne_Twister http://www.cplusplus.com/reference/random/mt19937/

Four completely portable functions are provided: 
1) pressEnter (by author), to prompt user to press enter to continue (by author).
2) clearScreen (with relevant citation), for clearing the screen independent of user's system.
3) isValid (by author), for input validation. Completely modular.
4) generateRandNum (by author), for random number generation using a Mersenne Twister. Feel free to adapt those by the author for personal use.

For future: Animated splash screen....? Static ASCII graphic temporarily in place Should improve input validation for menu selection to get rid of allowance entry of whitespace.

(っ ` -´ c) 然る可く
