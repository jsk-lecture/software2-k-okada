class Deposit():
    def __init__(self, init_balance):
        self.balance = init_balance

    def withdraw(self, amount):
        if amount > self.balance:
            print('Insufficient funds')
        self.balance = self.balance - amount
        return self.balance

kei = Deposit(100)
bill = Deposit(1000)

print(" kei(25) : {}".format(kei.withdraw(25)))
print("bill(25) : {}".format(bill.withdraw(25)))
print(" kei(25) : {}".format(kei.withdraw(25)))
print("bill(25) : {}".format(bill.withdraw(25)))
print(" kei(60) : {}".format(kei.withdraw(60)))
print("bill(60) : {}".format(bill.withdraw(60)))
