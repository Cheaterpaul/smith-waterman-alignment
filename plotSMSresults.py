#!/usr/bin/env python3
#
# ============================================================================
#
# Philipp Schubert
#
#    Copyright (C) 2017 - 2020
#    Software Engineering Group
#    Heinz Nixdorf Institute
#    Paderborn University
#    philipp.schubert@upb.de
#
# ============================================================================
#

import sys
import csv
import numpy as np
import matplotlib.pyplot as plt

if len(sys.argv) != 2:
	print("usage: prog <input csv>")
	exit(1)

input = sys.argv[1]

with open(input) as f:
    reader = csv.reader(f)
    header = next(reader)
    x = []
    y = []
    for row in reader:
        x.append(int(row[0]))
        y.append(int(row[1]))

plt.scatter(x, y, color='r', s=50, marker='x')
plt.xlim(min(x) - 5, max(x) + 5)
plt.ylim(min(y) - 5, max(y) + 5)
plt.xticks(np.linspace(min(x), max(x), 6, dtype=int))
plt.yticks(np.linspace(min(y), max(y), 6, dtype=int))
plt.xlabel(header[0], fontsize=18)
plt.ylabel(header[1], fontsize=18)
plt.show()

exit(0)
