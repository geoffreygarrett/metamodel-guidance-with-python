%% ENVIRONMENT PARAMETER INITIALISATION
% Specific problem constants.
P_E.sun_grav_param = 1.327124*10^20;   % [m^3 / s^2]

% Target body = Mars
mean_mars_sma  = 228 * 10 ^ 9  ;        % semi-major-axis [m]
mean_mars_radius  = 6779000 / 2;        % [m]
mars_grav_param   = 4.282837 * 10 ^ 13; % [m^3 / s^2]
P_E.target_grav_param = mars_grav_param;
P_E.target_mean_sma = mean_mars_sma;
P_E.target_mean_radius = mean_mars_radius;

% Satellite body.
P_E.satellite_h = 200 * 10^3;
P_E.satellite_sma = mean_mars_radius + P_E.satellite_h;
P_E.mean_motion = 1 / sqrt(P_E.satellite_sma^3/mars_grav_param);
P_E.P = 2 * pi / P_E.mean_motion;

% Communications body.
mean_earth_sma  = 149598023000  ;   % semi-major-axis [m]
P_E.comms_mean_sma = mean_earth_sma ;

% Initial orbital parameters.
P_E.initial_classical_satellite = ...
 [P_E.satellite_sma            ;   % semi-major-axis [m]
  0.0                          ;   % eccentricity    [-]
  0.0                          ;   % inclination     [rad]
  0.0                          ;   % raan            [rad]
  0.0                          ;   % argp            [rad]
  3/2*pi                       ;   % theta           [rad]
  P_E.target_grav_param]       ;   % mu              [m^2 / s^2]

P_E.initial_classical_target = ...
 [P_E.target_mean_sma          ;   % semi-major-axis [m]
  0.0                          ;   % eccentricity    [-]
  0.0                          ;   % inclination     [rad]
  0.0                          ;   % raan            [rad]
  0.0                          ;   % argp            [rad]
  0.0                          ;   % theta           [rad]
  P_E.sun_grav_param]          ;   % mu              [m^2 / s^2]

P_E.initial_classical_comms = ...
 [P_E.comms_mean_sma           ;   % semi-major-axis [m]
  0.0                          ;   % eccentricity    [-]
  0.0                          ;   % inclination     [rad]
  0.0                          ;   % raan            [rad]
  0.0                          ;   % argp            [rad]
  pi/2                         ;   % theta           [rad]
  P_E.sun_grav_param]          ;   % mu              [m^2 / s^2]

save('P_E.mat', 'P_E');

%% SIMULATE INDEPENDENT ENVIRONMENT SOLUTION
sim('environment_sim');

%% PERFORMANCE DEPENDENT PARAMETERS
% Spacecraft body geometry configuration.
P_F.star_sensor_1_vb = [1/sqrt(2), +1/sqrt(2), 0];
P_F.star_sensor_2_vb = [1/sqrt(2), -1/sqrt(2), 0];
P_F.thruster_vb = [-1, 0, 0];
P_F.antenna_vb = [1, 0, 0];
P_F.solar_array_vb = [0, 1, 0];

% Thrust related.
P_F.thrust_shadow_weight = 1.0;
P_F.thrust_no_shadow_weight = 1.0;

% Star sensor settings.
P_F.window_t = 600;                   % Blindness window. [s]
P_F.window_n = int16(P_F.window_t/10.0);  % Window samples. [#]

% Save performance parameters.
save('P_F.mat', 'P_F');


%% CREATE ENVIRONMENT BUS
load('ENVIRONMENT.mat');
busInfo = Simulink.Bus.createObject(E);
ENVIRONMENT = eval(busInfo.busName);

%% CONSTRUCTOR DEPENDENT PARAMETERS
P_X.max_omega = 10 * P_E.mean_motion * [1.0, 1.0, 1.0];
P_X.init_vel_vec = E.v_s.Data(1,:);
P_X.init_pos_vec = E.r_s.Data(1,:);
P_X.init_xBI = P_X.init_vel_vec/norm(P_X.init_vel_vec);
P_X.init_yBI = -P_X.init_pos_vec/norm(P_X.init_pos_vec);
P_X.init_zBI = cross(P_X.init_xBI, P_X.init_yBI);

save('P_X.mat', 'P_X');

%% CREATE PARAMETER BUS'
load('P_X.mat');
load('P_E.mat');
load('P_F.mat');

%% TESTING

t = [0.000 * P_E.P;
     0.500 * P_E.P;
     1.001 * P_E.P];
 
Wx = P_X.max_omega' * 0.1;

x_v = cat(2, t, zeros(size(Wx)), zeros(size(Wx)), Wx);
disp(x_v);
  
x_example = timeseries(x_v(:,2:end), x_v(:,1));
x_example_batch = cat(1, x_example, x_example, x_example, x_example);
x_example_batch_large = cat(1,  x_example_batch, x_example_batch, ...
                                x_example_batch, x_example_batch, ...
                                x_example_batch, x_example_batch, ...
                                x_example_batch, x_example_batch);
                            
x_example_batch_large = cat(1, x_example_batch_large, x_example_batch_large, ...
    x_example_batch_large,x_example_batch_large,x_example_batch_large);
save('x_example.mat','x_example');
x = x_example;


sout = sim('attitude3d');

