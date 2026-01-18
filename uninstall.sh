#!/usr/bin/env bash
set -e

APP_NAME="song-starter"
BIN_PATHS=(
  "/usr/local/bin/$APP_NAME"
  "/opt/homebrew/bin/$APP_NAME"
  "$HOME/.local/bin/$APP_NAME"
)

ZSH_COMPLETIONS=(
  "/usr/local/share/zsh/site-functions/_$APP_NAME"
  "/opt/homebrew/share/zsh/site-functions/_$APP_NAME"
  "$HOME/.zsh/completions/_$APP_NAME"
)

echo "Uninstalling $APP_NAME..."

# Remove binary
for path in "${BIN_PATHS[@]}"; do
  if [ -f "$path" ]; then
    echo "Removing binary: $path"
    sudo rm -f "$path" || rm -f "$path"
  fi
done

# Remove zsh completions
for comp in "${ZSH_COMPLETIONS[@]}"; do
  if [ -f "$comp" ]; then
    echo "Removing zsh completion: $comp"
    sudo rm -f "$comp" || rm -f "$comp"
  fi
done

# Clear zsh completion cache
if [ -f "$HOME/.zcompdump" ]; then
  echo "Clearing zsh completion cache"
  rm -f "$HOME/.zcompdump"*
fi

echo "$APP_NAME has been fully uninstalled."
echo "Restart your terminal if tab completion still appears."
