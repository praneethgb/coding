t = int(raw_input())

def check(words, font_size, w, h):
    w_count = 0
    h_count = font_size 
    for word in words:
        if w_count != 0:
            w_count += font_size
        w_count += len(word)*font_size
        if w_count > w:
            h_count += font_size
            w_count = len(word)*font_size
        if h_count > h:
            return False
    return True

        


for i in range(1, t+1):
    line = raw_input()
    w, h, s = line.split(' ', 2)
    flag = 0
    w = int(w)
    h = int(h)
    words = s.split(' ')
    max_length = max(map(len, words))
    if max_length > w:
        print "Case #%s: 0" % i
        continue
    font_size = w/max_length
    for j in xrange(font_size, 0, -1):
        if check(words, j, w, h):
            print "Case #%s: %s" % (i, j)
            flag =1
            break
    if flag == 0:
        print "Case #%s: 0" % i

