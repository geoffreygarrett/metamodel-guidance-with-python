function traj = pwlinrateTraj(w_i,t,q0,isPeriodic,tol)
% refine and integrate trajectory based on array w_i (N-by-3)
% parameters w_i define the shape of the angular rate trajectory in [0 1],
% each row of w_i contains the angular rate values at the breakpoints of
% an evenly-spaced polygonal line
% optionally specify isPeriodic = true for continuity at the endpoints
% (in this case, you should have w_i(end,:) = w_i(1,:))
% note: currently unsupported
% optionally, specify tolerance for quaternion integration

% return description string when called with no argument
if nargin == 0
    traj = 'piecewise-linear 3-axis angular rate trajectory (integrated to quaternion)';
    return;
end % if

% work with vertical array
if size(w_i,2) > size(w_i,1)
    w_i = w_i';
end

% default = non-periodic
if nargin < 4
    isPeriodic = false;
end

if nargin < 5
    tol = 1e-7;
end

if isPeriodic == true
    error('periodic traj currently unsupported => to be done');
end

N = size(w_i,1); % number of points
t_i = linspace(t(1),t(end),N)'; % brkpoints of piecewise linear rate profile

w = interp1q(t_i,w_i,t(:)); % refine angular rates trajectory
% compute angular acceleration (constant over each segment)
dw_i = diff(w_i,1)./repmat(diff(t_i(:)),1,3); 
[q,q_i] = quatInteg(q0,t_i,w_i,dw_i,t,tol); % integrate quaternion profile

% concatenate output into a single trajectory array
traj = [t(:),w,q];

% draw resulting curve if nargout == 0
if nargout == 0
    subplot(2,1,1);
    plot(t,w);
    hold on ;
    plot(t_i,w_i,'ro');
    xlabel('time [s]');
    ylabel('angular rate [rad/s]');
    
    subplot(2,1,2);
    plot(t,q);
    hold on ;
    plot(t_i,q_i,'ro');
    xlabel('time [s]');
    ylabel('quaternion [-]');
end % if
