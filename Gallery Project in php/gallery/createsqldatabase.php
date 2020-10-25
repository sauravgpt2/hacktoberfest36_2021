<?php

//connection variables
$host = 'shareddb1c.hosting.stackcp.net';
$user = 'testdb-32300ab8';
$password = 'wrongpassword123';

//create mysql connection
$con = new mysqli($host,$user,$password);
if (mysqli_connect_errno()) {
    echo "Connection failed:".mysqli_connect_error();
    die();
}

//create the database
if ( !mysqli_query($con,'CREATE DATABASE sample') ) {
    echo mysqli_error($con);
}

mysqli_select_db($con,"sample");

//create users table with all the fields
if(mysqli_query($con,'
CREATE TABLE `login` (
 `username` varchar(100) NOT NULL,
 `name` varchar(100) NOT NULL,
 `email` varchar(100) NOT NULL,
 `password` varchar(256) NOT NULL,
 `verified` tinyint(1) NOT NULL DEFAULT '0',
 `hash` varchar(100) NOT NULL,
 `image` varchar(100) NOT NULL,
 PRIMARY KEY (`username`),
 UNIQUE KEY `email` (`email`)
)'))
{
  echo "Success!";
}
else {
  die(mysqli_error($con));
}


?>
