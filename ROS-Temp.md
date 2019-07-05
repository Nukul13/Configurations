Jetson Nano Hardware
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