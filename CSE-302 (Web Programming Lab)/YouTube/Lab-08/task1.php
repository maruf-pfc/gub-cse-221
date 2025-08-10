<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<!-- Take a input and determine its type
1. number(positive,negative,zero),
2. character(uppercase,lowercase) -->

    <form action="task1.php" method="post">
        <input type="text" name="input" id="input">
        <input type="submit" value="Submit">
    </form>

    <?php 
        if(isset($_POST['input'])){ 
            // a common PHP construct used to check if a form input has been submitted via an HTTP POST request. 
            $input = $_POST['input'];
            if(is_numeric($input) == 0){
                echo "Zero";
                return;
            }
            if(empty($input)){
                echo "Please enter a value";
                return;
            }

            if(is_numeric($input)){
                if($input > 0) echo "Positive Number";
                else if($input < 0) echo "Negative Number";
            }else{
                if(ctype_upper($input)) echo "Uppercase Character";
                else if(ctype_lower($input)) echo "Lowercase Character";
                else echo "Special Character";
            }
        }
    ?>
</body>
</html>