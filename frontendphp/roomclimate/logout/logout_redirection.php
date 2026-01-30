<?php
    ob_start(); //this should be first line of your page
    session_start();

    if(isset($_SESSION['userLoggedIn'])) {
        if(false == $_SESSION['userLoggedIn']) {
            header("Location: https://www.nestinbase.com/roomclimate/login/login.php");
        } else {
            require '../../../backendphp/scripts/logout/logout.php';
        }
    } else if(!isset($_SESSION['userLoggedIn'])) {
        header("Location: https://www.nestinbase.com/roomclimate/login/login.php");
    }
?>