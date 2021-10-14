clc;

P2n = 55000;
U1n = 220;
Sn = 0.018;
Sk = 0.11;

ns = 3000;
kpd_n = 0.91;
cosfi_n = 0.92;
J = 0.25;
Ki_pusk = 7.5;
p = 1;

%% G-scheme Parameters, pu

gX0 = 6.6;
gR1 = 0.026;
gX1sig = 0.092;
gR2 = 0.019;
gX2sig = 0.12;

%% Rated Stator Current

I1n = P2n/(3*U1n*kpd_n*cosfi_n);


%% T-scheme Parameters, pu

tX1sig = 2*gX1sig*gX0 / (gX0 + sqrt(gX0^2 + 4*gX1sig*gX0));

C1 = gX1sig/tX1sig;

tR1 = gR1/C1;

tR2 = gR2/C1^2;

tX2sig = gX2sig/C1^2;

%% Base Resistance

Zb = U1n/I1n;


%% T-scheme Parameters, su

r1 = tR1*Zb;
r2 = tR2*Zb;

x1sig = tX1sig*Zb;
x2sig = tX2sig*Zb;
x0 = gX0*Zb;

%% Estimated Parameters

Wsn = pi*ns*p/30;
x1_full = x1sig + x0;
x2_full = x2sig + x0;

L1sig = x1sig/Wsn;
L2sig = x2sig/Wsn;
L0 = x0/Wsn;

L1_full = L0 + L1sig;
L2_full = L0 + L2sig;

L1_ = (L1_full * L2_full - L0^2)/L2_full;

sigma = 1 - L0^2/(L1_full*L2_full);

k2 = L0/L2_full;

T1sig = L1sig/r1;
T1_full = L1_full/r1;

T2 = L2sig/r2;
T2_full = L2_full/r2;

r1e = r1 + r2*k2^2;
L1e = L1_;

U1 = sqrt(2)*U1n;
I1 = sqrt(2)*I1n;

I0 = I1 * sqrt(r2^2 + (x2sig*Sn)^2) / sqrt(r2^2 + (x2_full*Sn)^2);
I2 = I0 * x0*Sn / sqrt(r2^2 + (x2sig*Sn)^2);
Phi0 = L0*I0;
Phi2 = Phi0;

kM = 3/2*p*Phi2^2*Wsn/r2;

Mn = kM*Sn;