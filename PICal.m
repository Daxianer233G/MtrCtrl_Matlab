Rs = 0.05;
Ls = 0.000635;
Ts = 1e-4;
F = 1/Ts/20;
Pp = 4; 
Flux = 0.192;
Udc = 560;
J = 0.011;
B = 0.001889;
n = 3000;
Pn = 3.5e4;

UBase_V = 600;
IBase_A = 300;
Ureal = 560;
Ireal = 220;

Preal = sqrt(3)*Ureal*Ireal;

PBase_W = sqrt(3)*UBase_V*IBase_A;
PU = Preal/PBase_W;

U_pu = Ureal/UBase_V;
I_pu = Ireal/IBase_A;
P_pu = I_pu*U_pu;



nBase_RPM = n;

% UBase_V = Udc/sqrt(3);
% PBase_W = Pn;
% IBase_A = 2*PBase_W/UBase_V/3;

wmBase_rps = nBase_RPM*pi/30;
wBase_rps = wmBase_rps * Pp;
FBase_Hz = wBase_rps/2/pi;
ZBase_Ohm = UBase_V/IBase_A;
LBase_H = ZBase_Ohm/wBase_rps;
RBase_Ohm = ZBase_Ohm;
wmBase_rps =wBase_rps/Pp;
TqBase_Nm = PBase_W/wmBase_rps;
FluxBase_Vs = UBase_V/wBase_rps;
JBase_kgmm = PBase_W/wmBase_rps/wmBase_rps;
tBase_s = 1/wBase_rps;

F_pu = F/FBase_Hz;
Flux_pu = Flux/FluxBase_Vs;
Ls_pu = Ls/LBase_H;
Rs_pu = Rs/RBase_Ohm;


Kt = 1.5*Pp*Flux;
Kp = 2*pi*F*Ls;
Ki = 2*pi*F*Ts*Rs;c
Ts_pu =Ts/tBase_s;

Kp_pu = 2*pi*F_pu*Ls_pu;
Ki_pu = 2*pi*F_pu*Ts_pu*Rs_pu;

Kps = 3*J/(5*Ts*Kt);
Kis = 3*J/(25*Ts*Ts*Kt);

Id = 1;Ld = Ls;Lq = Ls;Iq = 1;we = 1;dt = 1;
Ud = Rs*Id+Ld*Id/dt-we*Lq*Iq;
Uq = Rs*Iq+Lq*Iq/dt+we*(Ld*Id+Flux);

