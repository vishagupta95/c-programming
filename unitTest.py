#!/usr/bin/python
#python unitTest.py 172.22.149.203 admin insieme  900 1
from pexpect import *
import pexpect
import sys
import time
import os
import tempfile
import string
#import parsedroppkts
def read_file(path):
    cmd_file = path + '/cmd' + '.txt'
    f = open(cmd_file,'r')
    print ('Reading cmds from input file cmd.txt ')
    lines = f.readlines()
    f.close()
    print ('done.')
    return lines

def login(ssh, host, user, passwd):
    ssh_newkey = 'Are you sure you want to continue connecting (yes/no)?'
    ret = ssh.expect([pexpect.TIMEOUT, pexpect.EOF,ssh_newkey, '[P|p]assword:'])
    if ret == 0:
        print ('[-] Error Connecting to ' + host)
        return 0
    if ret == 1:
        print ('[-] Remote host ident changed, error Connecting to ' + host)
        print ('[-] Offending key in /users/arongong/.ssh/known_hosts')
        return 0
    if ret == 2:
        ssh.sendline('yes')
        ret = ssh.expect([pexpect.TIMEOUT, '[P|p]assword:'])
        if ret == 0:
            print ('[-] Could not accept new key from ' + host)
            return 0
    ssh.sendline(passwd)
    auth = ssh.expect(['[P|p]assword:', '>', '#'])
    if auth == 0:
        print ('User password is incorrect')
        return 0
    if auth == 1:
        print('username and password are correct')
        ssh.sendline('enable')
        ssh.sendline('y')
        enable = ssh.expect(['[P|p]assword:', '#'])
        if enable == 0:
            print ('enable password is incorrect')
            return 0
        if enable == 1:
            print ('en password is correct, ssh connected')
            return 1
    if auth == 2:
        print ('ssh connected')
        return 1
    else:
        print ('creds are incorrect')
        return 0

def prompt(ssh, timeout = 100):
    index = ssh.expect(['#', pexpect.EOF, pexpect.TIMEOUT], timeout=timeout)
    if index == 1:
        print (' ... terminated unexpectedly.')
    if index == 2:
        print (' ... timedout unexpectedly')

def prompt2(ssh, timeout = 100):
    index = ssh.expect(['This command will reboot the system. (y/n)?  [n]', pexpect.EOF, pexpect.TIMEOUT], timeout=timeout)
    if index == 1:
        print (' ... terminated unexpectedly.')
    if index == 2:
        print (' ... timedout unexpectedly')

def logout(ssh):
    ssh.sendline("exit")
    index = ssh.expect([pexpect.EOF, pexpect.TIMEOUT, '#?'], timeout = 2)
    if index==2:
        ssh.sendline("exit")
        ssh.expect([pexpect.EOF, pexpect.TIMEOUT], timeout = 1)
    ssh.close()

def strip_cr(file_name):
    with tempfile.NamedTemporaryFile(delete=False) as temp_f:
        with open(file_name) as file:
            for line in file:
                line = string.replace(line, '\r', '')
                temp_f.write(line)

            temp_f.close()
            os.system('mv ' + ' ' +  temp_f.name + ' ' + file_name)  

def inst_cmds(ssh, line):
    line = line.replace('[inst]' , '', 1)
    for idx in range(12):
        rep_str = ' ' + str(idx) + ' '
        new_line = line.replace(' x ', rep_str)
        ssh.sendline (new_line)
        time.sleep(0.3)
        print (new_line.rstrip())
        prompt(ssh)

def port_cmds(ssh, line):
    line = line.replace('[port]' , '', 1)
    for idx in range(1,97):
        rep_str = ' ' + str(idx) + ' '
        new_line = line.replace(' x ', rep_str)
        ssh.sendline (new_line)
        time.sleep(0.3)
        print (new_line.rstrip())
        prompt(ssh)

def reload_test():
    counter = 0
    if len(sys.argv) < 5 :
        print ("usage ", sys.argv[0], "<ip_address> <u_name> <pass_wd> <path> <timeout(secs)> [1=debug(opt)]")
    else : 
        hname = sys.argv[1]
        user = sys.argv[2]
        passwd = sys.argv[3]
        path = sys.argv[4]
        timeout = sys.argv[5]
        if len(sys.argv) > 6 :
            debug = sys.argv[6]
        else:
            debug = '0'
        if debug == '1':
            print (path)
        result_file = 'results_' + '.txt'
        constr = 'ssh ' + user + '@' + hname
        while 1:
            failed = False
            cards_up = False
            cards_coming_up = False
            ssh = pexpect.spawn(constr)
            out_file = open(result_file,'wb')
            ssh.logfile_read = out_file
            lines = read_file(path)
            os.system("echo > ~/.ssh/known_hosts")
            if login (ssh, hname, user, passwd) == 1:
                print ('Executing cmds ...')
                for line in lines:
                    if debug == '1':
                        print (line)
                    ssh.sendline (line)
                    print (line.rstrip())
                    prompt(ssh,10)
            else:
                break
            logout(ssh)
            out_file.close()
            result_file.strip()
            out_file = open(result_file,'r')
            lines = out_file.readlines()
            for line in lines:
                if debug == '1':
                    print (line)
                words = line.split()
                for word in words:
                    if (word == 'atleast'):
                        if debug == '1':
                            print (word)
                        failed = True
#                    if (word == 'ok' or word == 'active'):
#                        cards_up = True
#                    if (word == 'initializing' or word == 'testing' or word == 'present'):
#                        cards_coming_up = True
            out_file.close()
            if failed == True:
                print ("Cards in failure state.")
                break
#            if cards_up == True:
#                print ("No cards in failure state. Some cards are up")
#            else:
#                print ("No cards are up")
#                break
#            if cards_coming_up == True:
#                print ("Some cards are still coming up. Timeout can be increased.")
            counter = counter + 1
            print ("Reloading count %d" % counter)
            line = 'reload'
            line2 = 'y'
            ssh = pexpect.spawn(constr)
            if login (ssh, hname, user, passwd) == 1:
                print ('Executing cmds ...')
                #print line
                ssh.sendline (line)
                print (line.rstrip())
                prompt2(ssh,10)
                #print line2
                ssh.sendline (line2)
                print (line2.rstrip())
                prompt(ssh,10)
                
            logout(ssh)
            time.sleep(int(timeout))

if __name__ == '__main__':
     reload_test()

