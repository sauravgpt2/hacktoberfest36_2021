import string
from random import sample
import PySimpleGUI as sg
import pyperclip

def gen_passwd(length, is_digits, is_spch):
	UPPER = string.ascii_uppercase
	LOWER = string.ascii_lowercase
	DIGITS = string.digits
	SPECIAL_CHARS = string.punctuation

	if(not is_digits and not is_spch):
		choices = UPPER + LOWER
	elif(is_digits and not is_spch):
		choices = UPPER + LOWER + DIGITS
	elif(not is_digits and is_spch):
		choices = UPPER + LOWER + SPECIAL_CHARS
	else:
		choices = UPPER + LOWER + DIGITS + SPECIAL_CHARS

	tmp = "*"*length
	win['-PWD-'].update(tmp)
	return "".join(sample(choices, length))

def show_passwd(password):
	win['-PWD-'].update(password)

def copy(password):
	pyperclip.copy(password)

layout = [[sg.Text("Length:"), sg.Slider(range=(8,30), orientation='h', key='-LEN-')],
	  [sg.Text("Choose:"), sg.Checkbox("Digits", key='-DIGITS-'), sg.Checkbox("Special Characters", key='-SPCH-')],
	  [sg.Button("Generate")],
	  [sg.Text("Your Password:"), sg.Text(size=(30,1), key='-PWD-'), sg.Button("Show", disabled=True), sg.Button("Copy", disabled=True)]]

win = sg.Window("Password Generator", layout)

while True:
	event, values = win.read()
	if event == sg.WIN_CLOSED:
		break
	if event == "Generate":
		password = gen_passwd(int(values['-LEN-']), values['-DIGITS-'], values['-SPCH-'])
		win["Show"].update(disabled=False)
		win["Copy"].update(disabled=False)
	if event == "Show":
		show_passwd(password)
	if event == "Copy":
		copy(password)

win.close()
