## ros-lab:v1
- OpenGL
- CUDA Support
- System setup

## ros-lab:v2
Simple utilities and configurations (vim, tmux, zsh, python, sublime, etc)

## ros-lab:v3
- remove tabs from sublime
- install cmake in sublime
- install SublimeCodeIntel
- install c++ completions
- setup ros catkin worskspace - done in notebook
- add source /notebook/catkin_ws/devel/setup.bash to bashrc zshrc
- install neovim as well

- For Space-Vim Install
```
bash <(curl -fsSL https://raw.githubusercontent.com/liuchengxu/space-vim/master/install.sh)
```

- For ROS Controller packages
```
apt-get install ros-melodic-effort-controllers
apt-get install ros-melodic-ros-controllers
apt-get install ros-melodic-ros-control 
```

- For image processing over opencv2.x version and display issue
(Issue)[https://github.com/ros-perception/image_pipeline/issues/201]
```
cd catkin_ws
git -C src clone https://github.com/ros-perception/image_pipeline.git
git -C src/image_pipeline fetch origin pull/343/head:bugfix
git -C src/image_pipeline checkout bugfix
catkin_make
```

## ros-lab:v4
- sublime install gitsavvy and remove Git package
- `apt-get insall tree tig`
- In tmux activate plugins by "prefix + I" to fetch plugin and source it. So resurrect works for saving and restoring(prefix+C+s and prefix+C+r). also continum will autorestore.

- Setup vim & nvim as python ide (https://spacevim.org/use-vim-as-a-python-ide/)
- 

Uninstall spacevim
curl -sLf https://spacevim.org/install.sh | bash -s -- --uninstall
rm -rf ~/.space-vim/
rm -rf ~/.spacevim

For Spacevim setup https://github.com/EwanValentine/spacevim-setup
