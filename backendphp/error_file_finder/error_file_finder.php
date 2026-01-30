<?php
    include "/home/ilaviniu/backendphp/utilities/email_sender.php";

    $public_html_path = "/home/ilaviniu/public_html/";
    $backendphp_path = "/home/ilaviniu/backendphp/";
    $error_log_list = array();
    $nr_of_error_logs = 0;
    $email_content = "";
    
    /*read all files from public_html dir*/
    $iterator = new RecursiveDirectoryIterator($public_html_path);
    foreach(new RecursiveIteratorIterator($iterator) as $file) {
        
        if(strpos($file, "error_log")) {
        	array_push($error_log_list, $file);
        }
        
    }
    
    /*read all files from backendphp dir*/
    $iterator = new RecursiveDirectoryIterator($backendphp_path);
    foreach(new RecursiveIteratorIterator($iterator) as $file) {
        
        if(strpos($file, "error_log")) {
        	array_push($error_log_list, $file);
        }
        
    }

    /*check if error_log files exists*/    
    $nr_of_error_logs = sizeof($error_log_list);
    if($nr_of_error_logs > 0) {
        foreach ($error_log_list as $log) {
            $email_content .= $log."<br>";
        }
        
        /*send email*/
        $emailSender = new EmailSender("laviniu.ile@gmail.com", "Error Logs", "Error log files have been found in the following directories:<br> ". $email_content);
    }
    
?>