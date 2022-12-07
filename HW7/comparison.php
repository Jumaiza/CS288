<?php

session_start();

$id = $_GET["id"];

$host = "localhost";
$username = "root";
$password = "Cs288005!";
$dbname = "cs288";

$conn = mysqli_connect($host, $username, $password, $dbname);
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$vividPrice = 0.0;
$query = "SELECT * FROM vivid WHERE SKU='$id'";
$result = mysqli_query($conn, $query);
while ($row = mysqli_fetch_assoc($result))
    $vividPrice = number_format($row["ProductPrice"]*1.1,2,".","");
$_SESSION["vividPrice"] = $vividPrice;

$lmpPrice = 0.0;
$query = "SELECT * FROM lmp WHERE SKU='$id'";
$result = mysqli_query($conn, $query);
while ($row = mysqli_fetch_assoc($result))
    $lmpPrice = number_format($row["ProductPrice"]*1.1,2,".","");
$_SESSION["lmpPrice"] = $lmpPrice;

echo "<h1> Product Comparison from Vivid Racing and LMPerformance</h1>";
$query = "SELECT * FROM vivid WHERE SKU='$id'";
$result = mysqli_query($conn, $query);
while ($row = mysqli_fetch_assoc($result)) {
    $sku = $row["SKU"];
    $_SESSION["sku"] = $sku;
    $name = $row["ProductName"];
    $_SESSION["vividName"] = $name;
    $description = $row["ProductDesc"];
    $image = $row["RemImgUrl"];
    $score = $row["ReviewScore"];

    echo "<h3 id=$sku>$name</h3>";
    if ($lmpPrice>$vividPrice){
        echo "<h3 style='border: 3px solid green;'>Price: $$vividPrice</h3>";
        echo "<h4 style='border: 3px solid green;'>Cheaper than the other product!</h4>";
        echo "<img src=$image style='border: 3px solid green;'>";
    }else{
        echo "<h3>Price: $$vividPrice</h3>";
        echo "<img src=$image>";
    }
    echo "<p>$description</p>";
    echo "<p>Review Rating: $score</p>";
    echo "<form action='checkout.php' method='POST'> <button type='submit' name='vivid'>Buy Now!</button></form>";
    echo "<br></br>";
    
}

$query = "SELECT * FROM lmp WHERE SKU='$id'";
$result = mysqli_query($conn, $query);

while ($row = mysqli_fetch_assoc($result)) {
    $sku = $row["SKU"];
    $_SESSION["sku"] = $sku;
    $name = $row["ProductName"];
    $_SESSION["lmpName"] = $name;
    $description = $row["ProductDesc"];
    $image = $row["RemImgUrl"];
    $score = $row["ReviewScore"];

    echo "<h3 id=$sku>$name</h3>";
    if ($lmpPrice<$vividPrice){
        echo "<h3 style='border: 3px solid green;'>Price: $$lmpPrice</h3>";
        echo "<h4 style='border: 3px solid green;'>Cheaper than the other product!</h4>";
        echo "<img src=$image style='border: 3px solid green;'>";
    }else{
        echo "<h3>Price: $$lmpPrice</h3>";
        echo "<img src=$image>";
    }
    echo "<p>$description</p>";
    echo "<p>Review Rating: $score</p>";
    echo "<form action='checkout.php' method='POST'> <button type='submit' name='lmp'>Buy Now!</button></form>";
    echo "<br></br>";
    
}

mysqli_close($conn);

?>