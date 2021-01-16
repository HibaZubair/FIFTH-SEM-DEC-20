<?php

// Grab User submitted information
$email = $_POST["users_email"];
$pass = $_POST["users_pass"];
$db_host = "localhost";
$db_user = "root";
$db_pass = "";
$db_name = "studentinformation";

echo $email;
echo $pass;

// Connect to the database
$con = mysqli_connect($db_host,$db_user,$db_pass,$db_name);
// Make sure we connected successfully
if(! $con)
{
    die('Connection Failed'.mysqli_connect_error());
}
else
	echo "connection ban gaya";

// Select the database to use
//mysql_select_db("studentinformation",$con);

$sql_query="SELECT users_email, users_pass FROM users WHERE users_email = '$email'";



$result = mysqli_query($con,$sql_query);
if (!$result ) {
    printf("Error: %s\n", mysqli_error($con));
    exit();
}
$row = mysqli_fetch_array($result);

if($row["users_email"]==$email && $row["users_pass"]==$pass)
    echo"You are a validated user.";
else
    echo"Sorry, your credentials are not valid, Please try again.";
?>