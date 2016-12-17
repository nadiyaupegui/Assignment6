#ifndef SORT_H
#define SORT_H

#include <string>
#include <cstdlib> //for exit
#include <iostream>
#include <fstream>
#include <ctime>
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
    void printArr(char c) const;
    int getSize() const;

    void quick();
    void quickSort(int left, int right);
    int partition(int left, int right);

    void merge();
    void subMerge(T* arr, int left, int right);
    void merge(T* arr, int left, int right);
    void insertion();
    void bubble();



private:
    int size;
    T* quickArr;
    T* mergeArr;
    T* insertionArr;
    T* bubbleArr; 
};

template <class T>
Sort<T>::Sort():size(0)
{
    quickArr = NULL;
    mergeArr = NULL;
    insertionArr = NULL;
    bubbleArr = NULL;

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

    inStream >> size;
    if (size < 1)
    {
	cout << "Error. Invlaid size given." << endl;
	exit(1);
    }
    
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
int Sort<T>::getSize() const
{
    return size;
}

template <class T>
void Sort<T>::printArr(char c) const
{
    if (size == 0)
    	return;

    T* arr;
    if (c == 'b')
        arr = bubbleArr;
    else if (c == 'm')
        arr = mergeArr;
    else if (c == 'i')
        arr = insertionArr;
    else if (c == 'q')
        arr = quickArr;
    else
        return;


    for(int i = 0; i < size; ++i)
    {
	cout << arr[i] << " ";
    }
    cout << endl;
}

template <class T>
void Sort<T>::quick()
{
    if (size == 0)
	return;
    quickSort(0, size - 1);
}


template <class T>
void Sort<T>::quickSort(int left, int right)
{
    
    int index = partition(left, right);

    if (left < index - 1)
    {
	quickSort(left, index - 1);
    }

    if (index < right)
    {
	quickSort(index, right);
    }
}


template <class T>
int Sort<T>::partition(int left, int right)
{
    T pivot = quickArr[(left + right) / 2]; //choose pivot point
	
    while (left <= right)
    {
    //find element on the left that belongs on the right side
    	while (quickArr[left] < pivot)
	{
	    left++;
	}
	//Find element on the right that belongs on the left
	while (quickArr[right] > pivot)
	{
	    right--;
	}
	//Swap numbers and move left and right indicies
	if (left <= right)
	{
 	    T temp = quickArr[left];
	    quickArr[left] = quickArr[right];
	    quickArr[right] = temp;

	    left++;
	    right--;
	}
    }
    return left;
}

template <class T>
void Sort<T>::merge()
{
    subMerge(mergeArr, 0, size - 1);
}


template <class T>
void Sort<T>::subMerge(T* arr, int left, int right)
{
    if(size == 0)
	return;
    if (left < right)
    {
	int m = (left + right)/2;
	subMerge(arr, left, m);
	subMerge(arr, m+1, right);
	merge(arr, left, right);
    }
}


template <class T>
void Sort<T>::merge(T* arr, int left, int right)
{
    int i, j, k, m;
    int n = right - left + 1;
    T* temp = new T[n];

    k = 0;
    m = (left + right)/2;

    for (i = left; i <= m; ++i)
    {
	temp[k++] = arr[i];
    }
    for (j = right; j >= m+1; --j)
    {
	temp[k++] = arr[j];
    }

    i = 0;
    j = n - 1;
    k = left;

    while(i <= j)
    {
	if(temp[i] <= temp[j])
	{
	    arr[k++] = temp[i++];
	}
	else
	{
	    arr[k++] = temp[j--];
	}
    }
}



template <class T>
void Sort<T>::insertion()
{
    if(size == 0)
	return;

    for(int i = 1; i < size; ++i)
    {
	T temp = insertionArr[i];
        int j = i;
        while (j > 0 && insertionArr[j-1] >= temp)
	{
	    insertionArr[j] = insertionArr[j-1];
	    --j;
	}
	insertionArr[j] = temp;
    }    
}


template <class T>
void Sort<T>::bubble()
{
    if(size == 0)
	return;

    for(int i = 0; i < size; ++i)
    {
	for (int j = 0; j < size - 1; ++j)
	{
	    if(bubbleArr[j] > bubbleArr[j+1])
	    {
		T temp = bubbleArr[j+1];
		bubbleArr[j+1] = bubbleArr[j];
		bubbleArr[j] = temp;
	    }
	}
    }
}


#endif //SORT_H
