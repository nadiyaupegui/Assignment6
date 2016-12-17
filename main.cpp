#include "Sort.h"
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int arc, char** argv)
{
    string fileIn = argv[1];
    ifstream inStream;
    inStream.open(fileIn.c_str());
    if(inStream.fail())
    {
	cout << "Error. File not found." << endl;	
	exit(1);
    }    

    Sort<double> sort(fileIn);

    //Bubble Sort
 
    cout << "Bubble Sort" << endl;
    time_t endBubble;
    time_t begBubble;
    begBubble = time(NULL);

    sort.printArr('b');
    sort.bubble();
    sort.printArr('b');

    endBubble = time(NULL);
    double diffBubble = difftime(endBubble, begBubble);
    cout << "Time taken for bubble sort was " << diffBubble << endl;
    cout << endl;

    //Insertion Sort

    time_t endInsertion;
    time_t begInsertion;
    begInsertion = time(NULL);

    cout << "Insertion Sort" << endl;
    sort.printArr('i');
    sort.insertion();
    sort.printArr('i');

    endInsertion = time(NULL);
    double diffInsertion = difftime(endInsertion, begInsertion);
    cout << "Time taken for insertion sort was " << diffInsertion << endl;
    cout << endl;

    //Merge Sort

    time_t endMerge;
    time_t begMerge;
    begMerge = time(NULL);

    cout << "Merge Sort" << endl;
    sort.printArr('m');
    sort.merge();
    sort.printArr('m');

    endMerge = time(NULL);
    double diffMerge = difftime(endMerge, begMerge);
    cout << "Time taken for merge sort was " << diffMerge << endl;
    cout << endl;

    //Quick Sort

    time_t endQuick;
    time_t begQuick;
    begQuick = time(NULL);

    cout << "Quick Sort" << endl;
    sort.printArr('q');
    sort.quick();
    sort.printArr('q');

    endQuick = time(NULL);
    double diffQuick = difftime(endQuick, begQuick);
    cout << "Time taken for quick sort was " << diffQuick << endl;
    cout << endl;

    return 0;
}
