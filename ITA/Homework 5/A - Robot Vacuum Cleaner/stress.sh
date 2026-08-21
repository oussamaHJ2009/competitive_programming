# Compile all three
g++ gen.cpp -o gen
g++ main.cpp -o main
g++ test.cpp -o test
# Run infinite loop
for i in {1..10000}
do
./gen > in.txt
./main < in.txt > out_main.txt
./test < in.txt > out_test.txt
# Compare outputs ignoring whitespace ( - w )
diff -w out_main.txt out_test.txt || break
echo " Passed test : $i "
done
echo " Failed ! Check in . txt to see the failing case . "