clc;
clear;
TableSize = 2^10;
sinTable = zeros(2,TableSize);
cosTable = zeros(2,TableSize);
for i = 1:TableSize
    Angle_rad = i*pi/2/TableSize;
    sinTable(1,i) = sin(Angle_rad);
    sinTable(2,i) = Angle_rad;
    cosTable(1,i) = cos(Angle_rad);
    cosTable(2,i) = Angle_rad;
end
C_LUT_SinTable_sng_Null = sinTable(1,:);
C_LUT_AngleTable_sng_Null = sinTable(2,:);
% C_LUT_CosTable_sng_Null = cosTable(1,i);



