<?php

session_start();

$_SESSION['username'] = 'Risav Pyakurel';
$_SESSION['email'] = 'pyakurel.risav@gmail.com';
$username = $_SESSION['username'];
$email = $_SESSION['email'];
echo "Username: " . $username . "<br>";
echo "Email: " . $email . "<br>";
session_destroy();

?>