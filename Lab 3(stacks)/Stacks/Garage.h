#pragma once
#ifndef GARAGE_H_
#define GARAGE_H_

#include<string>
#include "ArrayStack.h"

using namespace std;


struct car {
	char code;
	string plateNo;
	//int carMoveCount;
	string location;

};

template<class ItemType>
class Garage :public ArrayStack<ItemType>
{
private:
	ArrayStack<car>lane1;
	ArrayStack<car>lane2;
	ArrayStack<car>street;
	int numLane1;
	int numLane2;
	int numStreet;

public: 
	Garage();		//constructor
	void arrive(car& carArriving);
	void depart(car& carDeparting);
	//void searcher(car& myCar);
	void printContents();
};
//IMPLEMENTATION
template<class ItemType>
Garage<ItemType>::Garage() {
	numLane1 = 0;
	numLane2 = 0;
	numStreet = 0;
}

template<class ItemType>
void Garage<ItemType>::arrive(car& carArriving) {
	if (numLane1 < MAX_STACK) {
		lane1.push(carArriving);
		numLane1++;
		carArriving.location = "lane1";
		cout << "Car license #" << carArriving.plateNo << " has arrived in lane 1!" << endl;
		
	}
	else {
		if (numLane2 < MAX_STACK) {
			lane2.push(carArriving);
			numLane2++;
			carArriving.location = "lane2";
			cout << "Car license #" << carArriving.plateNo << " has arrived in lane 2!" << endl;;
		}
		else {
			cout << carArriving.plateNo << " was not able to park" << endl;
		}

	}
}
template<class ItemType>
void Garage<ItemType>::depart(car& carDeparting) {

	int numMoves = 0;
	numStreet = 0;
	int numToLoop = numLane1;
	int numToLoopTwo = numLane2;

	cout << endl;
	cout << "Car license #" << carDeparting.plateNo << " is now departing." << endl;
		
	if (carDeparting.location == "lane1") {
		for (int i = 0; i < numToLoop; i++) {
			if (lane1.peek().plateNo != carDeparting.plateNo) {
				street.push(lane1.peek());
				lane1.pop();
				numStreet++;
				numLane1--;
				//numMoves++;
				
			}
			else {
				lane1.pop();
				numLane1--;
				numMoves ++;
				break;
			}
			numMoves++;

		}
		///to push bak into the stack after popping a car from the first stack
		for (int i = 0; i < numStreet; i++) {
			if (numLane1 < MAX_STACK) {
				lane1.push(street.peek());
				numLane1++;
			}
			else if (numLane2 < MAX_STACK) {
					lane2.push(street.peek());
					numLane2++;
			}
			street.pop();
			numMoves += 1;

			
		}
	}
	//checking lane 2 for the car to pop
	else if (carDeparting.location == "lane2") {
		for (int i = 0; i < numToLoopTwo; i++) {
			if (lane2.peek().plateNo != carDeparting.plateNo){
				street.push(lane2.peek());
				lane2.pop();
				//numMoves += 1;
				numStreet++;
				numLane2--;
			}
			else {
				lane2.pop();
				//numMoves += 1;
				numLane2--;
				break;
			}
			numMoves += 1;
			
		}
		//pushing the cars back into the lane after popping a car
		for (int i = 0; i < numStreet; i++) {
			if (numLane1 < MAX_STACK) {
				lane1.push(street.peek());
				numLane1++;
			}
			else if (numLane2 < MAX_STACK) {
					lane2.push(street.peek());
					numLane2++;
					
			}
			street.pop();
			numMoves += 1;
		}
	}
	
	
		cout << "There was(were): " << numMoves << " move(s) for Car #" << carDeparting.plateNo << " to exit from "<<carDeparting.location << endl;
		cout << endl;

		
}



template<class ItemType>
void Garage<ItemType>::printContents() //prints arriving car's license & time
{
	
	cout << "Lane 1: ";
	for (int i = 0; i < numLane1; i++) {
		cout << lane1.peek().plateNo << ", ";
		lane1.pop();

	}
	cout << endl;

	cout << "Lane 2: ";
	//cout << lane2.getTop() << endl;
	for (int i = 0; i < numLane2; i++) {
		cout << lane2.peek().plateNo << ", ";
		lane2.pop();
	}
	cout << endl;
}
#endif // !GARAGE_H_




//ALTERNATE SEARCH AND DEPART FUNCTION
/*
template<class ItemType>
void Garage<ItemType>::searcher(car& myCar) {
	bool didFind = false;
	int numMove = 0;

	//while (!didFind) {
		if (myCar.location == "lane1"){
			for (int i = 0; i < numLane1; i++) {

				if (lane1.peek().plateNo != myCar.plateNo) {
					if (lane2.isFull()) {
						street.push(lane1.peek());
						numStreet++;

					}
					else if (!lane2.isFull()) {
						lane2.push(lane1.peek());

					}
					lane1.pop();
					numLane1--;
				}

				else if (lane1.peek().plateNo == myCar.plateNo) {
					lane1.pop();
					numLane1--;
					didFind = true;
				}
				numMove += 1;

			}

			//to push items back into the stack
			for (int i = 0; i < numStreet; i++) {
				if (numLane1 < MAX_STACK) {
					lane1.push(street.peek());
					numLane1++;
				}
				else if (numLane2 < MAX_STACK) {
					lane2.push(street.peek());
					numLane2++;

				}
				street.pop();
				numMove += 1;
			}

		}

		else if (myCar.location == "lane2") {
			for (int i = 0; i < numLane2; i++) {
				if (lane2.peek().plateNo == myCar.plateNo) {
					lane2.pop();
					numLane2--;
					didFind = true;
				}
				else if (lane2.peek().plateNo != myCar.plateNo) {
					if (lane1.isFull()) {
						street.push(lane2.peek());
						numStreet++;
					}
					else if (!lane1.isFull()) {
						lane1.push(lane2.peek());
					}
					lane2.pop();
					numLane2--;
				}
				numMove += 1;
			}

			//TO push back the items into the stacks
			for (int i = 0; i < numStreet; i++) {
				if (numLane1 < MAX_STACK) {
					lane1.push(street.peek());
					numLane1++;
				}
				else if (numLane2 < MAX_STACK) {
					lane2.push(street.peek());
					numLane2++;

				}
				street.pop();
				numMove += 1;
			}

		}

	//}
		cout << "There was(were): " << numMove << " move(s) for Car #" << myCar.plateNo << " to exit from " << myCar.location << endl;
		cout << endl;

}
*/