<?php
session_start();

if (isset($_SESSION['message']) and !empty($_SESSION['message'])) {
    echo $_SESSION['message'];
    unset($_SESSION['message']);}

if (isset($_SESSION['logged_in'])) {
    if ($_SESSION['image'] == '') {
        $dp = 'images/default.png';
    } else {
        $dp = $_SESSION['image'];
    }

    ?>

   
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Admin Area</title>
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
         <ul class="nav navbar-nav navbar-right">
                
                <li><a href="./logout.php">Logout</a></li>
             
                <li><a href="./profile.php">Back to Dashboard</a></li>
        </ul>

        </div>
      </div>
    </div>
    <body>  
<div class="container">
    <div class="col-lg-3"></div>
    <div class="col-lg-8">
    <br>
       <div class="panel panel-default">
        <div class="panel-body">

        <h5>Upload a photo!</h5>
        <img class="img-thumbnail" alt="Profile Picture" src="<?php echo $dp ?>" width="70px" height="80px" alt="error">
        <br>
        <form class="form-group" action="uploaddp.php" method="post" enctype="multipart/form-data">
            <label class="col-lg-2" for="image">Display Picture</label>
            <br>
            <input  class="form-control" type="file" required name="image">
            <br>
            <br>
            <button class="btn btn-success"type="submit" name="upload" >Upload</button>
           

    </body>

    </html>


    <?php
} else {
    $_SESSION['message'] = "Please login to view this page!";
    header('Location: ./index.php');
}

?>