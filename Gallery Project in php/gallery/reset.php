<?php
/* The password reset form, the link to this page is included
from the forgot.php email message
 */
session_start();

require_once 'include/db.php';

// Make sure email and hash variables aren't empty
if (isset($_GET['email']) && !empty($_GET['email']) and isset($_GET['hash']) && !empty($_GET['hash'])) {
    // Make sure user email with matching hash exist

    $stmt = $con->prepare("SELECT * FROM `login` WHERE email = ? AND `hash`= ?");
    $stmt->bind_param("ss", $_SESSION['email'], $_SESSION['hash']);
    $_SESSION['email'] = $_GET['email'];
    $_SESSION['hash'] = $_GET['hash'];

    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows == 0) {
        $_SESSION['message'] = "You have entered invalid URL for password reset!";
        header("location: ./index.php");
    }
} else {
    $_SESSION['message'] = "Sorry, verification failed, try again!";
    header("location: ./index.php");
}
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
          <a href="index.php" class="navbar-brand">Admin Area !</a>
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




    <?php

if (isset($_SESSION['message']) and !empty($_SESSION['message'])) {
    echo $_SESSION['message'];
    unset($_SESSION['message']);}

?>
      <h1>Choose Your New Password</h1>

      <form class="form-group" action="reset_password.php" method="post">

        <label class="col-lg-4">New Password<span class="req">*</span>
        </label>
        <input class="form-control" type="password" required name="newpassword" />

        <label class="col-lg-6">Confirm New Password<span class="req">*</span>
        </label>
        <input class="form-control" type="password" required name="confirmpassword" /><br>
        <button class="btn btn-success" type="submit">Reset</button>

      </form>
  </body>

  </html>