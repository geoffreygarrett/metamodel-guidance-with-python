function Ft = batch_sim(mdl, X)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
batch_size = length(X);
tStart = tic;
warning('off','Simulink:Engine:UINotUpdatedDuringRapidAccelSim');
simIn(1:length(X)) = Simulink.SimulationInput(mdl);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
for i = 1:batch_size
    simIn(i) = simIn(i).setExternalInput(X(i));
    simIn(i) = simIn(i).setModelParameter(...
            'SimulationMode','normal',...
            'SaveOutput', 'on',...
            'SaveTime', 'on');
end
%            ,...
            %'RapidAcceleratorUpToDateCheck','off'

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
simOut = parsim(simIn, 'ShowProgress', 'on', ...
    'SetupFcn', @() parallel_rapid_accel_sims_script_setup(mdl));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function parallel_rapid_accel_sims_script_setup(mdl)
    % Temporarily change the current folder on the workers to an empty
    % folder so that any existing slprj folder on the client does not
    % interfere in the build process.
    currentFolder = pwd;
    tempDir = tempname;
    mkdir(tempDir);
    evalin( 'base', 'run workerInit.m' )
    cd (tempDir);
    %Simulink.BlockDiagram.buildRapidAcceleratorTarget(mdl);
    oc = onCleanup(@() cd (currentFolder));
    
end

n_s = size(simOut(1).F, 1);
n_f = size(simOut(1).F, 2);
n_b = batch_size;
% F = zeros(n_s, n_f, n_b);
% tout = zeros(n_s, 1, n_b);


Ft = zeros(n_s, 1+n_f, n_b);
for i = 1:batch_size
    Ft(:,2:end,i) = simOut(i).F;
    Ft(:,1,i) = simOut(i).t;
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
disp(["Duration: ", num2str(toc(tStart)/batch_size)]);
save('Ft.mat', 'Ft');
end

