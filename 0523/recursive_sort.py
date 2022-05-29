# -*- coding: utf-8 -*-
import random

def selection_sort(num):
    for i in range(len(num)):
        min = num[i] # 仮の最小値
        min_pos = i  # 仮の最小値の場所
        for n in range(i+1, len(num)):
            if num[n] < min : # 比較対象の数字が仮の最小値より小さければ、仮の最小値を更新
                min = num[n]
                min_pos = n
        tmp = num[i] # 最小値と最初の数を入れ替え
        num[i] = min
        num[min_pos] = tmp
    return num

##

def selection_sort2_impl(num, start_i):
    if start_i == len(num):
        return num
    
    min = num[start_i] # 仮の最小値
    min_pos = start_i  # 仮の最小値の場所
    for n in range(start_i + 1, len(num)):
        if num[n] < min : # 比較対象の数字が仮の最小値より小さければ、仮の最小値を更新
            min = num[n]
            min_pos = n
            
    tmp = num[start_i] # 最小値と最初の数を入れ替え
    num[start_i] = min
    num[min_pos] = tmp

    return selection_sort2_impl(num, start_i + 1)

def selection_sort2(num):
    return selection_sort2_impl(num, 0)

def selection_sort3_impl(num):
    if num == []:
        return num
    
    min = num[0] # 仮の最小値
    min_pos = 0  # 仮の最小値の場所
    for n in range(1, len(num)):
        if num[n] < min : # 比較対象の数字が仮の最小値より小さければ、仮の最小値を更新
            min = num[n]
            min_pos = n
            
    num[min_pos] = num[0] # 最小値と最初の数を入れ替え

    return [min] + selection_sort3_impl(num[1:])

def selection_sort3(num):
    return selection_sort3_impl(num)

##
##
##

def bubble_sort(num):
    for i in range(len(num)):
        for n in range(len(num)-1,i,-1):
            if num[n] < num[n-1] : # 比較対象の数字が一つ前の数字より小さければ入れ換える
                tmp = num[n]
                num[n] = num[n-1]
                num[n-1] = tmp
    return num

##

def bubble_sort2_impl(num, i):
    if i == len(num):
        return num

    for n in range(len(num)-1,i,-1):
        if num[n] < num[n-1] : # 比較対象の数字が一つ前の数字より小さければ入れ換える
            tmp = num[n]
            num[n] = num[n-1]
            num[n-1] = tmp

    return bubble_sort2_impl(num, i + 1)


def bubble_sort2(num):
    return bubble_sort2_impl(num, 0)

##

def bubble_sort3_impl(num):
    if num == []:
        return num

    for n in range(len(num)-1,0,-1):
        if num[n] < num[n-1] : # 比較対象の数字が一つ前の数字より小さければ入れ換える
            tmp = num[n]
            num[n] = num[n-1]
            num[n-1] = tmp

    return [num[0]] + bubble_sort3_impl(num[1:])


def bubble_sort3(num):
    return bubble_sort3_impl(num)

##
##
##

import time
def run_sort(f):
    num = [random.randint(1,100) for i in range(10)]
    start = time.clock()
    # call function
    print(f(num))
    print(num)
    elapsed_time = time.clock() - start
    print("%20s : elapsed time %f [sec]"%(f.__name__, elapsed_time))


if __name__ == '__main__':
    run_sort(selection_sort)
    run_sort(selection_sort2)
    run_sort(selection_sort3)
    run_sort(bubble_sort)
    run_sort(bubble_sort2)
    run_sort(bubble_sort3)

