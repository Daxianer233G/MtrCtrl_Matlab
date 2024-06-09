clear,clc;

% load IEHBDATA.mat
Ld = 68e-6;
Lq = 60e-6;
phi = 0.0059;
p = 5;
Imax = 120;
R = 0.031;
Udc = 14;
TestSpd = [900 1000 1100 1250 1400 1550 1700 1850 2000 2200 2400 2600 3000 3500 4000 5000 6500 9000 12000];
NumCur = max(size(0:0.015:Imax));
NumSpd = max(size(TestSpd));

IdVectr = zeros(1,NumCur);
IqVectr = zeros(1,NumCur);
MAPId_Caculation =zeros(NumSpd,NumCur); 
MAPIq_Caculation =zeros(NumSpd,NumCur); 
MAPTe_Caculation =zeros(NumSpd,NumCur);
LUTMAP_Id_Ori = cell(NumSpd,1);
LUTMAP_Iq_Ori = cell(NumSpd,1);
LUTMAP_Te_Ori = cell(NumSpd,1);

n=0;
for spd = [900 1000 1100 1250 1400 1550 1700 1850 2000 2200 2400 2600 3000 3500 4000 5000 6500 9000 12000]
    We = spd * 2*pi/60*p;
    Udc = Udc - 0.00549;
    i = 1;
    %search the voltage curve at every speed
    for Id = 0:-1:-Imax
        Iq = 0;
        Vd = R*Id - We*Lq*Iq;
        Vq = R*Iq + (phi + Ld*Id)*We;
        vpeak = sqrt(Vd^2 + Vq^2);
        vlimt = Udc/1.732;
        verr = vpeak - vlimt;
        while(verr < -0.4)
            Iq = Iq + 0.01;
            if(Id^2 + Iq^2 >= Imax^2)
                break;
            end
            Vd = R*Id - We*Lq*Iq;
            Vq = R*Iq + (phi + Ld*Id)*We;
            vpeak = sqrt(Vd^2 + Vq^2);
            vlimt = Udc/1.732;
            verr = vpeak - vlimt;
        end
        IdVectr(1,i) = Id;
        IqVectr(1,i) = Iq;
        if(Id^2 + Iq^2 >= Imax^2)
            IdVectr(1,i:end) = Id;
            IqVectr(1,i:end) = Iq;
            break;
        end
        i = i + 1;
    end
    
    
    n = n + 1;
    MAPId_Caculation(n,:) = IdVectr;
    MAPIq_Caculation(n,:) = IqVectr;
    MAPTe_Caculation(n,:) = 7.5*phi*IqVectr;
    %limit the max value
    [MaxTe,Index] = max(MAPTe_Caculation(n,:));
    MAPId_Caculation(n,Index:end) = MAPId_Caculation(n,Index);
    MAPIq_Caculation(n,Index:end) = MAPIq_Caculation(n,Index);
    MAPTe_Caculation(n,Index:end) = MAPTe_Caculation(n,Index);
    if(MAPIq_Caculation(n,1) >= 0.01)
        %voltage curve have intersect points with q axis.
        MAPIq_Caculation_temp = [linspace(0,MAPIq_Caculation(n,1),uint8(MAPTe_Caculation(n,1)/0.002)),...
                                MAPIq_Caculation(n,2:Index)];
        MAPId_Caculation_temp = [zeros(1,uint8(MAPTe_Caculation(n,1)/0.002)-1),MAPId_Caculation(n,1:Index)];
        MAPTe_Caculation_temp = 7.5*phi*MAPIq_Caculation_temp;
        maxTe_temp = max(MAPTe_Caculation_temp);

        MAPIq_Caculation_Interp = interp1(MAPTe_Caculation_temp,MAPIq_Caculation_temp,linspace(0,maxTe_temp,uint8(maxTe_temp/0.005)));
        MAPId_Caculation_Interp = interp1(MAPTe_Caculation_temp,MAPId_Caculation_temp,linspace(0,maxTe_temp,uint8(maxTe_temp/0.005)));
        %MAPIq_Caculation_Interp = interp1(MAPTe_Caculation_temp,MAPIq_Caculation_temp,(0:0.02:maxTe_temp));
        %MAPId_Caculation_Interp = interp1(MAPTe_Caculation_temp,MAPId_Caculation_temp,(0:0.02:maxTe_temp));



    else
        %voltage curve do not have intersect points with q axis.
        FirstNotZ = find(MAPIq_Caculation(n,:) > 0.01);
        IndxNotZ = FirstNotZ(1,1) - 1;
        MAPIq_Caculation_temp = MAPIq_Caculation(n,IndxNotZ:Index);
        MAPId_Caculation_temp = MAPId_Caculation(n,IndxNotZ:Index);
        MAPTe_Caculation_temp = 7.5*phi*MAPIq_Caculation_temp;
        maxTe_temp = max(MAPTe_Caculation_temp);

        MAPIq_Caculation_Interp = interp1(MAPTe_Caculation_temp,MAPIq_Caculation_temp,linspace(0,maxTe_temp,uint8(maxTe_temp/0.005)));
        MAPId_Caculation_Interp = interp1(MAPTe_Caculation_temp,MAPId_Caculation_temp,linspace(0,maxTe_temp,uint8(maxTe_temp/0.005)));

    end

    subplot(1,2,1);
    plot(MAPId_Caculation_Interp,MAPIq_Caculation_Interp,'LineWidth',2);
    if n <= 15
%        plot(MAPId{n, 1}(1,:),MAPIq{n, 1}(1,:),'*');
       hold on;
    else
       % do nothing;
    end
    %plot(MAPId{n, 1}(1,:),MAPIq{n, 1}(1,:),'*');
    grid on;
    hold on;
    LUTMAP_Id_Ori{n,1} = MAPId_Caculation_Interp;
    LUTMAP_Iq_Ori{n,1} = MAPIq_Caculation_Interp;
    LUTMAP_Te_Ori{n,1} = 7.5*phi*MAPIq_Caculation_Interp;

    subplot(1,2,2);
    plot(MAPId_Caculation(n,:),MAPIq_Caculation(n,:),'LineWidth',2);
    hold on;
    grid on;

end
set(gcf,'Position',[245 423 1250 555]);

LUTVctr_Te = LUTMAP_Te_Ori{1,1};
LUTVctr_Spd = [900 1000 1100 1250 1400 1550 1700 1850 2000 2200 2400 2600 3000 3500 4000 5000 6500 9000 12000];
LUTVctr_Tmx_temp = zeros(size(LUTVctr_Spd));
MAP_ROW = max(size(LUTVctr_Spd));
MAP_COL = max(size(LUTVctr_Te));

LUTMAP_Id_temp = zeros(MAP_ROW,MAP_COL);
LUTMAP_Iq_temp = zeros(MAP_ROW,MAP_COL);
% LUTMAP_Te_temp = zeros(MAP_ROW,MAP_COL);


%fill the map
for n = 1:MAP_ROW
    if(size(LUTMAP_Iq_Ori{n,1}) < MAP_COL)
        ColNum = max(size(LUTMAP_Iq_Ori{n,1}));
        LUTMAP_Id_temp(n,1:ColNum) = LUTMAP_Id_Ori{n,1};
        LUTMAP_Id_temp(n,ColNum+1:MAP_COL) = LUTMAP_Id_Ori{n,1}(1,end);
        LUTMAP_Iq_temp(n,1:ColNum) = LUTMAP_Iq_Ori{n,1};
        LUTMAP_Iq_temp(n,ColNum+1:MAP_COL) = LUTMAP_Iq_Ori{n,1}(1,end);
    else
        ColNum = max(size(LUTMAP_Iq_Ori{n,1}));
        LUTMAP_Id_temp(n,1:ColNum) = LUTMAP_Id_Ori{n,1};
        LUTMAP_Iq_temp(n,1:ColNum) = LUTMAP_Iq_Ori{n,1};
        
    end
    LUTVctr_Tmx_temp(1,n) = max(LUTMAP_Te_Ori{n,1});
end

LUTMAP_Iq = Simulink.Parameter;
LUTMAP_Id = Simulink.Parameter;
LUTVctr_Spd = Simulink.Parameter;
LUTVctr_Tmx = Simulink.Parameter;
LUTVctr_Te = Simulink.Parameter;
KCCM_MaxSpd_RPM = Simulink.Parameter;
KCCM_MinSpd_RPM = Simulink.Parameter;
KCCM_TqUpLimt_NM = Simulink.Parameter;

LUTMAP_Iq.Value = LUTMAP_Iq_temp(:,1:end);
LUTMAP_Id.Value = LUTMAP_Id_temp(:,1:end);
LUTVctr_Spd.Value = TestSpd;
LUT3_Tmx = zeros(n,1);
LUTVctr_Tmx.Value = LUTVctr_Tmx_temp;
LUTVctr_Te.Value = LUTMAP_Te_Ori{1,1};
KCCM_MaxSpd_RPM.Value = max(TestSpd);
KCCM_MinSpd_RPM.Value = min(TestSpd);
KCCM_TqUpLimt_NM.Value = max(LUTVctr_Tmx_temp);



% LUTMAP_Id.DataType = 'single';
% LUTMAP_Id.StorageClass = 'Const';
% LUTMAP_Iq.DataType = 'single';
% LUTMAP_Iq.StorageClass = 'Const';
% LUTVctr_Spd.DataType = 'single';
% LUTVctr_Spd.StorageClass =  'single';
% LUTVctr_Tmx.DataType = 'single';
% LUTVctr_Tmx.StorageClass =  'single';
% LUTVctr_Te.DataType = 'single';
% LUTVctr_Te.StorageClass = 'single';
% KCCM_MaxSpd_RPM.DataType = 'single';
% KCCM_MaxSpd_RPM.StorageClass =  'single';
% KCCM_MinSpd_RPM.DataType = 'single';
% KCCM_MinSpd_RPM.StorageClass =  'single';
% KCCM_TqUpLimt_NM.DataType = 'single';
% KCCM_TqUpLimt_NM.StorageClass =  'single';


% MtrInformation = 'XiaoChengMotor_5.25nm';
% CurveTime = datestr(now);
% save LUTData.mat  LUTMAP_Iq  LUTMAP_Id LUTVctr_Spd LUTVctr_Tmx LUTVctr_Te ...
%     KCCM_MaxSpd_RPM KCCM_MinSpd_RPM KCCM_TqUpLimt_NM MtrInformation CurveTime;
