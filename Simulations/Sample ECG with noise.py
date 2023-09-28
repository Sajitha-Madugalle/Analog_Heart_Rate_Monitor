import numpy as np
import matplotlib.pyplot as plt

# Reading the ECG data
ecg = []
for data in np.loadtxt('ecg_signal_dataset.csv'):
    ecg.append(data)

duration = 10  # seconds
T = duration / len(ecg)
Fs = 1 / T

# Obtaining the fourier transform
time = np.arange(T, duration + T, T)

# Increase the width of the plot
plt.figure(figsize=(40, 6))  # You can adjust the width and height as needed

plt.plot(time, ecg)
plt.xlabel('Time (s)')
plt.ylabel('ECG Signal')
plt.title('ECG Signal')

plt.show()
