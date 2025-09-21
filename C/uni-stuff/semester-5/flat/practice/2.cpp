// C++ program to check if a string 
// either starts or ends with 01
#include<iostream>
#include<string>
using namespace std;

void stateA(string);
void stateB(string);
void stateC(string);
void stateD(string); 
void stateE(string);
void stateF(string);

// Function for transition 
// state A
void checkstateA(string n)
{
    
    // State transition to 
    // B if the character is 
    // 0
    if(n[0] == '0')
       stateB(n.substr(1));
       
    // State transition to 
    // D if the character is 
    // 1
    else
       stateD(n.substr(1));
}

// Function for transition 
// state B         
void stateB(string n)
{
    
    // Check if the string has 
    // ended
    if (n.length() == 0)
        cout << "string not accepted";
    else
    {
        
        // State transition to C
        // if the character is 1
        if(n[0] == '1')
            stateC(n.substr(1));

        // State transition to D
        // if the character is 0
        else
            stateD(n.substr(1));
    }     
} 

// Function for transition 
// state C 
void stateC(string n)
{
    cout << "String accepted";
}

// Function for transition 
// state D
void stateD(string n)
{
    if (n.length() == 0)
        cout << "string not accepted";
    else
    {
        
        // State transition to D
        // if the character is 1
        if (n[0] == '1')
            stateD(n.substr(1));

        // State transition to E
        // if the character is 0
        else
            stateE(n.substr(1));
    }
}

// Function for transition 
// state E
void stateE(string n)
{
    if (n.length() == 0)
        cout << "string not accepted";
    else
    {
        
        // State transition to E
        // if the character is 0 
        if(n[0] == '0')
            stateE(n.substr(1));

        // State transition to F
        // if the character is 1
        else
            stateF(n.substr(1));
    }
}

// Function for transition 
// state F
void stateF(string n)
{
    if(n.length() == 0)
        cout << "string accepred";
    else
    {
        
        // State transition to D
        // if the character is 1
        if(n[0] == '1')
            stateD(n.substr(1));

        // State transition to E
        // if the character is 0
        else
            stateE(n.substr(1));
    }
} 

// Driver code
int main()
{
    string n;
    cout << "Enter the string: ";
    cin >> n;
    
    checkstateA(n);
    return 0;
}

