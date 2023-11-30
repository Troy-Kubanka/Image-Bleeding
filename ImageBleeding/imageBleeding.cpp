/*
Troy Kubanka

Quick Program to Test Image Bleeding in a C++ file
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
   // declare variables
   string imageType, comment, filename;
   int width, height, colorMax, red, green, blue, inputs, grayscale=0;
   ifstream inFile;
   ofstream outFile;
   // ask for file
   cout << "Enter your file here: " << endl;
   cin >> filename;
   // finding file 
   inFile.open(filename);
   if(!inFile)
   {
      cout << "Cannot open the input file. Program will terminate..." << endl;
      inFile.close();
      return -1;
   }
   outFile.open("BWimage.pgm");
   // reading file
   getline(inFile, imageType);
   getline(inFile, comment);
   inFile >> width;
   inFile >> height;
   inFile >> colorMax;
   // Output lines into PGM image file
   outFile << "P2" << endl;
   outFile << comment << endl;
   outFile << width << endl;
   outFile << height << endl;
   outFile << colorMax << endl;
   // calculate inputs aka all pixels 
   inputs = width*height;
   //loop -- while(inFile)
   while(grayscale <= inputs)
   {
      inFile >> red >> green >> blue;
      outFile << static_cast<int>(red*0.4+green*0.2+blue*0.4) << endl;
      grayscale += 1;
   }
   inFile.close();
   outFile.close();
return 0;
}

