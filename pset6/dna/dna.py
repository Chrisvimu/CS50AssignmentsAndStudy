from sys import argv
import csv
from re import search

dnaDict = {}

# checks for arguments.
if len(argv) != 3:
    print("Error usage, dna.py database.csv sequence.txt")
    exit()


# Creates a dictionary key and value, adding them to the dictionary.
def makeKey(person):
    name = person[0]
    person.pop(0)  # Deletes name from DNa fields
    adnKey = "".join(person)  # Joins the remaining columns
    dnaDict[adnKey] = name  # Creates dict relation


# Iterates using the atributes finding the higest repetition.
def findRepetitions(atribute, sequenceText):
    hasEnded = False
    x = atribute
    i = 1
    while hasEnded == False:
        if sequenceText.find(x) != -1:
            i += 1
            x = atribute*i  # Repeat the string once more
        else:
            hasEnded = True
    return i-1


# Gets DNA sequence to compare.
with open(argv[2], "r") as dnaSequence:
    dnaReader = str(next(csv.reader(dnaSequence)))


# Compares sequence to registers.
def isThisAMatch(key):
    x = dnaDict.get(key)
    if x != None:
        print(x)
    else:
        print("No match")


# Checks if there could be a DNA match.
def checksForMatch(atributes):
    atributes.pop(0)  # eliminates name from atributes
    newDnaKey = ""
    for x in atributes:
        tempDna = str(findRepetitions(x, dnaReader))  # gets number of repetitions for each DNA code
        newDnaKey = newDnaKey + tempDna
    isThisAMatch(newDnaKey)
    exit()


# Gets column headings for searching and atributes for dict.
with open(argv[1], "r") as dnaFile:
    reader = csv.reader(dnaFile)
    columnsDna = iter(reader)  # Columns for sequences of DNA in database
    atributesDna = next(reader)  # Atributes of the first colum for sequences of DNA
    for row in columnsDna:  # Loops for each element in the csv
        makeKey(row)
    checksForMatch(atributesDna)