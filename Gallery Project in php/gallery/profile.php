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
  
  <?php

  error_reporting( ~E_NOTICE ); // avoid notice
  
  require_once 'include/dbconfig.php';
  
  if(isset($_POST['btnsave']))
  {
    $username = $_POST['user_name'];// user name
    $userjob = $_POST['user_job'];// user email
    
    $imgFile = $_FILES['user_image']['name'];
    $tmp_dir = $_FILES['user_image']['tmp_name'];
    $imgSize = $_FILES['user_image']['size'];
    
    
    if(empty($username)){
      $errMSG = "Please Enter Photo Name";
    }
    else if(empty($userjob)){
      $errMSG = "Please Enter Category.";
    }
    else if(empty($imgFile)){
      $errMSG = "Please Select Photo.";
    }
    else
    {
      $upload_dir = 'user_images/'; // upload directory
  
      $imgExt = strtolower(pathinfo($imgFile,PATHINFO_EXTENSION)); // get image extension
    
      // valid image extensions
      $valid_extensions = array('jpeg', 'jpg', 'png', 'gif'); // valid extensions
    
      // rename uploading image
      $userpic = rand(1000,1000000).".".$imgExt;
        
      // allow valid image file formats
      if(in_array($imgExt, $valid_extensions)){     
        // Check file size '5MB'
        if($imgSize < 5000000)        {
          move_uploaded_file($tmp_dir,$upload_dir.$userpic);
        }
        else{
          $errMSG = "Sorry, your file is too large.";
        }
      }
      else{
        $errMSG = "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";    
      }
    }
    
    
    // if no error occured, continue ....
    if(!isset($errMSG))
    {
      $stmt = $DB_con->prepare('INSERT INTO tbl_users(userName,userProfession,userPic) VALUES(:uname, :ujob, :upic)');
      $stmt->bindParam(':uname',$username);
      $stmt->bindParam(':ujob',$userjob);
      $stmt->bindParam(':upic',$userpic);
      
      if($stmt->execute())
      {
        $successMSG = "new record succesfully inserted ...";
        //header("refresh:5;index.php"); // redirects image view page after 5 seconds.
      }
      else
      {
        $errMSG = "error while inserting....";
      }
    }
  }
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Admin Area !</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <link rel="stylesheet" href="css/bootstrap.css" media="screen">
    <link rel="stylesheet" href="css/custom.min.css">
    <script>
    //To check wether both the passwords are same
    function validate() {
      if (document.getElementById('password').value == document.getElementById('password2').value)
        return true;
      else {
        alert('Passwords do not match!');
        return false;
      }
    } 
  </script>
  </head>

  <body>
    <h1>Hey
            <?php echo $_SESSION['username'] ?>
        </h1>
    <div class="navbar navbar-default navbar-fixed-top">
      <div class="container">
        <div class="navbar-header">
          <a href="profile.php" class="navbar-brand">Admin</a>
          <button class="navbar-toggle" type="button" data-toggle="collapse" data-target="#navbar-main">
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
        </div>
         <ul class="nav navbar-nav navbar-right">
                <li><img src="<?php echo $dp ?>" width="50px" height="50px" alt="error"></li>
                <li><a href="./logout.php">Logout</a></li>
                <li> <a href="./change.php">Change your password</a></li>
                <li><a href="./changedp.php">Change your display picture</a></li>
        </ul>

        </div>
      </div>
    </div>

  <!--   Photo Uploading code -->
<div class="container">
  <div class="page-header">
      <h3 class="h3">Add new Photos! <!-- <a class="btn btn-primary" href="index.php"> <span class="glyphicon glyphicon-eye-open"></span> &nbsp; view all </a> --></h3>
    </div>
    

  <?php
  if(isset($errMSG)){
      ?>
            <div class="alert alert-danger">
              <span class="glyphicon glyphicon-info-sign"></span> <strong><?php echo $errMSG; ?></strong>
            </div>
            <?php
  }
  else if(isset($successMSG)){
    ?>
        <div class="alert alert-success">
              <strong><span class="glyphicon glyphicon-info-sign"></span> <?php echo $successMSG; ?></strong>
        </div>
        <?php
  }
  ?>   

<form method="post" enctype="multipart/form-data" class="form-horizontal">
      
  <table class="table table-bordered table-responsive">
  
    <tr>
      <td><label class="control-label">Photo Name</label></td>
        <td><input class="form-control" type="text" name="user_name" placeholder="Enter Photo Name" value="<?php ?>" /></td>
    </tr>
    
    <tr>
      <td><label class="control-label">Category</label></td>
        <td><input class="form-control" type="text" name="user_job" placeholder="Enter Category" value="<?php  ?>" /></td>
    </tr>
    
    <tr>
      <td><label class="control-label">Insert Photo</label></td>
        <td><input class="form-control" type="file" name="user_image" accept="image/*" /></td>
    </tr>
    
    <tr>
        <td colspan="2"><button type="submit" name="btnsave" class="btn btn-success">
        <span class="glyphicon glyphicon-save"></span> &nbsp; Save
        </button>
        </td>
    </tr>
    
    </table>
    
</form>


   

       
       
    </body>

    </html>
    <?php
} else {
    $_SESSION['message'] = '<div class="alert alert-dismissible alert-info">
  <button type="button" class="close" data-dismiss="alert">&times;</button>
  Please login to view this page!</div>';
    header('Location: ./index.php');
}

?>