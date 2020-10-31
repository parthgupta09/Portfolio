// Parth Gupta
// pg22947

#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Population.h"

using std::cout;
using std::cin;
using std::endl;

 
// This program visualizes the health of a population, as one individual
// goes from sick to recovered. Since contagion and inoculation are no
// incorporated in this part, it does not model the spread of disease, but
// rather provides the visualization framework for the later parts.
int main() {

  // Requests size of population from user
  cout << "Give me a population size: ";
  int population_size;
  cin >> population_size;

  // Initializes object of class Population with population size
  Population population1(population_size);
  
  // Randomly infect one member of population
  population1.random_infection();

  // Provides visualization of population health
  for (int day=1; ; day++) {
    cout << "On day " << day << ", " << population1.count_infected() << " are sick: ";
    
    for (int i=0; i<population_size; i++) { 
      if (population1.get_person(i).status_string()=="susceptible") {
	cout << "? ";
      } else if (population1.get_person(i).status_string()=="sick") {
	cout << "+ ";
      } else if (population1.get_person(i).status_string()=="recovered") {
	cout << "- ";
      }
    }
    cout << endl;

    // If nobody remains infected, then the disease has run its course. We then 
    // break out from the loop and end the simulation.
    if (population1.count_infected()==0) {
      cout << "Disease ran its course by day " << day << endl;
      break;
    }  

    // Update the health of every member of the population. In this program, it basically
    // just makes the sick person closer to recovery.
    population1.update();  
  }  


  return 0;
}
 

