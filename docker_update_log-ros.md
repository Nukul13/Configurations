## ros-lab:v1
- OpenGL
- CUDA Support
- System setup

## ros-lab:v2
Simple utilities and configurations (vim, tmux, zsh, python, sublime, xclip, etc)

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

- Setup clang-8
- Add LLVM repo `subl /etc/apt/sources.list`
```
deb http://apt.llvm.org/bionic/ llvm-toolchain-bionic-8 main
deb-src http://apt.llvm.org/bionic/ llvm-toolchain-bionic-8 main
```
- Now update repo and start installing
```
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key| apt-key add -
apt update
apt-get install clang-8 lldb-8 lld-8
# LLVM
apt-get install libllvm-8-ocaml-dev libllvm8 llvm-8 llvm-8-dev llvm-8-doc llvm-8-examples llvm-8-runtime
# Clang and co
apt-get install clang-8 clang-tools-8 clang-8-doc libclang-common-8-dev libclang-8-dev libclang1-8 clang-format-8 python-clang-8
# libfuzzer
apt-get install libfuzzer-8-dev
# lldb
apt-get install lldb-8
# lld (linker)
apt-get install lld-8
# libc++
apt-get install libc++-8-dev libc++abi-8-dev
# OpenMP
apt-get install libomp-8-dev
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

## ros-lab:v5
- More Clang utility and config
```
apt update
apt install clang-tidy-8

ln -s /usr/bin/clang-8 /usr/bin/clang
ln -s /usr/bin/clang++-8 /usr/bin/clang++
ln -s /usr/bin/llvm-ar-8 /usr/bin/llvm-ar
ln -s /usr/bin/llvm-as-8 /usr/bin/llvm-as
ln -s /usr/bin/clangd-8 /usr/bin/clangd
ln -s /usr/bin/clang-tidy-8 /usr/bin/clang-tidy
```

- For C++ Code completion use clangd - (refer this for sublime and vim setup)[https://clang.llvm.org/extra/clangd/Installation.html]
- sublime remove YCM
- sublime install LSP

- Vim C-family autocompletion using clangd
```
#vim recompile ~/.vim/plugged/YouCompleteMe 
cd ~/.vim/plugged/YouCompleteMe/
python3 install.py --clang-completer --clangd-completer --system-libclang --core-tests
```
- To put ros includes in path /usr/local/include (This folder was default empty)
`ln -s /opt/ros/melodic/include/* /usr/local/include/`

- Now sublime and `vim(~/.vimrc)` are configured to locate ros autocompletion


## ros-lab:v6
git config --global user.email "dwijaybane2@gmail.com"
git config --global user.name "Dwijay Bane"
git config --global core.editor "subl -n -w"

zsh plugins [tmux git-flow sudo tig zsh-autosuggestions zsh-syntax-highlighting]
[git flow setup and Doc](https://github.com/nvie/gitflow)
Also tmux plugin should be rearranged

sublime -> jedi removed and added anaconda

apt install locate tree less ack cmake-curses-gui cmake-qt-gui usbutils

pip install jupyter
pip3 install jupyter matplotlib ipython

vim ycmd python support

//add following to .zshrc and .bashrc
`alias autokey='apt-get update 2> /tmp/keymissing; for key in $(grep "NO_PUBKEY" /tmp/keymissing |sed "s/.*NO_PUBKEY //"); do echo -e "\nProcessing key: $key"; gpg --keyserver pool.sks-keyservers.net --recv $key && gpg --export --armor $key | apt-key add -; done'`

libfreenect -> make install
```
cd /notebook
git clone git://github.com/OpenKinect/libfreenect.git
cd libfreenect
mkdir build
python src/fwfetcher.py  // 111mb so have patience

// Open the file `usb_libusb10.c` as shown below and comment/remove line 443 i.e, `fnusb_keep_alive_led(ctx, audio)`:
subl src/usb_libusb10.c

// Open the `CmakeLists.txt` file and add the following line on line 40 ,i.e, after the line `PROJECT(libfreenect)`:
set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

// Build libfreenect
cd build
cmake -D BUILD_PYTHON=ON -D BUILD_PYTHON2=ON -D BUILD_PYTHON3=ON ..
cp ../audio.bin bin/
make -j4
// To test do this: cd bin/ -> ./freenect-camtest (if this works do next step) -> ./freenect-glview
make install
ldconfig /usr/local/lib
// Now try running: cd /notebook -> freenect-glview
// In this setup we skipped copying: "cp $HOME/platform/linux/udev/51-kinect.rules /etc/udev/rules.d/"
```

For bashrc and zshrc: [CPP ENV](https://gcc.gnu.org/onlinedocs/cpp/Environment-Variables.html)
```
# ROS Include
export CPATH=/opt/ros/melodic/include/:$CPATH
OR
export CPATH=/opt/ros/kinetic/include/:$CPATH

# For Custom Built Libraries
export LD_LIBRARY_PATH=/usr/local/lib/:$LD_LIBRARY_PATH

# Catkin_ws Package include
export CPATH=/notebooks/catkin_ws/devel/include:$CPATH

#Catkin_ws Package Source
source /notebooks/catkin_ws/devel/setup.bash
OR
source /notebooks/catkin_ws/devel/setup.zsh
```

## ros-lab:v7
