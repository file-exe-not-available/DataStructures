#pragma once
#ifndef SIDEPILE_H
#define SIDEPILE_H

#include <iostream>

class SidePile {
public:
    SidePile();                  
    void push(int card);          
    int pop();                    
    int RemainingCards() const;   

private:
    int stack[5];                 
    int top;                      
    static const int maxCap = 5; 
};

#endif 
