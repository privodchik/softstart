%% Date: 2019.03.04

%% Voltage Source Parameters
Vrms = 220; % V, rms
Vm = Vrms*sqrt(2); % Mag
ph_deg = [0 -120 120]; % degree
f = 50; % Hz

%{
P2 = 55000;
J = 0.25;

r1 = 0.0567;
r2 = 0.0409;

r1e = 0.0961    ;

L1sig = 0.638e-3;
L2sig = 0.821e-3;
L0 = 0.0464;
L1e = 0.0014;
%}


%% Load Parameters
L_load = L1e;
R_load = r1e;


%% Discrete Time
Ts =1e-6;

To1 = 0.01;
Kpr = 4.7;


%% 2019.12.30
% PI-Reg coefficients
PIREG_K_prop = L1e/(To1*Kpr);
PIREG_T_integ = 1/(r1e/(To1*Kpr));

%mex s_ACS.c s_ACS_wrapper.c C_folder\tf.c