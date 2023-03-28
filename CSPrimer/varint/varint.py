import struct

maxInt = './maxint.uint64'
oneInt = './150.uint64'
oneFiftyInt = './1.uint64'

num = -1
with open(maxInt,'rb') as f:
    num = struct.unpack('>Q',f.read())[0]

def encode(num):
    ans = []
    while num > 128:
        num 

def decode(num):
    return num