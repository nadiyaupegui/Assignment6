#ifndef SORT_H
#define SORT_H

#include <string>
#include <cstdlib> //for exit
#include <iostream>
#include <fstream>
using namespace std;


template <class T>
class Sort
{
public:
    Sort();
    Sort(std::string fileIn);
    ~Sort();

    void setArr(std::string fileIn);
    T* getArr(char c) const;

    T* quick();
    T* merge();
    T* insertion();
    T* bubble();

private:
    T* quickArr;
    T* mergeArr;
    T* insertionArr;
    T* bubbleArr;
    
};

template <class T>
Sort<T>::Sort()
{
    //deliberately empty
}


template <class T>
Sort<T>::Sort(std::string fileIn)
{
    setArr(fileIn);
}


template <class T>
Sort<T>::~Sort()
{
    delete [] quickArr;
    delete [] mergeArr;
    delete [] insertionArr;
    delete [] bubbleArr;
}

template <class T>
void Sort<T>::setArr(std::string fileIn)
{
    ifstream inStream;
    inStream.open(fileIn.c_str());
    if (inStream.fail())
    {
	cout <<"Error. File not found." << endl;
	exit(1);
    }

    int size;
    inStream >> size;
    
    quickArr = new T[size];
    mergeArr = new T[size];
    insertionArr = new T[size];
    bubbleArr = new T[size];

    int i = 0;
    while (i < size)
    {
	T next;
	inStream >> next;
	
	quickArr[i] = next;
	mergeArr[i] = next;
	insertionArr[i] = next;
        bubbleArr[i] = next;

	i++;
    }

    inStream.close();
}

template <class T>
T* Sort<T>::getArr(char c) const
{
    if (c == 'b')
	return bubbleArr;
    else if (c == 'm')
	return mergeArr;
    else if (c == 'i')
	return insertionArr;
    else if (c == 'q')
	return quickArr;
    else
	return NULL;
}


template <class T>
T* Sort<T>::quick(){}


template <class T>
T* Sort<T>::merge(){}


template <class T>
T* Sort<T>::insertion(){}


template <class T>
T* Sort<T>::bubble(){}


#endif //SORT_H
