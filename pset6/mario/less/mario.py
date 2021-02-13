from cs50 import get_int

# Declaring pyramid height with 0
pyramid = 0


# Loops asking for user input until an int betwen 1 and 8 is provided.
while(pyramid < 1 or pyramid > 8):
    pyramid = get_int("Height: ")

# prints # and spaces depending of the height of the pyramid
for row in range(pyramid):
    gatos = row + 1
    spaces = pyramid - gatos

    print(" " * spaces, end="")
    print("#" * gatos)

