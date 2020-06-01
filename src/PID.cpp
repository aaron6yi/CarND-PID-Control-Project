#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
/*
 PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;
*/ 
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
 
 
    prev_cte = 0;
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
      
}

void PID::UpdateError(double cte) {

    p_error = cte;
  
    d_error = cte - prev_cte;
  
    i_error = i_error + cte;

    prev_cte = cte;

}

double PID::TotalError() {
    double steer_angle = Kp * p_error + Kd * d_error + Ki * i_error;
    return steer_angle;
}

