<?php
    session_start();
    $_SESSION['name'] = "Samip Lamsal";
    $_SESSION['email'] = "lamsalsamip@outlook.com";
    echo "Session variables are set.";

    echo "Name is ".$_SESSION['name']."<br>";
    echo "Email is ".$_SESSION['email']."<br>";

    session_unset();

    if(isset($_SESSION['name'])){
        echo "Session is not deleted";
    }
    else{
        echo "Session is deleted";
    }

    session_destroy();  

?>