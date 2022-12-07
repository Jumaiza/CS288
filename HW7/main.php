<?php

$host = "localhost";
$username = "root";
$password = "Cs288005!";
$dbname = "cs288";

$conn = mysqli_connect($host, $username, $password, $dbname);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$query = "SELECT * FROM vivid";
$result = mysqli_query($conn, $query);

echo "<h1>CLICK THE IMAGE TO BUY YOUR PRODUCT!</h1>";
echo "<h2 style='color: red;'>VIVID RACING</h2>";
while ($row = mysqli_fetch_assoc($result)) {
    $sku = $row["SKU"];
    $name = $row["ProductName"];
    $image = $row["RemImgUrl"];

    echo "<h3 id=$sku>$name</h3>";
    echo "<a href='comparison.php?id=" . $sku . "'><img src='" . $image. "' /></a>";
}

$query = "SELECT * FROM lmp";
$result = mysqli_query($conn, $query);

echo "<h2 style='color: red;'>LMPerformance</h2>";
while ($row = mysqli_fetch_assoc($result)) {
    $sku = $row["SKU"];
    $name = $row["ProductName"];
    $image = $row["RemImgUrl"];

    echo "<h3 id=$sku>$name</h3>";
    echo "<a href='comparison.php?id=" . $sku . "'><img src='" . $image. "' /></a>";
}

mysqli_close($conn);

?>

