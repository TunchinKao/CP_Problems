#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# N.py
# @Author :  ()
# @Link   : 
# @Date   : 2022/1/28 下午6:16:02
import math
N, M = input().split()
N = int(N)
M = int(M)
round = 1
while(N != 0 and M != 0):
	sum = 0
	data = 0
	for i in range(N):
		data = int(input())
		sum += data
	print("Bill #" + str(round) + " costs " + str(sum) + ": each friend should pay " + str(int((sum // M))))
	print()
	round+=1
	N, M = input().split()
	N = int(N)
	M = int(M)
