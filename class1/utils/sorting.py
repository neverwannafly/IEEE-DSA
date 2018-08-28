from random import randint

num = 0
MAX = 100000

with open('../sorting/input.txt', 'w') as fp:
    fp.write(str(MAX) + "\n")
    while num < MAX:
        fp.write(str(randint(0, MAX-1)) + " ")
        num += 1
    fp.write("\n" + str(MAX-1))