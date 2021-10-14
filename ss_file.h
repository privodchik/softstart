// Date: 2021.10.13
// Created by: ID

#ifndef _SS_FILE_H
#define _SS_FILE_H

#include "iqmath.h"

struct CUabc{
    iq_t uA;
    iq_t uB;
    iq_t uC;
};

CUabc v2u(iq_t uab,iq_t ubc, iq_t uca);

iq_t sin2meandr(iq_t sin, iq_t deadBand);

#endif //_SS_FILE_H

