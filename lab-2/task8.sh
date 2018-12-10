#c:/cygwin64/bin/bash.exe
#   This software code is provided as open source software. No questions will be
#   answered relating to any part of this software, for any reason.
#
#   Much love,
#   https://github.com/alex-titus

total=1
if [ $? -gt 2 ]; then
    echo "Invalid amount of arguments"
    exit 1
else
    value=$1
    while [ $value -gt 0 ]
    do
        total=$(( total+value ))
        value=$(( value-1 ))
    done
    echo "Total sum is is: $total"
fi
