Simulate ECG (Electrocardiogram) waveforms using Python and LTspice.

## Overview

This section demonstrates the simulation of ECG waveforms using Python's Matplotlib and LTspice. This simulation allows visualization and manipulation of the  ECG signals.

## Simulation Process

Follow these steps to set up and run the simulation:

1. **Generate ECG Waveform in Python**:
   - A ECG data set was obtained [Data set as a CSV](ecg_signal_dataset.csv)
   - Use Matplotlib to generate ECG waveforms.
   - Export the waveform data as a text file (e.g., CSV) containing X and Y values.

   ```python
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

## LTspice Simulation

## Results

### Figure 01 - Circuit Diagram
[Circuit Diagram](LTspice_Simulations/Simulation-results/Schematic.pdf)

### Figure 02 - Before the Noise Cancellation
[Noise Cancellation](LTspice_Simulations/Simulation-results/Before-filter.png)

### Figure 02 - After the Noise Cancellation
[After the Noise Cancellation](LTspice_Simulations/Simulation-results/After-filtered.png.png)

In Figure 2, the 50Hz noise is effectively canceled out, as expected. The graph shows the waveforms before and after filtering.


Figures 3 and 4 provide a zoomed-in view of a heartbeat waveform. Figure 3 shows the unfiltered beat, while Figure 4 displays the same beat after 50Hz filtering in the simulation.

### Figure 03 - Unfiltered Heartbeat
[Unfiltered Heartbeat](LTspice_Simulations/Simulation-results/Not-Smoothed.png)

### Figure 04 - Filtered Heartbeat
[Filtered Heartbeat](LTspice_Simulations/Simulation-results/Smoothed.png)





