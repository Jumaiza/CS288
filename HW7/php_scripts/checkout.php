<?php

session_start();

echo "<h1>Checkout Page</h1>";

if (isset($_POST['vivid'])) {
    $price = $_SESSION['vividPrice'];
    $_SESSION["price"] = $price;

    $name = $_SESSION['vividName'];
    echo "<h3>You are buying: $name</h3>";
    echo "<h3>Total: $$price</h3>";
} else if (isset($_POST['lmp'])) {
    $price = $_SESSION['lmpPrice'];
    $_SESSION["price"] = $price;

    $name = $_SESSION['lmpName'];
    echo "<h3>You are buying: $name</h3>";
    echo "<h3>Total: $$price</h3>";
}

$_SESSION["skuTransaction"] = $_SESSION["sku"];


echo "<form action='transaction.php' method='POST'>
<label for='name'>Full Name:</label><br>
<input type='text' id='name' name='name'><br>
<br>
<label for='address'>Address:</label><br>
<input type='text' id='address' name='address'><br>
<br>
<label for='city'>City:</label><br>
<input type='text' id='city' name='city'><br>
<br>
<label for='state'>State:</label><br>
<input type='text' id='state' name='state'><br>
<br>
<label for='zipcode'>Zip Code:</label><br>
<input type='text' id='zipcode' name='zipcode'><br>
<br>
<label for='credit-card'>Credit Card Number:</label><br>
<input type='text' id='credit-card' name='credit-card'><br>
<br>
<label for='expiration'>Expiration Date:</label><br>
<input type='text' id='expiration' name='expiration'><br>
<br>
<label for='cvv'>CVV:</label><br>
<input type='text' id='cvv' name='cvv'><br>
<br>
<input style='width: 250px; height: 50px; font-size:20px' type='submit' id='submit' value ='Complete Purchase'>
</form>"

?>