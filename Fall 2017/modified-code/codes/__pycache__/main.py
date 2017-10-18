# Main code for fetching data

import name_by_letter as nbl 
from threading import Thread
def fetcher(num, begin, end):
    s = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    for i in range(begin, end):
        nbl.b(s[i])
        print("Fetcher: " + str(num) + ", letter: " + s[i] + ". Complete.")
    print("Fetcher: " + str(num) + " totally completed.")
    
def Main():
    # Max thread ~= 4
    # Complete Order 56217849 3
    t1 = Thread(target=fetcher, args=('1', 0,3)) # ABC
    t2 = Thread(target=fetcher, args=('2', 3,6)) # DEF
    t3 = Thread(target=fetcher, args=('3', 6,9)) # GHI
    #t31 = Thread(target=fetcher, args=('31', 6,12)) # GHI
    #t32 = Thread(target=fetcher, args=('32', 12,18)) # GHI
    #t33 = Thread(target=fetcher, args=('33', 18,24)) # GHI
    #t34 = Thread(target=fetcher, args=('34', 24,26)) # GHI
    t4 = Thread(target=fetcher, args=('4', 9,12)) # JKL
    t5 = Thread(target=fetcher, args=('5', 12,15)) # MNO
    t6 = Thread(target=fetcher, args=('6', 15,18)) # PQR
    t7 = Thread(target=fetcher, args=('7', 18,21)) # STU
    t8 = Thread(target=fetcher, args=('8', 21,24)) # VWX
    t9 = Thread(target=fetcher, args=('9', 24,26)) # YZ
    #t10 = Thread(target=timer, args=(0,2))
    t1.start()
    t2.start()
    t3.start()
    #t31.start()
    #t32.start()
    #t33.start()
    #t34.start()
    t4.start()
    t5.start()
    t6.start()
    t7.start()
    t8.start()
    t9.start()
   # t10.start()

    
    print("Main complete")

if __name__ == '__main__':
    Main()
