#!/bin/bash

# Default commit message if you don't provide one
MESSAGE="Update competitive programming solutions"

# If you pass an argument, use it as the commit message
if [ ! -z "$1" ]; then
    MESSAGE="$1"
fi

echo "🚀 Staging files..."
git add .

echo "💾 Committing changes with message: '$MESSAGE'..."
git commit -m "$MESSAGE"

echo "📤 Pushing to GitHub..."
git push origin main

echo "✅ Done!"

