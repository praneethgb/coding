t = int(raw_input())
c = ord('A')
for j in range(1,t+1):
    a = [0]*26
    s = raw_input()
    for i in s:
        index = ord(i) - c
        try:
            a[index] = a[index]+1
        except:
            pass
    ans = min(a[7], a[0], a[2]/2, a[10], a[4], a[17], a[20], a[15])
    print 'Case #%s: %s' % (j,ans)
