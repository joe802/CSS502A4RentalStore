// ----------------------------- customer.h -----------------------------------
// The Customer Class stores customer information and performs basic functions 
// such as setting the Customer data fields and equality/inequality comparison.
// ----------------------------------------------------------------------------
#ifndef CUSTOMER
#define CUSTOMER
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Customer{

  friend ostream & operator<<(ostream &, const Customer &);

  public:
    Customer();   //default constructor
    ~Customer();  //destructor
    Customer(int id, const string &first, const string &last);  //Customer fields are set equal to parameter 
	  Customer(const Customer &);               //copy constructor
	  
    Customer& operator=(const Customer &cust);//copy operator
    bool setCustomer(istream&);               //set Customer fields from data file
	                                            //returns true if the data is set, false when bad data
    String getFirstname(const int customerId) const; //getter for customer firstname
    String getLastname(const int customerId) const;  //getter for custoemr lastname
  	
    bool operator==(const Customer &cust) const;  //equality operator
    // if memory address is same, return true
    // if (customerID != cust.customerID || firstname != cust.firstname || lastname != cust.lastname )
    //   return false;
    // return true;

	  bool operator!=(const Customer &cust) const;  //inequality operater
    // return !(this == &cust);

    void addRentedMovie(Movie* movieRent);
    // rentedMovie.previousRentedMovie = rentedMovie;
    // rentedMovie.thisMovie = movieRent;
    // rentedMovie.isReturned = false;

    void ReturnMovie(Movie* movieRent);
    // rentedMovie *curr = rentedMovie;
    // while (curr != NULL)
    // {
    //   if curr.thisMovie == movieRent
    //     if curr.isReturned == false;
    //        curr.isReturned = true;
    //        break;
    //     else
    //        cout<<"movie has already been returned";
    //   curr = curr.previousRentedMovie;
    // }
    // cout<<"movie not found... check again"

    void printRentals();  //prints all rental records
    // rentedMovie *curr = rentedMovie;
    // while (curr != NULL)
    // {
    //   cout<<curr.thisMovie.info fields
    //   if (isReturned)
    //     cout<<returned;
    //   else
    //     cout<<borrowed;
    //   curr = curr.previousRentedMovie;
    // }

  private:
    //struct rentedMovie represents one rented movie. 
    //Link together for chain of rented Movies
    struct rentedMovie{
      Movie* thisMovie;       //This will point to the rentedMovie of this node
      rentedMovie* previousRentedMovie; //This will point to the previous rentedMovie in the chain
      bool isReturned;        //yes for returned, no for currently borrowed
    }
    int customerID;
    String firstname;
    String lastname;
    rentedMovie *rentedMovie;
    Customer *nextCustomer;
};

#endif