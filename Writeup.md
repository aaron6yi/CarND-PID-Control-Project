# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
### How to run the simulation
1. Navigate to `CarND-PID-Control-Project` folder 
2. run the commands below in the terminal
```
mkdir build && cd build
cmake .. && make
./pid
```
3. Click on the "Simulator" button in the bottom of the Udacity workspace.
4. Double-click the "Simulator" icon in that desktop to start the simulator.
## Introduce of the PID controller

PID control is a technique to correct vehicle steering Angle, throttle threshold and other behaviors according to loss components of P(proportion), I(integral) and D(differential) given vehicle crossing trajectory error.

In the Udacity automotive simulator, the CTE value is read from the data message sent by the simulator, and the PID controller updates the error value and predicts the steering angle based on the total error.
![](https://raw.githubusercontent.com/aaron7yi/CarND-PID-Control-Project/master/twiddle.png)
**The P (Proportional)  gain**

The proportional term computes an output proportional to the cross-track error. A pure P - controller is unstable and at best oscillates about the setpoint. The proportional gain contributes a control output to the steering angle of the form `-K_p cte`with a positive constant `K_p`.

**The D (Differential) gain**

The oscillations caused by purely D control can be mitigated by a term proportional to the derivative of the cross-track error. The derivative gain contributes a control output of the form `-K_d d/dt cte`, with a positive constant `K_d`.

**The I (Integral) gain**

A third contribution is given by the integral gain which simply sums up the cross-track error over time. The corresponding contribution to the steering angle is given by `-K_i sum(cte)`. 

### Discussion
How do I tune the P, I, D value:
**P value:** 
I have tune P value several times, it depends on the curve rate of the driving lance, . if its a sharp turn, P should be large enough to get the ego car back to the center of the lance. I set P value of 0.13 since the ego car almost out of the driving lance in the sharp turn when P smaller than 0.13, .
**D value:** 
D counteracts P to ring and overshoot the center line. A properly tuned D parameter will cause the car to approach the center line smoothly without ringing. At first, I set a relative small number of D value, and incrementally change it, then I found 0.006 could let the ego car driving with less over shoot.
**I value:**
This parameter is used to decrease systematic bias. I set I value to be a relative large number since the cte is always positive and the ego car steering to much while driving straightly. The simulation shows that I value of 2.7 works fine for the ego car. 
### Simulation result
[![Test video](https://raw.githubusercontent.com/aaron7yi/CarND-PID-Control-Project/master/simulation_record.gif)](https://github.com/aaron7yi/CarND-PID-Control-Project/blob/master/simulation_record.mp4)

### Future Improvements
- Adjust throttle to be controlled by the cross track error so that the vehicle can run faster
- Try to automatically tune gains by using twiddle algorithm