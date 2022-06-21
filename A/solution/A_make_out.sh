#!/bin/sh
cd ../testcases
../solution/build/A_make_in_files
for file in $(ls in)
do
    ../solution/build/A_solution < "in/${file}" > "out/${file}"
done
cd ../solution
