#program will produce a strong password
sentence=list(input("Enter the sentence :: ").split())
ch="!@#$%^&*()<>?"
pas=""
for i in sentence:
    pas=pas+chr(ord(i[0])+2)  #appending character 2 next to 1st character of word
pas=pas+ch[len(sentence)%(len(ch))] #appending special character in password
pas=pas+str(len(sentence)+9) #appending a no. equal to sentence length+9
i=0
while(len(pas)<8):
    pas=pas+chr(i+65)     # if password is smaller then 8 characters then append capital alternate letters starting from A
    i+=2
print(pas)