<?php
session_start();
  include 'include/dbconfig.php';
  $stmt = $DB_con->prepare('SELECT userID, userName, userProfession, userPic FROM tbl_users ORDER BY userID DESC');
  $stmt->execute();
?>

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Photo Gallery</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <link rel="stylesheet" href="css/bootstrap.css" media="screen">
    <link rel="stylesheet" href="css/custom.min.css">
    <link href="dist/lightbox.css" rel="stylesheet">
      
  </head>

  <body>
    <div class="navbar navbar-default navbar-fixed-top">
      <div class="container">
        <div class="navbar-header">
          <a href="index.php" class="navbar-brand">Home</a>
          <button class="navbar-toggle" type="button" data-toggle="collapse" data-target="#navbar-main">
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
        </div>
         <ul class="nav navbar-nav navbar-right">
               <li><a href="./admin.php">Log In</a></li>
                
        </ul>
            

        </div>
      </div>
    </div>


  <?php


if (isset($_SESSION['message']) and !empty($_SESSION['message'])) {
    echo $_SESSION['message'];
    unset($_SESSION['message']);}

?>
<br>
<div class="container">
   
   	<div class="panel panel-default">
    <div class="panel-body">
      <h4>Photo Gallery</h4>
 <?php
  
  if($stmt->rowCount() > 0)
  {
    while($row=$stmt->fetch(PDO::FETCH_ASSOC))
    {
      extract($row);
      ?>

       
     <div class="col-md-1">
        
        <a class="example-image-link" href="user_images/<?php echo $row['userPic']; ?>" data-lightbox="example-1"><img class="example-image" src="user_images/<?php echo $row['userPic']; ?>" style="height: 70px;width: 70px" alt="image-1" />
         <caption><?php echo $row['userName']; ?></caption>
        </a>
        
         
     </div>
  <?php
    }
  }
  else
  {
    ?>
        <div class="col-xs-12">
          <div class="alert alert-warning">
              <span class="glyphicon glyphicon-info-sign"></span> &nbsp; No Data Found ...
            </div>
        </div>
        <?php
  }
  
?>
</div>  


</div>   
</div>
</div>
<footer>


</footer>


  
    <script src="dist/lightbox-plus-jquery.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
  
  </body>
</html>




