i=1
for file in *; do
    # echo "$file"
    if [ $((i%2)) == 1 ]
    then
        echo "$file $i"
        mv $file $((i/2 +1)).in
    else
        echo " !! $file $i"
        mv $file $((i/2)).sol
    fi
    # echo "$((i%2))"
    i=$((i+1))
done
# echo "hi"