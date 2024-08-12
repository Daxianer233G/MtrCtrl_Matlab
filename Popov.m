clear all;
close all;
% clc;

% 数值积分的步长
h = 0.1;
% 仿真步数，相当于是100秒
L = 100/h;

% 对象参数
num = [1]; den = [1 1 1]; n = length(den) - 1; 
% plant的传递函数形态转换成状态空间
kp = 1;
[Ap, Bp, Cp, Dp] = tf2ss(kp * num, den);
% model的传递函数形态转换成状态空间
km = 1;
[Am, Bm, Cm, Dm] = tf2ss(km * num, den);

% 自适应律的自适应增益
gamma = 0.1;
yr0 = 0;        % 整个系统的参考输入值reference
u0 = 0;         % 初始状态输入
e0 = 0;         % 初始误差
ym0 = 0;        % 参考model的输出值

% 状态向量的初始值
xp0 = zeros(n,1);
xm0 = zeros(n,1);

kc0 = 0;         % 控制器可调增益的初始值

r = 0.6;        % 输入
% 输入信号是一个方波信号
t = 0:1000;
yr = r * square(t / 250 * pi);
% plot(yr);

for k = 1:L
    time(k) = k*h;
    
    % 欧拉法求解微分函数
    
    % 首先是plant的模型输入输出
    xp(:,k) = xp0 + h * (Ap * xp0 + Bp * u0);
    yp(k) = Cp * xp(:,k) + Dp * u0;
    
    % 接着是参考模型的输入输出
    xm(:,k) = xm0 + h * (Am * xm0 + Bm * yr0);
    ym(k) = Cm * xm(:,k) + Dm * yr0;
    
    % MIT 自适应律
    e(k) = ym(k) - yp(k);
    kc = kc0 + h * gamma * e0 * ym0;
    u(k) = kc * yr(k);
%     u(k) = kc * yr0;
    
    % 更新数据
    yr0 = yr(k);    % 模型参考输入reference
    u0 = u(k);      % 控制器的输出，实际plant的输入
    e0 = e(k);      % 误差迭代
    ym0 = ym(k);    % 参考模型的输出
    xp0 = xp(:,k);  % 实际plant模型的状态量
    xm0 = xm(:,k);  % 参考模型的状态量
    kc0 = kc;       % MIT自适应律的更新
end

% 画出参考模型输出和实际模型输出
plot(time,ym,'r',time,yp,'k:');
xlabel('t');
ylabel('y_m(t), y_p(t)');
legend('y_m(t)','y_p(t)');
    
    
