// Parth Gupta
// pg22947

#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Population.h"


// The constructor for the Population class takes in the size of the population
Population:: Population(int npeople):  population(vector<Person>(npeople)) {};


// The probability of contagion - spreading of illness from one sick person to 
// another - is a data member an object of class Population; this method
// collects that probability, given by the user in Part III and IV
void Population::set_probability_of_transfer(float contagion_probability) {
  probability_of_transfer = contagion_probability;
};


// Allows access of objects of class Person (and subsequently their methods),
// which compose objects of class Population. Useful if needed outside of the 
// object.
Person Population::get_person(int person_position) {
    return population.at(person_position);
  };


// Takes in the percent of individuals inoculated, and randomly inoculates
// the necessary number of individuals within the population. Used in Part 
// III and IV. Inoculated inividuals are not susceptible to contagion.
void Population::inoculate(float inoculation_percent) {
  
  // Determines number of people who need to be inoculated, based on 
  // given percentage
  int number_inoculated = inoculation_percent * population.size();
  
  // Sets seed for random number generator later in code
  srand(time(NULL));

  // Inoculates necessary number of individuals in population
  for (int i=1; i<=number_inoculated; i++) {
    bool new_inoculation = false;
    while (!new_inoculation) {
      
      // Randomly chooses person to inoculate
      int inoculated_person = rand() % population.size();

      // Ensures only individuals not previously inoculated become inoculated
      // so that the given percent of inoculated individuals is accurately met
      if (population.at(inoculated_person).status_string()!="inoculated") {
	population.at(inoculated_person).inoculate();
	new_inoculation = true;
      }
    }
  }
};


// This randomly infects one member of the population. This could be any member, 
// even someone inoculated (vaccines are not 100% effective). This first infection
// begins the spread of illness within the population.
void Population::random_infection() {
  int random_person = rand()% population.size();
  population.at(random_person).infect(5);
  population.at(random_person).update();
};


// Counts the number infected (sick) in the population at a given point in time
int Population::count_infected() {
  int number_infected=0;
  for (int i=0; i<population.size(); i++) {
    if (population.at(i).status_string()=="sick") {
      number_infected++;
    }
  }
  return number_infected;  
};


// Updates the health status of every member of the population. Does not account 
// for contagion or inoculation. Used in Part II.   
void Population::update() {
  for (int i=0; i<population.size(); i++) {
    population.at(i).update();
  }
};
 

// Updates the health status of every member of the population. Uses contagion
// probability to randomly infect individuals "neighboring" a sick individual. 
// Also accounts for inoculation - inoculated individuals cannot be infected
// in this manner. Used in Part III.
void Population::update_contagion() {
  for (int i=0; i<population.size(); i++) {
    population.at(i).update();
    if (population.at(i).status_string()=="sick") {

      // Random chance of infecting a neighbor
      float chance_to_infect = (rand()%100) / ((float) 100);
      if (chance_to_infect < probability_of_transfer) {
	int which_direction = rand()%2; // Determines which neighbor to infect
	if (which_direction==0 && i-1>=0) {
	  if (population.at(i-1).status_string()=="susceptible") {
	    population.at(i-1).infect(5); // Ensures neighbor exists and is susceptible
	  }
	} else if (which_direction==1 && i+1<population.size()) {
	  if (population.at(i+1).status_string()=="susceptible") {
	    population.at(i+1).infect(5); // Ensures neighbor exists and is susceptible
	  }
	}
      }
    }
  }
};


// Updates the health of every member of the population. Assumes that a sick
// individual will meet with a set number of people each day, and, based on 
// contagion probability, will randomly infect those people he meets. Also
// accounts for inoculation - inoculated inividuals cannot be infected in this
// manner. Used in Part IV.
void Population::update_spreading() {
  int number_contacted_by_sick = 6; // Number of people a sick person meets daily
  for (int i=0; i<population.size(); i++) {
    population.at(i).update();
    if (population.at(i).status_string()=="sick") {
      
      // "Meeting" present number of people if sick
      for (int count=1; count<=number_contacted_by_sick; count++) { 
	float chance_to_infect = (rand()%100) / ((float) 100); //Random chance to infect
	if (chance_to_infect < probability_of_transfer) {
	  int which_person = rand() % population.size();
	  if (population.at(which_person).status_string()=="susceptible") {
	    population.at(which_person).infect(5); // Ensures person is susceptible
	  }
	}
      }
    }
  }
};

 

