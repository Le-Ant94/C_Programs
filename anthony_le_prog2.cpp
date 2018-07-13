/*====================================================================================
 
 Program: Determine the specific location of a set of coordinates on a graph from a text file
 Author: Anthony Le
 Class: CS1428 Honor
 
 Instructor: Ziliang Zong
 Date: 09/18/2016
 Description: This is a program that will read the values of an (x,y) coordinates from a file named points.txt
 Input: points.txt file
 Output: the specific quadrant or axis the point (x,y) lies on a graph
 Compilation instructions: Usage:
 
 Modifications: 09/19/2016
 
 ====================================================================================*/

#include <iostream>
#include <fstream>

using namespace std;

int main()

{
    int x_c;
    int y_c;
    
    //original points.txt file
    
    ifstream fin;
    fin.open ("points.txt");
    
    if (!fin)
        { cout << "Failed to open the input file!" << endl;
        return -1; }
    
    fin>> x_c;
    fin>> y_c;
            
    fin.close ();
    
    //points.txt file after executing your program
    
    ofstream fout;
    fout.open ("points.txt", ios::app);
    
    //if statement to check if the point lies in Quadrant I
    if (x_c>0 && y_c>0)
        { fout << "The point ("<<x_c<<" , "<<y_c<<") lies in  Quadrant I" << endl; }
    
    //if statement to check if the point lies in Quadrant II
    else if (x_c<0 && y_c>0)
        { fout << "The point ("<<x_c<<" , "<<y_c<<") lies in Quadrant II" << endl; }
    
    //if statement to check if the point lies in Quadrant III
    else if (x_c<0 && y_c<0)
        { fout << "The point ("<<x_c<<" , "<<y_c<<") lies in Quadrant III" << endl; }
    
    //if statement to check if the point lies in Quadrant IV
    else if (x_c>0 && y_c<0)
        { fout << "The point ("<<x_c<<" , "<<y_c<<") lies in Quardrant IV" << endl; }
    
    //if statement to check if the point lies at the origin
    else if ( x_c==0 && y_c==0)
        { fout << "The point ("<<x_c<<" , "<<y_c<<") lies in the origin" << endl; }
    
    //if statement to check if the point lies on the x-axis
    else if (y_c==0)
        { fout << "The point ("<<x_c<<" , "<<y_c<<") lies on the x-axis" << endl; }
    
    //if statement to check if the point lies on the y-axis
    else { fout << "The point ("<<x_c<<" , "<<y_c<<") lies on the y-axis" << endl; }
    
    fout.close ();
    
    //exit gracefully
    
    return 0;
    
}
