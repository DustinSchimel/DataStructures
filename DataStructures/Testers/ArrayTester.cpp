//
//  ArrayTester.cpp
//  DataStructures
//
//  Created by Schimel, Dustin on 2/6/18.
//  Copyright © 2018 Schimel, Dustin. All rights reserved.
//

#include "ArrayTester.hpp"

void ArrayTester :: testArrayUse()
{
    Array<int> firstArray(10);
    
    for (int index = 0; index < 10; index++)
    {
        firstArray.setAtIndex(index, index);
    }
    
    for (int index = 0; index < firstArray.getSize(); index++)
    {
        cout << firstArray[index] << endl;
    }
    
    Array<int> secondArray(400);
    
    cout << secondArray.getSize() << endl;
    cout << firstArray.getSize() << endl;
    
    Array<int> thirdArray(secondArray);
    
    cout << thirdArray.getSize() << endl;
    firstArray = thirdArray;
    cout << firstArray[4] << endl;
    
    thirdArray[5] = 123;
    cout << thirdArray[5] << endl;

    //Testing
    
    Array<double> myFirstArray(100);
    
    Array<double> mySecondArray(myFirstArray);
    
    for (double index = 0; index < myFirstArray.getSize(); index++)
    {
        myFirstArray[index] = index;
    }
    
    mySecondArray = myFirstArray;
    
    cout << "My favorite number is " << mySecondArray.getFromIndex(5) << endl;
    
    mySecondArray.setAtIndex(5, 99);
    
    cout << "Now the number is " << mySecondArray.getFromIndex(5) << "in the second array" << endl;
    
    cout << "But the number is still " << myFirstArray.getFromIndex(5) << " in the first array" << endl;
    
}

void ArrayTester:: testAdvancedArray()
{
    vector<CrimeData> test = FileController :: readCrimeDataToVector("/Users/dsch3401/C++/DataStructures/DataStructures/Data/crime.csv");
    
    int arraySize = test.size();
    
    Array<CrimeData> data(arraySize);
    for (int index = 0; index < arraySize; index++)
    {
        data[index] = test[index];
    }
    
    Timer vectorTimer;
    Timer arrayTimer;
    
    vectorTimer.startTimer();
    cout << test[3425] << endl;
    vectorTimer.stopTimer();
    vectorTimer.displayInformation();
    
    arrayTimer.startTimer();
    cout << data[3425] << endl;
    arrayTimer.stopTimer();
    arrayTimer.displayInformation();
}
