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
  
    cout << "Sorting " << sort.getSize() << " elements." << endl;
    cout << endl;

    //Bubble Sort

    cout << "Bubble Sort" << endl;

    time_t endBubble;
    time_t begBubble;
    begBubble = time(NULL);
    cout << "Start: " <<  begBubble << endl;

    sort.bubble();
    
    endBubble = time(NULL);
    cout << "End: " << endBubble << endl;

    double diffBubble = difftime(endBubble, begBubble);
    cout << "Time taken: " << diffBubble << endl;
    cout << endl;

    //Insertion Sort

    cout << "Insertion Sort" << endl;

    time_t endInsertion;
    time_t begInsertion;
    begInsertion = time(NULL);
    cout << "Start: " << begInsertion << endl;    

    sort.insertion();
    
    endInsertion = time(NULL);
    cout << "End: " << endInsertion << endl;

    double diffInsertion = difftime(endInsertion, begInsertion);
    cout << "Time taken: " << diffInsertion << endl;
    cout << endl;
    
    //Merge Sort

    cout << "Merge Sort" << endl;

    time_t endMerge;
    time_t begMerge;
    begMerge = time(NULL);
    cout << "Start: " << begMerge << endl;

    sort.merge();
    
    endMerge = time(NULL);
    cout << "End: " << endMerge << endl;
    double diffMerge = difftime(endMerge, begMerge);
    cout << "Time taken: " << diffMerge << endl;
    cout << endl;   

    //Quick Sort

    cout << "Quick Sort" << endl;

    time_t endQuick;
    time_t begQuick;
    begQuick = time(NULL);
    cout << "Start: " << begQuick << endl; 
 
    sort.quick();
  
    endQuick = time(NULL);
    cout << "End: " << endQuick << endl;

    double diffQuick = difftime(endQuick, begQuick);
    cout << "Time taken: " << diffQuick << endl;
    
    return 0;
}
