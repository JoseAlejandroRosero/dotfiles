#!/bin/bash

set -e

# wallpaper
awww-daemon -f bgr &

# wlsunset for day and night gamma correction
wlsunset -t 2400 -T 7000 -d 1700 -g 1.2 -l 4.6 -L -74.1 &
 
# notifications( comment to use mako)
swaync --skip-system-css > ~/Desktop/swwaynclog &

# nm-applet
nm-applet &

# bar
waybar &

# safeeyes
safeeyes &

# clipboard content manager
wl-paste --type text &

# xwayland dpi scale
echo "Xft.dpi: 100" | xrdb -merge &
gsettings set org.gnome.desktop.interface text-scaling-factor 1.0 &

# permission autentication
/usr/libexec/xfce-polkit &

# panels, either conky or kitty's panel kitten
conky &

# pywalfox daemon
pywalfox start

# spawn a terminal and the password manager at start-up
kitty &
keepassxc &


## DEBUG FOR ENVIRONTMENT STUFF
#echo "dbus: $DBUS_SESSION_BUS_ADDRESS" >> /tmp/mango-debug.log
#echo "xdg-desktop-portal: $(pidof xdg-desktop-portal)" >> /tmp/mango-debug.log
