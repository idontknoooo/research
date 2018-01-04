# Main code for fetching data

import name_by_letter as nbl 
from threading import Thread

def fetcher(num, begin, end):

    s = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    for i in range(begin, end):
        nbl.b(s[i])
        print("Fetcher: " + str(num) + ", letter: " + s[i] + ". Complete.")
    print("Fetcher: " + str(num) + " totally completed.")
    
# Multi-threading fetcher
def Main():
    # Max thread ~= 4
    # Complete Order 56217849 3
    t1 = Thread(target=fetcher, args=('1', 0,6)) # ABCDEF
    t2 = Thread(target=fetcher, args=('2', 6,11)) # GHIJKL
    t3 = Thread(target=fetcher, args=('3', 11,18)) # MNOPQR
    t4 = Thread(target=fetcher, args=('4', 18,23)) # STUVWXYZ 
    t5 = Thread(target=fetcher, args=('5', 23,26)) # MNO

    t1.start()
    t2.start()
    t3.start()
    t4.start()
    t5.start()
    
    print("Main complete")

if __name__ == '__main__':
    Main()
