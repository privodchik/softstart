// Date: 2020.11.10
// User: ID

#ifndef _TF_DIFFERENTIATOR_H
#define _TF_DIFFERENTIATOR_H

#include "itrans_func.h"


class CDifferentiator : public ITransFunc{
    private:
        iq_t m_xk_1;
        iq_t m_1DivTs;
    
    public:
      CDifferentiator(iq_t _Ts,  iq_t _sat_pos, iq_t _sat_neg) : 
                    ITransFunc(_Ts, _sat_pos, _sat_neg), m_xk_1(0)
      {
          config_set();
      }
        
      virtual void config_set(){m_1DivTs = IQdiv(IQ(1), m_Ts);}
      
      #pragma inline = forced
      iq_t out_est(iq_t _xk){
          m_yk = IQmpy(m_1DivTs, _xk - m_xk_1);
          m_xk_1 = _xk;
	    return out_limit();
      }
      
};


#endif //_TF_DIFFERENTIATOR_H


