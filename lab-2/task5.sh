#c:/cygwin64/bin/bash.exe
#   This software code is provided as open source software. No questions will be
#   answered relating to any part of this software, for any reason.
#
#   Much love,
#   https://github.com/alex-titus


for i in $(seq 1 100);
do
    echo "$i"
done > numbs.txt

# wc ./numbs.txt
# 100 100 292 ./numbs.txt
# 100 new lines, 100 words, 292 bytes in numbs.txt
# head -n 38 numbs.txt | tail -n 14; > somenumbs.txt
# wc somenumbs.txt
# 14 14 42 somenumbs.txt
# 14 new lines, 14 words, 42 bytes in somenumbs.txt
