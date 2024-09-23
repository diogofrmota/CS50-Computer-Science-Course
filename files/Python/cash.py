from cs50 import get_float

cash = -1
while cash < 0:
    cash = get_float("cash: ")

cents = int(cash * 100)

c25 = cents // 25
cents %= 25

c10 = cents // 10
cents %= 10

c5 = cents // 5
cents %= 5

c1 = cents

print(c25 + c10 + c5 + c1)
