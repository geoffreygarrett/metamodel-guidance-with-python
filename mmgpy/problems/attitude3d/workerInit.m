load P_X.mat
load P_E.mat
load P_F.mat
load('ENVIRONMENT.mat');
busInfoE = Simulink.Bus.createObject(E);
ENVIRONMENT = eval(busInfoE.busName);
x = load('x_example.mat');
x = x.('x_example');