import math
ans=0
def f(n): #sum of factorial of digits
	sum=0
	for g in str(n):
		sum += math.factorial(int(g))
	return sum

#print f(342)

def sf(n): # sum of digits
	sum=0
	for g in str(n):
		sum+=int(g)
	return sum

#print sf(f(342))

for a in range(31,46):
	i=1
	while True:
		if sf(f(i))==a:
			ans+=sf(i)
			break
		i+=1
		print i

print ans
