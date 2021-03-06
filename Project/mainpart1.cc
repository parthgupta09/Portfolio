// Parth Gupta
// pg22947

#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Person.h"

using std::cin;
using std::cout;
using std::endl;

// Program tracks the health of one person, from susceptiblity to 
// sickness and finally to recovery
int main() {

  // Requesting user to provide name for object Person
  cout << "Give Person 1 a name: ";
  string name;
  cin >> name;

  // Initializing object person1 of class Person with name
  Person person1(name);

  // Setting seed for random number generator in for loop below
  srand(time(NULL));
  
  // Every iteration of this loop simulates the passage of one day. 
  for (int day=1; ; day++) {
    
    // Updating health of person
    person1.update(); 

    // Uses random number generator to determine if person is "unlucky"
    // and will be infected (5% chance). Note that only a person who is 
    // susceptible - not someone currently sick or recovered - can be infected.    
    float bad_luck =  (rand()%100)  / ((float) 100);
    if (bad_luck>0.95 && person1.status_string()=="susceptible"){
      person1.infect(5);
    }

    // Outputs health status to user
    cout << "On day " << day << ", " << person1.print_name() << " is "	\
	 << person1.status_string();
    if (person1.status_string()=="sick") {
      cout << " (" << person1.print_remaining_days() << " more sick days)" << endl;
    } else {
      cout << endl;
    }

    // If the person is no longer going to be sick (for this simulation, they would
    // be recovered), this if-statement breaks from the loop
    if (person1.is_stable()) {
      break;
    }
  }

  return 0;
}
 

