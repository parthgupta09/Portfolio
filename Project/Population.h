// Parth Gupta
// pg22947

#include<vector>
#include "Person.h"
using std::vector;

class Population {
private:
  vector<Person> population; float probability_of_transfer;
public:
  Population(int npeople);
  void set_probability_of_transfer(float contagion_probability);
  Person get_person(int person_position);
  void inoculate(float inoculation_percent);
  void random_infection();
  int count_infected();   
  void update();
  void update_contagion();  
  void update_spreading();
};
 
 

