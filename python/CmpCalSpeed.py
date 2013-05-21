# -*- coding: cp936 -*-
# �Ƚ�numpy.math ��Python��׼���math.sin�ļ����ٶ�

import time
import math
import numpy as np

x = [i * 0.001 for i in xrange(1000000)]
start = time.clock()
for i, t in enumerate(x):
    x[i] = math.sin(t) # math.sin ���㵥�����ȽϿ�
print "math.sin: ", time.clock() - start

x = [i * 0.001 for i in xrange(1000000)]
x = np.array(x)
start = time.clock()
np.sin(x, x) # numpy.sin �����������ȽϿ�
print "numpy.sin: ", time.clock() - start
