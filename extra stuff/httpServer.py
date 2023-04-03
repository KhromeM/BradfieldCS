from socket import *
import json
from datetime import datetime
import pytz

header = "HTTP/1.1 200 OK\nContent-Type: text/html\n"
data = ""
with open("./index.html","r") as f:
    data = f.read()


server = socket(AF_INET,SOCK_STREAM)
server.bind(('localhost',4001))
server.listen(100)
     

while True:
    (client,address) = server.accept()
    message = client.recv(1024).decode().split("\r\n\r\n")
    body = message[-1]
    time = datetime.utcnow().replace(tzinfo=pytz.utc)

    if body:
        body = json.loads(body)
        zone = body['Zone']
        time = time.astimezone(pytz.timezone(zone))

    timeString = str(time.time())[:8]
    print(timeString)
    
    response = data.replace('{TIME}',timeString)
    client.send(bytes(header + response,'utf-8'))
    client.close()
  





