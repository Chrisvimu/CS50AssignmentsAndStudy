from cs50 import get_float

# Constants to use in the program
quarter = 25
dime = 10
nickel = 5
penny = 1
# Variables to use
change = 0
coins = 0

# Makes the operation to get the reminder and the type of coin used


def greedy(x, div):
    i = 0
    global coins
    i = int((x / div))  # Rounding so that it only takes the whole number before the decimals
    x = (x % div)
    coins = (coins + i)
    return x

# Checkes and selects the operation to be made for change to reach 0


def lookChange(x):
    while (x > 0):
        print("Esto es el loop, ", x)
        if (x >= quarter):
            x = greedy(x, quarter)

        elif (x >= dime):
            x = greedy(x, dime)

        elif (x >= nickel):
            x = greedy(x, nickel)

        elif (x >= penny):
            x = greedy(x, penny)
        else:
            return x
    return x


# Validates user input
while(change < 0.1):
    change = round(100*(get_float("Change Owed: ")))
# Calculates minimun number of coins to give
lookChange(change)

# Return coins
print(coins)