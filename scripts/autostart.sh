#!/bin/sh

#[[ -f ~/.Xresources  ]] && xrdb -merge -I"$HOME" "$HOME"/.Xresources

#/usr/bin/pipewire &
#/usr/bin/pipewire-pulse &
#/usr/bin/pipewire-media-session &

#exec dwm 2> "$HOME"/.dwm.log
#exec dwm

run() {
  if ! pgrep -f "$1"; then
    "$@" &
  fi
}

run "$HOME/.config/dwm/scripts/./dwm_statusbar"
run "$HOME/.fehbg"
run "/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1"
run "fcitx5"
run "picom" --daemon
run "greenclip" daemon
redshift -P -O 5000
