
# 🛰️ Virtual Sensor Fusion Engine (Firmware Simulation Project)

## 🎯 Objective
Simulate real-time sensor fusion to estimate **pitch**, **roll**, and **yaw** using:
- Simulated accelerometer, gyroscope, and magnetometer data (CSV)
- Complementary filter algorithm in Embedded C
- RTOS-style task logic and modular structure
- Python visualization for result analysis

---

## 📁 Folder Structure
```
VirtualSensorFusion/
├── c/                   # All Embedded C source code
├── data/                # Simulated sensor inputs
├── output/              # Logs generated from fusion output
├── python/              # Orientation plot script
```

---

## 🧠 System Architecture

flowchart TD
    A[CSV Sensor Data] --> B[Sensor Reading Tasks]
    B --> C[Fusion Estimator (C)]
    C --> D[Orientation Log CSV]
    D --> E[Python Plotter]
```

---

## ⚙️ How to Run

### 1. Compile C Code (MinGW/MSVC)
```bash
gcc c/main.c c/fusion.c -o output/fusion_sim.exe
output/fusion_sim.exe
```

### 2. Plot Orientation in Python
```bash
cd python
python plot_orientation.py
```

---

## 📈 Output
Generates `orientation_log.csv`:
```
Time,Pitch,Roll,Yaw
0,0.00,0.00,0.00
1,0.02,0.01,0.01
...
```

---

## 👩‍💻 Author
**Nikita Sinha**  
📍 Master’s in ECE – Real-Time Systems & Firmware  
🔗 [LinkedIn Profile](https://www.linkedin.com/in/nikita-sinhaa/)
