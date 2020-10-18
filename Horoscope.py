import requests
from bs4 import BeautifulSoup
import sys
if len(sys.argv) == 1:
    val=input('Enter your zodiac sign : ')
    #   val = 'scorpio'
else:
    val = sys.argv[1]

r = requests.get(f'http://my.horoscope.com/astrology/free-daily-horoscope-{val}.html').text
search = BeautifulSoup(r, "html.parser")
#   print(search.title)
#   print(search.prettify())
try:
    date = search.find('strong').get_text()
    stat = search.find('p').get_text()
    stat = stat[len(date)+3:]
    print('Horoscope For Zodiac :',val,'\nHoroscope Date : ',date,'\nYour Hroscope Today : ',stat)
    #   print(stat)
    #   print(date)
except AttributeError:
    print('Hm. Your Zodiac sign is invalid.')
#   print(r.status)
