#!/bin/bash
cd ..
read sillka
read what
read isit
sed -i '' s/"$what"/"$isit"/ $sillka
date +%F' '%H:%M > ymdhhmmm
wc -c $sillka | awk '{print $1}' > weight
openssl sha256 $sillka | awk '{print $2}' > sha
echo "$sillka - `cat weight` - `cat ymdhhmmm` - `cat sha` - sha256" >> src/files.log