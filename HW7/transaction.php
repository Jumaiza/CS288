<?php

$timestamp = time();
$datetime = date("Y-m-d H:i:s", $timestamp);

$name = $_POST['name'];
$address = $_POST['address'];
$city = $_POST['city'];
$state = $_POST['state'];
$zipcode = $_POST['zipcode'];
$creditCard = $_POST['credit-card'];
$expiration = $_POST['expiration'];
$cvv = $_POST['cvv'];

session_start();

$sku = $_SESSION['skuTransaction'];
$price = $_SESSION['price'];

$host = "localhost";
$username = "root";
$password = "Cs288005!";
$dbname = "cs288";

$conn = mysqli_connect($host, $username, $password, $dbname);
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

$query = "INSERT INTO transactions (timestamp,sku,price,name,address,city,state,zipcode,ccnumber,expiration,cvv) VALUES ('$datetime','$sku','$price','$name','$address','$city','$state','$zipcode','$creditCard','$expiration','$cvv')";
$result = mysqli_query($conn, $query);

if ($result === TRUE) {
    echo "<h3 style='color: green;'>Thank you for your purchase! Click below to go to home page.</h3>";
    echo '<button onclick="location.href=\'main.php\';">Go to home page</button>';
  } else {
    echo "<h3 style='color: red;'>Order unsuccesful. Please fix your information and try again! Click below to go to home page.</h3>";
    echo '<button onclick="location.href=\'main.php\';">Go to home page</button>';
  }

?>