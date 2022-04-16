import statistics

def normalcdf(mu = 0, sigma = 1, lower_bound = -int(1e99), upper_bound = int(1e99)):
    return NormalDist(mu=mu, sigma=sigma).cdf(upper_bound) - NormalDist(mu=mu, sigma=sigma).cdf(lower_bound)
