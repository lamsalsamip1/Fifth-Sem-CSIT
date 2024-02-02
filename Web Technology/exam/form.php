<?php

if (isset($_POST['username'])) $name = $_POST['username'];
else $name = "(Not entered)";

// Name Validation
if(!preg_match("/^[a-zA-Z ]*$/",$name)) {
  $nameErr = "Error: Only letters and white space allowed";
  echo $nameErr;
  exit();
}
else{
    echo "You entered name as $name<br>";
    
}

// Email validation
if(isset($_POST['email'])) $email=$_POST['email'];
else $email="(Not entered)";

if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
  $emailErr = "Error: Invalid email format";
  echo $emailErr;
  exit();
}
else{
    echo "You entered email as $email<br>";
}

//Age validation
if(isset($_POST['age'])) $age=$_POST['age'];
else $age="(Not entered)";

if(!filter_var($age,FILTER_VALIDATE_INT)){
    $ageErr="Error: Invalid age";
    echo $ageErr;
    exit();
}
else{
    echo "You entered age as $age<br>";
}


?>