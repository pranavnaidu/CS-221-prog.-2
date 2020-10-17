#pragma once
#include <iostream>
#include <string>

using namespace std;

class FullQueue {};
class EmptyQueue {};

typedef char ExpenseType;

class QueType { 

public:

	struct ExpenseType {
		string memo;
		double amount;
	};

	ExpenseType new_item;

	QueType(int max);
	QueType();
	~QueType();
	bool isEmpty() const;
	bool isFull() const;
	void Enqueue(ExpenseType newExpense);
	void Dequeue(ExpenseType& expense);
	void MakeEmpty();

private:

	int front;
	int rear;
	ExpenseType* expenses;
	int maxQue = 6;
};
