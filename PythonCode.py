import re
import string

#   function CountAllItems()
#   Counts all items in 'ProgramInput.txt'
def CountAllItems():

    # open the file 'ProgramInput.txt' to read
    f = open("ProgramInput.txt", "r")

    #create new dict for groceries (key - Item, val - Count)
    groceries = {}

    # read through each line of the txt file...
    for line in f:

        # remove newline from each line and place in string lineClean
        lineClean = line.replace("\n", "")

        # if the item entered has already been encountered...
        if lineClean in groceries.keys():
            
            # increment the count for that item's dict entry
            groceries[lineClean] += 1

        # if the item hasn't been encountered already...
        else :

            # add the item into the dictionary with a new count of 1
            groceries[lineClean] = 1

    # close the file 'ProgramInput.txt'
    f.close()

    # print newline for formatting purposes
    print("\n")

    # for each item in the groceries dictionary...
    for x, y in groceries.items():

        # print "name": "count",
        print(x + ": " + str(y))

    # print newline for formatting
    print("\n")

#   function CountSpecificItem(x)
#   Counts all occurences of string 'x' in 'ProgramInput.txt'
def CountSpecificItem(x):

    # set initial count to 0
    count = 0

    # open the file ProgramInput.txt
    f = open("ProgramInput.txt", "r")

    # for each line in the ProgramInput.txt file...
    for line in f:

        # if the line, stripped of all newlines, is equal to the string being searched for...
        if line.replace("\n", "") == x:

            # increment count
            count = count + 1

    # close the file
    f.close()

    # return the count
    return count

#   function WriteFrequencies()
#   Counts the frequency of all purchases in ProgramInput.txt and outputs them to the file frequency.dat
def WriteFrequencies():

    # open file ProgramInput.txt
    f = open("ProgramInput.txt", "r")

    # create the empty groceries dictionary
    groceries = {}

    # go through each line in the opened file...
    for line in f:

        # lineClean is the line (item purchased) with all newlines removed
        lineClean = line.replace("\n", "")

        # if the item already exists in the groceries dictionary...
        if lineClean in groceries.keys():
 
            # increment the count for the item in the dictionary
            groceries[lineClean] += 1

        # if the item isn't already in the dictionary...
        else :

            # add the item  to the dictionary and set the initial count to 1
            groceries[lineClean] = 1

    # close ProgramInput.txt
    f.close()

    # open the frequency.dat file with overwrite privileges; create if non-existent
    fWrite = open("frequency.dat", "w+")

    # for each item in the dictionary as x - key, y - value...
    for x, y in groceries.items():
        
        # write a new line in frequency.dat with the item and its count
        fWrite.write("\n" + x + " " + str(y))

    # close frequency.dat
    fWrite.close()
