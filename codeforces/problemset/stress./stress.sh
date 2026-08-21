# Compile all three
g++ gen.cpp -o gen
g++ sol.cpp -o sol
g++ brute.cpp -o brute
# Run infinite loop
for i in {1..10000}
do
    ./gen > in.txt
    ./sol < in.txt > out_sol.txt
    ./brute < in.txt > out_brute.txt
    # Compare outputs ignoring whitespace ( - w )
    diff -w out_sol.txt out_brute.txt || break
    echo " Passed test : $i "
done
echo " Failed ! Check in . txt to see the failing case . "