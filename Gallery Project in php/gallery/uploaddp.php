<?php

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    
        require_once 'include/db.php';
        session_start();
        //This is the directory where images will be saved
        $target = "images/";
        $target = $target . $_SESSION['username'] . '.jpg';

        if (!move_uploaded_file($_FILES['image']['tmp_name'], $target)) {
            //Checks if there was problem uploading it to server
            $_SESSION['message'] =  "There was problem uploading your image! Please try again with a different image after loggin in!<br>";
            header("Location: ./changedp.php");

        } else {

            $stmt= $con->prepare("UPDATE `login` SET `image` =? WHERE `username` = ?");
            $stmt->bind_param("ss",$target,$_SESSION['usernmae']);
            
            if (!$stmt->execute()) {
                //In case SQL query does not update the value do something
                
            } else {
                $_SESSION['message'] = '<div class="alert alert-dismissible alert-success">
  <button type="button" class="close" data-dismiss="alert">&times;</button><strong>Upload successful!</strong></div>';
                $_SESSION['image'] = $target;
                header('Location: profile.php');
            }

        }

}
