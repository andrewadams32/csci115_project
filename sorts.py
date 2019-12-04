import os
import pandas as pd
import matplotlib.pyplot as plt
if os.environ.get('DISPLAY','') == '':
    plt.switch_backend('Agg')
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
minQS = data[data['Algorithm'] == 'Min_QuickSort']
medQS = data[data['Algorithm'] == 'Median_QuickSort']
randQS = data[data['Algorithm'] == 'Random_QuickSort']
HS = data[data['Algorithm'] == 'HeapSort']

#get comparison count of each algorithm
c_IS = to_int_list(IS['Comparisons'].values)
c_SS = to_int_list(SS['Comparisons'].values)
c_BS = to_int_list(BS['Comparisons'].values)
c_MS = to_int_list(MS['Comparisons'].values)
c_minQS = to_int_list(minQS['Comparisons'].values)
c_medQS = to_int_list(medQS['Comparisons'].values)
c_randQS = to_int_list(randQS['Comparisons'].values)
c_HS = to_int_list(HS['Comparisons'].values)

#get array access count of each algorithm
a_IS = to_int_list(IS['Accesses'].values)
a_SS = to_int_list(SS['Accesses'].values)
a_BS = to_int_list(BS['Accesses'].values)
a_MS = to_int_list(MS['Accesses'].values)
a_minQS = to_int_list(minQS['Accesses'].values)
a_medQS = to_int_list(medQS['Accesses'].values)
a_randQS = to_int_list(randQS['Accesses'].values)
a_HS = to_int_list(HS['Accesses'].values)

#get time taken for each algorithm
t_IS = to_int_list(IS['Time(ms)'].values)
t_SS = to_int_list(SS['Time(ms)'].values)
t_BS = to_int_list(BS['Time(ms)'].values)
t_MS = to_int_list(MS['Time(ms)'].values)
t_minQS = to_int_list(minQS['Time(ms)'].values)
t_medQS = to_int_list(medQS['Time(ms)'].values)
t_randQS = to_int_list(randQS['Time(ms)'].values)
t_HS = to_int_list(HS['Time(ms)'].values)

#get list of input sizes used
Number = to_int_list(IS['Number'])

#initialize plots
ax1=plt.subplot(1,3,1)
ax2=plt.subplot(1,3,3)
ax3=plt.subplot(1,3,2)

#plot list of input sizes as x-axis and comparison count as y axis for each algorithm
ax1.plot(Number, c_IS, label="Insertion", linewidth=3)
ax1.plot(Number, c_SS, label="Selection", linewidth=3)
ax1.plot(Number, c_BS, label="Bubble", linewidth=3)
ax1.plot(Number, c_MS, label="Merge", linewidth=3)
ax1.plot(Number, c_minQS, label="Min_Quick", linewidth=3)
ax1.plot(Number, c_medQS, label="Median_Quick", linewidth=3)
ax1.plot(Number, c_randQS, label="Random_Quick", linewidth=3)
ax1.plot(Number, c_HS, label="Heap", linewidth=3)

#label graph
ax1.grid(True)
ax1.set_ylabel("Comparisons")
ax1.set_xlabel("Input Size")
ax1.legend(loc="upper left", fontsize="xx-large")

#plot list of input sizes as x-axis and time taken as y axis for each algorithm
ax2.plot(Number, t_IS, label="Insertion", linewidth=3)
ax2.plot(Number, t_SS, label="Selection", linewidth=3)
ax2.plot(Number, t_BS, label="Bubble", linewidth=3)
ax2.plot(Number, t_MS, label="Merge", linewidth=3)
ax2.plot(Number, t_minQS, label="Min_Quick", linewidth=3)
ax2.plot(Number, t_medQS, label="Median_Quick", linewidth=3)
ax2.plot(Number, t_randQS, label="Random_Quick", linewidth=3)
ax2.plot(Number, t_HS, label="Heap", linewidth=3)

#label graph
ax2.grid(True)
ax2.set_ylabel("Time(ms)")
ax2.set_xlabel("Input Size")
ax2.legend(loc="upper left", fontsize="xx-large")

#plot list of input sizes as x-axis and time taken as y axis for each algorithm
ax3.plot(Number, a_IS, label="Insertion", linewidth=3)
ax3.plot(Number, a_SS, label="Selection", linewidth=3)
ax3.plot(Number, a_BS, label="Bubble", linewidth=3)
ax3.plot(Number, a_MS, label="Merge", linewidth=3)
ax3.plot(Number, a_minQS, label="Min_Quick", linewidth=3)
ax3.plot(Number, a_medQS, label="Median_Quick", linewidth=3)
ax3.plot(Number, a_randQS, label="Random_Quick", linewidth=3)
ax3.plot(Number, a_HS, label="Heap", linewidth=3)

#label graph
ax3.grid(True)
ax3.set_ylabel("Array Access")
ax3.set_xlabel("Input Size")
ax3.legend(loc="upper left", fontsize="xx-large")

#show graph
plt.show()