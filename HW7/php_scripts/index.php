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
echo "<h1 style='color: red; text-align:center;'>VIVID RACING</h1>";
while ($row = mysqli_fetch_assoc($result)) {
    $sku = $row["SKU"];
    $name = $row["ProductName"];
    $image = $row["RemImgUrl"];

    echo "<div style='border: 1px solid black'>";
    echo "<h3 id=$sku style='text-align: center;'>$name</h3>";
    echo "<a href='comparison.php?id=" . $sku . "'><img style='margin:auto; display:block;' src='" . $image. "' /></a>";
    echo "</div>";
    echo "<br>";
}

$query = "SELECT * FROM lmp";
$result = mysqli_query($conn, $query);

echo "<br>";
echo "<h1 style='color: red; text-align:center;'>LMPerformance</h1>";
while ($row = mysqli_fetch_assoc($result)) {
    $sku = $row["SKU"];
    $name = $row["ProductName"];
    $image = $row["RemImgUrl"];

    echo "<div style='border: 1px solid black'>";
    echo "<h3 id=$sku style='text-align: center;'>$name</h3>";
    echo "<a href='comparison.php?id=" . $sku . "'><img style='margin:auto; display:block;' src='" . $image. "' /></a>";
    echo "</div>";
    echo "<br>";
}

mysqli_close($conn);

?>

