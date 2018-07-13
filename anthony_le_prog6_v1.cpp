/*===============================================================
 
 Program: Happy Prime Numbers
 Author: Anthony Le
 Class: CS1428 Honors
 
 Instructor: Ziliang Zong
 Date: 12/02/2016
 Description: a program that determines the number of happy prime numbers from 1 to 1 million.
 Input: (none)
 Output: the number of happy prime numbers from 1 to 1 million.
 Compilation instructions: Usage:
 
 Modifications: 12/06/2016
 
 ===============================================================*/

#include <iostream>
#include <cmath>

using namespace std;

bool is_happy_prime(int x) //Determine if a number is both happy and prime
{
    if (x <= 1) //Only numbers greater than 1 can be both happy and prime
        return false;
    
    //Eliminate numbers that are not prime
    int i;
    
    for (i = 2; i <= sqrt (x); i++)
    {
        if (x % i == 0)
            return false;
    }
    
    //Eliminate numbers that are not happy
    int result;
    
    while (x != 1)
    {
        result = 0;
        
        while (x) //Until every digit has been summed
        {
            result += (x % 10) * (x % 10); //Square digit and add it to total
            x /= 10;
        }
        
        x = result;
        
        if (x == 4) //If x is 4, it is a sad number
            return false;
    }
    
    return true;
}

int main()
{
    int happy_prime_number = 0;
    
    for (int x = 1; x < 1000000; ++x)
    {
        if (is_happy_prime(x))
            ++happy_prime_number;
    }
    
    cout << "There are " << happy_prime_number << " happy prime numbers between 1 and 1 million." << endl;
}