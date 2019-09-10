import torch
n=1000
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
dist = torch.distributions.normal.Normal(loc = 0.0, scale = 1.0)
x = dist.sample((2 * n,1)).to(device)
y = dist.sample((2 * n,1)).to(device)
z = dist.sample((2 * n,1)).to(device)
S = torch.cat((x,y,z), axis=1).to(device)
S1 = S[:n,:].to(device)
S2 = S[n:,:].to(device)
print(f"Using torch device: {device}")
