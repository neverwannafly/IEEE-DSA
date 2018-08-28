num = 0
MAX = 1000000

with open('../searching/input.txt', 'w') as fp:
    fp.write(str(MAX) + "\n")
    while num < MAX:
        fp.write(str(num) + " ")
        num += 1
    fp.write("\n" + str(MAX-1))