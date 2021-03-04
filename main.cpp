// ----------------------------- Driver File ----------------------------------
// Main (driver file) will initialize the RentalStore Class, read and store 
// customer and movie data from data4customers.txt and data4movies.txt. It will 
// then read commands from data4commands.txt and perform the actions line by 
// line.
// ----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "rentalstore.h"
#include "customer.h"
#include "movie.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
using namespace std;

int main() {
  RentalStore R;
	
  //load all customer info
  ifstream infileCustomer("data4customers.txt");
	if (!infileCustomer) {
		cout << "File could not be opened." << endl;
		return 1;
	}
  for (;;){
		R.buildCustomer(infileCustomer);
		if (infileCustomer.eof())
			break;
	}

  //load all movie info
  ifstream infileMovie("data4movies.txt");
	if (!infileMovie) {
		cout << "File could not be opened." << endl;
		return 1;
	}
  for (;;){
		R.buildMovie(infileMovie);
		if (infileMovie.eof())
			break;
	}

  //perform commands
  ifstream infileCommand("data4commands.txt");
	if (!infileCommand) {
		cout << "File could not be opened." << endl;
		return 1;
	}
  for (;;){
		R.readCommands(infileCommand);
		if (infileCommand.eof())
			break;
	}

  return 0;
}