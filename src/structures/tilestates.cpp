#include "tilestates.h"
#include <iostream>
char stateToChar(state st){
    if(st == state::none){
        std::cout<<"susogus";
    }

    if(st == state::empty){
        return ' ';
    }else if(st == state::blocked){
        return 'X';
    }else if(st == state::start){
        return 'P';
    }else if(st == state::end){
        return 'K';
    }else if(st == state::visited){
        return '#';
    }else if(st == state::checked){
        return '*';
    }else{
        return '$';
    }
}