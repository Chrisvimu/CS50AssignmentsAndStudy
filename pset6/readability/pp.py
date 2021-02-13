import re

oppe = "picoloco !"
# Finds characters from english alphabet
x = re.findall("[a-zA-Z]",oppe)
# Finds white space
x1 = re.findall(r"[^\S\n\t]+", oppe)
x2 = re.findall("[.!?]", oppe)
print("dddd ",len(x))
print("fff ",len(x1))
print("ggg ",len(x2))
y = len(x)
print(y)
for char in oppe:
    if char == "o":
        print (char)
