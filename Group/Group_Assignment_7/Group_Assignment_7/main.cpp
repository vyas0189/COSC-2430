#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include "classes.h"
using namespace std;

/*
*Vyas Ramankulangara: 100%
Sam Parker: 0%
Got help from Sarah Syed, she walked me through and help me understand the problem
*/

string removeDelimiters(const string &input);
string addDelimiters(const string &input);
Node<Food> *favorite(BST<Food> tree, fstream &ofs);

int main()
{
	fstream ifs("allfood.txt");

	string data, name;
	int calories, category;
	Food food;
	BST<Food> content;
	while (getline(ifs, data))
	{
		istringstream iss(removeDelimiters(data));
		iss >> name >> calories >> category;
		food.setAll(addDelimiters(name), calories, category);
		Node<Food> temp(food);
		content.add(food);
	}
	ifs.close();

	BST<Food> plants, protein, carbs, dairy;
	Stack<Node<Food> *> stk;
	Node<Food> *cu = content.root;
	while ((cu != nullptr) || (!stk.isEmpty()))
	{
		if (cu != nullptr)
		{
			stk.push(cu);
			cu = cu->left;
		}
		else
		{
			cu = stk.pop();
			if (cu->info.category == 1)
			{
				cu->info.goOnDiet();
				plants.insertIntoAVL(cu->info);
			}
			else if (cu->info.category == 2)
			{
				cu->info.goOnDiet();
				protein.insertIntoAVL(cu->info);
			}
			else if (cu->info.category == 3)
			{
				cu->info.goOnDiet();
				carbs.insertIntoAVL(cu->info);
			}
			else if (cu->info.category == 4)
			{
				cu->info.goOnDiet();
				dairy.insertIntoAVL(cu->info);
			}
			cu = cu->right;
		}
	}

	Node<Food> *meal;
	LinkedList<Food> *tracker = new LinkedList<Food>[28];
	for (int today = 0; today < 28; today++)
	{
		tracker[today].day = today;

		meal = plants.dailyMeal();
		meal->info.eatThis();
		tracker[today].push_back(meal->info);
		meal = protein.dailyMeal();
		meal->info.eatThis();
		tracker[today].push_back(meal->info);
		meal = carbs.dailyMeal();
		meal->info.eatThis();
		tracker[today].push_back(meal->info);
		meal = dairy.dailyMeal();
		meal->info.eatThis();
		tracker[today].push_back(meal->info);

		tracker[today].print();
	}

	fstream output("nonFav.txt");

	output << "List Of All Non-Favorite Food Items For The Current Month:" << endl;
	Node<Food> *fPlant = favorite(plants, output);
	Node<Food> *fProtein = favorite(protein, output);
	Node<Food> *fCarbs = favorite(carbs, output);
	Node<Food> *fDairy = favorite(dairy, output);

	output.close();
}

string removeDelimiters(const string &input)
{
	string res;
	int size = input.length();
	for (int i = 0; i < size; i++)
	{
		if (input[i] == ' ')
		{
			res += ',';
		}
		else if (input[i] == ':')
		{
			res += ' ';
		}
		else
		{
			res += input[i];
		}
	}
	return res;
}

string addDelimiters(const string &input)
{
	string res;
	int size = input.length();
	for (int i = 0; i < size; i++)
	{
		if (input[i] == ',')
		{
			res += ' ';
		}
		else
		{
			res += input[i];
		}
	}
	return res;
}

Node<Food> *favorite(BST<Food> tree, fstream &ofs)
{
	if (ofs.is_open())
	{
		int currentMax = 0;
		Stack<Node<Food> *> stack;
		Node<Food> *cu = tree.root, *p = tree.root;
		while ((cu != nullptr) || (!stack.isEmpty()))
		{
			if (cu != nullptr)
			{
				stack.push(cu);
				cu = cu->left;
			}
			else
			{
				cu = stack.pop();
				if (cu->info.favorite == 0)
				{
					ofs << cu->info << endl;
				}
				if (currentMax < cu->info.favorite)
				{
					currentMax = cu->info.favorite;
					p = cu;
				}
				cu = cu->right;
			}
		}
		return p;
	}
	return 0;
}