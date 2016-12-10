#include "Sort.h"
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int arc, char** argv)
{
    Sort<double> sort("test.txt");

    cout << "Quick Sort" << endl;
    sort.printArr('q');
    sort.quick();
    sort.printArr('q');
    cout << endl;


    cout << "Insertion Sort" << endl;
    sort.printArr('i');
    sort.insertion();
    sort.printArr('i');
    cout << endl;

    cout << "Bubble Sort" << endl;     
    time_t end;
    time_t beginning;
    beginning = time(NULL);

    sort.printArr('b');
    sort.bubble();   
    sort.printArr('b');
 
    end = time(NULL);
    double diff = difftime(end, beginning);
    cout << "Time taken for bubble sort was " << diff << endl;

 
    return 0;
}
