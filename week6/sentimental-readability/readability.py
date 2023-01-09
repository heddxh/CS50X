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
