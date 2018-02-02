#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stopwatch.h"

#define arrSize 25000
#define basecase 20

using namespace std;

template <class T>
void insertionSort(T[], size_t size);
template <class T>
void selectionSort(T[], size_t size);

template<typename T>
void quicksort(T data[], const int size);
template<typename T>
void quicksort(T data[], int first, int last);

template<typename T>
void quicksort2(T data[], const int size, unsigned int bc);
template<typename T>
void quicksort2(T data[], int first, int last, unsigned int bc);



int main()
{
	Stopwatch s;

	srand(time(0));

	int arr[arrSize];
	int arr2[arrSize];

	for (size_t i = 0; i < arrSize; i++)
	{
		arr[i] = rand() % 100;
		arr2[i] = arr[i];
	}

	s.start();
	quicksort(arr2, arrSize);
	s.stop();

	cout << "quicksort 1 = " << s.getDuration() << endl;

	s.start();
	quicksort2(arr, arrSize, 5);
	s.stop();

	cout << "quicksort 2 && bc = " << basecase << "= " << s.getDuration() << endl;
}

template <class T>
void selectionSort(T arr[], size_t size)
{
	//T less = arr[0];
	int index;

	for (size_t i = 0; i < size; i++)
	{
		T less = arr[i];
		index = i;
		for (size_t j = i; j < size; j++)
		{
			// Finding smallest
			if (less > arr[j])
			{
				less = arr[j];
				index = j;
			}
		}
		// Swap
		std::swap(arr[i], arr[index]);
	}
}
template <class T>
void insertionSort(T arr[], size_t size)
{
	int index;
	for (size_t i = 1; i < size; i++)
	{
		index = i;
		while (arr[index - 1] > arr[index] && index > 0)
		{
			std::swap(arr[index - 1], arr[index]);
			index--;
		}
	}
}

//======================================================================
// quicksort()
// This is the "internal" version of quicksort which is called when the 
// largest element in the array has been put last in the array.
//
// The function takes three parameters:
// data[] : The array to sort
// first  : The FIRST position in the array to sort
// last	  : The LAST position in the array to sort
// The function sorts data[] in ascending order.
//======================================================================
template<typename T>
void quicksort(T data[], int first, int last)
{
	// 'lower' points to the first position to check for too-large elements
	// 'upper' points to the first position to check for too-small elements
	// The first position in the array is omitted as it will hold the pivot 
	// element
	int lower = first + 1;
	int upper = last;

	// The middle element (first+last)/2 is selected as pivot element and 
	// swapped into the first position
	std::swap(data[first], data[(first + last) / 2]);

	T pivot = data[first];

	while (lower <= upper)
	{
		// The two pointers have not yet crossed each other - 
		// continue to scan for out-of-place elements
		while (data[lower] < pivot)	lower++;
		while (pivot < data[upper])	upper--;

		if (lower < upper)
		{
			// lower still < upper, so both lower and upper must 
			// point to out-of-place elements. 
			// Swap the elements and advance both pointers
			std::swap(data[lower++], data[upper--]);
		}
		else
		{
			// lower and upper have crossed (or point to the same element)
			// advance lower so they have crossed for sure and the while 
			// loop will break in next iteration
			lower++;
		}
	}

	// At this point, lower and upper have crossed, and the "coarse-grained sorting"
	// is complete. Now swap the pivot element into its place
	std::swap(data[upper], data[first]);

	// If the sub-array to the LEFT of the pivot holds more than 1 element, sort it
	if (first < upper - 1) quicksort(data, first, upper - 1);
	// If the sub-array to the RIGHT of the pivot holds more than 1 element, sort it
	if (upper + 1 < last) quicksort(data, upper + 1, last);

	// When the two recursive calls both complete, the sorting is complete, i.e., 
	// the "merge"-step is empty for quicksort
}

//======================================================================
// This is the "external" version of quicksort - the one that clients will call
// This merely finds the largest element and puts it at the end of the array,
// then callse the "internal" version (see above) to do the actual sorting.
// The function takes two arguments
// data[] : The array to sort
// size  : The size of the array to sort
//======================================================================
template<typename T>
void quicksort(T data[], const int size)
{
	int i, max;
	if (size < 2)	// The array is trivially sorted if it it contains 1 or 0 elements
		return;
	for (i = 1, max = 0; i < size; i++)
	{
		// find the largest element and put it at the end of data[]
		if (data[max] < data[i]) max = i;
	}

	// swap the element into the last position
	std::swap(data[size - 1], data[max]);

	// Call the internal quicksort. 
	// Note that the last position is not included in the sorting
	// as it contains the largest element and thus is already in its final position
	quicksort(data, 0, size - 2);
}



template<typename T>
void quicksort2(T data[], int first, int last, unsigned int bc)
{
	// 'lower' points to the first position to check for too-large elements
	// 'upper' points to the first position to check for too-small elements
	// The first position in the array is omitted as it will hold the pivot 
	// element
	int lower = first + 1;
	int upper = last;

	// The middle element (first+last)/2 is selected as pivot element and 
	// swapped into the first position
	std::swap(data[first], data[(first + last) / 2]);

	T pivot = data[first];

	while (lower <= upper)
	{
		// The two pointers have not yet crossed each other - 
		// continue to scan for out-of-place elements
		while (data[lower] < pivot)	lower++;
		while (pivot < data[upper])	upper--;

		if (lower < upper)
		{
			// lower still < upper, so both lower and upper must 
			// point to out-of-place elements. 
			// Swap the elements and advance both pointers
			std::swap(data[lower++], data[upper--]);
		}
		else
		{
			// lower and upper have crossed (or point to the same element)
			// advance lower so they have crossed for sure and the while 
			// loop will break in next iteration
			lower++;
		}
	}

	// At this point, lower and upper have crossed, and the "coarse-grained sorting"
	// is complete. Now swap the pivot element into its place
	std::swap(data[upper], data[first]);

	// If the sub-array to the LEFT of the pivot holds more than 1 element, sort it
	if (first < (upper - bc)) quicksort2(data, first, upper - 1, bc);
	else insertionSort(&data[first], upper - first);
	// If the sub-array to the RIGHT of the pivot holds more than 1 element, sort it
	if ((upper + bc) < last) quicksort2(data, upper + 1, last, bc);
	else insertionSort(&data[upper], last - upper);

	// When the two recursive calls both complete, the sorting is complete, i.e., 
	// the "merge"-step is empty for quicksort
}

//======================================================================
// This is the "external" version of quicksort - the one that clients will call
// This merely finds the largest element and puts it at the end of the array,
// then callse the "internal" version (see above) to do the actual sorting.
// The function takes two arguments
// data[] : The array to sort
// size  : The size of the array to sort
//======================================================================
template<typename T>
void quicksort2(T data[], const int size, unsigned int bc)
{
	int i, max;
	if (size < 2)	// The array is trivially sorted if it it contains 1 or 0 elements
		return;
	for (i = 1, max = 0; i < size; i++)
	{
		// find the largest element and put it at the end of data[]
		if (data[max] < data[i]) max = i;
	}

	// swap the element into the last position
	std::swap(data[size - 1], data[max]);

	// Call the internal quicksort. 
	// Note that the last position is not included in the sorting
	// as it contains the largest element and thus is already in its final position
	quicksort2(data, 0, size - 2, bc);
}