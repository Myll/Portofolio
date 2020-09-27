from socket import socket
from threading import Thread

def receive_function(connection):
    while True: #step 3
        message = connection.recv(2048) #step 1
        print(message.decode()) #step 2
    return

serverSock = socket()

serverSock.bind(("localhost", 12345))
serverSock.listen(5)

conn, _ = serverSock.accept()

print("Client Connected")

#receive process
receive_thread = Thread(target=receive_function, args=(conn,))
receive_thread.start()

#send process
while True: #step 3
    message = input() #step 1
    conn.send(message.encode()) #step 2