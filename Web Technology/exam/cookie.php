<html>
<?php

    $cookie_name = "user";
    $cookie_value = "Samip Lamsal";
     setcookie($cookie_name, $cookie_value, time() + (86400 * 30),"/"); // 86400 = 1 day


    // check and display cookie
    if(isset($_COOKIE[$cookie_name])) {
        echo "Cookie named '" . $cookie_name . "' is set!<br>";
        echo "Value is: " . $_COOKIE[$cookie_name];
    } else {
        echo "Cookie named '" . $cookie_name . "' is not set!";
    }
    setcookie($cookie_name, "", 0);
     if(isset($_COOKIE[$cookie_name])) {
        echo "<br> Cookie is not deleted";
        
    } 
    
     else {
        echo "<br> Cookie 'user' is deleted.";
    }

?>
</html>
