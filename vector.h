#pragma once
#include <iostream>
#include <stdexcept>
using std::cout;

template<typename T>
class Vector
{
public:

	Vector()
	{

		realloc(2);

	}
	void pushback(T&& item)
	{
		if (m_size >= m_capacity)
		{
			realloc(m_capacity + 1 / 2 * m_capacity);
			cout << m_size;
		}
		m_data[m_size++] = std::move(item);
	}
	void pushback(const T& item)
	{
		if (m_size >= m_capacity)
		{
			realloc(m_capacity + 1/2 * m_capacity);
			cout << m_size;
		}
		m_data[m_size++] = item;
	}

	const T& operator[](size_t index) const
	{
		return m_data[index];
	}
	T& operator[](size_t index)
	{
		return m_data[index];
	}
	size_t size()
	{
		return m_size;
	}

private:
	T* m_data = nullptr;
	size_t m_size = 0;

	size_t m_capacity = 0;

private:
	void realloc(size_t newCap)
	{
		T* new_data = new T[newCap];

		for (int i = 0; i < m_size; ++i)
			new_data[i] = m_data[i];
		delete[] m_data;
		m_data = new_data;
		m_capacity = newCap;
	}
};