/*===============================================================
 
 Program: Find the volume of a water tower given the height of the water
 Author: Anthony Le
 Class: CS1428 Honors
 
 Instructor: Ziliang Zong
 Date: 09/29/2016
 Description: This is a program that will compute the volume of water in the city's water tower, given the height of the water in the tower.
 Input: height of the water in the tower
 Output: water volume in the tower
 Compilation instructions: Usage:
 
 Modifications: 09/29/2016
 
 ===============================================================*/

#include <iostream>

using namespace std;

int main ()

{
    
    // Declaring variables
    const float PI = 3.1415926, r1 = 15, r2 = 25;
    float h, height, cyl1, cyl2, cone1, cone2;
    
    //Asking user to input height
    cout << "Enter height of water in tower: ";
    cin >> height;
    
    // Equations to compute the volume of the water, given the height //
    
    /* Calculate the volume of cylinder 1 */
    h = (height > 20.0) ? 20.0 : height;
    cyl1 = PI*(r1*r1)*h;
    
    /* Calculate the volume of cylinder 1 + cone 1 */
    h = (height > 30.0) ? 25.0 : height - 5.0;
    cone1 = (PI / 3.0) * ((h*h*h)-(r1*r1*r1)) + cyl1;
    
    /* Calculate the volume of cylinder 1 + cone 1 + cylinder 2 */
    h = (height > 40.0) ? 10.0 :  height - 30.0;
    cyl2 = (PI*(r2*r2)*h) + cone1;
    
    /* Calculate the volume of cone 2 + cylinder 1 + cone 1 + cylinder 2 */
    h = (height > 50.0) ? 25.0 : height - 25.0;
    cone2 = (PI / 3.0) * ((h*h*h)-(r1*r1*r1)) + cyl2;
    
    // if/else if statements to calculate and output volume given the height
    if (height>0 && height<=20)
        cout << "With a height of " << height << " feet, the volume is " << cyl1 << " cubic feet.\n";
    
    else if (height>20 && height<=30)
        cout << "With a height of " << height << " feet, the volume is " << cone1 << " cubic feet.\n";
    
    else if (height>30 && height<=40)
        cout << "With a height of " << height << " feet, the volume is " << cyl2 << " cubic feet.\n";
    
    else if (height>40 && height<=50)
        cout << "With a height of " << height << " feet, the volume is " << cone2 << " cubic feet.\n";
    
    else if (height<0)
        cout << "Incorrect height - range 0-50.";
    
    else if (height>50)
        cout << "You are not paying attention. Please read the manual. Program exiting.";
    
    // exit gracefully
    return 0;
    
}