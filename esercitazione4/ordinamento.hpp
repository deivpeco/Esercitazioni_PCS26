#pragma once
#include <vector>
#include <iostream>
#include <string>



template<typename T>

void bubble_sort(std::vector<T>& v)
{
	if (v.size() < 2)
	{
		return;
	}
	for (size_t i = 0; i < (v.size()-1); i++) 
	{
		for (size_t j = (v.size()-1); j > i; j--)
		{
			if  (v[j]<v[j-1]) 
			{
				T a = v[j];
				v[j] = v[j-1];
				v[j-1] = a;
			}
		}
	}
}

template<typename T> 

void insertion_sort(std::vector<T>& v)
{
	if (v.size() < 2)
	{
		return;
	}
	for (size_t j = 1; j < v.size(); j++)
	{
		T key = v[j];
		size_t i = j;
		while ( i > 0 && v[i-1] > key) 
		{
			v[i] = v[i-1];
			i--;
		}
		v[i] = key;
	}
}

template<typename T>

void selection_sort(std::vector<T>& v)
{
	if (v.size() < 2)
	{
		return;
	}
	for (size_t i = 0; i < (v.size()-1); i++)
	{
		size_t min = i;
		for (size_t j = i+1; j < v.size(); j++)
		{
			if (v[j] < v[min]) 
			{
				min = j;
			}
		}
		if (min != i)
		{
			T a = v[min];
			v[min] = v[i];
			v[i] = a;
		}
	}
}

template<typename T> 

bool is_sorted(const std::vector<T>& v)
{
	if (v.size() == 0)
	{
		return true;
	}
	for (size_t i = 0; i < (v.size() - 1); i++)
	{
		if (v[i] > v[i+1])
		{
		return false;
		}
	}
	return true;
}

template<typename T>
void print_vector(const std::vector<T>& v)
{
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
}

