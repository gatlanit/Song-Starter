#!/bin/bash

set -e

# REPO
REPO="gatlanit/Song-Starter"

# Check OS and ARCH
OS=$(uname | tr '[:upper:]' '[:lower:]')
ARCH=$(uname -m)

# Make sure correct OS is being using here
if [ "$OS" != "darwin" ] && [ "$OS" != "linux" ]; then
  echo "Unsupported OS: $OS"
  exit 1
fi

# Select correct binary
if [ "$OS" == "darwin" ]; then
  if [ "$ARCH" == "x86_64" ]; then
    BINARY="song-starter-osx-x86_64"
  elif [ "$ARCH" == "arm64" ]; then
    BINARY="song-starter-osx-arm64"
  else
    echo "Unsupported architecture: $ARCH"
    exit 1
  fi
elif [ "$OS" == "linux" ]; then
  if [ "$ARCH" == "x86_64" ]; then
    BINARY="song-starter-linux-x86_64"
  elif [ "$ARCH" == "arm64" ]; then
    BINARY="song-starter-linux-arm64"
  else
    echo "Unsupported architecture: $ARCH"
    exit 1
  fi
fi

# Fetch the latest release from GitHub
LATEST_RELEASE=$(curl -s https://api.github.com/repos/$REPO/releases/latest | grep "tag_name" | awk -F ': "' '{print $2}' | sed 's/",//')

# Download the binary for user's platform
echo "Downloading song-starter version $LATEST_RELEASE for $OS $ARCH..."
curl -L "https://github.com/$REPO/releases/download/$LATEST_RELEASE/$BINARY" -o song-starter

chmod +x song-starter

# Check if the directory exists, create it if not
if [ ! -d "/usr/local/bin" ]; then
  echo "/usr/local/bin does not exist. Creating directory..."
  sudo mkdir -p /usr/local/bin
fi

# Move the binary to the correct location
if [ "$OS" == "darwin" ]; then
  DESTINATION="/usr/local/bin/song-starter"
elif [ "$OS" == "linux" ]; then
  DESTINATION="/usr/local/bin/song-starter"
fi

# Install the binary
echo "Installing song-starter to $DESTINATION..."
sudo mv song-starter $DESTINATION

echo "Installation complete!"

