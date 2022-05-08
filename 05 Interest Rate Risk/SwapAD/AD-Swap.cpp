// This file demo's how to price a swap and compute swap DV01 risk using algorithmic differentiation (AD)
// We demo how to compute DV01 using AD tangent mode (forward) and AD adjoint mode (backwards)

// Tangent mode works forwards and shifts the inputs, a bit like numerical bumping, one risk output at a time
// Adjoint mode works backwards and shifts output risks and can compute all price constituent risks in one go
// In this file we process a single swap, but we could use this approach for a swap portfolio and a vector of adjoints

// Usually we have to perform tangent mode multiple times and bump each input individially, but for swap DV01
// tangent mode works well as we can enable forward and discount risk inputs at the the same time.

// PV01 captures swap forward risk
// DV01 captures swap forward + discount risk

#include <cmath>    // for math methods e.g. exp()
#include <vector>   // for vectors
#include <iostream> // for input/output to console
#include <iomanip>  // for input/output precision
using namespace std;

// Compute the swap present value
void price_swap( int payReceive,             // [IN]: Pay or Receive Fixed: 1 = pay, -1 = receive
                 double notional,            // [IN]: Swap Notional
                 double fixed_rate,          // [IN]: Fixed Leg: fixed rate in decimal
                 vector<double> fixed_tau,   // [IN]: Fixed Leg: fixed coupon accrual year fractions
                 vector<double> fixed_t,     // [IN]: Fixed Leg: fixed coupon payment time in years
                 double float_spread,        // [IN]: Float Leg: floating spread in decimal
                 vector<double> float_tau,   // [IN]: Float Leg: float coupon accrual year fractions
                 vector<double> float_t,     // [IN]: Float Leg: float coupon payment time in years
                 vector<double> float_rates, // [IN]: Float Leg: floating forward rates in decimal
                 double zero_rate            // [IN]: Discounting zero rate in decimal; For simplicity we assume df=exp(-z.t) given a constant zero rate z
                )
{
    // Validate Swap Schedule
    if (fixed_tau.size() != fixed_t.size())     { cout << "Fixed Schedule Error: Wrong size of fixed_tau" << endl; return; }
    if (float_tau.size() != float_t.size())     { cout << "Float Schedule Error: Wrong size of float_tau" << endl; return; }
    if (float_rates.size() != float_t.size())   { cout << "Float Schedule Error: Wrong size of float_rates" << endl; return; }
    
    // Fixed Leg PV
    double fixed_pv = 0.0;
    double fixed_annuity = 0.0;
    for (size_t i = 0; i < fixed_t.size(); ++i)
    {
        fixed_pv += notional * fixed_rate * fixed_tau[i] * exp(-zero_rate*fixed_t[i]);
        fixed_annuity += notional * fixed_tau[i] * exp(-zero_rate*fixed_t[i]);
    }
    
    // Float Leg PV
    double float_pv = 0.0;
    for (size_t j = 0; j < float_t.size(); j++)
    {
        float_pv += notional * (float_rates[j] + float_spread) * float_tau[j] * exp(-zero_rate*float_t[j]);
    }
    
    // Swap PV
    double swap_pv = payReceive * (fixed_pv - float_pv);
    
    // Display Result(s)
    cout << "Swap Results" << endl;
    cout << "Swap PV: "  << std::fixed << std::setprecision(2) << swap_pv << endl;
    cout << "PV01: " << std::fixed << std::setprecision(2) << -payReceive * fixed_annuity * 0.0001 << endl; // annuity * 1 bps
    cout << endl;
    return;
}

// Compute the swap present value with risks using tangent mode
// Tangent mode uses forward differentiation where we peturb risk inputs
// Tangent risks are denoted 'dot' and risk variables have the suffix '_dot'
void swap_price_tangent_mode( int payReceive,                   // [IN]: Pay or Receive Fixed: 1 = pay, -1 = receive
                              double notional,                  // [IN]: Swap Notional
                              double fixed_rate,                // [IN]: Fixed Leg: fixed rate in decimal
                              vector<double> fixed_tau,         // [IN]: Fixed Leg: fixed coupon accrual year fractions
                              vector<double> fixed_t,           // [IN]: Fixed Leg: fixed coupon payment time in years
                              double float_spread,              // [IN]: Float Leg: floating spread in decimal
                              vector<double> float_tau,         // [IN]: Float Leg: float coupon accrual year fractions
                              vector<double> float_t,           // [IN]: Float Leg: float coupon payment time in years
                              vector<double> float_rates,       // [IN]: Float Leg: floating forward rates in decimal
                              double zero_rate,                 // [IN]: Discounting zero rate in decimal; For simplicity we assume df=exp(-z.t) given a constant zero rate z
                              vector<double> float_rates_dot,   // [IN]: RISK INPUT - forward rate risk, bump size for each float leg forward rate
                              double zero_rate_dot              // [IN]: RISK INPUT - discounting risk, bump size for zero rate
                            )
{
    // Validate Swap Schedule
    if (fixed_tau.size() != fixed_t.size())         { cout << "Fixed Schedule Error: Wrong size of fixed_tau" << endl; return; }
    if (float_tau.size() != float_t.size())         { cout << "Float Schedule Error: Wrong size of float_tau" << endl; return; }
    if (float_rates.size() != float_t.size())       { cout << "Float Schedule Error: Wrong size of float_rates" << endl; return; }
    
    // Validate Risk Inputs
    if (float_rates_dot.size() != float_rates.size()) { cout << "Risk Input Error: Wrong size of float_rates_dot" << endl; return; }
    
    // Fixed Leg PV
    double fixed_pv = 0.0;
    double fixed_pv_dot = 0.0;
    
    for (size_t i = 0; i < fixed_t.size(); ++i)
    {
        fixed_pv += notional * fixed_rate * fixed_tau[i] * exp(-zero_rate*fixed_t[i]); // df = exp(-z.t)
        fixed_pv_dot += -fixed_t[i] * notional * fixed_rate * fixed_tau[i] * exp(-zero_rate*fixed_t[i]) * zero_rate_dot;
    }
    
    // Float Leg PV
    double float_pv = 0.0;
    double float_pv_dot = 0.0;
    
    for (size_t j = 0; j < float_t.size(); j++)
    {
        float_pv += notional * (float_rates[j] + float_spread) * float_tau[j] * exp(-zero_rate*float_t[j]); // df = exp(-z*t)
        float_pv_dot += notional * float_tau[j] * exp(-zero_rate*float_t[j]) * float_rates_dot[j];
        float_pv_dot += -float_t[j] * notional * (float_rates[j] + float_spread) * float_tau[j] * exp(-zero_rate*float_t[j]) * zero_rate_dot;
    }
    
    // Swap PV
    double swap_pv = payReceive * (fixed_pv - float_pv);
    double swap_pv_dot = payReceive * (fixed_pv_dot - float_pv_dot);
    
    // Display Result(s)
    cout << "Swap PV: " << std::fixed << std::setprecision(2) << swap_pv << endl;
    cout << "Risk Value: " << std::fixed << std::setprecision(2) << swap_pv_dot << endl;
    cout << endl;
    
    return;
}


// Compute the swap present value with risks using adjoint mode
// Adjoint mode uses backward or reverse differentiation where we peturb risk outputs and calculate all risk components
// for each output. Here we have a single price output. Referse differentiation requires that we do a forward sweep to
// gather all variables before differentiating backwards. Adjoint risks are denoted 'bar' and risk variables have the
// suffix '_bar'
void swap_price_adjoint_mode( int payReceive,               // [IN]: Pay or Receive Fixed: 1 = pay, -1 = receive
                              double notional,              // [IN]: Swap Notional
                              double fixed_rate,            // [IN]: Fixed Leg: fixed rate in decimal
                              vector<double> fixed_tau,     // [IN]: Fixed Leg: fixed coupon accrual year fractions
                              vector<double> fixed_t,       // [IN]: Fixed Leg: fixed coupon payment time in years
                              double float_spread,          // [IN]: Float Leg: floating spread in decimal
                              vector<double> float_tau,     // [IN]: Float Leg: float coupon accrual year fractions
                              vector<double> float_t,       // [IN]: Float Leg: float coupon payment time in years
                              vector<double> float_rates,   // [IN]: Float Leg: floating forward rates in decimal
                              double zero_rate,             // [IN]: Discounting zero rate in decimal; For simplicity we assume df=exp(-z.t) given a constant zero rate z
                              double swap_pv_bar            // [IN]: RISK INPUT - Calculate all swap pv risk constituents: 1=On, 2=Off
                            )
{
    // Validate Swap Schedule
    if (fixed_tau.size() != fixed_t.size())         { cout << "Fixed Schedule Error: Wrong size of fixed_tau" << endl; return; }
    if (float_tau.size() != float_t.size())         { cout << "Float Schedule Error: Wrong size of float_tau" << endl; return; }
    if (float_rates.size() != float_t.size())       { cout << "Float Schedule Error: Wrong size of float_rates" << endl; return; }

    // Compute Adjoint shift shift_sizes
    // We would typically use the curve jacobian for this and/or add an ajoint method
    // to the yield curve forward and discount factor interpolation methods
    double shift_size_f = 0.0001;
    double shift_size_z = 0.0001;
    
    // Fixed Discount Factor Shift Sizes
    vector<double> fixed_df(fixed_t.size(),0.0);
    vector<double> fixed_shifted_df(fixed_t.size(),0.0);
    vector<double> shift_size_fixed_df(fixed_t.size(),0.0);
    
    for (size_t i = 0; i < fixed_t.size(); ++i)
    {
        fixed_df[i] = exp(-zero_rate*fixed_t[i]);
        fixed_shifted_df[i] = exp(-(zero_rate+shift_size_z)*fixed_t[i]);
        shift_size_fixed_df[i] = fixed_shifted_df[i] - fixed_df[i];
    }
    
    // Float Discount Factor Shift Sizes
    vector<double> float_df(float_t.size(),0.0);
    vector<double> float_shifted_df(float_t.size(),0.0);
    vector<double> shift_size_float_df(float_t.size(),0.0);
    
    for (size_t j = 0; j < float_t.size(); ++j)
    {
        float_df[j] = exp(-zero_rate*float_t[j]);
        float_shifted_df[j] = exp(-(zero_rate+shift_size_z)*float_t[j]);
        shift_size_float_df[j] = float_shifted_df[j] - float_df[j];
    }
    
    // Forward Sweep for Price
    // -----------------------
    
    // STEP 1: Fixed Leg PV
    double fixed_pv = 0.0;
    for (size_t i = 0; i < fixed_t.size(); ++i)
    {
        fixed_df[i] = exp(-zero_rate*fixed_t[i]); // Step 1.1
        fixed_pv += notional * fixed_rate * fixed_tau[i] * fixed_df[i]; // Step 1.2
    }
    
    // STEP 2: Float Leg PV
    double float_pv = 0.0;
    for (size_t j = 0; j < float_t.size(); ++j)
    {
        float_df[j] = exp(-zero_rate*float_t[j]); // Step 2.1
        float_pv += notional * (float_rates[j] + float_spread) * float_tau[j] * float_df[j]; // Step 2.2
    }
    
    // STEP 3: Swap PV
    double swap_pv = payReceive * (fixed_pv - float_pv );
    
    
    // Back Propogation for Risk
    // -------------------------

    // STEP 3. Risk from Swap PV Calculation
    // double swap_pv = payReceive * (fixed_pv - float_pv );
    double fixed_pv_bar = payReceive * swap_pv_bar;
    double float_pv_bar = -payReceive * swap_pv_bar;

    // STEP 2. Risk from Float Leg PV Calculation
    // Note: We must follow loop steps in reverse order!!!
    double float_rates_bar = 0.0;
    double discount_factor_bar = 0.0;
    double zero_rate_bar = 0.0;
    
    for (size_t j = float_t.size(); j-- >0;)
    {
        // float_pv += notional * (float_rates[j] + float_spread) * float_tau[j] * discount_factor; // Step 2.2
        float_rates_bar += notional * float_tau[j] * float_df[j] * float_pv_bar * shift_size_f; // apply risk output shift size
        discount_factor_bar += notional * (float_rates[j] + float_spread) * float_tau[j] * float_pv_bar * shift_size_float_df[j]; // apply risk output shift size
        
        // double discount_factor = exp(-zero_rate*float_t[j]); // Step 2.1
        zero_rate_bar += -float_t[j] * exp(-zero_rate*float_t[j]) * discount_factor_bar;
    }

    // STEP 1. Risk from Fixed Leg PV Calculation
    // Note: We must follow loop steps in reverse order!!!
    for (size_t i = fixed_t.size(); i-- >0;)
    {
        // fixed_pv += notional * fixed_rate * fixed_tau[i] * discount_factor; // Step 1.2
        discount_factor_bar += notional * fixed_rate * fixed_tau[i] * fixed_pv_bar * shift_size_fixed_df[i]; // apply risk output shift size
        
        // double discount_factor = exp(-zero_rate*fixed_t[i]); // Step 1.1
        zero_rate_bar += -fixed_t[i] * exp(-zero_rate*fixed_t[i]) * discount_factor_bar;
    }

    // Display Result(s)
    cout << "Swap PV: " << std::fixed << std::setprecision(2) << swap_pv << endl;
    cout << "float_rates_bar: " << std::fixed << std::setprecision(2) << float_rates_bar << " (pv01)" << endl;
    cout << "discount_factor_bar: " << std::fixed << std::setprecision(2) << discount_factor_bar << " (discount risk)" << endl;
    cout << "dv01: " << std::fixed << std::setprecision(2) << float_rates_bar + discount_factor_bar << endl;
    cout << endl;
    
    return;
}

int main()
{
    // For simplicity in this example we assume df = exp(-z.t) and a given constant zero rate
    double zero_rate = 0.015; // Zerp Rate, 1.5%

    // 1.   Swap Specification
    // Receive Annual Fixed 5% vs Annual LIBOR Flat for 5 years
    int payReceive              = 1;                               // Rec = 1, Pay = -1
    double notional             = 1000000;                          // USD 1,000,000
    double fixed_rate           = 0.05;                             // Fixed Rate 5.0%
    vector<double> fixed_tau    = { 1.0, 1.0, 1.0, 1.0, 1.0 };      // Annual Fixed Coupons
    vector<double> fixed_t      = { 1.0, 2.0, 3.0, 4.0, 5.0 };      // Paying Fixed Each Year for 5 Years
    double float_spread         = 0.0;                              // Zero Float Spread 
    vector<double> float_tau    = { 1.0, 1.0, 1.0, 1.0, 1.0 };      // Annual Float Coupons
    vector<double> float_t      = { 1.0, 2.0, 3.0, 4.0, 5.0 };      // Paying Float Each Year for 5 Years
    vector<double> float_rates  = { 0.01, 0.01, 0.01, 0.01, 0.01 }; // LIBOR Rates 1.0%

    // 2. Price Swap
    cout << "Swap Specification" << endl;
    cout << "5Y IRS: USD 1,000,000 Receive Fixed 2% vs LIBOR Flat" << endl;
    cout << endl;
    price_swap(payReceive, notional, fixed_rate, fixed_tau, fixed_t, float_spread, float_tau, float_t, float_rates, zero_rate);

    // 3. Tangent Mode: Forward Rate Shift Sizes for Risk Scenarios
    vector<double> f1_dot   = { 0.0001, 0.0000, 0.0000, 0.0000, 0.0000 };  // Forward Rate Risk for f(t1) only: 1 Basis Point shift
    vector<double> f2_dot   = { 0.0000, 0.0001, 0.0000, 0.0000, 0.0000 };  // Forward Rate Risk for f(t2) only: 1 Basis Point shift
    vector<double> f3_dot   = { 0.0000, 0.0000, 0.0001, 0.0000, 0.0000 };  // Forward Rate Risk for f(t3) only: 1 Basis Point shift
    vector<double> f4_dot   = { 0.0000, 0.0000, 0.0000, 0.0001, 0.0000 };  // Forward Rate Risk for f(t4) only: 1 Basis Point shift
    vector<double> f5_dot   = { 0.0000, 0.0000, 0.0000, 0.0000, 0.0001 };  // Forward Rate Risk for f(t5) only: 1 Basis Point shift
    vector<double> no_f_dot = { 0.0000, 0.0000, 0.0000, 0.0000, 0.0000 };  // No Forward Rate Risk
    vector<double> all_f_dot  = { 0.0001, 0.0001, 0.0001, 0.0001, 0.0001 };  // Forward Rate Risk for All Forwards: 1 Bps Shift i.e. PV01
    
    // 4. Tangent Mode: Discount Factor Risk Shift Size
    double zero_rate_dot    = 0.0001;   // DF Risk: Shift zero rate by 1 bps
    double no_zero_rate_dot = 0.0;      // DF Risk: No Shift
    
    // 5. Adjoint Mode: All price risk constituents
    double swap_pv_bar      = 1.0;      // Enable price risk (on=1, off=0): shift_sizes are applied directly to outputs

    // 6. Risk Scenarios
    cout << "Tangent Mode: Forward Risk (PV01)" << endl;
    swap_price_tangent_mode(payReceive, notional, fixed_rate, fixed_tau, fixed_t, float_spread, float_tau, float_t, float_rates, zero_rate, all_f_dot, no_zero_rate_dot);
    
    cout << "Tangent Mode: Discount Risk" << endl;
    swap_price_tangent_mode(payReceive, notional, fixed_rate, fixed_tau, fixed_t, float_spread, float_tau, float_t, float_rates, zero_rate, no_f_dot, zero_rate_dot);

    cout << "Tangent Mode: Forward Risk + Discount Risk (DV01)" << endl;
    swap_price_tangent_mode(payReceive, notional, fixed_rate, fixed_tau, fixed_t, float_spread, float_tau, float_t, float_rates, zero_rate, all_f_dot, zero_rate_dot);

    cout << "Adjoint Mode: All Price Risk Constituents" << endl;
    swap_price_adjoint_mode(payReceive, notional, fixed_rate, fixed_tau, fixed_t, float_spread, float_tau, float_t, float_rates, zero_rate, swap_pv_bar);
    
    return 0;
}





