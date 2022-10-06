#!bin/bash
cd
cd T01D01-0/ 
cd src/
cd ai_help
sh keygen.sh
cd key
find . -type f -empty -print -delete
cd ..
sh unifier.sh
cp main.key key
