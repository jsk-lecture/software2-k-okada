import math
def make_monitored(f):
    count = 0
    def mf(arg):
        nonlocal count
        if arg == 'how-many-calls?':
            return count
        elif arg == 'rest-count':
            count = 0
            return count
        else:
            count = count + 1
            return f(arg)
    return mf

sqrt = make_monitored(math.sqrt)
print("sqrt(9)   = {}".format(sqrt(9)))
print("sqrt(100) = {}".format(sqrt(100)))
print("sqrt called {}".format(sqrt('how-many-calls?')))

