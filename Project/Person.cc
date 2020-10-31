// Parth Gupta
// pg22947

#include<iostream>
#include "Person.h"

// The class Person has a name, a health status indicator (status_number), and
// a member to track the days of illness remaining (remaining_days_sick) if 
// the Person falls sick
Person::Person(string name_input) {
  name = name_input;
  status_number = 0; // Number is used to indicate health; default is susceptible (0)
  remaining_days_sick = -2; // default setting, so initial health is not sick
};


// This constructor provides a default name and requires no input.
// It is used in the class Population (which utilizes objects of class Person).
Person::Person() { 
  name = "Joe"; 
  status_number = 0;
  remaining_days_sick = -2;
};


// Printing name of Person
string Person::print_name() {
  return name;
};


// Printing the remaining days Person is sick
int Person::print_remaining_days() {
  return remaining_days_sick;
};


// "Infects" the Person (makes them sick) for the number of days
// input into the method (provided by the main program)
void Person::infect(int total_days_sick) {
  remaining_days_sick = total_days_sick;
};


// This method "updates" the health status of the Person, simulating the
// passage of one day. It only changes the health status of someone if 
// they are sick/infected, by reducing the number of days remaining in their
// sickness. Otherwise the person's health stays the same.
void Person::update() {
  if (remaining_days_sick>0) {
    status_number = 1;      
    remaining_days_sick--;
  } else if (remaining_days_sick == 0) {
    status_number = -1;
  }
};


// "Inoculates" Person by changing their health status indicator to 
// equal -2. Inoculated person cannot catch sickness from someone else.
void Person::inoculate() {
  status_number = -2;
};


// Outputs the health of Person based on their health status indicator
string Person::status_string() {
  if (status_number==0) {
    return "susceptible"; // susceptible is status 0
  } else if (status_number==1) {
    return "sick"; // sick is status 1
  } else if (status_number==-1) {
    return "recovered"; // recovered (formerly sick, no longer susceptible) is status -1
  } else if (status_number==-2) {
    return "inoculated"; // inoculated (not susceptible) is status -2
  }
};


// If Person is not going to get sick (either recovered or inoculated),
// i.e. if they are stable, this method indicates that.
bool Person::is_stable() {
  if (status_number<=-1) {
    return true;
  } else {
    return false;
  }
};


