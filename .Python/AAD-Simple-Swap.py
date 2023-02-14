import math

def price_swap():
    
    # Swap Data: 1 year swap fixed vs float
    phi = 1.0;   # ReceiveFixed=1.0 or PayFixed=-1.0
    n = 1000000; # Notional
    r = 0.02;    # Fixed Rate 2.0%
    tau = 1.0;   # Coupon Year Fraction
    t = 1.0;     # Swap Maturity
    
    # Market Data
    f = 0.01    # Forward Rate 1.0%
    z = 0.02    # Zero Rate 2.0% used by Discount Factor = exp(-z.t)
    
    # Swap Price
    df           = math.exp(-z*t) # 1.
    pv_fixed     = phi*n*r*tau*df # 2.
    pv_float     = -phi*n*f*tau*df # 3.
    pv_swap      = pv_fixed+pv_float # 4.
    
    # Analytical Risk
    # pv01 = forward rate risk - change in swap pv for 1 bps change in forwards
    # df01 = discount factor risk - change in swap pv for change in discount factors (from 1bp in zero rate change)
    # dv01 = forward + df risk
    pv01_swap    = -phi*n*tau*df*0.0001             # dFloatPV/dForwardRate x 1 bps change in forward rate
    df01_swap    = (phi*n*r*tau - phi*n*f*tau) * (math.exp(-(z+0.0001)*t)-math.exp(-z*t))    # dSwapPrice/dDiscountFactor x change in df for 1 bps change in zero rate
    dv01_swap    = pv01_swap + df01_swap
    
    # Risk Shift Sizes
    shift_size_f = 0.0001 # 1 bps shift 
    shift_size_z = 0.0001 # 1 bps shift
    original_df  = math.exp(-z*t)
    shifted_df   = math.exp(-(z+shift_size_z)*t)
    shift_size_df = shifted_df-original_df # Change in df for a 1 bps change in zero rate

    # Tangent Mode: Forward Sweep
    # Tangent risks are denoted "dot". This mode works forwards and shifts the inputs
    # Consequently we only get one risk output at a time, bit like numerical bumping
    #
    # Example:     Function    y = 2x^2 
    #              Tangent     y_dot = 4x.x_dot 
    #              Given       x_dot = 1           # Risk Shift_size
    #              Result      dy/dx = 4x
    #
    z_dot           = 1 * shift_size_z # init shift size - shift applied to inputs in tangent mode
    f_dot           = 1 * shift_size_f # init shift size - shift applied to inputs in tangent mode
    df_dot          = -t*math.exp(-z*t)*z_dot # 1.
    pv_fixed_dot    = phi*n*r*tau*df_dot # 2.
    pv_float_dot    = -phi*n*tau*df*f_dot -phi*n*f*tau*df_dot # 3.
    pv_swap_dot     = pv_fixed_dot + pv_float_dot # 4.
    
    # Adjoint Mode: Backwards Sweep
    # Adjoint risks are denoted "bar". This mode works in reverse and shifts the outputs
    # Consequently we get a full break-down of all risks in one go
    #
    # Example:     Function    y = 2x^2
    #              Adjoint     x_bar = 4x.y_bar
    #              Given       y_bar = 1           # Risk Shift_size
    #              Result      dy/dx = 4x
    #
    pv_swap_bar     = 1.0 # init to one as shift-sizes are applied to outputs in adjoint mode
    pv_fixed_bar    = pv_swap_bar # 4.
    pv_float_bar    = pv_swap_bar # 4.
    f_bar           = -phi*n*tau*df*pv_float_bar * shift_size_f # 3.   Note: f_bar output  - apply required shift size
    df_bar          = -phi*n*f*tau*pv_float_bar * shift_size_df # 3.   Note: df_bar output - apply required shift size
    df_bar          += phi*n*r*tau*pv_fixed_bar * shift_size_df # 2.   Note: df_bar output - apply required shift size
    z_bar           = -t*math.exp(-z*t)*df_bar # 1.
        
    # Results
    print("Swap Price")
    print("pv_swap:       {:.2f}".format(pv_swap))
    print()
        
    print("Analytical Swap Risk")
    print("forward risk:  {:.2f} (pv01)".format(pv01_swap))
    print("discount risk: {:.2f}".format(df01_swap))
    print("dv01:          {:.2f}".format(dv01_swap))
    print()
        
    print("Tangent Mode Risk")
    print("pv_swap_dot:   {:.2f}".format(pv_swap_dot))
    print("dv01:          {:.2f}".format(pv_swap_dot))
    print()
        
    print("Adjoint Mode Risk")
    print("f_bar:         {:.2f} (forward risk)".format(f_bar))
    print("df_bar:        {:.2f} (discount risk)".format(df_bar))
    print("dv01:          {:.2f}".format(f_bar+df_bar))

def main():
    # Price swap has algorithmic differentiation (AD) risk embedded
    # Therefore when pricing we get the exact risk in real-time for close to free
    price_swap()

if __name__ == "__main__":
    main()
