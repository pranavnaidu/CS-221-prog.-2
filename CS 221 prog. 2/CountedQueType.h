#pragma once
#include <iostream>
#include <string>
#include "QueType.h"

class CountedQueType : public QueType {

public:

	CountedQueType(int max);
	void Enqueue(ExpenseType newExpense);
	void Dequeue(ExpenseType& expense);
	int GetLength() const;
	double GetTotalExpenses();
	string ToString();

private:

	int length;

};