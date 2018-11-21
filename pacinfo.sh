#! /bin/bash
# script to provide info about installed packages
echo "All Packages: $(pacman -Q | wc -l)" & PIDA=$!
echo "Explicitly Installed: $(pacman -Qe | wc -l)" & PIDE=$!
wait $PIDA
wait $PIDE
echo "Explicitly Installed from Official Repos: $(pacman -Qne | wc -l)" & PIDEO=$!
echo "Total Installed from Official Repos: $(pacman -Qn | wc -l)" & PIDO=$!
wait $PIDEO
wait $PIDO
echo "Installed from AUR: $(pacman -Qm | wc -l)"
