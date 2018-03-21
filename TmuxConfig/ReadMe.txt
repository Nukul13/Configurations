-----------------------------------------------
For installing base16-gnome-terminal profiles:
-----------------------------------------------
cp -r base16-gnome-terminal* ~/.config

Now to install base16-ocean.dark theme profile

~/.config/base16-gnome-terminal/base16-ocean.dark.sh

Open Terminal and go to preference -> profile 
and set base16-ocean.dark as default shell


-----------------------------------------------
For installing Tmux config:
-----------------------------------------------
Make sure "sudo apt-get install xclip" is installed

cp tmux.conf ~/.tmux.conf


-----------------------------------------------
For installing Tmux Plugin Manager and Plugins:
-----------------------------------------------
git clone https://github.com/tmux-plugins/tpm ~/.tmux/plugins/tpm

gedit ~/.tmux.conf   (append at end)
--------------------------------------------
# List of plugins
set -g @plugin 'tmux-plugins/tpm'
set -g @plugin 'tmux-plugins/tmux-sensible'

# Other examples:
# set -g @plugin 'github_username/plugin_name'
# set -g @plugin 'git@github.com/user/plugin'
# set -g @plugin 'git@bitbucket.com/user/plugin'

# Initialize TMUX plugin manager (keep this line at the very bottom of tmux.conf)
run '~/.tmux/plugins/tpm/tpm'
--------------------------------------------

gedit ~/.tmux.conf   (append in plugin list)
--------------------------------------------
set -g @plugin 'tmux-plugins/tmux-resurrect'
set -g @plugin 'tmux-plugins/tmux-continuum'
set -g @plugin 'tmux-plugins/tmux-yank'

#Restores Tmux session saved by continuum
set -g @continuum-restore 'on'

#Restores shell history by resurrect 
#only those that dont have foreground ps running
set -g @resurrect-save-shell-history 'on'

#Restores Pane Contents
set -g @resurrect-capture-pane-contents 'on'
#set -g default-command "reattach-to-user-namespace -l $SHELL"
--------------------------------------------

To install and activate plugin:
run tmux
c-a shift+I