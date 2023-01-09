from cs50 import get_string


text = get_string('Text:')
words = text.split()
count_word = len(words)
count_letter = 0
count_sentence = 0


for i in range(count_word):
    if words[i].isalpha() == False:
        for letter in words[i]:
            if letter.isalpha():
                count_letter += 1
            elif letter in '.?!':
                count_sentence += 1
    else:
        count_letter += len(words[i])

L = count_letter / count_word * 100
S = count_sentence / count_word * 100

print(count_letter, count_word, count_sentence)

index = round(0.0588 * L - 0.296 * S - 15.8)

if index >= 16:
    print('Grade 16+')
elif index < 1:
    print('Before Grade 1')
else:
    print(f'Grade {index}')