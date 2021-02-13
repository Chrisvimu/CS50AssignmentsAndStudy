# Imports and libs
from sys import argv
import csv

# Dictionary
dnaDict = {}

# checks for arguments
if len(argv) != 3:
    print("Error usage, dna.py database.csv sequence.txt")
    exit()

# Creates a dictionary key and value, adding them to the dictionary
def makeKey(person):
    name = person[0]
    person.pop(0) #Deletes name from DNa fields
    adnKey = "".join(person)
    dnaDict[adnKey] = name
    print(dnaDict)


# Gets column headings for searching.
with open(argv[1], "r") as dnaFile:
    reader = csv.reader(dnaFile)
    columnsDna = next(reader) #Columns for sequences of DNA in database
    print(columnsDna, len(columnsDna))
    print(columnsDna[0])
    makeKey(columnsDna)
    for row in reader[1:]:
        if row
        print(makeKey(row))

# Creates a dictionary

    # Procesa la llave + el valor(nombre) y lo agrega al diccionario


# Searches for ocurrences of each secuence

    # Procesa llave de DNA
    # Por cada atributo,
        # busca repeticiones del mismo.
        # compara el contador actual con el registrado, si es mayor se guarda si no se sigue.
        # al llegar al final del archivo termina.
    # Añade la cantidad maxima de repeticiones no interrumpidas
    # Se llama a si mismo hasta que no queden secuencias por revisar.

# Compares sequence to registers

    # revisa los registros, si hay una llave igual hace un match.
    # Si no, sale negativo.


