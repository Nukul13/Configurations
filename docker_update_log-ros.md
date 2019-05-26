## ros-lab:v1
OpenGL
CUDA Support

## ros-lab:v2
Simple utilities and configurations (zsh, python, sublime, etc)

## ros-lab:v3
remove tabs from sublime
install cmake in sublime
setup ros catkin worskspace - done in notebook
add source /notebook/catkin_ws/devel/setup.bash to bashrc zshrc

install neovim as well

bash <(curl -fsSL https://raw.githubusercontent.com/liuchengxu/space-vim/master/install.sh)

apt install ros-melodic-effort-controllers
apt install ros-melodic-ros-control ros-melodic-ros-controllers

Issue https://github.com/ros-perception/image_pipeline/issues/201
cd catkin_ws
git -C src clone https://github.com/ros-perception/image_pipeline.git
git -C src/image_pipeline fetch origin pull/343/head:bugfix
git -C src/image_pipeline checkout bugfix
catkin_make







