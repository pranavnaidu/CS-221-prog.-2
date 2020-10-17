//************************************************************************************************************
//CountedQueType class implementation

#include <iostream>
#include "CountedQueType.h"

void CountedQueType::Enqueue(ExpenseType newExpense) { //adds a new item to the rear of the queue

	try {
		QueType::Enqueue(newExpense);
		length++;
	}
	catch (FullQueue) {
		throw FullQueue();
	}
}

void CountedQueType::Dequeue(ExpenseType& expense) { //removes the item at the front of the queue.

	try {
		QueType::Dequeue(expense);
		length--;
	}
	catch (EmptyQueue) {
		throw EmptyQueue();
	}
}

int CountedQueType::GetLength() const {  //returns the length of the queue

	return length;
}

CountedQueType::CountedQueType(int max) : QueType(max) { //parameterized constructor

	length = 0;
}

double CountedQueType::GetTotalExpenses() { //returns the sum of the expenses as a double number

	double total_sum = 0;
	double temp_amount = 0;
	int temp_queue_elements = CountedQueType::GetLength();

	for (int i = 0; i < temp_queue_elements; i++) {
		Dequeue(new_item);
		temp_amount = new_item.amount;
		total_sum = total_sum + temp_amount;
		Enqueue(new_item);
	} 

	return total_sum;
}

void CountedQueType::MakeEmpty() {  //removes all of the elements of the queue

	QueType::MakeEmpty();
	length = 0;

}
