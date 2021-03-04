// -------------------------------- movie.h -----------------------------------
// This class stores movie information from the data4movies.txt file. It stores
// the movie's title, director, stock and release date.
// ----------------------------------------------------------------------------
#ifndef MOVIE
#define MOVIE
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Movie{
  friend ostream & operator<<(ostream &, const Movie &); // prints movie info

public:
  Movie(); // constructor
  //  title = NULL; // stores title of the movie
  //  director = NULL; // stores director's name
  //  stock = NULL; // stores the stock
  //  year = NULL; // stores the year the movie was released
  //  nextMovie = nullptr;
  ~Movie(); // destructor
  Movie(const Movie& m); // copy constructor
  // title = m.getTitle();
  // director = m.getDirector();
  // stock = m.getStock();
  // year = m.getYear();
  // nextMovie = nullptr;
  string getTitle(); // returns the name of the movie
  // return title;
  string getDirector(); // returns the director of the movie
  // return director;
  int getStock(); // returns the stock of the movie
  // return stock;
  int getYear(); // returns the year the movie was released
  // return year;
  void setStock(int newStock); // sets the stock of the movie
  // if(newStock >= 0){
  //  stock = newStock;
  // }
  bool subtractStock(); //Subtracts -1 from movie stock
  // if(stock > 0){
  //    stock = stock - 1;
  //    return true;
  // }
  // else{
  //    return false;
  // }
  void addStock(); //Adds +1 to movie stock
  // stock = stock + 1;

  // Movie Operator overloads
  // Each operator will be overloaded in their subclass cpp methods
  bool operator<(const Movie& movie) const;
  // 
  // if (movie is classic){
  //    Return true if current object release date is less than param object. 
  //    False otherwise.
  // }
  // if (movie is drama){
  //    Return true if current object director name comes before param
  //    director. False otherwise.
  // }
  // if (movie is comedy){
  //    Return true if current object title comes before title. 
  //    False otherwise.
  // }
  bool operator>(const Movie& movie) const;
  // if (movie is classic){
  //    Return true if current object release date is more than param object. 
  //    False otherwise.
  // }
  // if (movie is drama){
  //    Return true if current object director name comes after param
  //    director alphabetically. False otherwise.
  // }
  // if (movie is comedy){
  //    Return true if current object title comes after param title
  //    alphabetically. False otherwise.
  // }
  bool operator<=(const Movie& movie) const;
  // if (movie is classic){
  //    Return true if current object release date is less than or equal to 
  //    param object. False otherwise.
  // }
  // if (movie is drama){
  //    Return true if current object director name comes before or equal to 
  //    param director. False otherwise.
  // }
  // if (movie is comedy){
  //    Return true if current object title comes before or equal to title. 
  //    False otherwise.
  // }
  bool operator>=(const Movie& movie) const;
  // if (movie is classic){
  //    Return true if current object release date is more or equal to than 
  //    param object. False otherwise.
  // }
  // if (movie is drama){
  //    Return true if current object director name comes after or equals 
  //    param director alphabetically. False otherwise.
  // }
  // if (movie is comedy){
  //    Return true if current object title comes after or equals param title
  //    alphabetically. False otherwise.
  // }
  bool operator==(const Movie& movie) const;
  // if (movie is classic){
  //    Return true if current object equals param object. False otherwise.
  // }
  // if (movie is drama){
  //    Return true if current object director name equals param director. 
  //    False otherwise.
  // }
  // if (movie is comedy){
  //    Return true if current object title equals param title. False 
  //    otherwise.
  // }
  bool operator!=(const Movie& movie) const;
  // if (movie is classic){
  //    Return true if current object doesn't equal param object. False 
  //    otherwise.
  // }
  // if (movie is drama){
  //    Return true if current object director name doesn't equal param
  //    director. False otherwise.
  // }
  // if (movie is comedy){
  //    Return true if current object title doesn't equal param title. False 
  //    otherwise.
  // }
private:
  string title; // stores title of the movie
  string director; // stores director's name
  int stock; // stores the stock
  int year; // stores the year the movie was released
  Movie *nextMovie; // stores movie pointer for hash table
  
};
#endif