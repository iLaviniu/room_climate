<?php
    $php_scripts_root = str_replace("public_html", "backendphp/",$_SERVER['DOCUMENT_ROOT'] );
    include $php_scripts_root.'utilities/constants.php';
    include $php_scripts_root.'utilities/mysql_connection.php';

    ob_start(); //this should be first line of your page
    session_start();

    $account_user = $_POST["username"];
    $account_password = $_POST["password"];
    $account_hashed_password = password_hash($account_password, PASSWORD_BCRYPT);
    
    // Create connection
    MySQLConnection::getInstance();
    
    /*check if user already exists*/
    $sql_user_exists = "select username from users where username = '".$account_user."'";
    $result_user_exists = (MySQLConnection::getConnection())->query($sql_user_exists);
    
    if($result_user_exists->num_rows == 0) {

        $sql_insert = "insert into users (username, password, role, code_reset_password, crp_date_time) values ('".$account_user."', '".$account_hashed_password."', '".admin."', '000000', '0000-00-00 00:00:00')";
        $sql_insert_result = (MySQLConnection::getConnection())->query($sql_insert);

        (MySQLConnection::getConnection())->close();

        if($sql_insert_result == true) {
            $_SESSION['userStatus'] = "administrator added successfully!";
            $_SESSION['userLoggedIn'] = false;
            header("Location: https://www.nestinbase.com/register_intent/register_intent.php");
        } else {
            header( 'Location: https://www.nestinbase.com/errors/server_error.php' ); die;
        }
        
    } else {
        $_SESSION['userStatus'] = "user already registered!";
        $_SESSION['userLoggedIn'] = false;
        header("Location: https://www.nestinbase.com/register_intent/register_intent.php");
    }
?>