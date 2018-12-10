#c:/cygwin64/bin/bash.exe
#   This software code is provided as open source software. No questions will be
#   answered relating to any part of this software, for any reason.
#
#   Much love,
#   https://github.com/alex-titus

for i in $(seq 1 5); do
    for j in $(seq 1 $i); do
        echo -e "*\c"
    done
    echo
done

for k in $(seq 5 -1 1); do
    for l in $(seq $k); do
        echo -e "*\c"
    done
    echo
done
