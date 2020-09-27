from socket import socket
from threading import Thread


#Function untuk menerima pesan masuk
def receive_msg(connection):
    while True: #dibuat sebagai true agar terus berjalan saat ada message baru
        msg = connection.recv(2048) #ditentukan berapa besar client bisa menginput
        print(msg.decode()) #keluarkan isi chatnya dengan terlebih dahulu di decode agar bisa dibaca

    return


#Inisiasi Server
def Main():
    #server akan membuat pemberitahuan bahwa sudah on
    print("Server is online and running")

    #setelah sudah menyala, dibuat diatur koneksinya
    koneksi = socket()
    koneksi.bind(("localhost", 4445))
    koneksi.listen(1) #angka 1 menandakan bahwa server hanya akan menampung 1 koneksi
    print("Aktif via port: 4445") #untuk menandakan dia aktif di port berapa

    #setelah settingan server dibuat maka selanjutnya client akan connect
    conn,_ = koneksi.accept()
    #beri notifikasi client sudah connect
    print("Player is in")

    #Threading receive message
    receiveThread = Thread(target=receive_msg, args=(conn,)) #kita melempar koneksinya kedalam fungsi penerimaan message
    receiveThread.start()

    #Untuk send message
    msg = input() #kita mendefine bahwa message adalah apapun yang kita ketik nantinya
    conn.send(msg.encode()) #setelah kitaa ketik maka akan kita di terjemahkan atau di encode kemudian akan dikirim ke tujuan

    return


#main function untuk menjalankan semua seperti di bahasa C
if __name__ == "__main__":
    Main()
    pass


#Codingan dikerjakan bersama Wahyu dan Stanly dibantu oleh Winner
#Codingan diedit sedikit untuk mempermudah pemahaman sendiri