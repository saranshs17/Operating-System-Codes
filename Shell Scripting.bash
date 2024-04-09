echo "Enter a: " 
read a
echo "Enter b: "
read b
echo "Enter the operation: "
read operation
case $operation in
    "+")
        sum=$(($a + $b))
        echo "$sum"
        ;;
        "-")
        sub=$(($a - $b))
        echo "$sub"
        ;;
        "*")
        mul=$(($a * $b))
        echo "$mul"
        ;;
        "/")
        div=$(($a / $b))
        echo "$div"
        ;;
        "%")
        mod=$(($a % $b))
        echo "$mod"
        ;;
        "^")
        pow=$(($a ** $b))
        echo "$pow"
        ;;
    *)
        echo "Unsupported operation"
        ;;
esac
