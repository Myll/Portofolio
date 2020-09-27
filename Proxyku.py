from socket import socket
from threading import Thread


#Prepare Statement
scanner_prep = ["motherfucker", "fuck", "damn","bastard"]

#prosedur check jika ada kata-kata yang sesuai dengan kata-kata sensor
def check_message(msg):
    global scanner_prep #dibuat jadi variable global supaya bisa dipakai untuk client dan server
    global y

    for x in range(len(scanner_prep)): #checking sesuai panjang kata-kata yang diblok
        if scanner_prep[i] in msg:
            y = False #Jika kata-kata dilarang ditemukan maka y berubah menjadi false untuk indikasi bahwa kalimat akan difilter

    return msg


#process pengecekan kata yang masuk
def player_process(playerconn, masterconn):
    while y = True: #step 4
        msg = playerconn.recv(2048).decode() #step 1
        msg = check_message(msg) #step 2
        masterconn.send(msg.encode()) #step 3
    
    return


#socket connect to server #untuk koneksi dari proxy ke server
mastersock = socket()
mastersock.connect(("localhost", 4445))
print("Connection to Host established")


#socket listen from client
playersock = socket()
playersock.bind(("localhost", 4446))
playersock.listen(5)
conn, _ = playersock.accept()
print("Player is ready")


#create Threading
player_process_thread = Thread(target=player_process, args=(conn, mastersock,))
player_process_thread.start()


#create server process
while y = True: #step 4
    msg = masterSock.recv(2048).decode() #step 1
    msg = check_message(msg) # step 2
    conn.send(msg.encode()) #step 3