import numpy as np
n=1000
x = np.random.normal(loc = 0.0, scale = 1.0, size = 2*n) 
y = np.random.normal(loc = 0.0, scale = 1.0, size = 2*n) 
z = np.random.normal(loc = 0.0, scale = 1.0, size = 2*n) 
S = np.concatenate(([x],[y],[z]), axis=0).T
S1 = S[:n,:]
S2 = S[n:,:]