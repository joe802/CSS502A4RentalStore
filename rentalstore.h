// --------------------------- rentalstore.h ----------------------------------
// The RentalStore class reads from multiple files containing information on
// movies, customers and a commands file. The class stores information from 
// the movies and customers, and performs commands based off the command file
// such as borrow, return, showing inventory and history.
// ----------------------------------------------------------------------------
#ifndef RENTALSTORE
#define RENTALSTORE
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
#include "customer.h"
using namespace std;

const int MAX_CLASSIC = 201; //Max number hashing for Classics (year-1900)
const int MAX_DRAMA = 27;    //Max number hashing for Drama (26 letters)
const int MAX_COMEDY = 27;   //Max number hashing for Comedy (26 letters)
const int MAX_GENRE = 3;     //Max number hashing for Genre (3 genres)
const int MAX_CUSTOMER = 10; //Max number hashing for Customer (buckets of 100)

class RentalStore{
public:
  RentalStore(); // constructor
  ~RentalStore(); // destructor
  void readCommands(ifstream& infile); // reads from the data4commands.txt
  //while(!inFile.eof()){
    //read line from txt
    //switch (B | R | H | I)
    //case I:
    //  this.inventory();
    //  continue; no more fields
    //case H:
    //  Customer* currentCustomer = 
    //  currentCustomer.printRentals(); //****WILL NEED PUBLIC FIND METHOD
    //case B:
    //  inFile >> customerID;
    //  inFile >> genreType;
    //  inFile >> sortAtr1;
    //  inFile >> sortAtr2;
    //  borrow(customerID, genreType, sortAtr1, sortAtr2);
    //case R:
    //  inFile >> customerID;
    //  inFile >> genreType;
    //  inFile >> sortAtr1;
    //  inFile >> sortAtr2;
    //  borrow(customerID, genreType, sortAtr1, sortAtr2);
    //default:
    //  Print error message for incorrect data and/or incorrect command
  //}
  void buildMovie(ifstream& infile); // reads from data4movies.txt
  //read line from txt
  //if comedy
  //  insertComedy()
  //else if drama
  //  insertDrama()
  //else if classic
  //  insertClassic()
  //else (movie type is invalid (e.g. "Z"))
  //  get rid of line 
  //  output to notify user of the false entry
  
  void buildCustomer(ifstream& infile); // reads from data4customers.txt
  // reads line from txt file
  // while(not at the end of file){
  //    stores customer ID into an int
  //    stores last name into a string
  //    stores first name into a string.
  //    insertCustomer(ID, first name, last name)
  // }
  
  bool borrow(int customerID, char mediaType, string movieType, 
  string movieData); // subtracts 1 to stock for each movie borrowed
  //  Movie* foundMovie = findMovie(mediaType, movieType, movieData);
  //  if(foundMovie.subtractStock()){
  //    Customer* foundCustomer = findCustomer(customerID);
  //    foundCustomer.addRentedMovie(foundMovie);  
  //    return true;
  //  }
  //  else {return false;} //

  bool returns(int customerID, char mediaType, string movieType, 
  string movieData); // adds 1 to stock for each movie returned
  //  Movie* foundMovie = findMovie(mediaType, movieType, movieData);
  //  if(foundMovie.addStock()){
  //    Customer* foundCustomer = findCustomer(customerID);
  //    foundCustomer.returnMovie(foundMovie);  
  //    return true;
  //  }
  //  else {return false;} //
  void inventory(); // outputs the inventory of all items in the store
  //  for(int i = 0; i<= MAX_GENRE){
  //    Loop through each hasTable depending on genreType
  //      Loop through each value of linked list of movies for each hash El
  //        cout << MovieName << movies in stock
  //  }
  void history(int customerID); // outputs all the transactions of a customer
  //  Customer* currentCustomer = findCustomer(customerID);
  //  currentCustomer.printRentals();
private:
  int count; // keeps track of how many movies are stored
  Movie movieGenres[MAX_GENRE];
  Classic hashClassics[MAX_CLASSIC]; // hastable storing classic movies
  Comedy hashComedy[MAX_COMEDY]; // hastable storing comedy movies
  Drama hashDramas[MAX_DRAMA]; // hastable storing dramas movies
  Customer hashCustomers[MAX_CUSTOMER]; // array stores the customers information
  Movie* findMovie(char mediaType, string movieType, string movieData);
  // Movie targetMovie(movieData);
  // if movieType is Classic
  //   int index = year - 1900;
  //   Movie *curr = hashClassics[index];
  // else if movieType is Comedy
  //   int index = converting first character of Title into ASCII;
  //   Movie *curr = hashComedy[index];
  // else if movieType is Drama
  //   int index = converting first character of Director into ASCII;
  //   Movie *curr = hashDrama[index];
  // while (curr != NULL)
  // {
  //   if curr == targetMovie;
  //     return curr;
  // }

  Customer* findCustomer(int customerID)
  // int firstDigit = first digit of customerID;
  // Customer *found;
  // if(hashCustomer[firstDigit].customerID == customerID){
  //    found = hashCustomer[firstDigit];
  // }
  // else{
  //    Customer *current = hashCustomer[firstDigit];
  //    while(current != NULL){
  //      if(current->customerID == customerID){
  //        found = current;
  //        break; 
  //      }
  //      current = current->nextCustomer;
  //      if(current == NULL){
  //
  //      }
  //    }   
  // }
  // return found;
  
  bool insertComedy(int stock, string director, string title, int year);
  //hash by first letter of Title
  //converting first character of Title into ASCII 
  //rest of pseudo code similar to insertClassic
  
  bool insertDrama(int stock, string director, string title,  int year);
  //hash by first letter of Director
  //converting first character of Director into ASCII 
  //rest of pseudo code similar to insertClassic

  bool insertClassics(int stock, string director, string title, string actor, int year);
  //hash by year 
  //int index = year - 1900;
  //Classic *newClassic;
  //newClassic = Classic(stock, director, title, actor, year);
  //if hashClassics[index] is empty
  //  hashClassics[index] = *newClassic;
  //else if collision occurs, go through linked list to find the correct spot
  //  compare newClassic by year, then month, then Major actor
  //  store newClassic ptr in the linked list and update links

  bool insertCustomer(int customerID, string lastName, string firstName);
  // Customer *newCustomer = new Customer(customerID, firstName, lastName);
  // int firstDigit = first digit of customerID;
  // if(hashCustomer[firstDigit] == NULL){
  //    hashCustomer[firstDigit] = newCustomer;  
  // }
  // else{
  //    Customer *current = hashCustomer[firstDigit];
  //    while(current != NULL){
  //        if(current->nextCustomer == NULL){
  //            current->nextCustomer = newCustomer;
  //            break;
  //        }
  //        current = current->nextCustomer;
  //    }
  // }
};

#endif