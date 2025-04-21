
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('../output/orientation_log.csv')
plt.plot(data['Time'], data['Pitch'], label='Pitch')
plt.plot(data['Time'], data['Roll'], label='Roll')
plt.plot(data['Time'], data['Yaw'], label='Yaw')
plt.title('Orientation Estimation Over Time')
plt.xlabel('Time (ms)')
plt.ylabel('Degrees')
plt.legend()
plt.grid()
plt.show()
