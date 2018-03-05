//
//  RecursionTester.cpp
//  DataStructures
//
//  Created by Schimel, Dustin on 3/5/18.
//  Copyright © 2018 Schimel, Dustin. All rights reserved.
//

#include "RecursionTester.hpp"

int RecursionTester :: fib(int number)
{
    if ( number == 0 || number == 1 )
    {
        cout << "Reached a base case" << endl;
        return 1;
    }
    else
    {
        cout << "Reached a recursive case with: " << number - 1 << " and " << number - 2 << endl;
        return fib (number - 1) + fib (number - 2);
    }
}

string RecursionTester :: mystery(string word)
{
    if (word.length() == 2)
    {
        return word;
    }
    else
    {
        return word + mystery(word.substr(0, word.length() -2));
    }
    
    //if (word.length() == 1)
    //{
    //    return word;
    //}
    //else
    //{
    //    return word + mystery(word.substr(0, word.length() -1));
    //}
}

void RecursionTester :: testRecursionNumbers()
{
    Timer recursionTimer;
    cout << "Testing fibonacci with 13" << endl;
    recursionTimer.startTimer();
    cout << fib(13) << endl;
    recursionTimer.stopTimer();
    recursionTimer.displayInformation();
}

void RecursionTester :: testRecursionString()
{
    cout << mystery("XO") << endl;
    cout << mystery("Boop") << endl;
    cout << mystery("Doooop") << endl;
}
