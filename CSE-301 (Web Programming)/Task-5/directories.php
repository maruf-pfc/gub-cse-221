<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        // Create test directory structure
        mkdir("test_dir");
        mkdir("test_dir/subdir");
        // Create some test files
        file_put_contents("test_dir/file1.txt", "Content 1");
        file_put_contents("test_dir/file2.txt", "Content 2");
        file_put_contents("test_dir/document.pdf", "PDF Content");
        file_put_contents("test_dir/subdir/file3.txt", "Content 3");
        echo "<h3>Using glob() function:</h3><br>";
        // List all .txt files
        echo "All .txt files in test_dir:<br>";
        $txt_files = glob("test_dir/*.txt");
        foreach($txt_files as $file) {
            echo $file . "<br>";
        }
        // List all files using wildcard
        echo "<br>All files in test_dir:<br>";
        $all_files = glob("test_dir/*");
        foreach($all_files as $file) {
            echo $file . "<br>";
        }
        // List files in subdirectories using ** pattern
        echo "<br>All .txt files in test_dir and subdirectories:<br>";
        $recursive_files = glob("test_dir/**/*.txt");
        foreach($recursive_files as $file) {
            echo $file . "<br>";
        }
        echo "<h3>Using scandir() function:</h3><br>";
        // List files using scandir
        echo "Files in test_dir:<br>";
        $files = scandir("test_dir");
        foreach($files as $file) {
            if($file != "." && $file != "..") {
                echo $file . "<br>";
            }
        }
        // List files in subdirectory
        echo "<br>Files in subdir:<br>";
        $subdir_files = scandir("test_dir/subdir");
        foreach($subdir_files as $file) {
            if($file != "." && $file != "..") {
                echo $file . "<br>";
            }
        }
        // Clean up test files and directories
        unlink("test_dir/file1.txt");
        unlink("test_dir/file2.txt");
        unlink("test_dir/document.pdf");
        unlink("test_dir/subdir/file3.txt");
        rmdir("test_dir/subdir");
        rmdir("test_dir");
        echo "<br>Test files and directories cleaned up.<br>";
    ?>
</body>
</html>