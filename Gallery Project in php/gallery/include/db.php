<?php

	$host = 'localhost';
	$user = 'root';
	$password = '';
	$database = 'testdb';

	$con = mysqli_connect($host,$user,$password,$database);

	if(mysqli_connect_error($con))
	{
		echo "Failed to connect to MySQL".mysqli_connect_error();
	}

?>
