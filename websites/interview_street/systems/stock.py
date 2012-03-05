def msum2(a):
    bounds, s, t, j = (0,0), -float('infinity'), 0, 0
    for i in xrange(len(a)):
        t = t + a[i]
        if t > s: bounds, s = (j, i+1), t
        if t < 0: t, j = 0, i+1
    return (s, bounds)

t = int(raw_input())
while t:
    profit = 0
    n = int(raw_input())
    data = map(int, raw_input().split())
    diff = [data[i+1]-data[i] for i in xrange(len(data)-1)]
    while diff:
        part_profit, bounds = msum2(diff)
        if part_profit > 0:
            profit += part_profit
        del diff[bounds[0]]
    t = t-1
    print profit
