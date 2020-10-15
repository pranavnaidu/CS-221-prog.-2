#include <iostream>
#include <string>
#include "QueType.h"

//QueType class implementation

QueType::QueType(int max) {

	maxQue = max + 1;
	front = maxQue - 1;  
	rear = maxQue - 1;
	expenses = new ExpenseType[maxQue];
}

QueType::QueType() { // default class constructor

	// Post: maxQue, front, and rear are initialized, the array to hold the queue elements has been allocated.

	maxQue = 6;
	front = maxQue - 1;
	rear = maxQue - 1;
	expenses = new ExpenseType[maxQue];
}

QueType::~QueType() { // class destructor

	delete[] expenses;
}

void QueType::MakeEmpty() { 

	// Post: front and rear have been reset to empty state.

	front = maxQue - 1;
	rear = maxQue - 1;
}

bool QueType::isEmpty() const {

	// returns is the array is empty or not.

	return (rear == front);
}

bool QueType::isFull() const {

	// returns is the array is full or not.

	return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(ExpenseType newExpense) {

	// Post: if the queue is not full, the new item goes at the end of the queue, otherwise, a FullQueue exception is thrown.

	if (isFull()) {
		throw FullQueue();
	}
	else {
		rear = (rear + 1) % maxQue;
		expenses[rear] = newExpense;
	}
}

void QueType::Dequeue(ExpenseType& expense) {

	// Post: if the queue is not empty, the item at the front of the queue is removed, otherwise, an EmptyQueue exception is thrown.

	if (isEmpty()) {
		throw EmptyQueue();
	}
	else {
		front = (front + 1) % maxQue;
		expense = expenses[front];
	}
}

//************************************************************************************************************
//CountedQueType class implementation

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