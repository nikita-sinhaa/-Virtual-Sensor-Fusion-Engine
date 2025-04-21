# 🛰️ Virtual Sensor Fusion Engine – Advanced Firmware Simulation (RTOS + Adaptive Filtering)

## 🎯 Objective
This is a  firmware simulation project that computes device orientation (pitch, roll, yaw) using **adaptive complementary filtering**, **real-time scheduling**, and **task deadline tracking** – all built in Embedded C and Python.


---
## 🚀 Key Features

- ✅ **Simulated Sensor Fusion** from CSV-based accelerometer, gyroscope, and magnetometer data
- ✅ **Adaptive Complementary Filter** with noise handling and dynamic alpha
- ✅ **Task Deadline Monitoring** with jitter and deadline miss logging
- ✅ **RTOS-style Scheduling** using Windows timing APIs
- ✅ **Orientation Logging + Visualization**
- ✅ **No Microcontroller, Sensor, or Docker Required**

---

## 📁 Folder Structure
```
VirtualSensorFusion/
├── c/                   # C source code (RTOS + Fusion)
├── data/                # Simulated sensor input (100Hz)
├── output/              # Logs: orientation + task metrics
├── python/              # Python script for plotting
```

---

## 🧠 Architecture Diagram

flowchart TD
    A[CSV Sensor Data] --> B[Sensor Reading (C)]
    B --> C[Adaptive Complementary Filter]
    C --> D[Orientation CSV Output]
    C --> E[Execution Metrics Log]
    D --> F[Python Plot Viewer]
```

---

## ⚙️ Build & Run (Windows)
### Step 1 – Compile & Run
```bash
gcc c/main.c c/fusion.c c/scheduler.c c/task_monitor.c -o output/fusion_sim.exe
output/fusion_sim.exe
```

### Step 2 – Visualize Output
```bash
cd python
python plot_orientation.py
```

---

## 📈 Outputs

### `orientation_log.csv`
```
Time,Pitch,Roll,Yaw
0,0.00,0.00,0.00
1,0.03,0.01,0.01
...
```

### `metrics_log.csv`
```
Time(ms),Task,Exec_Time(ms),Deadline(ms),Status
0,Fusion,3.12,10.00,Met
1,Fusion,3.14,10.00,Met
...
```

---

## 👩‍💻 Author
**Nikita Sinha**  
🔧 Firmware & Embedded Systems | M.S. Electrical and Computer Engineering  
