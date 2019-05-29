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
- sublime jedi (python auto completion)
- sublime ycmdCompletion (optional)

- In tmux activate plugins by "prefix + I" to fetch plugin and source it. So resurrect works for saving and restoring(prefix+C+s and prefix+C+r). also continum will autorestore.

- Install packages for vim plugins and utilities
```
apt update
apt-get install tree tig nmap gdebi-core evince
apt-get install python-dev python3-dev texlive

```

- Install nodejs
```
curl -sL https://deb.nodesource.com/setup_10.x | bash -
apt install nodejs
curl -sL https://dl.yarnpkg.com/debian/pubkey.gpg | apt-key add -
echo "deb https://dl.yarnpkg.com/debian/ stable main" | tee /etc/apt/sources.list.d/yarn.list
apt-get update && apt-get install yarn

npm install -g neovim
```

- For Installing space-vim (plugins)[https://github.com/liuchengxu/space-vim/blob/master/layers/LAYERS.md]. See Layer Usages and Pre-requisites for setting up keybindings and other configurations.

- Python Packages for plugins
```
pip install jedi pynvim
pip3 install flake8 jedi pynvim 
```

- For Latex preview plugin
`ln -s /usr/bin/evince /usr/bin/acroread`

- copy `spacevim` file from configurations to file `~/.spacevim` and replace it.
```
rm ~/.spacevim
cp spacevim ~/.spacevim
#make sure its correct
cat ~/.spacevim    
```

- Now run vim
```
:PlugInstall
:PlugStatus
```
- Now run nvim
```
:PlugInstall
:PlugStatus
:checkhealth
```

- Setting up ycmd for vim
```
cd ~/.vim/plugged/YouCompleteMe 
python3 install.py --clang-completer
```
