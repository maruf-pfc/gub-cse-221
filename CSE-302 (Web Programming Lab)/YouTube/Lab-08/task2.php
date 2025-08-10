<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<!-- Check vowel or consonant using switch/case -->

    <form action="task2.php" method="post">
        <input type="text" name="input" id="input">
        <input type="submit" value="Submit">
    </form>

    <?php 
        function convertLower($input){
            return strtolower($input);
        }

        if(isset($_POST['input'])){
            $input = $_POST['input'];

            if(empty($input)){
                echo "Please enter a value";
                return;
            }

            $input = convertLower($input);

            switch($input){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    echo "Vowel";
                    break;
                default:
                    echo "Consonant";
            }
        }
    ?>
</body>
</html>