data = [2, 3, 4, '*', '+'] # (3 * 4) + 2
#data = [13, 5, 4, '+', 3, '/', 4, '*', '-']
stack = []
for d in data:                       # get d from daa
    if type(d) == int:               # if d is int
        stack.append(d)              # push d to stack
    else:                            # d is operator
        x = stack.pop()
        y = stack.pop()
        if d == '+':
            z = y + x
        elif d == '*':
            z = y * x
        elif d == '-':
            z = y - x
        elif d == '/':
            z = y / x
        stack.append(z)

print("answer is {}".format(stack.pop()))

# mul = lambda x, y: x * y
# add = lambda x, y: x + y
def mul(x, y) : return x * y
def add(x, y) : return x + y
data = [2, 3, 4, mul, add] # ((4 mul 3) add 2) -> add(mul(4, 3), 2) +(*(4, 3), 2)
stack = []
for d in data:                       # get d from daa
    if type(d) == int:               # if d is int
        stack.append(d)              # push d to stack
    else:                            # d is operator
        x = stack.pop()
        y = stack.pop()
        z = d(y, x)
        stack.append(z)

print("answer is {}".format(stack.pop()))

data = [2, 3, 4, lambda x, y: x * y, lambda x, y: x + y]
for d in data:
    if type(d) == int:
        stack.append(d)
    else:
        x = stack.pop()
        y = stack.pop()
        z = d(y, x)
        stack.append(z)

print("answer is {}".format(stack.pop()))

