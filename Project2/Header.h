#pragma once
#include <string>
#include <iostream>
#include <locale.h>
#include <iomanip>

using namespace std;
class Vector
{
private:
	int cur_size;
	int buf_size;
	int *els;

public:
	//default constructor
	Vector (){
		cur_size = 0;
		buf_size = 0;
		els = nullptr;
	}

	//size constructor
	Vector(int size)
	{
		this->cur_size = size;
		this->buf_size = size;
		this->els = new int[buf_size];
		for (size_t i = 0; i < buf_size; i++)
			els[i] = 0;
	}

	//copy constructor                                                      
	Vector(const Vector&src)
	{
		this->cur_size = src.cur_size;
		this->buf_size = src.cur_size;

		this->els = new int[cur_size];

		for (int i = 0; i < cur_size; i++)
			els[i] = src.els[i];
	}

	void push_back(const int &e) {
		if (cur_size >= buf_size)
		{
			int *temp;
			buf_size *= 2;
			temp = new int[buf_size];
			for (int i = 0; i < cur_size; i++)
				temp[i] = els[i];

			delete[] els;
			els = temp;
		}
		els[cur_size++] = e;
	}

	void push_insertAt( int pos, const int &e)
	{
		if (cur_size >= buf_size)
		{
			int *temp;
			buf_size *= 2;
			temp = new int[buf_size];
			for (int i = 0; i < cur_size; i++)
			{
				if (i == pos-1)
				{
					temp[i] = e;
					
				}
				else if(i<pos-1)
					temp[i] = els[i];
				else 
					temp[i] = els[i-1];
			}
			delete[] els;
			els = temp;
		}
		else
		{
			int *temp;
			temp = new int[buf_size];
			for (int i = 0; i < cur_size; i++)
			{
				int *temp;
				buf_size *= 2;
				temp = new int[buf_size];
				for (int i = 0; i < cur_size; i++)
				{
					if (i == pos-1)
					{
						temp[i] = e;

					}
					else if (i < pos-1)
						temp[i] = els[i];
					else
						temp[i] = els[i - 1];
				}
			}
			delete[] els;
			els = temp;
		}


	

	}

	void pop_back()
	{
		if (cur_size > 0)
			cur_size--;
	}
	                 
	int& at(int pos)
	{
		return  els[pos - 1]; 
	}

	void print()
	{
		for (int i = 0; i < cur_size; i++)
			cout << left << setw(5) << els[i];
	}
	                      
	//destructor
	~Vector()
	{
		delete[]els;
		els = nullptr;       
	}
};
