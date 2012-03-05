ans=0
MAX=1000
for a in range(1,MAX):
	if a%5==0 or a%3==0:
		ans+=a
print ans
