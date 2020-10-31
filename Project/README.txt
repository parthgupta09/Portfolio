Infectious Disease Project
Parth Gupta (pg22947)
SDS 322 - Intro to Scientific Programming

Instructions on compiling and running programs for project

Part I - Coding the Basics (39.2)
1. Compile methods of class Person (Person.cc) into object file (Person.o):
   
   icpc -c Person.cc

2. Compile main program for Part I (mainpart1.cc) into object file (mainpart1.o):
   
   icpc -c mainpart1.cc

3. Link newly created methods (Person.o) and main program (mainpart1.o) 
    object files to create executable (part1program):
   
   icpc -o part1program mainpart1.o Person.o

4. Run executable (part1program):

   ./part1program



Part II - Population (39.3)
1. Compile methods of class Person (Person.cc) into object file (Person.o):
   
   icpc -c Person.cc

2. Compile methods of class Population (Population.cc) into object file (Population.o):
   
   icpc -c Population.cc

3. Compile main program for Part II (mainpart2.cc) into object file (mainpart2.o):
   
   icpc -c mainpart2.cc

4. Link newly created methods (Person.o, Population.o) and main program (mainpart2.o) 
    object files to create executable (part2program):
   
   icpc -o part2program mainpart2.o Population.o Person.o

5. Run executable (part2program):

   ./part2program



Part III - Contagion (39.4)
1. Compile methods of class Person (Person.cc) into object file (Person.o):
   
   icpc -c Person.cc

2. Compile methods of class Population (Population.cc) into object file (Population.o):
   
   icpc -c Population.cc

3. Compile main program for Part III (mainpart3.cc) into object file (mainpart3.o):
   
   icpc -c mainpart3.cc

4. Link newly created methods (Person.o, Population.o) and main program (mainpart3.o) 
    object files to create executable (part3program):
   
   icpc -o part3program mainpart3.o Population.o Person.o

5. Run executable (part3program):

   ./part3program



Part IV - Spreading (39.5)
1. Compile methods of class Person (Person.cc) into object file (Person.o):
   
   icpc -c Person.cc

2. Compile methods of class Population (Population.cc) into object file (Population.o):
   
   icpc -c Population.cc

3. Compile main program for Part IV (mainpart4.cc) into object file (mainpart4.o):
   
   icpc -c mainpart4.cc

4. Link newly created methods (Person.o, Population.o) and main program (mainpart4.o) 
    object files to create executable (part4program):
   
   icpc -o part4program mainpart4.o Population.o Person.o

5. Run executable (part4program):

   ./part4program
