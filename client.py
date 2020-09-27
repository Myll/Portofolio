from socket import socket
from threading import Thread

def receive_function(connection):
    while True: #step 3
        message = connection.recv(2048) #step 1
        print(message.decode()) #step 2
    return

clientSock = socket()

clientSock.connect(("localhost", 12346))

print("client connected")

#receive process
receive_thread = Thread(target=receive_function, args=(clientSock,))
receive_thread.start()

#send process
while True: #step 3
    message = input() #step 1
    clientSock.send(message.encode()) #step 2