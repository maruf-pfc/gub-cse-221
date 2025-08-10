<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        $fruits = ["apple", "banana", "orange", "mango", "apple"];
        echo "Original array:<br>";
        print_r($fruits);
        $count = count($fruits);
        echo "<br>Number of elements: $count<br>";
        array_push($fruits, "grape");
        echo "<br>After pushing 'grape':<br>";
        print_r($fruits);
        $last = array_pop($fruits);
        echo "<br>Popped element: $last<br>";
        array_unshift($fruits, "kiwi");
        echo "<br>After unshifting 'kiwi':<br>";
        print_r($fruits);
        $first = array_shift($fruits);
        echo "<br>Shifted element: $first<br>";
        $search = in_array("banana", $fruits);
        echo "<br>Is 'banana' in array? " . ($search ? "Yes" : "No") . "<br>";
        $position = array_search("orange", $fruits);
        echo "Position of 'orange': $position<br>";
        $reversed = array_reverse($fruits);
        echo "<br>Reversed array:<br>";
        print_r($reversed);
        sort($fruits);
        echo "<br>Sorted array:<br>";
        print_r($fruits);
        rsort($fruits);
        echo "<br>Reverse sorted array:<br>";
        print_r($fruits);
        shuffle($fruits);
        echo "<br>Shuffled array:<br>";
        print_r($fruits);
        $numbers = array_fill(0, 3, 10);
        echo "<br>Filled array with 10:<br>";
        print_r($numbers);
        $merged = array_merge($fruits, ["pear", "plum"]);
        echo "<br>Merged array:<br>";
        print_r($merged);
        $arr1 = [1, 2, 3, 4, 5];
        $arr2 = [3, 4, 5, 6, 7];
        $intersect = array_intersect($arr1, $arr2);
        echo "<br>Intersection of arrays:<br>";
        print_r($intersect);
        $sum = array_sum($arr1);
        echo "<br>Sum of numbers: $sum<br>";
        $product = array_product($arr1);
        echo "Product of numbers: $product<br>";
        $unique = array_unique($fruits);
        echo "<br>Unique fruits:<br>";
        print_r($unique);
        $numbers = [1, 2, 3, 4, 5];
        $filtered = array_filter($numbers, function($n) {
            return $n % 2 == 0;
        });
        echo "<br>Filtered even numbers:<br>";
        print_r($filtered);
        $reduced = array_reduce($numbers, function($carry, $item) {
            return $carry + $item;
        }, 0);
        echo "<br>Reduced sum: $reduced<br>";
    ?>
</body>
</html>