from socket import socket
from threading import Thread


#Function untuk menerima pesan masuk
def receive_msg(connection):
    while True: #dibuat sebagai true agar terus berjalan saat ada message baru
        msg = connection.recv(2048) #ditentukan berapa besar client bisa menginput
        print(msg.decode()) #keluarkan isi chatnya dengan terlebih dahulu di decode agar bisa dibaca

    return


#Inisiasi Client
def Main():
    #Client memberi info bahwa dia sudah menyala
    print("Player is online")

    #settingan koneksi setelah menyala
    Playersock = socket()
    Playersock.connect(("localhost", 4445)) #client kita arahkan connect ke port yang dibukakan oleh server yaitu 4445

    #setelah client terkoneksi dengan server
    print("Connection Established") #memberitahukan bahwa sudah terkoneksi dengan server

    #Process threading untuk menerima pesan
    receiveThread = Thread(target = receive.msg, args=(Playersock,)) #kita lemparkan koneksi yang berisi pesan ke dalam function penerima pesan
    receiveThread.start()
    
    #Process untuk mengirim pesan
    msg = input() #untuk kita dapat mengetik pesan kita
    Playersock.send(msg.encode()) #pesan di convert/encode dan dikirim

    return


#main function untuk menjalankan semua seperti di bahasa C
if __name__ == "__main__":
    Main()
    pass


#Codingan dikerjakan bersama Wahyu dan Stanly dibantu oleh Winner
#Codingan diedit sedikit untuk mempermudah pemahaman sendiri