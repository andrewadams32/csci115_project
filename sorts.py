import os
import pandas as pd
import matplotlib.pyplot as plt
if os.environ.get('DISPLAY','') == '':
    print('no display found. Using non-interactive Agg backend')
    plt.use('Agg')
import numpy as np

#get relative path of csv data file
path = os.path.relpath('./out.csv')
data = pd.read_csv(path)

#helper function to convert all values in list to int
def to_int_list(l):
    return list(map(int, l))

#separate data by algorithm
IS = data[data['Algorithm'] == 'InsertionSort']
SS = data[data['Algorithm'] == 'SelectionSort']
BS = data[data['Algorithm'] == 'BubbleSort']
MS = data[data['Algorithm'] == 'MergeSort']
QS = data[data['Algorithm'] == 'QuickSort']
HS = data[data['Algorithm'] == 'HeapSort']

#get comparison count of each algorithm
c_IS = to_int_list(IS['Comparisons'].values)
c_SS = to_int_list(SS['Comparisons'].values)
c_BS = to_int_list(BS['Comparisons'].values)
c_MS = to_int_list(MS['Comparisons'].values)
c_QS = to_int_list(QS['Comparisons'].values)
c_HS = to_int_list(HS['Comparisons'].values)

#get time taken for each algorithm
t_IS = to_int_list(IS['Time(ms)'].values)
t_SS = to_int_list(SS['Time(ms)'].values)
t_BS = to_int_list(BS['Time(ms)'].values)
t_MS = to_int_list(MS['Time(ms)'].values)
t_QS = to_int_list(QS['Time(ms)'].values)
t_HS = to_int_list(HS['Time(ms)'].values)

#get list of input sizes used
Number = to_int_list(IS['Number'])

#initialize plots
ax1=plt.subplot(1,2,1)
ax2=plt.subplot(1,2,2)

#plot list of input sizes as x-axis and comparison count as y axis for each algorithm
ax1.plot(Number, c_IS, label="Insertion", linewidth=5)
ax1.plot(Number, c_SS, label="Selection", linewidth=5)
ax1.plot(Number, c_BS, label="Bubble", linewidth=5)
ax1.plot(Number, c_MS, label="Merge", linewidth=5)
ax1.plot(Number, c_QS, label="Quick", linewidth=5)
ax1.plot(Number, c_HS, label="Heap", linewidth=5)

#label graph
ax1.grid(True)
ax1.set_ylabel("Comparisons")
ax1.set_xlabel("Input Size")
ax1.legend(loc="upper left", fontsize="xx-large")

#plot list of input sizes as x-axis and time taken as y axis for each algorithm
ax2.plot(Number, t_IS, label="Insertion", linewidth=5)
ax2.plot(Number, t_SS, label="Selection", linewidth=5)
ax2.plot(Number, t_BS, label="Bubble", linewidth=5)
ax2.plot(Number, t_MS, label="Merge", linewidth=5)
ax2.plot(Number, t_QS, label="Quick", linewidth=5)
ax2.plot(Number, t_HS, label="Heap", linewidth=5)

#label graph
ax2.grid(True)
ax2.set_ylabel("Time(ms)")
ax2.set_xlabel("Input Size")
ax2.legend(loc="upper left", fontsize="xx-large")

#show graph
plt.show()