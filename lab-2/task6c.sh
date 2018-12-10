#c:/cygwin64/bin/bash.exe
#   This software code is provided as open source software. No questions will be
#   answered relating to any part of this software, for any reason.
#
#   Much love,
#   https://github.com/alex-titus

echo "Enter a value 5 to 9"
read value

while [ $value -lt 5 -o $value -gt 9 ]; do
    echo "Incorrect value, please give a value between 5 and 9"
    read value
done

for i in $(seq 1 $value); do
    spaces=$(($value - $i))
    for l in $(seq 1 $spaces); do
        echo -e " \c"
    done
        for j in $(seq 1 $i); do
            echo -e " $i\c"
        done
    echo
done
