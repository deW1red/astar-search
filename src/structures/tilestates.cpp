#include "tilestates.h"

char stateToChar(state st){
    if(st == state::empty){
        return ' ';
    }else if(st == state::blocked){
        return 'X';
    }else if(st == state::start){
        return 'P';
    }else if(st == state::end){
        return 'K';
    }
}