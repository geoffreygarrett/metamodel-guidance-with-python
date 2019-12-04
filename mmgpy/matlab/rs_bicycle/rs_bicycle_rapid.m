%load("rs_bicycle_init.m");
mdl = "rs_bicycle2";
rtp = Simulink.BlockDiagram.buildRapidAcceleratorTarget(mdl);
%%

x1 = [
0, 0;    
5, 0.5;
100, 0.5;
200, 0];

x2 = [
0, 0;    
5, 0.1;
10, 0.3;
200, 0];

x_set = cat(3, x1,x2,x1, x1, x1, x1, x1, x1, x1, x1, x1, x1, x1, x1, x1);



%vel = x;
% 
%simout1=sim(mdl, "rs_bicycle2/block", 'x2');
% simout2=sim(mdl, "vel/vel", vel);
% %simout2=sim(mdl, 'vel', x2);

test = @() run_sims(x_set, rtp, mdl);


%out = run_sims(x_set, rtp, mdl);


function simout = run_sims(x_set, rtp, mdl)
    num_x = size(x_set,3);
    for i = 1:num_x
        paramSet(i) = ...
            Simulink.BlockDiagram.modifyTunableParameters(rtp, ...
            'vel', x_set(:,:,i));
    end
    for i = 1:num_x
        simout(i) = sim(mdl,'SimulationMode','rapid',...
                          'RapidAcceleratorUpToDateCheck','off', ...
                          'RapidAcceleratorParameterSets',paramSet(i));
    end
end