<?php
/* Reset your password form, sends reset.php password link */
session_start();

include 'include/sendmailbasic.php';
require_once 'include/db.php';


// Check if form submitted with method="post"

if ( $_SERVER['REQUEST_METHOD'] == 'POST' )
{
    if( isset($_SESSION['username']) && !empty($_SESSION['username']) AND isset($_SESSION['logged_in']) && !empty($_SESSION['logged_in']) ) //Check if user is logged in
    {
      $result = mysqli_query($con,"SELECT * FROM login WHERE username='$_SESSION[username]'");

      $user = mysqli_fetch_assoc($result); // $user becomes array with user data

      if(password_verify($_POST['password'],$user['password']))
      {
        $address='reset.php?email='.$user['email'].'&hash='.$user['hash'];
        header("location: $address");
    }
    else {
      echo '<div class="alert alert-dismissible alert-danger">
  <button type="button" class="close" data-dismiss="alert">&times;</button>
  Incorrect password! Try again!.
</div>';
    }
  }
  else {
    $_SESSION['message'] = "Forbidden";
    header("location: ./index.php");
  }


}
?>


<?php

    if(isset($_SESSION['logged_in']))
    {

?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Change Your Password</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <link rel="stylesheet" href="css/bootstrap.css" media="screen">
    <link rel="stylesheet" href="css/custom.min.css">
</head>
  <body>
    <div class="navbar navbar-default navbar-fixed-top">
      <div class="container">
        <div class="navbar-header">
          <a href="change.php" class="navbar-brand">Admin Area !</a>
          <button class="navbar-toggle" type="button" data-toggle="collapse" data-target="#navbar-main">
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
        </div>
       

        </div>
      </div>
    </div>
 <div class="container">
    <div class="col-lg-4"></div>
    <div class="col-lg-6">
    <h1>Admin Area !</h1>
       <div class="panel panel-default">
        <div class="panel-body">



 

    <form class="form-group" action="change.php" method="post">
      <label class="col-lg-4">Current password<span>*</span></label>
      <input class="form-control" type="password" required name="password"/><br>
    <input class="btn btn-info" type="submit" value="Change"/>
    </form>

</body>

</html>

<?php
    }
    else {
        $message = "Please login to view this page!";
        echo "<script>alert('$message');</script>";
        header('Refresh:0;url=./index.php');
    }

?>
</div></div></div></div>