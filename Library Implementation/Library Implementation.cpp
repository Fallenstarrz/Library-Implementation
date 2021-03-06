// Implement a minimum of 5 Boost functions in a C++ program.  
// Document which functions you utilized and why in a short document, or explain that as comments in your program.
// 

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <boost/foreach.hpp>
#include <boost/algorithm/cxx11/is_sorted.hpp>
#include <boost/algorithm/cxx14/equal.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/algorithm/copy.hpp>

// Function to generate random number
int generateRandomNumber()
{
	int number = rand() % 10;
	return (number);

	// The boost random library was used before being replaced with the STL version.
	// The boost version was a pseudo random number generator that refused to accept time seeds
	// and didn't like it when I passed a reference to this function to seed the generator.
	// I spent about 2 hours trying to make it work with various solutions found on the internet,
	// before I decided that the time I was investing in it wasn't worth it and chose a different boost function instead.
}

// Function to add random number to List
std::vector<int> addRandomToList(int x, std::vector<int> list)
{
	int num = x;
	list.push_back(num);
	return (list);

}

// Reverse List Print
void printIndividualValuesInReverse(std::vector<int> list)
{
	BOOST_REVERSE_FOREACH(int i, list)
	{
		std::cout << list[i];
	}
	std::cout << std::endl;

	//I have used for each loops in UE4 and Unity, but this one doesn't quite work the same way.
	// It also comes equip with sparatic bugs that sometimes skips elements, which is extremely irritating.
	// I will probably use other methods I learned using the stl for loop while researching this in its place.
	// It was fun to play with and the bugs taught me a lot about more advanced programming methods, so I decided
	// to keep this as a reminder.

	// Boost Function 1
}

// Function to check if the lists are sorted
void checkSortedList(std::vector<int> list)
{
	if (boost::algorithm::is_sorted(list))
	{
		std::cout << "This list is sorted" << std::endl;
	}
	else
	{
		std::cout << "This list is not sorted" << std::endl;
	}

	// I chose to use the boost is_sorted to check and see if the list of numbers were sorted in ascending order.
	// There are also ways to use other boost functions to check if is_decending, is_ascending and additional ones
	// That I found pretty cool. Maybe I will use them in the future, but I wanted to make sure that all 5 of my 
	// chosen functions worked in the same program to avoid complicating the readability.

	// Boost function 2
}

// Function to sort both lists
std::vector<int> sortList(std::vector<int> list)
{
	boost::range::sort(list);
	return(list);

	// I chose to use boost sort here. It seemed fitting for working with numbers, but I learened in my research
	// that it can be used for so much more.. I hope to continue to expand on the things I can do with the boost
	// library over time. There are still a lot of things I don't understand.

	// Boost Function 3
}

// Function to check if both functions are equal
void compareLists(std::vector<int> firstList, std::vector<int> secondList)
{
	if (boost::algorithm::equal(firstList.begin(), firstList.end(), secondList.begin(), secondList.end()))
	{
		std::cout << "The Lists are the same" << std::endl;
	}
	else
	{
		std::cout << "The Lists are not the same" << std::endl;
	}

	// I used boost equal to compare the two arrays. I chose to use this because this function takes a while to build without
	// some of the skills learned while researching the boost library.

	// Boost Function 4
}

// Function to print lists
void displayLists(std::vector<int> list)
{
	boost::range::copy(list, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	// I used boost copy to do a print of the vectors. I chose to use this because it is much easier than iterating through the
	// vectors by hand.

	// Boost Function 5
}



int main()
{
	// Vector declations
	std::vector<int> list1;
	std::vector<int> list2;

	// Random number seed
	srand(static_cast<unsigned int>(time(0)));

	// Random Numbers below
	for (int i = 0; i < 10; i++)
	{
		list1 = addRandomToList(generateRandomNumber(), list1);
	}
	for (int i = 0; i < 10; i++)
	{
		list2 = addRandomToList(generateRandomNumber(), list2);
	}

	//Unsorted Lists
	displayLists(list1);
	displayLists(list2);
	system("pause");

	//Sorted Lists
	std::cout << std::endl;
	list1 = sortList(list1);
	list2 = sortList(list2);
	displayLists(list1);
	displayLists(list2);
	system("pause");

	//Check Sorted
	std::cout << std::endl;
	checkSortedList(list1);
	checkSortedList(list2);
	system("pause");

	//Reverse Print
	std::cout << std::endl;
	printIndividualValuesInReverse(list1);
	printIndividualValuesInReverse(list2);
	system("pause");

	// Check is lists are the same
	std::cout << std::endl;
	compareLists(list1, list2);

	std::cout << std::endl;
	system("pause");

    return 0;
}

