<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        // Create a test directory and file
        $dir = "test_directory";
        $file = "test_directory/sample.txt";
        $content = "Hello, this is a sample content.<br>Second line of text.";
        // Create directory
        if (!is_dir($dir)) {
            mkdir($dir);
            echo "Directory created: $dir<br>";
        }
        // Write content to file
        file_put_contents($file, $content);
        echo "Content written to file<br>";
        // Read file contents
        $read_content = file_get_contents($file);
        echo "<br>File contents:<br>$read_content<br>";
        // Get file information
        echo "<br>File Information:<br>";
        echo "Basename: " . basename($file) . "<br>";
        echo "File exists: " . (file_exists($file) ? "Yes" : "No") . "<br>";
        echo "File size: " . filesize($file) . " bytes<br>";
        echo "File permissions: " . decoct(fileperms($file)) . "<br>";
        echo "Last modified: " . date("Y-m-d H:i:s", filemtime($file)) . "<br>";
        echo "Is directory: " . (is_dir($file) ? "Yes" : "No") . "<br>";
        echo "Is readable: " . (is_readable($file) ? "Yes" : "No") . "<br>";
        echo "Is writable: " . (is_writable($file) ? "Yes" : "No") . "<br>";
        echo "Disk free space: " . disk_free_space(dirname($file)) . " bytes<br>";
        // Create a copy of the file
        $copy_file = $dir . "/sample_copy.txt";
        copy($file, $copy_file);
        echo "<br>File copied to: $copy_file<br>";
        // Rename the copy
        $new_name = $dir . "/renamed_file.txt";
        rename($copy_file, $new_name);
        echo "File renamed to: $new_name<br>";
        // Change file permissions
        chmod($file, 0644);
        echo "Changed file permissions<br>";
        // List directory contents using glob
        echo "<br>Directory contents using glob:<br>";
        foreach (glob($dir . "/*") as $file_path) {
            echo $file_path . "<br>";
        }
        // List directory contents using scandir
        echo "<br>Directory contents using scandir:<br>";
        $files = scandir($dir);
        foreach ($files as $file_name) {
            if ($file_name != "." && $file_name != "..") {
                echo $file_name . "<br>";
            }
        }
        // Clean up - Delete files and directory
        unlink($file);
        unlink($new_name);
        rmdir($dir);
        echo "<br>Cleaned up test files and directory<br>";
    ?>
</body>
</html>