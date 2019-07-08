### Jetson Nano Hardware
GPIO - https://www.jetsonhacks.com/2019/06/07/jetson-nano-gpio/
     - https://github.com/NVIDIA/jetson-gpio
Pinout Diag - https://www.jetsonhacks.com/nvidia-jetson-nano-j41-header-pinout/

Jetson Nano nvidia - https://developer.nvidia.com/embedded/jetson-nano-developer-kit
Getting Started by nvidia - https://developer.nvidia.com/embedded/learn/get-started-jetson-nano-devkit
Isaac SDK - https://developer.nvidia.com/isaac-sdk
Jetson-Projects by nvidia - https://developer.nvidia.com/embedded/community/jetson-projects
Two days to a Demo - https://developer.nvidia.com/embedded/twodaystoademo
Jetson-Tutorials by nvidia - https://developer.nvidia.com/embedded/learn/tutorials
L4T Development Guide - https://docs.nvidia.com/jetson/l4t/index.html

Getting Started by PyImageSearch - https://www.pyimagesearch.com/2019/05/06/getting-started-with-the-nvidia-jetson-nano/

### 3D models
- BoMotor
https://grabcad.com/library/yellow-dc-motor-1
https://grabcad.com/library/motor-gear-box-4
https://grabcad.com/library/bomotor-1/details?folder_id=420554

- Wheel
https://grabcad.com/library/wheel-d65x25-1
https://grabcad.com/library/yellow-smart-robot-wheel-motor-1
https://grabcad.com/library/dc-motor-with-wheel-1
https://grabcad.com/library/diy-rc-car-wheel/details?folder_id=276040

- Encoder and encoder wheel
https://grabcad.com/library/ir-motor-speed-encoder-arduino-wyc-h2010-1
https://grabcad.com/library/encoder-wheel-3

- studs
https://grabcad.com/library/standoff-richco-1

- Castor Wheel
https://grabcad.com/library/kjn-o125mm-swivel-castor-caster-1
https://grabcad.com/library/heavy-duty-rubber-castors-o125mm-1
https://grabcad.com/library/rodizio-gl-312-bp-giratorio-wheel-and-castor-1
https://grabcad.com/library/caster-wheel-bppe-160-mm-total-lock-brake-1

- Castor Ball
https://grabcad.com/library/castor-wheel-10

- Jetson Nano
https://grabcad.com/library/nvidia-jetson-nano-1
https://grabcad.com/library/jetson-nano-3
https://grabcad.com/library/jetson-nano-in-box-1
https://grabcad.com/library/jetson-nano-1

- Jetson Tx1/Tx2 + module
https://grabcad.com/library/jetson-tx2-1
https://grabcad.com/library/nvidia-jetson-tx1-1/details?folder_id=2092523
https://grabcad.com/library/nvidia-jetson-tx1-tx2-1

- Jetson Tk1
https://grabcad.com/library/nvidia-jetson-tk1-kit-with-mounting-1

- 2d embedded Camera
https://grabcad.com/library/raspberry-pi-camera-module-v2-1
https://grabcad.com/library/see3cam_cu130-13mp-custom-lens-usb-3-0-camera-1/details?folder_id=1415499
https://grabcad.com/library/raspberry-pi-camera-housing-with-tilting-function-1
https://grabcad.com/library/raspberry-pi-camera-3

- 3d checkerboard pattern
https://grabcad.com/library/3d-checkerboard-pattern-1

- kinect sensor
https://grabcad.com/library/kinect-xbox-360
https://grabcad.com/library/kinect-1

- RPi
https://grabcad.com/library/raspberry-pi-3-b-1
https://grabcad.com/library/raspberry-pi-3-board-1
https://grabcad.com/library/raspberry-pi-3-model-b-reference-design-solidworks-cad-raspberry-pi-raspberrypi-rpi-1

- Hokuyo lidar
https://grabcad.com/library/hokuyo-utm-30lx-2
https://grabcad.com/library/hokuyo-ust-10lx-lidar-1

- RPLiDAR
https://grabcad.com/library/rp-lidar-a1-inventor-reassembly-1

- L298N
https://grabcad.com/library/l298n-stepper-motor-driver-red-1
https://grabcad.com/library/l298n-stepper-motor-driver-green-1

- Mi Power Bank
https://grabcad.com/library/power-bank-of-mi-1
https://grabcad.com/library/xiaomi-mi-power-bank-2-1000mah-black-1

- IMU 9DOF
https://grabcad.com/library/grove-imu-9-dof-v1-1

- PX4 PixFalcon
https://grabcad.com/library/pixfalcon-hobbyking-micro-px4-autopilot-1

- Turtlebot base
https://grabcad.com/library/irobot-icreate-2-reference-cad-model-1

- Complete robots
https://grabcad.com/library/arduino-4wd-buggy-kit-1
https://grabcad.com/library/arduino-2wd-robot-chassis-1
https://grabcad.com/library/robot-pepega-1/details?folder_id=5907674



### Scripts to convert to urdf
https://github.com/syuntoku14/fusion2urdf
https://github.com/Rhoban/onshape-to-robot



$ cat /sys/class/gpio/gpiochip0/label
    tegra-gpio

$ cat /sys/debug/tegra-gpio

$ cat /sys/kernel/debug/pinctrl/pinctrl-devices
    name [pinmux] [pinconf]
    70008d4.pinmux yes yes
    ...

- Figure out pin mapping
$ cat /sys/kernel/debug/pinctrl/70008d4.pinmux/pinconf-pins   <- This will give you complete list of linux pin mapping for GPIO/Peripherals

- For our purpose DAP4_SCLK PJ7 belongs to pin 79

- Lets see available sysfs gpio
$ cat /sys/kernel/debug/gpio   <- for active gpio

- Map GPIO Pin79
$ echo 79 > /sys/class/gpio/export

$ cat /sys/kernel/debug/gpio   <- check again it will show up with its status

- To set direction as output for pin79
$ echo out > /sys/class/gpio/gpio79/direction

- To switch pin79 ON, set value 1
$ echo 1 > /sys/class/gpio/gpio79/value

- Unmap GPIO Pin79
$ echo 79 > /sys/class/gpio/unexport