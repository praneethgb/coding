#count  = 0
def splitter(status, M):
    for i in range(1, len(status)):
        start = status[0:i]
        end = status[i:]
        #if start <= M and end <= M:
 #       count += 1
        yield [start, end]
        for split in splitter(end, M):
            #if start <= M:
  #          count +=1
            result = [start]
            result.extend(split)
            yield result

comb = list(splitter('12','12'))
print comb
