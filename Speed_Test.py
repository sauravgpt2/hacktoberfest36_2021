import speedtest # pip install speedtest-cli
import time
s = speedtest.Speedtest()

print("Loading Servers")
s.get_servers() # Getting the servers

print("Connecting to the Best Server")
bestServer = s.get_best_server() # Choosing the best server
print(f"Connected to {bestServer['host']} located in {bestServer['country']} ")
time.sleep(1)

print("Starting Speed Test...")
time.sleep(2)

print("Pinging The Server...") 
ping = s.results.ping # Ping the server
time.sleep(1)

print("Downloading...")
download = s.download() # Download test
time.sleep(1)

print("Uploading...")
upload = s.upload() # Upload test
time.sleep(1)

def border_msg(msg): # For the border message
    row = len(msg)
    print(row)
    h = ''.join(['+'] + ['-' *row] + ['+'])
    result = h + '\n'"|"+msg+"|"'\n' + h
    print(result)

print("*************RESULTS*************")
border_msg(f"Ping: {ping:.2f} ms")
border_msg(f"Download Speed: {download /1024/1024:.2f} Mbit/s")
border_msg(f"Upload Speed: {upload /1024/1024:.2f} Mbit/s")
print("************THANKYOU************")