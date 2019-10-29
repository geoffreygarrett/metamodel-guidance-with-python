import matlab.engine
eng = matlab.engine.start_matlab()
#eng.sim("Bicycle")

eng.load("test.mat")
eng.eval("load('test.mat')")
print(eng.workspace['duration'])

#sim_in = eng.Simulink.SimulationInput("Bicycle")
#sim_out = eng.sim(sim_in)
#print(sim_out)
