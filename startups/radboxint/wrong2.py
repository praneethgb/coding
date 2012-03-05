def minCoins (a,b):
	result = []
	for i in range(b+1):
		result.append(99999)
		
	result[0] = 0
	for current in range(1,b+1):
		for k in range(len(a)):
			ref = result[current - a[k]] + 1
			if a[k] <= current and ref < result[current]:
				result[current] = result[current - a[k]] + 1
		return result[b]

SumNeeded = 11
AvailDenominations = [1,3,5]
value = minCoins(AvailDenominations,SumNeeded)
print "Number of coins needed = ",value
