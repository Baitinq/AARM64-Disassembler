#!/bin/bash

out_dir="./bin"

mkdir $out_dir 2> /dev/null

for f in $(find ./src -type f \( -iname \*.cpp -o -iname \*.s \))
do
    out_file=$(echo $f | sed 's/.\/src/.\/bin/g' | sed 's/\.cpp/\.o/g' | sed 's/\.s//g')
    mkdir -p $(dirname $out_file)
    if [[ $f == *.s ]]
    then
        aarch64-linux-gnu-as $f -o $out_file
    else
        g++ -g -c $f -o $out_file
    fi
done

g++ -o ./bin/disasm $(find ./bin -type f -name "*.o") -lgcc
