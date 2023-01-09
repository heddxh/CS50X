from cs50 import get_string


text = get_string('Text:')
words = text.split()
count_word = len(words)

for i in range(count_word):
    if words[i].isalpha():
        count_letter += len(words[i])
    elif words[i][-1] in '.?!':
        count_letter += len(words[i]) - 1
        count_sentence += 1

L = count_letter / count_word * 100
S = count_sentence / count_word * 100

index = 0.0588 * L - 0.296 * S - 15.8

print()