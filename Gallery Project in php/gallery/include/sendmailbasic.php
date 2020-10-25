<?php

	function email_std($email_id,$subject,$body)
	{

		$mail_to = $email_id;
		$mail_sub = $subject;
		$From_name= "Veronica";
		$mail_content = $body;

		require_once('PHPMailer-master/PHPMailerAutoload.php');

		$mail = new PHPMailer(true);
		$mail->IsSMTP(); // telling the class to use SMTP

		try
		{


			/*For Gmail*/
			/*
			$mail->Host       = "smtp.gmail.com";   // SMTP server
			$mail->SMTPAuth   = true;              // enable SMTP authentication
			$mail->SMTPSecure = "ssl";            // sets the prefix to the servier
			$mail->Port       = 465;             // set the SMTP port for the GMAIL
			Also change login credentials
			*/


			/*For Yandex Mail*/
			$mail->Host = 'smtp.yandex.com';  // Specify main and backup SMTP servers
			$mail->SMTPAuth = true;                               // Enable SMTP authentication
			$mail->SMTPSecure = 'tls';                            // Enable TLS encryption, `ssl` also accepted
			$mail->Port = 587;                                    // TCP port to connect to

			$mail->Username = '';                 // SMTP username
			$mail->Password = '';                           // SMTP password
			$mail->From = '';
			$mail->FromName = $From_name;

			$mail->addReplyTo('', 'No-reply');
			$mail->addAddress($mail_to,"User 1");
			$mail->Subject = $mail_sub;
			$mail->AltBody = 'To view the message, please use an HTML compatible email viewer!'; // optional - MsgHTML will create an alternate automatically
			$mail->Body = $mail_content;
			if($mail->Send())
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		catch (phpmailerException $e)
		{
			echo "Error : ".$e->errorMessage();
		}
		catch (Exception $e)
		{
			echo $e->getMessage();
		}
	}
?>
