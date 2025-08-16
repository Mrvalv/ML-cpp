#ifndef LINREG_H
#define LINREG_H

#include "types.h"

class LinReg{

    private:
        float slope;
        float intercept;

    public:
        LinReg(const vp& dataset);
        float predict(float x) const;
        float evaluate(const vp& test_Set);
        float get_slope() const {return slope;}
        float get_intercept() const {return intercept;}
};

#endif