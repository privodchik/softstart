// Date: 2021.10.13
// Created by: ID

#include "ss_file.h"

CUabc v2u(iq_t uab,iq_t ubc, iq_t uca){
    CUabc u;
    u.uA = (2.0*uab + ubc) / 3.0;
    u.uB = (2.0*ubc + uca) / 3.0;
    u.uC = (2.0*uca + uab) / 3.0;
    
    return u;
}

iq_t sin2meandr(iq_t sin, iq_t deadBand){
    return sin > deadBand ? 1 : sin < -deadBand ? -1 : 0;
}



