#include <iostream>
// #include <vector>
using namespace std;

struct vector
{
    int _size;
    int _capacity;
    int * _data;

    vector(int size = 0) : _size { size }, _capacity { size }
    {
        this->_data = new int[size];
    }

    vector(int size = 0, int value = 0) : _size { size }, _capacity { size }
    {
        for (int i = 0; i < size; i++)
            this->_data[i] = value;
    }

    ~vector()
    {
        delete [] _data;
    }

    void push_back(int value)
    {
        if(_size == _capacity)
            this->reserve(_capacity == 0 ? 1 : 2 * _capacity);
        
        this->_data[_size] = value;
        ++this->_size;
    }

    void pop_back()
    {
        if (_size == 0)
            return;
        --this->_size;
    }

    int& at(int index)
    {
        if (index < 0 || index >= this->_size)
            throw string("indice invalido");
        return this->_data[index];
    }

    void reserve(int capacity)
    {
        int * _new_data = new int[capacity];

        int quantidade = min(_size, capacity);

        for (int i = 0; i < quantidade; i++)
            _new_data[i] = _data[i];

        this->_size = quantidade;
        this->_capacity = capacity;
        delete [] _data;
        this->_data = _new_data;
    }

    void insert(int * it, int value)
    {
        int pos = it - this->_data;
        if(this->_size == this->_capacity)
            this->reserve(2 * _capacity);
        
        for (int i = this->_size; i > pos; i--)
        {
            this->_data[i] = this->_data[i - 1];
        }

        ++this->_size;
        this->_data[pos] = value;
        
    }

    void erase(int * it) 
    {
        int pos = it - _data;
        for (int i = pos; i < _size - 1; i++)
            _data[i] = _data[i + 1];
        --this->_size;
    }

    int capacity()
    {
        return this->_capacity;
    }

    int size()
    {
        return this->_size;
    }

    int& front()
    {
        return this->_data[0];
    }

    int& back()
    {
        return this->_data[_size - 1];
    }

    int * begin()
    {
        return _data;
    }

    int * end()
    {
        return _data + _size;
    }

};


int main()
{


    return 0;
}