<?php

// object oriented method
$servername="localhost";
$username="root";
$password="Samip2003";


//Createing connection
// $conn= new mysqli($servername,$username,$password);

// //checking connection
// if($conn->connect_error){
//     die("Connection failed: ".$conn->connect_error);
// }


// procedural method
$conn= mysqli_connect($servername,$username,$password);
if(!$conn){
    die("Connection failed: ".mysqli_connect_error());
}
else{

    echo "Connected successfully<br>";
}

//crete table
//write sql query
$sql="CREATE DATABASE myDB";
if(mysqli_query($conn,$sql)){
    echo "Database created successfully<br>";
}
else{
    echo "Error creating database: ".mysqli_error($conn);
}


mysqli_close($conn);
?>