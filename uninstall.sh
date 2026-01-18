#!/usr/bin/env bash
install_path="/usr/local/bin/song-starter"

if [ -f "$install_path" ]; then
    sudo rm "$install_path"
    echo "song-starter uninstalled."
else
    echo "song-starter not found at $install_path"
fi
