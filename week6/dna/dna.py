import csv
import sys


def main():

    #Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit('Usage: python dna.py data.csv sequence.txt')

    # Read database file into a variable
    db = []
    with open(sys.argv[1]) as DB_FILE:
        DB = csv.DictReader(DB_FILE)
        for row in DB:
            db.append(row)
        strs = DB.fieldnames # 在这里直接加上.pop(0)会变成[n,a,m,e]???????
        strs.pop(0)

    # Read DNA sequence file into a variable
    with open(sys.argv[2]) as SEQ_FILE:
        seq = SEQ_FILE.read()

    # Find longest match of each STR in DNA sequence
    result ={}
    for str in strs:
        result[str] = longest_match(seq, str)

    # Check database for matching profiles
    for i in range(len(db)):
        name = db[i]['name']
        del db[i]['name']
        # Cant use db[i] in result since Dict is unhashable
        print(f'result: {result}')
        if is_dict_in(db[i], result) == 1:
            print(name)
            return
        else:
            print(f'No match {is_dict_in(db[i], result)}')
            return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


def is_dict_in(d1, d2):
    '''Check if Dict d1 is in Dict d2. If so, return True'''
    for key in d1:
        temp = d2.get(key)
        if temp == None:
            return 2
        elif temp != d1[key]:
            return 3
        else:
            return 1


if __name__ == '__main__':
    main()
