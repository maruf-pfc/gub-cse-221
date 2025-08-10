<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<!-- Write a php program to perform a binary search.
Sample array:
var items = [1, 2, 3, 4, 5, 7, 8, 9];
Expected Output:
binary_Search(items, 1); //0
binary_Search(items, 5); //4 
-->

    <?php 
        function binary_Search($arr, $x) {
            $low = 0;
            $high = count($arr) - 1;
            while ($low <= $high) {
                $mid = ($low + $high) / 2;
                if($arr[$mid] == $x) {
                    return $mid;
                } else if ($x < $arr[$mid]) {
                    $high = $mid - 1;
                } else {
                    $low = $mid + 1;
                }
            }
            return -1;
        }

        $items = [1, 2, 3, 4, 5, 7, 8, 9];
        echo "binary_Search(items, 1): " . binary_Search($items, 1) . "<br>";
        echo "binary_Search(items, 5): " . binary_Search($items, 5);
    ?>
</body>
</html>