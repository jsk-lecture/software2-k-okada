#!/usr/bin/env python
# -*- coding: utf-8 -*-

import math

a = 1.0
b = -100000.0
c = 1.0

x1 = (- b - math.sqrt(b*b - 4*a*c))/2*a
x2 = (- b + math.sqrt(b*b - 4*a*c))/2*a

print("a  = {:27.20e}".format(a))
print("b  = {:27.20e}".format(b))
print("c  = {:27.20e}".format(c))
print("x1 = {:27.20e}".format(x1))
print("x2 = {:27.20e}".format(x2))
print("e1   {:27.20e}".format(a * x1 * x1 + b * x1 + c))
print("e2   {:27.20e}".format(a * x2 * x2 + b * x2 + c))

def sign(a):
    if a > 0:
        return 1
    else:
        return -1

x1_ = (- b - sign(b)*math.sqrt(b*b - 4*a*c))/2*a
x2_ = c / (a * x1_)
print("x1'= {:27.20e}".format(x1_))
print("x2'= {:27.20e}".format(x2_))

print("e1'  {:27.20e}".format(a * x1_ * x1_ + b * x1_ + c))
print("e2'  {:27.20e}".format(a * x2_ * x2_ + b * x2_ + c))
