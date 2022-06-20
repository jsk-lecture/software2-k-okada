#!/usr/bin/env python

import time
import threading

# test-thread.py

shared_resource = 0

def task(loop):
    global shared_resource
    for i in range(loop):
        print("Thread {}: i:{}, shared_resource:{}".format(
            threading.current_thread().ident, i, shared_resource))
        shared_resource = shared_resource + 1
        time.sleep(10.0/loop)

thread1 = threading.Thread(target=task, args=([10]))
thread2 = threading.Thread(target=task, args=([20]))
thread1.start()
thread2.start()

thread1.join()
thread2.join()
print("shared_resource {}".format(shared_resource))
