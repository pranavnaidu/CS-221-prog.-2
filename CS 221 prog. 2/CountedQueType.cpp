//************************************************************************************************************
//CountedQueType class implementation

#include <iostream>
#include "CountedQueType.h"

void CountedQueType::Enqueue(ExpenseType newExpense) {

	try {
		QueType::Enqueue(newExpense);
		length++;
	}
	catch (FullQueue) {
		throw FullQueue();
	}
}

void CountedQueType::Dequeue(ExpenseType& expense) {

	try {
		QueType::Dequeue(expense);
		length--;
	}
	catch (EmptyQueue) {
		throw EmptyQueue();
	}
}

int CountedQueType::GetLength() const {

	return length;
}

CountedQueType::CountedQueType(int max) : QueType(max) {

	length = 0;
}

double CountedQueType::GetTotalExpenses() {

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

void CountedQueType::MakeEmpty() {

	QueType::MakeEmpty();
	length = 0;

}
