<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');

$conn=mysqli_connect('192.168.167.3', 'leeingyu', '1234', 'leeingyu_term',4567);
?>

<!doctype html>
<html>
<style>
        a{text-decoration:none; color:blue;}
        body{text-align:center}
    </style>
    <head>
        <meta charset="utf-8">
        <title>Leeingyu</title>
    </head>
    <body>
        <h1>Insert ChatHistory</h1>
        <h1><a href="index.php">Back to Index</a></h1>

        <input type="number" name="ChatCode" placeholder="ChatCode(int)">
        <input type="text" name="ChatHistory" placeholder="ChatHistory(string)">
        <br><br>
        <input type="button" value="INSERT">
        <input type="button" value="SHOW">
    </body>
</html>