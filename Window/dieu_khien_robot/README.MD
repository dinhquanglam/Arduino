# Gesture-Controlled 4WD Robot Car (MPU6050 + nRF24L01 + Arduino)

A wireless robot car that is controlled by **hand tilt gestures**.  
The transmitter reads motion data from an **MPU6050 IMU** and sends 2-axis control values over a **2.4GHz nRF24L01** radio link.  
The receiver on the car decodes the data and drives the motors through a motor driver to move **forward / backward / left / right** and **stop** when the controller is level.

---

## Demo / Idea
Tilt the controller:
- Tilt forward → car moves forward  
- Tilt backward → car moves backward  
- Tilt left → car turns left  
- Tilt right → car turns right  
- Hold level → car stops  

---

## Hardware Used
- 2 × Arduino boards (UNO/Nano recommended)
- 2 × nRF24L01 modules (TX + RX)
- 1 × MPU6050 (accelerometer + gyroscope)
- 4WD robot chassis with DC motors + battery pack
- Motor driver module(s) (H-bridge)
- Jumper wires / power supply (stable 3.3V for nRF24L01 recommended)

---

## How It Works

### 1) Transmitter (Hand Controller) — `file1.ino`
- Reads accelerometer/gyro values from **MPU6050** via I2C (`Wire`).
- Uses `ax` and `ay` to create 2 control values:
  - `data[0]` from **ax** → forward/backward
  - `data[1]` from **ay** → left/right
- Maps raw sensor values into ranges suitable for threshold decisions:
  - `data[0] = map(ax, -17000, 17000, 300, 400)`
  - `data[1] = map(ay, -17000, 17000, 100, 200)`
- Sends `data[2]` continuously using nRF24L01:
  - Pipe address: `0xE8E8F0F0E1LL`

### 2) Receiver (Robot Car) — `file2.ino`
- Listens for packets from the transmitter on the same pipe address.
- Decides motion based on thresholds:
  - `data[0] > 380` → Forward
  - `data[0] < 310` → Backward
  - `data[1] > 180` → Turn Left
  - `data[1] < 110` → Turn Right
  - Center range → Stop
- Drives motors using PWM enable pins and direction pins (`IN1…IN8`).

---

## Wiring Notes
- nRF24L01 uses SPI (check your Arduino SPI pins: MOSI/MISO/SCK).
- In the code, nRF24L01 pins are:
  - `CE = 9`, `CSN = 10`
- MPU6050 uses I2C:
  - `SDA`, `SCL` pins depend on the board (UNO: A4/A5)

---

## Libraries Required
Install these in Arduino IDE Library Manager:
- `RF24`
- `I2Cdev`
- `MPU6050`

---

## How to Run
1. Upload **Transmitter code** to the Arduino connected to MPU6050 + nRF24L01.
2. Upload **Receiver code** to the Arduino on the robot car (motor driver + nRF24L01).
3. Power the car motors separately (recommended).
4. Tilt the controller to drive the car.

---

## Future Improvements
- Add failsafe: stop motors if no signal is received for a timeout.
- Add smoothing/filtering to reduce jitter.
- Add proportional speed control based on tilt angle.
- Add calibration for stable “neutral” position.

---

## Author
Lam DINH
