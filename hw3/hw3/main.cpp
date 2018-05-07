/*
*Created by Vyas Ramankulangara
* 04/01/2018
*COSC 2430
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <map>
#include <iterator>
#include <set>
#include "ArgumentManager.h"
using namespace std;

void replaceDeletimers(string &deletimer)
{
	for (auto &c : deletimer)
	{
		if (c == '{' || c == ',' || c == '}')
		{
			c = ' ';
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "./database input=input1.txt output=output1.txt" << endl;
		return -1;
	}

	ArgumentManager am(argc, argv);
	const string input = am.get("input"), output = am.get("output");

	fstream ifs(input);
	unsigned long long index = -1;
	string data, operation, info;
	unordered_map<string, set<unsigned long long>> hash;
	map<unsigned long long, vector<string>> bst;
	ofstream ofs(output);

	while (ifs >> operation >> info)
	{
		if (operation == "add")
		{
			string attr;
			index++;
			replaceDeletimers(info);
			auto &ptr1 = bst[index];
			istringstream ss(info);
			while (ss >> attr)
			{
				hash[attr].insert(index);
				ptr1.push_back(attr);
			}
		}
		else if (operation == "get")
		{
			string getter;
			replaceDeletimers(info);
			istringstream ss3(info);
			ss3 >> getter;
			auto s1 = hash[getter];
			while (ss3 >> getter)
			{
				set<unsigned long long> intersect;
				auto s2 = hash[getter];
				set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(intersect, intersect.begin()));
				s1 = intersect;
				if (s1.empty())
				{
					break;
				}
			}
			for (auto id : s1)
			{
				ofs << "{";
				bool comma = true;
				auto &ptr = bst[id];
				for (auto &at : ptr)
				{
					if (comma)
						comma = false;
					else
						ofs << ",";
					ofs << at;
				}
				ofs << "}\n";
			}
			ofs << "\n";
		}
		else if (operation == "delete")
		{
			string deleter;
			replaceDeletimers(info);
			istringstream ss4(info);
			ss4 >> deleter;
			auto s1 = hash[deleter];
			while (ss4 >> deleter)
			{
				set<unsigned long long> intersect;
				auto s2 = hash[deleter];
				set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(intersect, intersect.begin()));
				s1 = intersect;
				if (s1.empty())
				{
					break;
				}
			}
			for (auto id : s1)
			{
				auto &ptr = bst[id];
				for (auto att : ptr)
				{
					hash[att].erase(id);
				}
				bst.erase(id);
			}
		}
	}
	ifs.close();
	ofs.close();
}