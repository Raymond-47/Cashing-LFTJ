//
// Created by 景祖宽 on 2021/6/13.
//

#include "VariableAssignment.h"

VariableAssignment::VariableAssignment(int var, int ass) {
    this->variable1 = var;
    this->variable2 = ass;
}

VariableAssignment::VariableAssignment(int var1, int ass1, int var2, int ass2) {
    this->variable1 = var1;
    this->assignment1 = ass1;
    this->variable2 = var2;
    this->assignment2 = ass2;
}

bool VariableAssignment::operator==(VariableAssignment var) {
    if(this->variable1 == var.variable1 && this->variable2 == var.variable2 && this->assignment1 ==var.assignment1 && this->assignment2 == var.assignment2 && this->counter == var.counter){
        return true;
    }else{
        return false;
    }
}