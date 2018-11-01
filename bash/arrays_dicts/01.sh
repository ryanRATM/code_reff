myArray=(apples grapes banananas orange MANGO!!)

# can do either: ${arr[*]} OR ${arr[@]}
for fruit in ${myArray[@]}
do
   echo "fruit: $fruit"
done
