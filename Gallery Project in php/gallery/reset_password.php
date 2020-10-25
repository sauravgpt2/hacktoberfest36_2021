<?php
/* Password reset process, updates database with new user password */
session_start();

require_once 'include/db.php';

function unique_salt()
{
    return substr(sha1(mt_rand()), 0, 22);
}

// Make sure the form is being submitted with method="post"
if ($_SERVER['REQUEST_METHOD'] == 'POST') {

    // Make sure the two passwords match
    if ($_POST['newpassword'] == $_POST['confirmpassword']) {

        // We get $_POST['email'] and $_POST['hash'] from the session variables

        $stmt = $con->prepare("UPDATE `login` SET `password`=? , `hash` = ? WHERE `email`=?");
        $stmt->bind_param("sss", $new_password, $new_hash, $_SESSION['email']);

        $new_password = password_hash($_POST['newpassword'], PASSWORD_BCRYPT);
        $new_hash = password_hash(unique_salt(), PASSWORD_BCRYPT);

        if ($stmt->execute()) {
            $_SESSION['message'] = '<div class="alert alert-dismissible alert-success">
  <button type="button" class="close" data-dismiss="alert">&times;</button>
Your password has been reset successfully! Please login to continue!</div>';
            header('Location: ./index.php');
        }

        unset($_SESSION['hash']);
        unset($_SESSION['email']);

    } else {
        $_SESSION['message'] = '<div class="alert alert-dismissible alert-warning">
  <button type="button" class="close" data-dismiss="alert">&times;</button>
  <h4>Warning!</h4>
Two passwords you entered don\'t match, try again!</div>';
        header("location: ./reset_password.php");
    }

}
