//
//  Controller.cpp
//  DataStructures
//
//  Created by Schimel, Dustin on 1/31/18.
//  Copyright © 2018 Schimel, Dustin. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

void Controller :: start()
{
    //Timer codeTimer;
    //codeTimer.startTimer();
    //cout << "Look code on the screen" << endl;
    //codeTimer.stopTimer();
    //codeTimer.displayInformation();
    //codeTimer.resetTimer();
    //codeTimer.startTimer();
    
    //vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/dsch3401/C++/DataStructures/DataStructures/Data/crime.csv");
    
    //for(int index = 200; index < 216; index++)
    //{
    //    cout << index << " is " << myData[index] << endl;
    //}
    
    //codeTimer.stopTimer();
    //codeTimer.displayInformation();
    
    //findMaxAndMin();
    
    //testArray();
    
    ArrayTester myTest;
    myTest.testArrayUse();
    myTest.testAdvancedArray();
}

void Controller :: findMaxAndMin()
{
    Timer searchTimer;
    searchTimer.startTimer();
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/dsch3401/C++/DataStructures/DataStructures/Data/crime.csv");
    
    int minIndex = 0;
    int maxIndex = 0;
    
    for (int index = 1; index < myData.size(); index++)
    {
        if (myData[minIndex] > myData[index])
        {
            minIndex = index;
        }
        
        else if (myData[maxIndex] < myData[index])
        {
            maxIndex = index;
        }
    }
    
    searchTimer.stopTimer();
    cout << "The smallest Crime stat is at " << minIndex << " and it is: " << myData[minIndex] << endl;
    cout << "The largest Crime stat is at " << maxIndex << " and it is: " << myData[maxIndex] << endl;
    searchTimer.displayInformation();
}

void Controller :: testArray()
{
    Array<int>dustinArray(45);
    
    cout << dustinArray.getSize() << endl;
    
    dustinArray[0] = 123;
    dustinArray.setAtIndex(0, 321);
    
    cout << dustinArray[0] << endl;
}
