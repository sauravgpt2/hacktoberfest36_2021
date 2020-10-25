
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Login Page</title>
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
    <div class="navbar navbar-default navbar-fixed-top">
      <div class="container">
        <div class="navbar-header">
          <a href="admin.php" class="navbar-brand">Login are for Admin</a>
          <button class="navbar-toggle" type="button" data-toggle="collapse" data-target="#navbar-main">
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
        </div>
         <ul class="nav navbar-nav navbar-right">
                
                <li> <a href="./index.php">Back To Home</a></li>
              
        </ul>

        </div>
      </div>
    </div>


  <?php
session_start();

if (isset($_SESSION['message']) and !empty($_SESSION['message'])) {
    echo $_SESSION['message'];
    unset($_SESSION['message']);}

?>
   <div class="container">
   	<div class="col-lg-4"></div>
    <div class="col-lg-4">
   	<h1>Admin Area !</h1>
   	<div class="panel panel-default">
  <div class="panel-body">
   <form class="form-group" action="login.php" method="post">
      <label  class="col-lg-2">Username</label>
      <input class="form-control" type="text" required name="username" />

      <label class="col-lg-2">Password</label>
      <input class="form-control" type="password" required name="password" />
      <br>

      <button class="btn btn-success" type="submit" name="login" />Log In</button>

    </form>
  </div>
  </div>
</div>
    

    
   


    </div>
    <script src="js/jquery-1.10.2.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
  
  </body>
</html>




