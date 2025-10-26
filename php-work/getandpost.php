<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="getandpost.php" method = "post">
        <label for="">first name: </label>
        <input type="text" name="firstname"><br>
        <label for="">second name: </label>
        <input type="text" name="secondname"> <br>
        <label for="">pass: </label>
        <input type="text" name="pass">
        <input type="submit" name="press">
    </form>
    <form action="getandpost.php" method = "post">
        <input type="radio" name="question1">
        10 dh <br>
       <input type="radio" name="question1">
        20 dh <br>
        <input type="radio" name="question1">
        30 dh <br>
        <input type="submit" name="hi">
    </form>
    <form action="getandpost.php" method="post">
        <input type="checkbox" name="adam">
        adam <br>
         <input type="checkbox" name="aya">
        aya <br>
        <input type="checkbox" name="ayman">
        ayman <br>
        <input type="submit" name="sub">
    </form>
        <form action="getandpost.php" method="post">
        <input type="checkbox" name="q1[]">
        adam <br>
         <input type="checkbox" name="q1[]">
        aya <br>
        <input type="checkbox" name="q1[]">
        ayman <br>
        <input type="submit" name="subq1">
    </form>
</body>
</html>

<?php 
if(isset($_POST["subq1"]))
{
    $n = $_POST["q1"];
    foreach($n as $i)
    {
        echo $i;
    }

}
?>