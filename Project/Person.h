// Parth Gupta
// pg22947

#include<string>
using std::string;

class Person {
private:
  string name; int status_number; int remaining_days_sick;
public:
  Person(string name_input);
  Person();
  string print_name();
  int print_remaining_days();
  void infect(int total_days_sick);
  void inoculate(); 
  void update();
  string status_string();
  bool is_stable();
};

 

