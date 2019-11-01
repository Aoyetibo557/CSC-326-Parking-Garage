//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "ArrayStack.h"
#include "Stacks/Garage.h"
#include<fstream>

using namespace std;

void stackTester(StackInterface<std::string>* stackPtr)
{
	string items[] = {"zero", "one", "two", "three", "four", "five"};
	cout << "Empty: " << stackPtr->isEmpty() << endl;
	for (int i = 0; i < 6; i++)
   {
		std::cout<<"Pushing " << items[i] << std::endl;
      bool success = stackPtr->push(items[i]);
      if (!success)
         cout << "Failed to push " << items[i] << " onto the stack." << endl;
	}
   
	cout << "Empty?: " << stackPtr->isEmpty() << endl;
	
	for (int i = 0; i < 5; i++)  // NEEDS TO BE 5 TO AVOID ASSERT ERROR
   {
		cout << "Loop " << i << std::endl;
      cout << "peek1: " << stackPtr->peek() << endl;
		cout << "pop: " << stackPtr->pop() << endl;
		cout << "Empty: " << stackPtr->isEmpty() << endl;
	}
	cout<< "Empty: " << stackPtr->isEmpty() << endl;
   cout << "pop an empty stack: " << endl;
	cout << "pop: " << stackPtr->pop() << endl; // nothing to pop!
   
   cout << "peek into an empty stack (should fail): " << endl;
	cout << "peek: " << stackPtr->peek() << endl; // nothing to peek!
}  // end stackTester

int main()
{
	Garage<car>parkingLot;
	
	car myCars;

	fstream textfile;

	textfile.open("carList.txt");

	if (!textfile) {
		cout << "File Not opened" << endl;
	}

	while (!textfile.eof()) {
		textfile >> myCars.code;
		textfile >> myCars.plateNo;

		if (myCars.code == 'A') {
			parkingLot.arrive(myCars);
		}
		if (myCars.code == 'D') {
			parkingLot.depart(myCars);
		}
	}
	
	cout << endl;
	cout << "Final state of the Stack" << endl;
	parkingLot.printContents();
	


	system("pause");
   return 0;
}  // end main

//OUTPUT
/*
Car license #Car1 has arrived in lane 1!
Car license #Car2 has arrived in lane 1!
Car license #Car3 has arrived in lane 1!
Car license #Car4 has arrived in lane 1!
Car license #Car5 has arrived in lane 1!

Car license #Car3 is now departing.
There was(were): 5 move(s) for Car #Car3 to exit


Car license #Car2 is now departing.
There was(were): 5 move(s) for Car #Car2 to exit


Car license #Car1 is now departing.
There was(were): 5 move(s) for Car #Car1 to exit

Car license #Car6 has arrived in lane 1!
Car license #Car7 has arrived in lane 1!
Car license #Car8 has arrived in lane 1!
Car license #Car9 has arrived in lane 2!
Car license #Car10 has arrived in lane 2!

Car license #Car9 is now departing.
There was(were): 3 move(s) for Car #Car9 to exit


Car license #Car8 is now departing.
There was(were): 2 move(s) for Car #Car8 to exit


Car license #Car7 is now departing.
There was(were): 2 move(s) for Car #Car7 to exit

Car license #Car11 has arrived in lane 2!
Car license #Car12 has arrived in lane 2!
Car license #Car13 has arrived in lane 2!

Car license #Car11 is now departing.
There was(were): 5 move(s) for Car #Car11 to exit

Car license #Car14 has arrived in lane 2!
Car license #Car15 has arrived in lane 2!

Car16 was not able to park

Final state of the Stack
Lane 1: Car8, Car7, Car6, Car5, Car4,
Lane 2: Car15, Car14, Car13, Car12, Car10,

Press any key to continue . . .



*/