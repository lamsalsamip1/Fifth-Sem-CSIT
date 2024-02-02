<?php

//database parameters
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

// Form data
$name=$_POST['name'];
$hobbies=$_POST['hobbies'];
$gender=$_POST['gender'];
$faculty=$_POST['faculty'];


// inserting data
$entered_hobbies=implode(',',$hobbies);
$sql="INSERT INTO PLAYER(name,gender,hobbies) VALUES ('$name','$gender','$entered_hobbies')";


if(mysqli_query($conn,$sql)){
    echo "Data inserted successfully<br>";
    echo "Faculty is $faculty";
}
else{
    echo "Error inserting data: ".mysqli_error($conn);
}

//creating table
// $sql="CREATE TABLE PLAYER(
//     id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
//     name VARCHAR(30) NOT NULL,
//     gender VARCHAR(20) NOT NULL,
//     hobbies VARCHAR(50) NOT NULL )   ";


// if(mysqli_query($conn,$sql)){
//     echo "Table created successfully<br>";
// }
// else{
//     echo "Error creating table: ".mysqli_error($conn);
// }
mysqli_close($conn)

// foreach($hobbies as $hobby){
//     echo $hobby;
// }
// echo "Name:$name | Gender: $gender ";
?>