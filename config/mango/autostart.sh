#!/bin/bash

set -e

# screen recording
dbus-update-activation-environment --systemd WAYLAND_DISPLAY XDG_CURRENT_DESKTOP=wlroots &

#xdg-desktop-portal
#/usr/libexec/xdg-desktop-portal -r

# wallpaper
awww-daemon -f bgr &

# password manage
keepassxc &

# wlsunset for day and night gamma correction
wlsunset -t 2400 -T 7000 -d 1700 -g 1.2 -l 4.6 -L -74.1 &

# mps and mpDris2
mpd &
mpDris2 &
 
# notifications( comment to use mako)
swaync --skip-system-css > ~/Desktop/swwaynclog &

# nm-applet
nm-applet &

# bar
#waybar -c ~/.config/waybar/config_di -s ~/.config/waybar/style_di.css &
waybar &

# safeeyes
safeeyes &

# clipboard content manager
wl-paste --type text --watch cliphist store &

# xwayland dpi scale
echo "Xft.dpi: 100" | xrdb -merge &
gsettings set org.gnome.desktop.interface text-scaling-factor 1.0 &

# permission autentication
/usr/libexec/xfce-polkit &

# panels, either conky or kitty kitten
conky &
#. "$HOME/.local/bin/kitty-panels" &

# pywalfox daemon
pywalfox start

# required for some apps temporarily
systemctl --user mask xdg-desktop-portal-gtk.service 

## DEBUG FOR ENVIRONTMENT STUFF
#echo "path: $PATH" >> /tmp/mango-debug.log
#echo "user: $USER" >> /tmp/mango-debug.log
#echo "home: $HOME" >> /tmp/mango-debug.log
#echo "dbus: $DBUS_SESSION_BUS_ADDRESS" >> /tmp/mango-debug.log
echo "xdg-desktop-portal: $(pidof xdg-desktop-portal)" >> /tmp/mango-debug.log
#which brightnessctl >> /tmp/mango-debug.log
#which brightness-osd >> /tmp/mango-debug.log
