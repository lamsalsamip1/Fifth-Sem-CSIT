<?php

$servername="localhost";
$username="root";
$password="Samip2003";

$dbname="myDB";
$conn=mysqli_connect($servername,$username,$password,$dbname);
if(!$conn){
    die("Connection failed: ".mysqli_error($conn));
}
else{
    echo "Connected successfully<br>";
}

$sql="CREATE TABLE STUDENT(
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    firstname VARCHAR(30) NOT NULL,
    lastname VARCHAR(30) NOT NULL,
    email VARCHAR(50),
    reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
)";
if(mysqli_query($conn,$sql)){
    echo "Table created successfully<br>";
}
else{
    echo "Error creating table: ".mysqli_error($conn);
}


mysqli_close($conn);

?>