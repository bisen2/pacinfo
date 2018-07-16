#! /bin/bash
# script to provide info about installed packages
echo "All Packages: $(pacman -Q | wc -l)"
echo "Explicitly Installed: $(pacman -Qe | wc -l)"
echo "Explicitly Installed from Official Repos: $(pacman -Qne | wc -l)" & PIDEO=$!
echo "Total Installed from Official Repos: $(pacman -Qn | wc -l)" & PIDO=$!
wait $PIDEO
wait $PIDO
echo "Explicitly Installed from AUR: $(pacman -Qme | wc -l)" & PIDAO=$!
echo "Total Installed from AUR: $(pacman -Qm | wc -l)" & PIDA=$!
wait $PIDAO
wait $PIDA
