// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
#include <map>
std::string infx2pstfx(std::string inf) {
  TStack<char> stack;
	std::string res = "";

	std::map<char, int>prior = { {'(', 0}, {')', 1}, {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3} };

	for (int i = 0; i < inf.length(); i++) 
	{
		if (inf[i] >= '1' && inf[i] <= '9') 
		{
			res += inf[i];
		}
		else if (inf[i] == '(')
		{
			stack.push(inf[i]);
		}
		else if (inf[i] == ')')
		{
			while (stack.get() != '(')
			{
				res += stack.get();
				stack.pop();
			}
			stack.pop();
		}
		else
		{
			while (!stack.isEmpty() && prior[stack.get()] >= prior[inf[i]])
			{
				res += stack.get();
				stack.pop();
			}
			stack.push(inf[i]);
		}
	}

	while (!stack.isEmpty()) {
		res += stack.get();
		stack.pop();
	}
	//add " "
	std::string fres = "";
	for (int i = 0; i < res.size(); i++) {
		fres += res[i];
		fres += " ";
	}
	fres.resize(fres.size()-1); //delete last " "
	return fres;
}

int eval(std::string pst) {
  int temp1 = 0;
	int temp2 = 0;
	TStack<int> stack;
	for (int i = 0; i < pst.length(); i++)
	{
		if (pst[i] >= '1' && pst[i] <= '9')
		{
			stack.push(pst[i] - '0');
		}
		if (pst[i] == '+' || pst[i] == '-' || pst[i] == '*' || pst[i] == '/')
		{
			temp1 = stack.get();
			stack.pop();
			temp2 = stack.get();
			stack.pop();
			if (pst[i] == '+')
			{
				stack.push(temp1 + temp2);
			}
			else if (pst[i] == '-')
			{
				stack.push(temp2 - temp1);
			}
			else if (pst[i] == '*')
			{
				stack.push(temp1 * temp2);
			}
			else if (pst[i] == '/')
			{
				stack.push(temp2 / temp1);
			}
		}
	}
	return stack.get();
}
