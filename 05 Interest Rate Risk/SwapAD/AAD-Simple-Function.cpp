#include <iostream>
using namespace std;

double function(double x1, double x2)
{
    double a = x1*x1;				// Step 1:  a = x1^2	
    double b = 2*a; 				// Step 2: 	b = 2.x1^2
    double c = x2;					// Step 3: 	c = x2
    double d = 3*c;					// Step 4: 	d = 3*x2
    double f = b + d;				// Step 5: 	f = 2*x1^2 + 3*x2
    return f;
}

double tangent( double x1, double x2, double x1_dot, double x2_dot )
{
	double a = x1*x1;				// Step 1:	a = x1^2
	double a_dot = 2*x1*x1_dot;
	double b = 2*a; 				// Step 2: 	b = 2.x1^2
	double b_dot = 2*a_dot;
	double c = x2;					// Step 3: 	c = x2
	double c_dot = x2_dot;
	double d = 3*c;					// Step 4: 	d = 3*x2
	double d_dot = 3*c_dot;
	double f = b + d;				// Step 5: 	f = 2*x1^2 + 3*x2
	double f_dot = b_dot + d_dot;
 	return f_dot;
}

void adjoint( double x1, double x2, double f_bar )
{
 	// Forward Sweep
	double a = x1*x1;				// Step 1:	a = x1^2	
 	double b = 2*a; 				// Step 2: 	b = 2.x1^2
 	double c = x2;					// Step 3: 	c = x2
 	double d = 3*c;					// Step 4: 	d = 3*x2
 	double f = b + d;				// Step 5: 	f = 2*x1^2 + 3*x2

 	// Back Propagation
 	double b_bar = f_bar;			// Step 5:  b_bar 	= df/db
 	double d_bar = f_bar;			// Step 5:	d_bar 	= df/dd
 	double c_bar = 3*d_bar;			// Step 4: 	c_bar 	= df/dc
 	double x2_bar = c_bar; 			// Step 3:  x2_bar 	= df/dx2
 	double a_bar = 2*b_bar;			// Step 2: 	a_bar 	= df/da
 	double x1_bar = 2*x1*a_bar;		// Step 1:	x1_bar 	= df/dx1
 
 	// Display Results
 	std::cout << "df/dx1: " << x1_bar << std::endl;
  	std::cout << "df/dx2: " << x2_bar << std::endl;
}

int main()
{
    cout << "Using (x1,x2) = (2,3)" << endl;
    cout << "f(x1,x2) = " << function(2,3) << endl;
	cout << "tangent: x1_dot = " << tangent(2,3,1,0) << endl;
	cout << "tangent: x2_dot = " << tangent(2,3,0,1) << endl;
	cout << "adjoint mode" << endl;
	adjoint(2,3,1);
    return 0;
}
