<?php
$servername="localhost";
$username="root";
$password="";

//create connection
$conn=mysqli_connect($servername,$username,$password);

//check connection
if(!$conn){
	die("connection failed". mysqli_connect_error());
}
echo "connected successfully";
//create database 
$sql="CREATE DATABASE lab_example_f";
if($conn->query($sql)==TRUE){
	echo "Database created successfully";
}
else{
	echo "Error creating database : ". $conn->error;
}
$conn->close();
?>