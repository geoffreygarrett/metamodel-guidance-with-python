%% Orbital init
%Specific problem constants.
sun_grav_param = 1.327124*10^20;   % [m^3 / s^2]

% Target body = Mars
mean_mars_sma  = 228 * 10 ^ 9  ;        % semi-major-axis [m]
mean_mars_radius  = 6779000 / 2;        % [m]
mars_grav_param   = 4.282837 * 10 ^ 13; % [m^3 / s^2]
target_grav_param = mars_grav_param;
target_mean_sma = mean_mars_sma;
target_mean_radius = mean_mars_radius;

% Satellite body.
satellite_h = 200 * 10^3;
satellite_sma = mean_mars_radius + satellite_h;
mean_motion = 1 / sqrt(satellite_sma^3/mars_grav_param);
P = 2 * pi / mean_motion;
max_omega = 10 * mean_motion;

% Communications body.
mean_earth_sma  = 149598023000  ;   % semi-major-axis [m]
comms_mean_sma = mean_earth_sma ;


% Initial orbital parameters.
initial_classical_satellite = ...
 [satellite_sma                ;   % semi-major-axis [m]
  0.0                          ;   % eccentricity    [-]
  0.0                          ;   % inclination     [rad]
  0.0                          ;   % raan            [rad]
  0.0                          ;   % argp            [rad]
  3/2*pi                       ;   % theta           [rad]
  target_grav_param]           ;   % mu              [m^2 / s^2]

initial_classical_target = ...
 [target_mean_sma              ;   % semi-major-axis [m]
  0.0                          ;   % eccentricity    [-]
  0.0                          ;   % inclination     [rad]
  0.0                          ;   % raan            [rad]
  0.0                          ;   % argp            [rad]
  0.0                          ;   % theta           [rad]
  sun_grav_param]              ;   % mu              [m^2 / s^2]

initial_classical_comms = ...
 [comms_mean_sma                ;   % semi-major-axis [m]
  0.0                          ;   % eccentricity    [-]
  0.0                          ;   % inclination     [rad]
  0.0                          ;   % raan            [rad]
  0.0                          ;   % argp            [rad]
  pi/2                         ;   % theta           [rad]
  sun_grav_param]              ;   % mu              [m^2 / s^2]

%% Attitude init
init_quaternion = [1; 0; 0; 0];


% Define test design vector.
x = [0,        max_omega*0.1,  0, 0               ;...
     0.5 * P,  max_omega*0.1,  0, 0               ;...
     1.0 * P,  max_omega*0.1,  0, 0               ];


% Initial attitude parameters.
velSatMars = load('env/v_satellite.mat').ans;
posSatMars = load('env/r_satellite.mat').ans;
init_vel_vec = velSatMars.Data(1,:);
init_pos_vec = posSatMars.Data(1,:);

% Initial body frame in inertial.
%initial_spacecraft_v = velSatMars(1)/norm(velSatMars(1));
init_xBI = [1, 0, 0];
init_yBI = [0, 1, 0];
init_zBI = [0, 0, 1];

% Spacecraft body geometry configuration.
star_sensor_1_vb = [1/sqrt(2), +1/sqrt(2), 0];
star_sensor_2_vb = [1/sqrt(2), -1/sqrt(2), 0];
thruster_vb = [-1, 0, 0];
antenna_vb = [1, 0, 0];
solar_array_vb = [1, 0, 0];

% Thrust settings.
thrust_shadow_weight = 1.0;
thrust_no_shadow_weight = 1.0;

% Star sensor settings.
window_t = 600;                   % Blindness window. [s]
window_n = int16(window_t/10.0);  % Window samples. [#]
