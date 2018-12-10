#c:/cygwin64/bin/bash.exe
#   This software code is provided as open source software. No questions will be
#   answered relating to any part of this software, for any reason.
#
#   Much love,
#   https://github.com/alex-titus

for i in $(seq 1 5); do
    for j in $(seq 1 $i); do
        echo -e "$i\c"
    done
    echo
done
