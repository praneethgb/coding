def mincoins(som,coinlist):
	result = []
	for i in range(som+1):
		result.append(-1)
	result[0] = 0
	for i in range(1,som+1):
		for value in coinlist:
			if value<=i and (result[i-value]+1<result[i] or result[i] == -1):
				if result[i-value] != -1:
					result[i] = result[i - value] + 1
	return result[som]



SumNeeded = 11
AvailDenominations = [5,5,5]
value = mincoins(SumNeeded, AvailDenominations)
print "Number of coins needed = ",value

