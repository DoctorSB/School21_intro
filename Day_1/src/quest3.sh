#!bin/bash
cd
cd T01D01-0/ 
cd src/

mv door_management_fi door_management_files
cd door_management_files/
mkdir door_configuration
mkdir door_map
mkdir door_logs

mv *.log door_logs
mv *.conf door_configuration
mv door_map_1.1 door_map