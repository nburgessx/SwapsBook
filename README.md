# Interest Rate Swaps – Theory, Pricing and Practice
Supporting materials for my book on electronic rates markets, includes Excel workbooks, pricers and background research
  
## CONTENTS
  
## PREFACE
Purpose of the Book  
Book Structure  
Acknowledgements  
About the Author  
List of Symbols and Abbreviations  
  
## PART ONE: THEORY – PRODUCTS AND MODELS
  
#### Chapter 1 Introduction to Interest Rate Markets 
1.1 Project Finance, Risk Management & Hedge Instruments   
1.2 Interest Rate Benchmarks   
1.3 Impact of Benchmark Rate Reform  
1.4 Market Terminology  
1.5 Interest Rate Market Changes  
#### Chapter 2 Introduction to Interest Rate Swaps
2.1 Swap Quotation as an NPV or Par Rate  
2.2 Swap Quotation as a Spread Over US Treasury Yields  
2.3 Swap Positions Terminology  
2.4 Swap Trading & Execution  
2.5 Swap Trade Specification  
2.6 Swap Schedule Parameters  
2.7 Swap Schedule Generation  
2.8 Swap Schedules & Pricing  
2.9 Swap Trading Conventions  
#### Chapter 3 Interest Rate Products & Pricing   
3.1 Interest Rate Swaps (IRS)  
3.2 Overnight Indexed Swaps (OIS)  
3.3 Risk-Free Rate Swaps (RFR)  
3.4 Tenor Basis Swaps (TBS)  
3.5 Cross Currency Swaps (XCCY)  
3.6 Credit Default Swaps (CDS)  
3.7 Asset Swaps (ASW)  
3.8 Forward Rate Agreements (FRA)  
3.9 Interest Rate Futures (FUT)  
#### Chapter 4 Yield Curves, Forecasting & Discounting  
4.1 Forward Rates  
4.2 Discount Factors  
4.3 The Forward Rate - Discount Factor Relationship  
4.4 Impact of Collateral  
4.5 Yield Curve Modelling  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.5.1 Forward Rate & Discount Factor Discovery  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.5.2 State Variables & Interpolation Methods  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.5.3 Calibration Instruments & Behaviour  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.5.4 Calibration Process  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.5.5 Optimization: Solving, Minimizing and Constraints  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.5.6 Curve Build Order & Dependencies  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.5.7 Curve Bootstrapping  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.5.8 Global Calibration  
4.6 Advanced Curve Features  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.6.1 Curve Jacobians  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.6.2 Ultra-Fast Curves  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.6.3 Real-Time Risk  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.6.4 Modelling Jumps, Spikes and the Turn-of-Year Effect  
4.7 LIBOR Reform  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.7.1 LIBOR Benchmark Reform (BMR)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.7.2 Risk-Free Rate (RFR) Curves  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.7.3 RFR Curve Summary – Putting Everything Together  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 4.7.4 Curve Requirements – Why is Calibration so Hard  
  
#### Chapter 5 Interest Rate Risk  
5.1 Analytical Risk  
5.2 Numerical Risk  
5.3 Curve Jacobians  
5.4 Algorithmic Differentiation  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 5.4.1 Tangent Mode (AD)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 5.4.2 Adjoint Mode (AAD)  
  
#### Chapter 6 Credit Models  
6.1 Credit Risky Cash Flows  
6.2 Hazard Rates  
6.3 Survival Probabilities  
6.4 Structural & Intensity Models  
6.5 Hazard Rate Calibration  
6.6 Standard Credit Market Models  
6.7 Credit Proxies, Sector and Index CDS  
  
## PART TWO: PRICING & PRACTICE  
  
#### Chapter 7 Interest Rate Swap Pricing & Risk  
7.1 Annuity Definition   
7.2 Interest Rate Swap Pricing  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.2.1 Fixed Leg Definition  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.2.2 Float Leg Definition   
7.3 Swap Trading, Market Quotes & Conventions  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.3.1 Par Rate Definition  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.3.2 Receiver Swaps  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.3.3 Payer Swaps  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.3.4 Generic Swaps  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.3.5 Par Rate Quote Convention  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.3.6 Market Par Rate Definition  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.3.7 Trade Par Rate Definition  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.3.8 Choice of Par Rate  
7.4 Interest Rate Swap Risk  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.4.1 Duration Matching & Hedging  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.4.2 Macaulay's Duration  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.4.3 Modified Duration  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.4.4 Swap PV01  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.4.5 Swap DV01  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.4.6 Hedge Ratios & Duration Matching  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.4.7 Numerical Risk - PV01 & DV01  
#### Chapter 8 Interest Rate Swap Case Study Examples  
8.1 Swap Schedules  
8.2 Swap Market Data  
8.3 USD Receiver Swap PV  
8.4 USD Receiver Swap Par Rate  
8.5 EUR Payer Swap PV  
8.6 EUR Payer Swap Par Rate  
8.7 Swap Risk Case Study  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 8.7.1 Swap Fixed & Float Annuities  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 8.7.2 Swap Par Rate  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 8.7.3 Swap PV  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 8.7.4 Macaulay's Duration  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 8.7.5 Modified Duration  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 8.7.6 Swap PV01  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 8.7.7 Swap DV01  
#### Chapter 9 Asset Swap Structuring  
9.1 Credit Risk  
9.2		Asset Swap Spreads  
9.3		Multiple Swap Curves & Yield Curve Calibration  
9.4		Benchmark Swap Curves  
9.5		Risk-Free Rate Curves  
9.6		Curve Risk  
9.7		Convexity Risk  
9.8		Par Adjustments, Funding & Collateral  
9.9		Asset Swap Pricing Methodologies  
9.10	Yield-Yield Asset Swap Spread  
9.11	Par-Par Asset Swaps  
9.12	Par-Par Asset Swap Structuring & Cash Flows  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 9.12.1	Initial Notional Exchanges  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 9.12.2	Interim Coupons  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 9.12.3	Final Notional Exchanges  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 9.12.4	Asset Swap Structure Summary  
9.13	Summary of Asset Swap Pricing Methodologies  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 9.13.1	Yield-Yield Asset Swap Spread  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 9.13.2	Par-Par Asset Swap Spread  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 9.13.3	Market Value Adjusted (MVA)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 9.13.4	Yield Accrete  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 9.13.5	Z-Spread  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 9.13.6	CDS Spread  
#### Chapter 10 Asset Swap Pricing & Examples 
10.1 Yield-Yield Asset Swap Spread Formula  
10.2 Yield-Yield Asset Swap Spread Examples  
10.3 Par-Par Asset Swap Spread Formula  
10.4 Par-Par Asset Swap Spread Examples  
