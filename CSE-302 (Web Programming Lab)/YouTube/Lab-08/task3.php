<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<!-- Calculate sum of even numbers up to 100 using for loop -->

    <?php 
        $sum = 0;
        for($i = 2; $i <= 100; $i += 2){
            $sum += $i;
        }

        echo "Sum of even numbers up to 100: $sum";
    ?>
</body>
</html>