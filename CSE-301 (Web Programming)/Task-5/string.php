<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        $name = "রহিম আহমেদ";
        echo "Original string: " . $name . "<br>";
        $length = strlen($name);
        echo "String length: " . $length . "<br>";
        $other_name = "ফাতিমা বেগম";
        $comparison = strcmp($name, $other_name);
        echo "String comparison result: " . $comparison . "<br>";
        $position = strpos($name, "ম");
        echo "Position of 'ম': " . $position . "<br>";
        $extracted = substr($name, 6, 5);
        echo "Extracted substring: " . $extracted . "<br>";
        $uppercase = strtoupper($name);
        echo "Uppercase: " . $uppercase . "<br>";
        $lowercase = strtolower($name);
        echo "Lowercase: " . $lowercase . "<br>";
        $text_with_spaces = "  বাংলা ভাষা  ";
        $trimmed = trim($text_with_spaces);
        echo "Trimmed text: '" . $trimmed . "'<br>";
        $sentence = "সুপ্রভাত,বাংলাদেশ,ঢাকা";
        $array = explode(",", $sentence);
        echo "Exploded array: ";
        print_r($array);
        $joined = implode(" ", $array);
        echo "Imploded string: " . $joined . "<br>";
    ?>
</body>
</html>