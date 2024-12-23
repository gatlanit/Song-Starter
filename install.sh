#!/bin/bash

set -e

# Replace with your GitHub repo
REPO="gatlanit/Song-Starter"

# Detect OS
OS=$(uname | tr '[:upper:]' '[:lower:]')

# Ensure compatibility
if [ "$OS" != "linux" ] && [ "$OS" != "darwin" ]; then
  echo "Unsupported OS: $OS"
  exit 1
fi

# Destination for the binary
DESTINATION="/usr/local/bin/song-starter"

# Fetch the latest release tag from GitHub
LATEST_RELEASE=$(curl -s https://api.github.com/repos/$REPO/releases/latest | grep "tag_name" | awk -F ': "' '{print $2}' | sed 's/",//')

echo "Downloading song-starter version $LATEST_RELEASE..."

# Download the binary from the latest release
curl -L "https://github.com/$REPO/releases/download/$LATEST_RELEASE/song-starter" -o song-starter

# Make it executable
chmod +x song-starter

# Move the binary to the correct location
echo "Installing song-starter to $DESTINATION..."
sudo mv song-starter $DESTINATION

echo "Installation complete!"