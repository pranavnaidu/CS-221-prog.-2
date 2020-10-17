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


	return 0.0;
}

string CountedQueType::ToString()
{
	return string();
}