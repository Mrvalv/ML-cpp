#include "LinReg.h"

LinReg::LinReg(const vp& dataset){
    float N = static_cast<float>(dataset.size());
    float sum_x{0}, sum_y{0}, sum_x2{0}, sum_xy{0};

    for (const auto& pairs : dataset){
        sum_x += pairs.first;
        sum_y += pairs.second;
        sum_x2 += pairs.first * pairs.first;
        sum_xy += pairs.first * pairs.second;
    }

    float slope_denominator = ((N*sum_x2) - (sum_x*sum_x));

    if (N == 0 || slope_denominator == 0){
        slope = 0.0f;
        intercept = 0.0f;
    }else{
        slope =  ((N*sum_xy) - (sum_x*sum_y)) / slope_denominator;
        intercept = (sum_y - (slope*sum_x)) / N;
    }
}

float LinReg::predict(float x) const{
    return slope * x + intercept;
}

float LinReg::evaluate(const vp& test_set){
    float nmse{1.0f};
    float N = static_cast<float>(test_set.size());
    if(N==0)return nmse;
    else{
        for (const auto& pairs : test_set){
            float y {pairs.second};
            float y_hat{predict(pairs.first)};

            nmse += ((y_hat - y)*(y_hat - y));
        }
        float mse{nmse/N};
        return mse;
    }
}
