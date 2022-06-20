#!/usr/bin/env python

import time
import threading

shared_resource = 0

def task(loop):
    global shared_resource, mutex
    for i in range(loop):
        print("Thread {}: i:{}, shared_resource:{}".format(
            threading.current_thread().ident, i, shared_resource))
        for j in range(10000):
            mutex.acquire()
            tmp = shared_resource
            tmp = tmp + 1
            time.sleep(1/1000000.0)
            shared_resource = tmp
            mutex.release()
        time.sleep(10.0/loop)

mutex = threading.Lock()
thread1 = threading.Thread(target=task, args=([10]))
thread2 = threading.Thread(target=task, args=([20]))
thread1.start()
thread2.start()

thread1.join()
thread2.join()
print("shared_resource {}".format(shared_resource))
