/*=========================================================================================================================================
 
 Program: Straight triangle side length calculation
 Author: Anthony Le
 Class: CS1428 Honor
 
 Instructor: Ziliang Zong
 Date: 09/08/2016
 Description: This program calculates the length of the third side of a straight triangle when the lengths of the other two sides are given.
 Input: Length of two sides in a straight triangle
 Output: The length of the third side in a straight triangle
 Compilation instructions: Usage:
 
 Modifications: 09/08/2016
 
 =========================================================================================================================================*/
 
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()

{
    //Compute the length of the hypotenuse of a right triangle given the lengths of two adjacent sides
    
    double sideA=0.0, sideB=0.0, sideC=0.0;
    cout<< "Input the length of side A:";
    cin>> sideA;
    cout<< "Input the length of side B:";
    cin>> sideB;
    sideC = sqrt(sideA*sideA + sideB*sideB);
    cout<< "The length of the hypotenuse is " << sideC << endl;

    //Compute the length of an adjacent side of a right triangle given one adjacent side and the hypotenuse
    
    cout<< "Input the length of the hypotenuse:";
    cin>> sideC;
    cout<< "Input the length of Side A:";
    cin>> sideA;
    sideB = sqrt(sideC*sideC - sideA*sideA);
    cout<< "The length of Side B is " << sideB << endl;
    
    return 0;
}
