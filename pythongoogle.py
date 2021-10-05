# google search using python steps to install
# pip indtall beautifulsoup then pip install google
try:
	from googlesearch import search
except ImportError:
	print("No module named 'google' found")

# to search
query = "Geeksforgeeks"

for j in search(query, tld="co.in", num=10, stop=10, pause=2):
	print(j)
