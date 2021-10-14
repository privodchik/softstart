// Date: 2019.12.31
// User: ID
// MATLAB model: "SoftStarter"


#include <CPIREG.h>

cpireg::cpireg(){
	m_xk_1 = 0;
	m_xk = 0;
	m_K = 0;
	m_Ti = 0;
	m_Ts_div_Ti = 0;

}

cpireg::~cpireg(){
}

int cpireg::out_est(int _xk){
	m_yk += (_xk - m_xk_1) * m_K + _xk * m_Ts_div_Ti;

	if (m_yk > m_sat_pos) m_yk = m_sat_neg;
	else if (m_yk < m_sat_neg) m_yk = m_sat_neg;

	m_xk_1 = _xk;
	return m_yk;
}


