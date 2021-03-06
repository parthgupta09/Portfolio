// Parth Gupta
// pg22947

#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Population.h"


using std::cout;
using std::cin;
using std::endl;


// This program visualizes the health of a population, as a randomly
// infected individual is able to spread a contagious disease. Inoculation
// and contagion are considered. Infected individuals have many more 
// opportunities to infect susceptible indivdiuals than they did in the 
// previous part, making this a more realistic simulation.
int main() {

  // Requests size of population from user
  cout << "Give me a population size: ";
  int population_size;
  cin >> population_size;

  // Requests user to provide how contagious the disease is
  cout << "How contagious is the disease (decimal): ";
  float contagion_probability;
  cin >> contagion_probability;

  // Requests user to provide the percent of population inoculated
  cout << "What percent of people were vaccinated (decimal): ";
  float inoculation_percent;
  cin >> inoculation_percent;

  // Initializes object of class Population with population size
  Population population1(population_size);

  // Initializes the contagion probability and inoculates the percent
  // of the population requested by the user
  population1.set_probability_of_transfer(contagion_probability); 
  population1.inoculate(inoculation_percent);

  // Randomly infects one member of population, beginning spread of disease
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
      } else if (population1.get_person(i).status_string()=="inoculated") {
	cout << "* ";
      }
    }   
    cout << endl;

    // If nobody remains infected, then the disease has run its course. We then
    // break out from the loop and end the simulation.
    if (population1.count_infected()==0) {
	cout << "Disease ran its course by day " << day << endl;
	break;
      }  

    // Updates the health of every member. In addition to bringing the sick closer to 
    // recovery, this method allows for the possiblity of sick indivdiuals infecting
    // multiple, random other individuals. Inoculated individuals cannot be infected 
    // in this manner.
      population1.update_spreading();  
    }  


    return 0;
}
 

