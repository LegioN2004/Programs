# Demonstrates changing file permissions using chmod
# Read by owner only
chmod 400 sample.txt
ls -l sample.txt
# Read by group only
chmod 040 sample.txt
ls -l sample.txt
# Read by anyone
chmod 004 sample.txt
ls -l sample.txt
# Write by owner only
chmod 200 sample.txt
ls -l sample.txt
# Write by group only
chmod 020 sample.txt
ls -l sample.txt
# Write by anyone
chmod 002 sample.txt
ls -l sample.txt
# Execute by owner only
chmod 100 sample.txt
ls -l sample.txt
# Execute by group only
chmod 010 sample.txt
ls -l sample.txt
# Execute by anyone
chmod 001 sample.txt
ls -l sample.txt
# Allow read permission to owner and group and anyone.
chmod 444 sample.txt
ls -l sample.txt
# Allow everyone to read, write, and execute file.
