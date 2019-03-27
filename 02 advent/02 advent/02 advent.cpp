#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

bool onlyOneDifference(std::string first, std::string second)
{
	int countDiffs = 0;
	std::string result = "";
	for (int i = 0; i < first.length(); ++i)
	{
		
		if (first[i] != second[i])
			++countDiffs;	
		else
			result += first[i];
	}
	if (countDiffs == 0 || countDiffs == 1)
	{ 
		std::cout << result << std::endl;
		return true;
	}
	return false;
}

std::vector<std::string> countInputs(std::string filename)
{
	std::ifstream file(filename);
	std::string input;
	std::vector<std::string> vec;
	while (file >> input)
	{
		vec.push_back(input);
	}
	file.close();
	return vec;
}

std::vector<std::string> cutFirstLetters(std::vector<std::string> vec)
{
	for (auto iter = vec.begin(); iter != vec.end(); ++iter)
	{
		*iter = (*iter).substr(1, (*iter).length());
	}
	return vec;
}

void main()
{ 
	auto vec = countInputs("input.txt");
	std::sort(vec.begin(), vec.end(), [](std::string a, std::string b) {return a > b; });
	bool found = false;
	for (auto iterator = vec.begin(); (iterator+1) != vec.end(); ++iterator)
	{
		found = onlyOneDifference(*iterator, *(iterator + 1));
		if (found)
			return;
	}
	// below must be dont if first letter was the only difference, due to sorting
	vec = cutFirstLetters(vec);
	std::sort(vec.begin(), vec.end(), [](std::string a, std::string b) {return a > b; });
	for (auto iterator = vec.begin(); (iterator + 1) != vec.end(); ++iterator)
	{
		found = onlyOneDifference(*iterator, *(iterator + 1));
		if (found)
			return;
	}
	std::cout << "nothing found" << std::endl;
}
