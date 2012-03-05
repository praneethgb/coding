# http://codeeval.com/open_challenges/37/
import sys
from collections import defaultdict
import string

f = open(sys.argv[1], 'r')
cases = f.readlines()
for case in cases:
    every_letter = True
    if case:
        letters = defaultdict(int)
        for letter in case:
            letters[letter.lower()] += 1
        for letter in string.lowercase:
            if not letter in letters.keys():
                sys.stdout.write(letter)
                every_letter = False
        if every_letter:
            print "NULL"
        else:
            print
