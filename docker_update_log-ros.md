## ros-lab:v1
OpenGL
CUDA Support
System setup

## ros-lab:v2
Simple utilities and configurations (vim, tmux, zsh, python, sublime, etc)

## ros-lab:v3
remove tabs from sublime
install cmake in sublime
install SublimeCodeIntel
install c++ completions
setup ros catkin worskspace - done in notebook
add source /notebook/catkin_ws/devel/setup.bash to bashrc zshrc

install neovim as well

bash <(curl -fsSL https://raw.githubusercontent.com/liuchengxu/space-vim/master/install.sh)

apt-get install ros-melodic-effort-controllers
apt-get install ros-melodic-ros-controllers
apt-get install ros-melodic-ros-control 

Issue https://github.com/ros-perception/image_pipeline/issues/201
cd catkin_ws
git -C src clone https://github.com/ros-perception/image_pipeline.git
git -C src/image_pipeline fetch origin pull/343/head:bugfix
git -C src/image_pipeline checkout bugfix
catkin_make

## ros-lab:v4
apt-get insall tree
sublime install gitsavvy



