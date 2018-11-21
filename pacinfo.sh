#! /bin/bash
# script to provide info about installed packages
echo "All Packages: $(pacman -Q | wc -l)"
echo "Explicitly Installed: $(pacman -Qe | wc -l)"
echo "Explicitly Installed from Official Repos: $(pacman -Qne | wc -l)"
echo "Total Installed from Official Repos: $(pacman -Qn | wc -l)"
echo "Installed from AUR: $(pacman -Qm | wc -l)"
