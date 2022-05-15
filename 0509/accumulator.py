###
total = 0
def make_accumulator(initial_amount):
    total = initial_amount
    def accumulator(amount):
        global total
        total += amount
        return total
    return accumulator


a = make_accumulator(5)
print("a(10) = {}".format(a(10)))
print("a(10) = {}".format(a(10)))


####
def make_accumulator(initial_amount):
    total = initial_amount
    def accumulator(amount):
        nonlocal total
        total += amount
        return total
    return accumulator

a = make_accumulator(5)
print("a(10) = {}".format(a(10)))
print("a(10) = {}".format(a(10)))
