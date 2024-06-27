#!/bin/sh

run() {
  if ! pgrep -f "$1"; then
    "$@" &
  fi
}

# load dwm and dmenu colors from xresources
# xrdb -merge -I"$HOME" ~/.config/dwm/xcolors_dwm/xcolors.xresources
xrdb -merge -I"$HOME" ~/.Xresources
xsetroot -name "fsignal:2"

run "$HOME/.fehbg"
run "$HOME/.config/dwm/scripts/./dwm_statusbar"
run "/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1"
run "fcitx5"
run "picom" --daemon
run "greenclip" daemon
redshift -P -O 5000
