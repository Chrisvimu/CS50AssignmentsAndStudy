# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


# Creates dictionary of teams for tournaments
def makeKey(team, keyName, valueName):

    key = str(team[0])  # Gets the name of the team
    value = int(team[1])  # Gets the value
    temp = {keyName: key, valueName: value}  # Creates a dict with the name of the team and another item
    return(temp)


# Creates a dictionary to store how much wins the team has had
def makeCount(team, counts):
    key = team
    value = 1
    if(key in counts):  # If the key is not in the dict, its inserted. Else it's value is incremented by 1.
        counts[key] += value
    else:
        counts[key] = value
    return(counts)


# Main function, only calls other functions.
def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # List of teams
    teams = []

    # TODO: Read teams into memory from file
    with open(sys.argv[1], "r") as file:  # Opens file
        reader = csv.reader(file)  # Reader gives iterable properties to the object
        next(reader, None)  # Skips header
        for row in reader:
            X = makeKey(row, 'team', 'rating')  # Calls for (makeKey) the creates elements in dictionary
            teams.append(X.copy())  # appends a copy of the dictionary returned by makeKey()

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(0, N, 1):
        winner = simulate_tournament(teams)
        makeCount(winner, counts)

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""

    while len(teams) != 1:
        teams = simulate_round(teams)
    return teams[0]["team"]  # I used this syntax to extract the dict from the list, and the name of the winning team from the remaining dict


if __name__ == "__main__":
    main()
