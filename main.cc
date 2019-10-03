/*************************
 * Zach Schmitz
 * CS3610, Dr. Liu
 * Project 1 
 * Fall 2019
 * 
 * K.I.S.S Version
**************************/

#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char* argp[]){
    unsigned int max; //Number that is input from the console

    if (argc == 1){
        cout << "Missing argument" << endl;
        return -1;
    }
    else{
        try{
            max = std::stoi(argp[1])-1;
        }
        catch(...){
            cout << "Unexpected argument" << endl;
            return -1;
        }
    }

    if(max < 2 || max > 30000){
        cout << "Arguement must be within bounds. 2-30,000" << endl;
        return -1;
    }

    //Create and initialize arrays
    bool co[max]; //Array of true false
    int prime[max]; //Array of numbers 
    for(unsigned int i = 0; i < max; i++){
        prime[i] = i+2; //Fills the prime array with values 2-n
        co[i] = true; //Initializes co array with true. True meaning prime
    }

    //implementation of the Sieve of Eratosthenes algorithm 
    unsigned int temp = 0; //Temp variable to parse arrays
    while(temp < sqrt(max)){
        for(unsigned int i = temp+1; i <  max; ++i){
            if(prime[i]%(prime[temp]) == 0) //if the number has a factor of prime@i then it is not prime
                co[i] = 0; //sets the associated value to not prime
        }
        temp++;
    }
    
    //print primes
    for(unsigned int i = 0; i<max; ++i){
        if (co[i] == 1)
            cout << prime[i] << " ";
    }
    cout << endl;
    
    //prints composites
    for(unsigned int i = 0; i<max; ++i){
        if (co[i] == 0)
            cout << prime[i] << " ";
    }

    return 0;
};