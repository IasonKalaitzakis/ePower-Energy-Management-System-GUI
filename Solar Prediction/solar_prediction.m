clear;
close all ;
clc ;
% warning off;

t = [0:0.5:24];

load('PV_prod_summer.mat')
radiation = movmean(PV_load,3);
% load('solar_PV_production_1000_rated_watts.mat')
% load('solar_radiation.mat')
load('summer_daily_temperature.mat')
temperature = data;

figure
plot(t,radiation,'b','LineWidth', 1.5)
ylabel('I_r (W/m^2)')
xlabel('t (hours)')

figure
plot(t,temperature,'r','LineWidth', 1.5)
ylabel('T (°C)')
xlabel('t (hours)')

% Ppv = (radiation/100)* 1000 .* [1-0.005.*(temperature+10)] * 0.04
Ppv = (radiation/100)* 30000 .* [1-0.005.*(temperature+10)] * 0.04

figure
plot(t,movmean(Ppv,2)/300,'g','LineWidth', 1.5)
% ylabel('P_P_V (kW)')
ylabel('P_P_V (W)')
xlabel('t (hours)')
