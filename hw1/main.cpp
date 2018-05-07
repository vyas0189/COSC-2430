#include <iostream>
#include <fstream>
#include <string>
#include "ArgumentManager.h"
#include "node.h"
using namespace std;

/*
Help from Sarah Syed
*/

void getKeys(string one, string a[], int numKeys) {
	int loc1 = 1;
	int loc2 = one.find(":", loc1);
	for (int i = 0; i < numKeys; i++) {
		if (i == numKeys - 1) {
			loc2 = one.find(":", loc1);
			a[i] = one.substr(loc1, loc2 - loc1);
		}
		else {
			a[i] = one.substr(loc1, loc2 - loc1);
			loc1 = one.find(",", loc2) + 1;
			loc2 = one.find(":", loc1);
		}
	}
}

void findKey(string* k, int numKeys, string* a, int numAtt, int* s) {
	for (int i = 0; i<numAtt; i++) {
		for (int j = 0; j<numKeys; j++) {
			if (k[j] == a[i]) {
				s[i] = j;
			}
		}
	}
}

void extractEntries(string* import, string* clean, int size, int govCount, int keyCount, int numOKeys) {
	int end = 0, loc1 = 0, loc2 = 0;
	for (int j = 0; j < size; j++) {
		end = import[j].size();
		loc1 = import[j].find(":", 1) + 1;
		loc2 = import[j].find(",", loc1);
		for (int i = 0; i < govCount; i++) {
			if ((i == govCount - 1) && (govCount == numOKeys)) {
				loc2 = import[j].find("}", loc1);
				clean[j] = clean[j] + " " + import[j].substr(loc1, loc2 - loc1);
			}
			else if (i == govCount - 1) {
				loc2 = import[j].find(",", loc1);
				clean[j] = clean[j] + " " + import[j].substr(loc1, loc2 - loc1);
			}
			else {
				loc1 = import[j].find(":", loc2) + 1;
				loc2 = import[j].find(",", loc1);
			}
		}
	}
}

int getNumberOfKeys(string line) {
	int end = line.size();
	int counter = 0;
	for (int i = 0; i<end; i++) {
		if (line[i] == ':') {
			counter++;
		}
	}
	return counter;
}

void swap(string *&a, string *&b) {
	string *temp = a;
	a = b;
	b = temp;
}

void insertionSort(string* origin, string* arr, int n)
{
	int i, j;
	string key1, key2;
	for (i = 1; i < n; i++)
	{
		key1 = arr[i];
		key2 = origin[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key1)
		{
			arr[j + 1] = arr[j];
			origin[j + 1] = origin[j];

			j = j - 1;

		}
		arr[j + 1] = key1;
		origin[j + 1] = key2;
	}
}

void selectionSort(string* fromFile, string* listToArray, int size)
{
	for (int i = 0, j, least; i < size - 1; i++)
	{
		for (j = i + 1, least = i; j < size; j++)
		{
			if (listToArray[j] < listToArray[least])
			{
				least = j;
			}
			if (i != least)
			{
				swap(listToArray[least], listToArray[i]);
				swap(fromFile[least], fromFile[i]);
			}
		}
	}
}

void swap(string* arr, int a, int b) {
	string placeholder;
	placeholder = arr[a];
	arr[a] = arr[b];
	arr[b] = placeholder;
}

void merge(string* records, string* attributes, int start, int mid, int end) {

	int size1 = mid - start + 1;
	int size2 = end - mid;

	string *tempAttLeft = new string[size1]();
	string *tempAttRight = new string[size2]();
	string *tempRecLeft = new string[size1]();
	string *tempRecRight = new string[size2]();
	int i, j, k;

	for (i = 0; i < size1; i++) {
		tempAttLeft[i] = attributes[start + i];
		tempRecLeft[i] = records[start + i];
	}
	for (j = 0; j < size2; j++) {
		tempAttRight[j] = attributes[mid + 1 + j];
		tempRecRight[j] = records[mid + 1 + j];
	}
	i = 0;
	j = 0;
	k = start;
	while (i < size1 && j < size2) {
		if (tempAttLeft[i] <= tempAttRight[j]) {
			records[k] = tempRecLeft[i];
			attributes[k] = tempAttLeft[i];
			i++;
		}
		else
		{
			records[k] = tempRecRight[j];
			attributes[k] = tempAttRight[j];
			j++;
		}
		k++;
	}

	while (i < size1) {
		attributes[k] = tempAttLeft[i];
		records[k] = tempRecLeft[i];
		i++;
		k++;
	}
	while (j < size2) {
		attributes[k] = tempAttRight[j];
		records[k] = tempRecRight[j];
		j++;
		k++;
	}
	delete[]tempAttLeft;
	delete[]tempAttRight;
	delete[]tempRecLeft;
	delete[]tempRecRight;
}


void mergeSort(string records[], string attribute[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(records, attribute, start, mid);
		mergeSort(records, attribute, mid + 1, end);
		merge(records, attribute, start, mid, end);
	}

}

void quickSort(string records[], string attribute[], int start, int end) {
	int mid = (start + end) / 2;
	string pivot = attribute[mid];
	int i = start, j = end;
	string temp1;
	string temp2;

	while (start < j || i < end) {
		while (attribute[i] < pivot) {
			i++;
		}
		while (attribute[j] > pivot) {
			j--;
		}
		if (i <= j) {
			temp1 = attribute[i];
			temp2 = records[i];
			attribute[i] = attribute[j];
			records[i] = records[j];
			attribute[j] = temp1;
			records[j] = temp2;
			i++;
			j--;
		}
		else {
			if (start < j) {
				quickSort(records, attribute, start, j);
			}
			if (i < end) {
				quickSort(records, attribute, i, end);
			}
			return;
		}
	}

}


void heapify(string records[], string attribute[], int n, int i)
{
	string temp1;
	string temp2;
	int highest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < n && attribute[left] > attribute[highest])
	{
		highest = left;
	}
	if (right < n && attribute[right] > attribute[highest]) {
		highest = right;
	}
	if (highest != i)
	{
		temp1 = attribute[i];
		temp2 = records[i];
		attribute[i] = attribute[highest];
		records[i] = records[highest];
		attribute[highest] = temp1;
		records[highest] = temp2;
		heapify(records, attribute, n, highest);
	}
}

void heapSort(string records[], string attribute[], int numRec)
{
	string temp1;
	string temp2;
	for (int i = numRec / 2 - 1; i >= 0; i--)
	{
		heapify(records, attribute, numRec, i);
	}

	for (int i = numRec - 1; i >= 0; i--)
	{
		temp1 = attribute[0];
		temp2 = records[0];
		attribute[0] = attribute[i];
		records[0] = records[i];
		attribute[i] = temp1;
		records[i] = temp2;
		heapify(records, attribute, i, 0);

	}
}

void run(string num, string* arr1, string* arr2, int size) {
	bool run = true;
	while (run) {
		if (num == "select") {
			selectionSort(arr1, arr2, size);
			run = false;
		}
		else if (num == "insert") {
			insertionSort(arr1, arr2, size);
			run = false;
		}
		else if (num == "merge") {
			mergeSort(arr1, arr2, 0, size - 1);
			run = false;
		}
		else if (num == "quick") {
			quickSort(arr1, arr2, 0, size - 1);
			run = false;
		}
		else if (num == "heap")
			heapSort(arr1, arr2, size);
			run = false;
		}
}

int main(int argc, char* argv[]) {

	if (argc < 4) {
		cout << " ./sort input = in1.txt attributes = att1.txt output = out1.txt sort = quick"  << endl;
		return -1;
	}
	ArgumentManager am(argc, argv);
	const string input = am.get("input");
	const string outputFile = am.get("output");
	const string attribute = am.get("attributes");
	const string sort = am.get("sort");

	linkedList record(input);
	record.readFromFile();
	record.fillArray();

	int numRecords = record.counter;
	string* recArray = record.listToArray;

	record.destroy();

	linkedList attributes(attribute);
	attributes.readAttributes();
	attributes.fillArray();
	int numAttr = attributes.counter;
	string* attributesFromFile = attributes.listToArray;
	attributes.destroy();

	int numKeys = getNumberOfKeys(recArray[0]);
	string* key = new string[numKeys];
	getKeys(recArray[0], key, numKeys);

	int* search = new int[numAttr];
	findKey(key, numKeys, attributesFromFile, numAttr, search);

	string* extracted = new string[numRecords];
	for (int k = 0; k < numAttr; k++) {
		extractEntries(recArray, extracted, numRecords, search[k] + 1, numAttr, numKeys);
	}

	run(sort, recArray, extracted, numRecords);

	ofstream ofs;
	ofs.open(outputFile);
	for (int i = 0; i<numRecords; i++) {
		if (!recArray[i].empty()) {
			ofs << recArray[i] << endl;
		}
	}
	ofs.close();
}