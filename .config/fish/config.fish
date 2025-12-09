if status is-interactive
    # Commands to run in interactive sessions can go here
end

source ~/.cache/wal/colors.fish
set -gx EDITOR vim
set -gx TERMINAL kitty
set -gx PKG_CONFIG_PATH /usr/lib/x86_64-linux-gnu/pkgconfig /usr/share/pkgconfig /usr/local/lib/pkgconfig

source ~/.config/fish/themes/matugen.fish
