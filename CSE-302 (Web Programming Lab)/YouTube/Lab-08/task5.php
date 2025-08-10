<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<!-- Find the leap years in a given range of years. (using function)
-->

    <?php 
        function isLeapYear($year){
            return ($year % 4 == 0 && ($year % 100 != 0 || $year % 400 == 0));
        }

        function findLeapYears($start, $end){
            $leapYears = [];
            for($i = $start; $i <= $end; $i++){
                if(isLeapYear($i)){
                    array_push($leapYears, $i);
                }
            }
            return $leapYears;
        }

        $start = 2000;
        $end = 2012;
        $leapYears = findLeapYears($start, $end);
        echo "[" . implode(",", $leapYears) . "]";
    ?>
</body>
</html>