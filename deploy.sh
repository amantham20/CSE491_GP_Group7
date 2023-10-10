#!/bin/bash

# Build MkDocs site for gh-pages branch
mkdocs build --clean

# Create and switch to the gh-pages branch
git checkout -b gh-pages

# Move the generated site files to the root directory
mv site/* .

# Commit and push changes to the gh-pages branch
git add .
git commit -m "Update MkDocs site for GitHub Pages"
git push origin gh-pages

# Switch back to the main branch
git checkout main
