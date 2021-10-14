// Date: 2019.12.31
// User: ID
// MATLAB model: "SoftStarter"


#ifndef CPIREG_H
#define CPIREG_H

#include "stdint.h"

class cpireg
{
		int m_xk_1;
		int m_xk;
		int m_K;
		int m_Ti;
		int m_Ts_div_Ti;

	public:
		cpireg();
		~cpireg();

		int out_est(int _xk);


};


#endif



