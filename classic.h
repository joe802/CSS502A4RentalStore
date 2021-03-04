// ------------------------------ classic.h -----------------------------------
// The class 'Classic' is a subclass of class 'Movie'. In addition to inheriting
// all the properties of 'Movie', 'Classic also contains the data items
// 'majorActor' and 'releaseMonth'.
// ----------------------------------------------------------------------------
#ifndef CLASSIC_H
#define CLASSIC_H
#include "movie.h"

class Classic: public Movie {
public:
  Classic();    //Default constructor
  // majorActor = NULL;
  // releaseMonth = NULL;
  ~Classic();   //Destructor
  string getMajorActor(); //Returns majorActor data as String
  //  return majorActor;
  string getReleaseMonth(); //Returns release month as String
  //  return releaseMonth;
  void setMajorActor(string name); //Sets the majorActor String 
  //  majorActor = name;
  void setReleaseMonth(string month); //Sets releaseMonth String
  //  releaseMonth = month;
private:
  string majorActor;  //Stores Classic Movie Major Actor
  string releaseMonth;  //Stores Classic Movie Release Month
};
#endif