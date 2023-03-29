![image](https://user-images.githubusercontent.com/4067689/218286213-acbb929a-f9df-4f7a-85b9-ec8d1eb34602.png)

**Quant Research Papers**  
https://ssrn.com/author=1728976

**Support Materials, C++ & Excel Examples**  
https://github.com/nburgessx/SwapsBook

**Available from Amazon UK**  
https://www.amazon.co.uk/dp/9994985949

**Available from Amazon USA**  
https://www.amazon.com/dp/9994985949

**Available from Eliva Press**  
Email info@elivapress.com for 10% discount  
https://www.elivapress.com/en/book/book-9161981805/

# Low Latency Interest Rate Markets - Theory, Pricing and Practice

**Interest Rate Markets**  
The primary function of interest rate markets is to bring together borrowers and lenders to facilitate the financing of government and corporate projects. It is a market that facilitates more than USD 370 trillion of funding solutions globally. Large scale government and corporate projects carry considerable risk for which interest rate markets provide a wide variety of solutions. Interest rate swaps fix borrowing costs and protect domestic investors from interest rate risk, whilst cross currency swaps protect foreign investors from FX risk. The market provides credit default swaps to protect against counterparty payment defaults and asset swaps provide a fund raising solution to invest in bonds.

**Why the need for speed and low latency?**  
The interest rate market is primarily an USD 81 trillion electronic market. It is a highly liquid market where transactions take place in real-time with high precision and tight bid-offer spreads of typically 1/10th of a basis point. Consequently, financial service providers, market makers and high frequency traders must compete accurately and at high speed.

**Why purchase this book?**  
This book shares my insights as an experienced and successful Quant and market practitioner. The analytics I have built at several major financial institutions has been of the highest quality, accuracy and speed. If on a standard desktop in Excel I have been able to compete in interest rate markets and perform calculations in micro-seconds, imagine how my analaytical solutions perform on a server with sophisticated hardware or on the cloud (certainly nano-seconds or better).  

Brute force hardware or cloud solutions may provide speed, but at high financial cost and often miss signifnificant optimizations. The secret sauce and key ingredient to low latency lies in having a detailed understanding of the markets and products on a micro-level to heavily optimize calculations before applying hardware solutions. The majority of pricing and risk calculations can be fundamentally reduced to trival calculations. This is achieved by understanding how to reduce model, portfolio pricing and risk calculations into a state where we can precompute and store the majority of the calculation as static data that does not require continuous recomputation to track the market.  

To compete and succeed in interest rate markets, one must pay attention to the details, which on the surface appear straight forward and trivial, but few look deeper into how to bypass the majority of the calculation. My book demonstrates these techniques and provides examples. I have succeeded in applying these concepts for major financial institutions. Not only do my solutions offer precision and low latency, but they are also low cost and acccessable to all. The world-class analytics I build outperforms competitors who overlook these details as trivia and often insist pricing and risk systems have no state and a low memory footprint.

# Author Biography
Nicholas Burgess has a breadth of practitioner experience accumulated from having worked on trading floors internationally as a Quant for many large investment banks, hedge funds and financial institutions including Citigroup, UBS, Credit Suisse, Bank of America, CQS Hedge Fund, Deutsche Bank, Commerzbank, Société Générale, ANZ, MUFG, Mizuho, HSBC and currently XP Investments. This has allowed the author to gain broad insight and exposure to the trading, pricing and risk management of interest rates, fixed income, equities, credit, commodities, FX, hybrids & exotics, inflation and XVA. Recently he worked as the Head of Quant Research and Analytics for Mizuho specializing in electronic swaps trading, low latency pricing and risk analytics. Currently he manages the core Quant teams covering at XP Inc in Brazil. 

He is well‐qualified having read financial strategy at Saïd Business School, University of Oxford with post‐graduate research in machine learning and algorithmic trading strategies. He also read quant finance at Henley Business School and Mathematics at the University of Manchester. Over the course of his professional and academic career the author has written and published many quantitative and finance research papers.

# Book Reviews  
In today’s interest rate derivatives markets, there is a rising urgency to provide timely, accurate computations to adequately support for electronic pricing, trading and risk management. The construction of low latency interest rate systems is a challenging task at the leading edge of quantitative and practical applications. For readers with a need to understand the theoretical and practical content of such systems there is no other source needed except this one book.  With great clarity of text and its emphasis on pragmatic applications, all written by an industry practitioner, this book sets the standard for low latency practice in today’s interest rate derivatives markets.  
***Ronald T. Slivka, Ph.D.***, *Adjunct Professor, NYU Tandon School of Engineering*

The world of quantitative finance is constantly evolving to meet the requirements of an ever-changing market, new regulations, improvements in technology and the greater need for real-time calculations. This book addresses these challenges and is the result of years of experience at leading financial institutions. It is remarkable in the wide-ranging topics it covers, and the level of mathematical detail it contains while remaining accessible. This book is a worthy reference on every quant bookshelf.  
***Ian Castleton***, *Director of Quantitative Analytics, Mizuho International*

Nicholas is a world-class Quant and thinker, who capably traverses academic theory for market practitioners to integrate into their investment and risk processes. This book is poised to be a critical compendium on rates markets for years to come.  
***Karim Henide***, *Portfolio Manager, Record Currency Management*

## CONTENTS
  
Low Latency Interest Rate Markets  
Preface  
Acknowledgements  
Introduction  
Excel Support Materials  
List of Symbols and Abbreviations  
  
## PART ONE: THEORY – PRODUCTS AND MODELS
  
#### Chapter 1 Introduction to Low Latency Interest Rate Markets 
1.1 Project Finance, Risk Management & Hedge Instruments   
1.2 Low Latency Market Requirements & Techniques   
1.3 Interest Rate Benchmarks   
1.4 Impact of Benchmark Rate Reform  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1.4.1 Structural Interest Rate Changes  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1.4.2 Fall-Back Rates  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1.4.3 Yield Curve Changes  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 1.4.4 New Interest Rate Products  
1.5 Market Terminology  
1.6 Interest Rate Market Changes  
#### Chapter 2 Introduction to Interest Rate Swaps
2.1 Swap Quotation as an NPV or Par Rate  
2.2 Swap Quotation as a Spread Over US Treasury Yields  
2.3 Swap Positions Terminology  
2.4 Swap Trading & Execution  
2.5 Swap Trade Specification  
2.6 Swap Schedule Parameters  
2.7 Swap Schedule Generation  
2.8 Swap Schedules & Pricing  
2.9 LIBOR Trading Conventions  
2.10 RFR Trading Conventions  
#### Chapter 3 Interest Rate Products & Pricing   
3.1 Interest Rate Swaps (IRS)  
3.2 Overnight Indexed Swaps (OIS)  
3.3 Risk-Free Rate Swaps (RFR)  
3.4 Tenor Basis Swaps (TBS)  
3.5 Cross Currency Swaps (XCCY)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.5.1 Funding Example  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.5.2 Cross Currency Swap Risks  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.5.3 Cross Currency Swap Features  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.5.4 Example: Trading Book & Cash Flow Schedule  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.5.5 Fixed or Floating Interest  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.5.6 CSA Collateral Posting  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.5.7 FX Forward Rates & CSA Adjustments  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.5.8 Marked-to-Market (MTM)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.5.9 Notional FX Resets  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.5.10 Notional Scaling Factor  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.5.11 Cross Currency Swap Pricing  
3.6 Credit Default Swaps (CDS)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.6.1 CDS Standardization  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.6.2 CDS Specifications & Terminology  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.6.3 CDS Events & Triggers  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.6.4 CDS Default Swap Pricing  
3.7 Asset Swaps (ASW)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.7.1 Credit Risk  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.7.2 Asset Swap Spreads  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.7.3 Yield-Yield Asset Swap Spread  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.7.4 Par-Par Asset Swap Spread  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.7.5 Par-Par Asset Swap Spreads with Accrued Interest  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.7.6 Asset Swap Spread Example  
3.8 Forward Rate Agreements (FRA)  
3.9 Interest Rate Futures (FUT)  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.9.1 What is an Interest Rate Future?  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.9.2 Differences between Futures and FRAs  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.9.3 Futures Contract Specifications  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.9.4 Futures Quotes & Pricing  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.9.5 Hedging with Futures  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.9.6 Futures Trading, Initial & Variation Margin  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.9.7 Yield Curve Calibration Using Futures  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 3.9.8 Futures Convexity Adjustments  
#### Chapter 4 Yield Curves, Forecasting & Discounting Cash Flows 
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
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 5.4.3 Swap Risk Examples  
5.5 Computing the Swap Price & DV01 Risk  
5.6 Professional AD Implementation  

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
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.4.4 Analytical Swap PV01 Risk  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.4.5 Analyticak Swap DV01 Risk  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.4.6 Hedge Ratios & Duration Matching  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.4.7 Numerical Risk  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 7.4.8 Advanced Riks  
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
#### Chapter 11 Multiples Pricing & Trader Rules of Thumb  
11.1 Key Pricing & Risk Factor - The Annuity Factor  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.1.1	Swap Pricing using the Annuity Factor  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.1.2	Swap Risk using the Annuity Factor  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.1.2	Credit Default Swap Pricing using the Annuity Factor  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.1.3	Credit Risk using the Annuity Factor  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.1.4	Asset Swap Spread using the Annuity Factor  
11.2 Trader Rule of Thumb - The Annuity Approximation  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.2.1	Annuity Assumptions  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.2.2	Trader Rule of Thumb  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.2.3	Rule of Thumb 1: Swap Pricing and Risk  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.2.4	Rule of Thumb 2: CDS Pricing and Risk  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.2.5	Rule of Thumb 3: Asset Swap Spread  
11.3 Multiples Pricing & Risk - Base Cases & Reference Prices  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.3.1	Base Case 1 – Swap Pricing & Risk Multiples  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.3.2	Base Case 2 – CDS Pricing & Risk Multiples  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 11.3.3	Base Case 3 – Asset Swap Spread Factors  
11.4	Applications of Multiples for Quick Pricing & Risk  
11.5 Low Latency Considerations  
