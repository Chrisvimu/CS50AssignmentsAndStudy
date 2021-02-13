# Imports for dependancies
import cs50
import re

# Function to get index acording to the Coleman-Liau index


def readingIndex(letters, sentence, words):
    X = (0.0588 * (100 * letters / words) - 0.296 * (100 * sentence / words) - 15.8)
    return X

# Function to check for letters and sentences and words in text


def processText(newText):
    rLttr = len(re.findall("[a-zA-Z]", newText))
    rWrd = len(re.findall(r"[^\S\n\t]+", newText)) + 1
    rSntnc = len(re.findall("[.!?]", newText))

    return readingIndex(rLttr, rSntnc, rWrd)

# Function that returns the grading as a String


def getGrading(grade):
    if grade > 16:
        X = "Grade 16+"
    elif grade < 1:
        X = "Before Grade 1"
    else:
        X = "Grade " + str(grade)

    return X


# Get text
inpt = cs50.get_string(input)
# Calls functions
Z = getGrading(round(processText(inpt)))

# Returns results
print(Z)