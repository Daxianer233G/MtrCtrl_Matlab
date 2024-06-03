clc; clear;
U_dc = 15;%Voltage Set
PhaseVoltageMax = U_dc/1.732;
% motor parameter
pairs = 5;phi=0.0059;Rs=0.03;Lq= 80e-6;Ld= 80e-6;
MaxCur = 130;
MINId = -phi/Ld;
SpeedRnge =[950 1100 1250 1400 1550 1700 1850 2000 2200 2400 2600 2800 3000 3300 3600 4000 4500 5000 6000 7000 8000];
MtrSpeedMin = min(SpeedRnge);MtrSpeedMax= max(SpeedRnge);
MaxTe = 1.5*pairs*(phi.* MaxCur);
IsSetIncRnge = 5;
FluxAngIncRnge = 1;
FluxAng = 0:FluxAngIncRnge:90;
IsSet =0:IsSetIncRnge:MaxCur;
IsSet_10= 0:10:MaxCur;

% LdTest = [0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080]*10^-2;
% LqTest = [0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080 0.0080]*10^-2;
LdTest = zeros(1,size(IsSet,2));
LqTest = zeros(1,size(IsSet,2));
LdTest = LdTest + 8e-5;
LqTest = LqTest + 8e-5;
Ld_Grid = griddedInterpolant(IsSet,LdTest,'pchip');
Lq_Grid = griddedInterpolant(IsSet,LqTest,'pchip');
L_Table = linspace(0,MaxCur,length(IsSet));
Ld_Map = Ld_Grid(L_Table);
Lq_Map = Lq_Grid(L_Table);
% figure(1);
% plot(Ld_Map);
% hold on;
% plot(Lq_Map);

% Create map variables, IdMAP, IqMAP
SizeofIsSet = length(IsSet);
MAP_IdCurnt = zeros(length(SpeedRnge),length(IsSet));
MAP_IqCurnt = zeros(length(SpeedRnge),length(IsSet));
% for i = 1:length(SpeedRnge)
%     Inc = 0;
%     for j = 1 : length(IsSet)
%         MAP_IqCurnt(i,j) = Inc;
% %         MAP_IdCurnt(i,j) = Inc;
%         Inc = Inc + 0.00001;
%     end
% end
SizeofMapCol= length(IsSet);
MAP_Id_Interpolant = cell(length(SpeedRnge),1);
MAP_Iq_Interpolant = cell(length(SpeedRnge),1);
Table_Iq = cell(length(SpeedRnge),1);
Table_Id = cell(length(SpeedRnge),1);
MAP_Te_Interpolant = cell(length(SpeedRnge),1);
MAP_Id_temp = cell(1,1);
MAP_Iq_temp = cell(1,1);
MAP_Size = SizeofIsSet*1;
Vd_Map = zeros(1,length(IsSet));
Vq_Map = zeros(1,length(IsSet));
Vpeak_Map = zeros(1,length(IsSet));
%search all datas those belong to the intersection area of current circle
%and voltage ellipse

j= 1;%speed index
for n_rpm= SpeedRnge
    w = 2*pi*n_rpm*pairs/60;
    i = 1;%current index
    k = 1;%Ldq Index
    for IsSet = 0:IsSetIncRnge:MaxCur
        for FluxAng=0:FluxAngIncRnge:90
%             Vd = -w*Lq*IsSet*cosd(FluxAng) + Rs*IsSet*sind(FluxAng + 180);
%             Vd = -w*Lq*Iq + Rs*Id;
%             Vq = w*(phi + Ld*IsSet*sind(FluxAng + 180)) + Rs*IsSet*cosd(FluxAng);
%             Vq = w*(phi + Ld*Id)+ Rs*Iq;
%             V_Peak= sqrt(Vd^2 + Vq^2);
            Id = -IsSet*sind(FluxAng);
            Iq = IsSet*cosd(FluxAng);
            Vd_Map(k) =Rs*Id- w*Lq_Map(k)*Iq;
            Vq_Map(k) =Rs*Iq + w*(phi + Ld_Map(k)*Id);
            Vpeak_Map(k) = sqrt(Vd_Map(k)^2 + Vq_Map(k)^2);
%             if k > 13
%                 k = 14;
%             end
% 
% 
% 
% 
% 
            if(Vpeak_Map(k) <= PhaseVoltageMax)
                MAP_IdCurnt(j,i) = IsSet*sind(FluxAng + 180);
                MAP_IqCurnt(j,i) = IsSet*cosd(FluxAng);

                if i>1
                    if MAP_IqCurnt(j,i-1) > MAP_IqCurnt(j, i)
                       MAP_IqCurnt(j,i) = MAP_IqCurnt(j,i-1);
                    end
                    if MAP_IdCurnt(j,i-1) < MAP_IdCurnt(j,i)
                       MAP_IdCurnt(j,i) = MAP_IdCurnt(j,i-1);
                    end
                end
                i = i + 1;
                break;
            else
%                 Vpeak_Map(k) = sqrt(Vd_Map(k)^2 + Vq_Map(k)^2)
%                 j
%                 i
%                   k
%                 FluxAng
%                 MAP_IqCurnt
%                 MAP_IdCurnt
                continue;
            end
        end
        if(Vpeak_Map(k)> PhaseVoltageMax)
            i = i + 1;
        end
            k = k + 1;
    end
            j = j + 1;%speed index
end
% j = j - 1;
% Reconfig IdMAP,while the motor speed is high enough, even iq is 0.
% id must be set as some value to weak flux.
% i=1:
IsSet =0:IsSetIncRnge:MaxCur;
for i = 2:size(IsSet, 2)
    for j = 1:size(SpeedRnge,2)
         if MAP_IqCurnt(j,i) == 0
             MAP_IqCurnt(j,i) = MAP_IqCurnt(j,i - 1);
             MAP_IdCurnt(j,i) = MAP_IdCurnt(j - 1,i);
         end
    end
end


for j= 1:length(SpeedRnge)
    if(abs(MAP_IqCurnt(j,2)- 5) > 0.0001)%the first value of Iq array must be zero,so we should begin from the sec
        SearchIndx=2;
        while(abs(MAP_IqCurnt(j,SearchIndx) - 0) < 0.0001 )%get the first nonzero ig index.
            SearchIndx = SearchIndx +1;
            if SearchIndx >= size(MAP_IqCurnt, 2)
                break;
            end
        end
        %iq is zero,caculate the intersetcion point of voltage ellipse and
        %d axis
        IdTemp = MAP_IdCurnt(j,SearchIndx);
        while(1)
            Vd = Rs * IdTemp;
            Vq = SpeedRnge(j)*2*pi*pairs*(phi + Ld*IdTemp)/60;
            V_Peak= sqrt(Vd^2 + Vq^2);
            if(V_Peak >= PhaseVoltageMax)
                break;
            end
            IdTemp = IdTemp + 0.5;

        end
        % MAP IdCurnt(i,1:SearchIndx)= MAP IdCurnt(j, SearchIndx)
        if IdTemp >0
            IdTemp = 0;
        end
        MAP_IdCurnt(j,1:SearchIndx-1) = IdTemp;
    end

end
%[1300:1450:1600:1750:1900:2100:2300:2600;2900:3300;3800: 4500: 5300: 6200: 7500]
%fitting curve
MAP_Te = 1.5*pairs*(phi.*MAP_IqCurnt + (Ld - Lq).*MAP_IdCurnt .* MAP_IqCurnt);
MaxTeIndex = 1:length(SpeedRnge);
TeTableSize = fix(MaxTe/0.1);
TeIndexTable = zeros(length(SpeedRnge),TeTableSize);

colNameIq = {'Te','Iq'};
colNaneId = {'Te','Id'};
rowName ={'2500','2700','2900','3300','3600','4000','4400','4800','5400','6000','3800','7000','8000','9000'};
MaxTe_Table = zeros(length(SpeedRnge),1);


for j= 1:length(SpeedRnge)
    NonZoIndx= 1;
    while( abs(MAP_Te(j,NonZoIndx)-0)< 0.001)
        NonZoIndx = NonZoIndx + 1;
        if NonZoIndx >= size(MAP_Te(j,:),2)
            break;
        end
    end

    EachSpdMaxTe= max(MAP_Te(j,:));
%   EachSpdMaxTe
    MaxTeIndex(j) = 1;
    while (MAP_Te(j, MaxTeIndex(j)) < EachSpdMaxTe)
        if MAP_IdCurnt(j,MaxTeIndex(j)) <= MINId
            break;
        end
        MaxTeIndex(j) = MaxTeIndex(j)+1;
    end

% MAP_Te(i,NonZoIndx- 1:end) = DataUniquechack(MAP_Te(i,NonzoIndx - 1:end));
% 
% MAP_Iq_temp{1} = griddedInterpolant( MAP_Te(j, NonzoIndx - 1: MaxTeIndex(j)),MAP_IqCurnt(j,NonzoIndx - 1:MaxTeIndex(j)),'linear');
% MAP_Id_temp{1} = griddedInterpolant( MAP_Te(j, NonzoIndx - 1: MaxTeIndex(j)),MAp_IdCurnt(j,NonzoIndx - 1:MaxTeIndex(j)),'linear');
% 
% Te_table1 = linspace(MAP_Te(j, NonoIndx - 1), MAP_Te(j, MaxleIndex(i)),round(MaxTeIndex(i)*MAP_Size/SizeofMapCol));

    sizeofTable = round(MaxTeIndex(j)*MAP_Size/SizeofMapCol);

    MAP_Te(j, 1 : MaxTeIndex(j)) = DataUniqueChack(MAP_Te(j, 1 : MaxTeIndex(j)));
    MAP_Iq_temp{1} = griddedInterpolant( MAP_Te(j, 1 : MaxTeIndex(j)), MAP_IqCurnt (j, 1: MaxTeIndex(j)), 'linear');
    MAP_Id_temp{1} = griddedInterpolant( MAP_Te(j, 1 : MaxTeIndex(j)), MAP_IdCurnt (j, 1: MaxTeIndex(j)), 'linear');
    MaxTe_Table(j,1) = MAP_Te(j,MaxTeIndex(j));
    Te_table1 = linspace(MAP_Te(j, 1), MAP_Te(j, MaxTeIndex(j)),sizeofTable);

    MAP_Iq_Interpolant{j, 1}(1:sizeofTable)= MAP_Iq_temp{1}(Te_table1);
    MAP_Id_Interpolant{j, 1}(1:sizeofTable)= MAP_Id_temp{1}(Te_table1);
    MAP_Te_Interpolant{j, 1} = 1.5*pairs*(phi.*MAP_Iq_Interpolant{j,1} + (Ld- Lq).*MAP_Id_Interpolant{j,1}.* MAP_Iq_Interpolant{j,1});

    TeIndex=0;
    while(TeIndex < TeTableSize)
        Te = MAP_Te(j,MaxTeIndex(j));
        TeIndex = TeIndex + 1 ;
        for i= 1:MaxTeIndex(j)

            if Te > MAP_Te_Interpolant{j, 1}(i)
                i = i + 1;
            else
                TeIndexTable(i,TeIndex)= i;
                break;
            end
        end
    end
    Table_Iq{j, 1} = table(MAP_Te_Interpolant{j, 1}, MAP_Iq_Interpolant{j,1},'variableNames',colNameIq);
    Table_Id{j, 1} = table(MAP_Te_Interpolant{j, 1}, MAP_Id_Interpolant{j,1},'variableNames',colNaneId);
end

flux_Id_Table = zeros(length(SpeedRnge),TeTableSize);
flux_Iq_Table = zeros(length(SpeedRnge),TeTableSize);

% for i = 1:length(SpeedRnge)
%     for j = 1:TeTableSize
%         if TeIndexTable(i,j) == 0
%             flux_Iq_Table(i,j:end)= MAP_Iq_Interpolant{i,1}(TeIndexTable(i,j-1));
%             flux_Id_Table(i,j:end)= MAP_Id_Interpolant{i,1}(TeIndexTable(i,j-1));
%             break;
%         end 
%     flux_Iq_Table(i,j) = MAP_Iq_Interpolant{i,1} (TeIndexTable(i,j));
%     flux_Id_Table(i,j) = MAP_Id_Interpolant{i,1} (TeIndexTable(i,j));
%     end
% end

% Te_BreakPoint = 1.5*pairs*(phi.*flux_Iq_Table + (Ld - Lq).*flux_Id_Table .* flux_Iq_Table);


figure(1);
plot([MINId, MINId],[0, MaxCur],'b');
hold on;
for cur= 20:10:MaxCur
plot(cur*sind(180:270),cur*cosd(0:90));
hold on;
end
grid on;
for j= 1:length(SpeedRnge)
    figure(1);
    plot (MAP_Id_Interpolant{j,1},MAP_Iq_Interpolant{j,1});
    Str=[num2str(SpeedRnge(j)),'RPM'];
    text(MAP_Id_Interpolant {j, 1} (1,end),MAP_Iq_Interpolant {j, 1} (1, end), Str);
    hold on;
    figure(2);
    plot(MAP_IdCurnt(j,:))
    hold on;
    figure(3);
    plot(MAP_IqCurnt(j,:));
    hold on;
end
grid on;
function Array = DataUniqueChack(Array)

    TempArray= ones(1,length(Array));
    counter = 0;
    TempArray(1) = Array(1);
    for i= 2:length(Array)
        TempArray(i)= Array(i);
        for j= 1:i-1
            if TempArray(j) == Array(i)
                counter = counter +1;
                TempArray(i)= Array(i)+0.0000001*counter;
            end
        end
    end
    Array= TempArray;
end










