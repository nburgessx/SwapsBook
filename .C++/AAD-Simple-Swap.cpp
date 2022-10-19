// We price a simple swap and demonstrate how to calculate the risk using algorithmic differentation (AD)
// Here we demo how to compute swap DV01 using tangent and adjoint mode as part of the pricing process.
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

// Macro to help display output to four decimal places
#define DISPLAY_NUMBER fixed << setprecision(4)

double swap_pv(double phi, double n, double r, double tau, double t, double f, double s, double z) 
{
    double df 	    = exp(-z*t);			    // Step 1.   Discount Factor using zero rate, z
	double pv_fixed = phi*n*r*tau*df; 		    // Step 2.   Fixed PV = φ N r τ_1 P(0,t_1 )
	double pv_float = -phi*n*(f+s)*tau*df; 		// Step 3.   Float PV = φ N(l_1+s) τ_1 P(0,t_1 )
	double pv_swap  = pv_fixed+pv_float; 		// Step 4.   Swap PV = Fixed PV + Float PV
	return pv_swap;
}

double tangent(double phi, double n, double r, double tau, double t, double f, double s, double z, double f_dot, double z_dot) 
{
	double df 		     = exp(-z*t);			// Step 1.
	double df_dot 		 = -t*exp(-z*t)*z_dot;
    double pv_fixed 	 = phi*n*r*tau*df; 		// Step 2.
 	double pv_fixed_dot  = phi*n*r*tau*df_dot;
	double pv_float 	 = -phi*n*(f+s)*tau*df; // Step 3.
	double pv_float_dot  = -phi*n*tau*df*f_dot - phi*n*f*tau*df_dot;
    double pv_swap 	     = pv_fixed+pv_float; 	// Step 4.
	double pv_swap_dot 	 = pv_fixed_dot + pv_float_dot;
	return pv_swap_dot;
}

double adjoint(double phi, double n, double r, double tau, double t, double f, double s, double z, double pv_bar) 
{
    // Risk Shift Sizes - We want our risks to be relative to a 1 basis shift size in forward and zero rates
    double shift_size_f = 0.0001; // Shift Forward Rates 1 Basis point 
    double shift_size_z = 0.0001; // Shift Zero Rate 1 Basis Point
    double original_df  = exp(-z*t);
    double shifted_df   = exp(-(z+shift_size_z)*t);
    double shift_size_df = shifted_df-original_df;
    
    // Forward Sweep
    double df 	        = exp(-z*t);			    // Step 1.   Discount Factor using zero rate, z
	double pv_fixed     = phi*n*r*tau*df; 		    // Step 2.   Fixed PV = φ N r τ_1 P(0,t_1 )
	double pv_float     = -phi*n*(f+s)*tau*df; 		// Step 3.   Float PV = φ N(l_1+s) τ_1 P(0,t_1 )
	double pv_swap      = pv_fixed+pv_float; 		// Step 4.   Swap PV = Fixed PV + Float PV
	
	// Backward Propagation
	double pv_fixed_bar = pv_bar;                   // Step 4.
    double pv_float_bar = pv_bar;                   // Step 4.
    double f_bar        = -phi*n*tau*df*pv_float_bar    *shift_size_f;  // Step 3.   Apply forward rate shift size
    double df_bar       = -phi*n*f*tau*pv_float_bar     *shift_size_df; // Step 3.   Apply df shift size
    df_bar              += phi*n*r*tau*pv_fixed_bar     *shift_size_df; // Step 2.   Apply df shift size
    double z_bar        = -t*exp(-z*t)*df_bar;      // Step 1.
    
    // DV01 Result
    return f_bar + df_bar;
}

int main()
{
    // Swap Data: 1 year swap fixed vs float
    double phi = 1.0;       // ReceiveFixed=1.0 or PayFixed=-1.0
    double n = 1000000;     // Notional
    double r = 0.02;        // Fixed Rate 2.0%
    double tau = 1.0;       // Coupon Year Fraction
    double t = 1.0;         // Swap Maturity
    
    // Market Data
    double f = 0.01;        // Forward Rate 1.0%
    double s = 0.0;         // Floating Spread 0.0%
    double z = 0.02;        // Zero Rate 2.0% used by Discount Factor = exp(-z.t)
    
    // Tangent Mode
    double f_dot = 0.0001;  // Shift forward rate by 1 basis point
    double z_dot = 0.0001;  // Shift zero rate by 1 basis point

    // Adjoint mode
    double pv_bar = 1.0;    // Enable adjoint mode: On=1.0, Off=0.0
    
    // Swap PV, Tangent AD and Adjoint AD
    cout << "swap pv = " << swap_pv(phi, n, r, tau, t, f, s, z) << endl;
    cout << "tangent mode: pv01 = " << DISPLAY_NUMBER << tangent(phi, n, r, tau, t, f, s, z, f_dot, 0) << endl;
    cout << "tangent mode: discount risk = " << DISPLAY_NUMBER << tangent(phi, n, r, tau, t, f, s, z, 0, z_dot) << endl;
    cout << "tangent mode: dv01 = " << DISPLAY_NUMBER << tangent(phi, n, r, tau, t, f, s, z, f_dot, z_dot) << endl;
    cout << "adjoint mode: dv01 = " << DISPLAY_NUMBER << adjoint(phi, n, r, tau, t, f, s, z, pv_bar) << endl;
    return 0;
}


