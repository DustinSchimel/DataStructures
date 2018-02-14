//
//  FileController.hpp
//  DataStructures
//
//  Created by Schimel, Dustin on 1/31/18.
//  Copyright © 2018 Schimel, Dustin. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include "../Data/CrimeData.hpp"
#include <string>
#include <fstream>  //handles files
#include <iostream>
#include <vector>
#include <sstream>
#import "../Model/Structures/LinkedList.hpp"

using namespace std;

class FileController
{
public:
    static vector<CrimeData> readCrimeDataToVector(string filename);
};

static LinkedList<CrimeData> readDataToList(string filename);

LinkedList<CrimeData> FileController :: readDataToList(stirng fileName)
{
    LinkedList<CrimeData> crimes;
    
    string curretnCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(fileName);
    
    //If the file exists at that path.
    if (dataFile.is_open())
    {
        //Keep reading until you are at the end of the file.
        while (!datFile.eof())
        {
            //Grab each  line from the CSV seperated by the carriage return character.
            getline(dataFile, currentCSVLine, '\r');
            //Exclude header row
            if (rowCount != 0)
            {
                //Create a CrimeData instance from the line. Exclude a black line (usually if opened seperately)
                if(currentCSVLine.length() != 0)
                {
                    CrimeData row(currentCSVLine);
                    crimes.add(row);
                }
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    
    return crimes;
}

#endif /* FileController_hpp */
