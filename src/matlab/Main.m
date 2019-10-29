clear all;

% Design vector.
%x = Simulink.Parameter([0.2, 0.05, 0.1, 0.1, 0.1, 0.1]);

% Parameters.
g              = Simulink.Parameter(9.81);  % [m/s/s]
init_position  = Simulink.Parameter(0.0);   % [m]
init_velocity  = Simulink.Parameter(0.0);   % [m/s]
duration       = Simulink.Parameter(200.0); % [s]
limit_velocity = Simulink.Parameter(60.0);  % [m/s]

% Environment parameters.
env_route_length = 1000;                      % [m]
env_traffic_pos = [0.25; 0.75];               % [-] Fraction of route.
env_traffic_times = [180 * 0.25; 180 * 0.75]; % [s]
env_traffic_durations = [10.0; 20.0];         % [s]
env_forest = [0.40,0.60];                     % [-] Fraction of route.
env_t_rain_start = 100.0;                     % [-] Fraction of route.  
env_mu_s_dry = 0.7;
env_mu_s_wet = 0.4;


save("test");
simIn = Simulink.SimulationInput('Bicycle');
% simIn.setModelParameter('init_position', init_position);
% simIn.setModelParameter('init_velocity', init_velocity);
% simIn.setModelParameter('body_mass', body_mass);
% simIn.setModelParameter('x', x);

simIn = simIn.setModelParameter('StopTime', string(200));
simIn = simIn.setModelParameter('FixedStep', string(0.1));
simIn = simIn.setModelParameter('Solver', 'ode4');

simOut = sim(simIn);

