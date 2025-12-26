#!/bin/zsh

commands=(
"bat arrange.txt record.txt"
"clear"
"grep -i 'this' record.txt"
"grep -i '\"this\"' record.txt"
"grep -i \"this\" record.txt"
"grep -c \"this\" record.txt"
"grep -c \"This\" record.txt"
"grep -l \"this\" *"
"grep -l \"bye\" *"
"grep -ni \"this\""
"grep -ni \"this\" *"
"grep -ni \"hi\" *"
"cat > employee.txt <<'EOF'
# sample employee data - edit as needed
# name dept grade salary
Alice HR B6 45000
Bob IT 4 30000
Carol Sales B6 42000
EOF"
"ls"
"cat employee.txt"
"v employee.txt"   # may open editor; replace with 'vim' or remove if not installed
"ls"
"awk '{print}' employee.txt"
"awk '/manager/ {print}' employee.txt"
"awk '{print \$1,\$4}' employee.txt"
"awk '{print NR,\$0}' employee.txt"
"clear"
"awk '{print NR,\$0}' employee.txt"
"awk '{print \$1,\$NF}' employee.txt"
"awk 'NR==3,NR==6 {print NR,\$0}' employee.txt"
"awk '{ if (length(\$0) > max) max = length(\$0) } END { print max }' employee.txt"
"clear"
"awk '{ if (length(\$0) > max) max = length(\$0) } END { print max }' employee.txt"
"awk 'END { print NR }' employee.txt"
"awk 'length(\$0) > 10' employee.txt"
"awk '{ if(\$3 == \"B6\") print \$0; }' employee.txt"
"awk '{ if(\$3 == \"this\") print \$0; }' employee.txt"
"awk '{ if(\$3 == \"\") print \$0; }' employee.txt"
"cat employee.txt"
"awk '{ if(\$3 == \"4\") print \$0; }' employee.txt"
"awk '{ if(\$3 == \"45000\") print \$0; }' employee.txt"
"clear"
"awk '{ if(\$3 == \"B6\") print \$0; }' employee.txt"
"awk 'BEGIN { for(i=1;i<=6;i++) print \"square of\", i, \"is\", i*i; }'"
)

for cmd in "${commands[@]}"; do
  echo "> $cmd"
  eval "$cmd"
  echo
  read -r -p "Press Enter to run next command (Ctrl-C to stop)..." </dev/tty
done


