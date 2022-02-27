#ifndef _PID_H
#define _PID_H
typedef struct {

	/* Controller gains */
	float Kp;
	float Ki;
	float Kd;

	/* Derivative low-pass filter time constant 导数低通滤波时间常数(比T大一点)*/
	float tau;

	/* Output limits (输出界限)*/
	float limMin;
	float limMax;
	
	/* Integrator limits (积分界限)*/
	float limMinInt;
	float limMaxInt;

	/* Sample time (in seconds) */
	float T;

	/* Controller "memory" */
	float integrator;
	float prevError;			/* Required for integrator */
	float differentiator;
	float prevMeasurement;		/* Required for differentiator */

	/* Controller output */
	float out;

} PIDController;

void  PIDController_Init(PIDController *pid);
float PIDController_Update(PIDController *pid, float setpoint, float measurement);
#endif