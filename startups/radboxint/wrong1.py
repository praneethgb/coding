def MinCoins(sum, coinDenominations):
	result = []
	for i in range(0,sum+1):
		result.append(-1)

	result[0]=0
	for currentSum in range(1,sum+1):
		for j in range(0,len(AvailDenominations)):
		  ref = result[currentSum - AvailDenominations[j]] + 1

         	  if (AvailDenominations[j] <= currentSum and ref < result[currentSum]) or ref <= -1:

				tempA = result[currentSum - AvailDenominations[j]]
				tempB = tempA+1
           			result[currentSum] = tempB

        return result[sum]

SumNeeded = 11
AvailDenominations = [1,3,5]
value = MinCoins(SumNeeded, AvailDenominations)
print "Number of coins needed = ",value

