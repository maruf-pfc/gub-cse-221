<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        $a = 3;
        $b = 4;
        $c = sqrt(pow($a, 2) + pow($b, 2));
        echo "Pythagorean theorem (3,4,5 triangle): $c<br><br>";
        echo "Math Functions Examples:<br>";
        echo "abs(-7.2): " . abs(-7.2) . "<br>";
        echo "ceil(4.3): " . ceil(4.3) . "<br>";
        echo "cos(0): " . cos(0) . "<br>";
        echo "floor(4.7): " . floor(4.7) . "<br>";
        echo "log(2.718): " . log(2.718) . "<br>";
        echo "log10(100): " . log10(100) . "<br>";
        echo "max(2, 3, 4): " . max(2, 3, 4) . "<br>";
        echo "min(2, 3, 4): " . min(2, 3, 4) . "<br>";
        echo "pow(2, 3): " . pow(2, 3) . "<br>";
        echo "rand(1, 10): " . rand(1, 10) . "<br>";
        echo "round(3.4): " . round(3.4) . "<br>";
        echo "round(3.5): " . round(3.5) . "<br>";
        echo "sin(90): " . sin(90) . "<br>";
        echo "sqrt(16): " . sqrt(16) . "<br>";
        echo "tan(45): " . tan(45) . "<br><br>";
        echo "Math Constants:<br>";
        echo "PI (M_PI): " . M_PI . "<br>";
        echo "E (M_E): " . M_E . "<br>";
        echo "Natural log of 2 (M_LN2): " . M_LN2 . "<br>";
        $angle = 45;
        $radius = 5;
        $area = M_PI * pow($radius, 2);
        $circumference = 2 * M_PI * $radius;
        echo "<br>Circle Calculations (radius = 5):<br>";
        echo "Area: " . round($area, 2) . "<br>";
        echo "Circumference: " . round($circumference, 2) . "<br>";
    ?>
</body>
</html>