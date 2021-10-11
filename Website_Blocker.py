# 1. Open CMD in adminstrative mode go to the file location(C:\Users\Dell\Documents\PYTHON PROJECTS\Website-Blocker) and run main.py
# 2. Go to this file location(C:\Windows\System32\drivers\etc\hosts) and check whether the websites name are written to the hosts named file and check the websites in the browser that they are running or not with the help of the url. 


import time
from datetime import datetime as dt

ip_localmachine="127.0.0.1"
website_lists=["www.facebook.com", "facebook.com"]
hosts_path="C:\Windows\System32\drivers\etc\hosts"
start_time="09:0:0"
end_time="1:0:0"

now = dt.now()
current_time = now.strftime("%H:%M:%S")
print(current_time)

while True:
    if start_time <= current_time and current_time <= end_time:
        print("Working Hours")
        with open(hosts_path, "r+") as file:
            content = file.read();
            for website in website_lists:
                if website in content:
                    pass
                else:
                    file.write(ip_localmachine+" "+website+"\n")
    else:
        print("Non-Working Hours")
        with open(hosts_path, "r+") as file:
            content = file.readlines();
            file.seek(0)
            for line in content:
                if not any(website in line for website in website_lists):
                    file.write(line)
                
                file.truncate()
    time.sleep(10)