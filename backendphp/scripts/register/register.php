<?php
    use PHPMailer\PHPMailer\PHPMailer;
    use PHPMailer\PHPMailer\Exception;

    $php_scripts_root = str_replace("public_html", "backendphp/",$_SERVER['DOCUMENT_ROOT'] );
    include $php_scripts_root.'utilities/constants.php';
    include $php_scripts_root.'utilities/mysql_connection.php';
    
    require $php_scripts_root.'utilities/PHPMailer/src/Exception.php';
    require $php_scripts_root.'utilities/PHPMailer/src/PHPMailer.php';
    require $php_scripts_root.'utilities/PHPMailer/src/SMTP.php';

    ob_start(); //this should be first line of your page
    session_start();
    
    $account_user = $_POST["username"];
    $account_password = $_POST["password"];
    $register_code_mail = $_POST["registercode"];
    
    if(empty($_POST)) {
        die();
    }
    
    if( ($account_user === "") || ($account_password === "") || ($register_code_mail === "") ) {
        die();
    }
    
    // Create connection
    MySQLConnection::getInstance();
    
    /*check if account_user exists in table newcomersintent*/
    $sql_newcomersintent = "select * from newcomersintent where email='".$account_user."'";
    $sql_newcomersintent_result = (MySQLConnection::getConnection())->query($sql_newcomersintent);
    
    if($sql_newcomersintent_result->num_rows == 1) {
        $row = $sql_newcomersintent_result->fetch_row();
        
        /*get registration code from data base*/
        $register_code_db = $row[1];
        
        /*get register code expiration*/
        $register_code_expiration = $row[2]; 
        
        /*get time-date now*/
        $date_now = date("Y-m-d H:i:s");
        $thisMoment = new DateTime($date_now);
        
        $expirationMoment = new DateTime($register_code_expiration);
        if($thisMoment > $expirationMoment) {
            /*register code expired!*/
            /*Close MySQL connection*/
            MySQLConnection::close();
            $_SESSION['userStatus'] = "register code expired!";
            header("Location: https://www.nestinbase.com/roomclimate/register_intent/register_intent.php");
        } else {
            /*register code valid!*/
            
            /*comparison between register code from mail and register code from data base*/
            if(intval($register_code_mail) == intval($register_code_db)) {
                
                /*encrypt new password*/
                $password_hashed = password_hash($account_password, PASSWORD_BCRYPT);
                
                $sql_insert_newComer = "insert into newcomers (username, password, date_time) values ('".$account_user."', '".$password_hashed."', '".$date_now."')";
                $sql_insert_newComer_result = (MySQLConnection::getConnection())->query($sql_insert_newComer);
        
                if ($sql_insert_newComer_result == true) {
          
                    /*remove email from newcomersintent table*/
                    $sql_remove_email = "delete from newcomersintent where email='".$account_user."'";
                    $sql_remove_email_result = (MySQLConnection::getConnection())->query($sql_remove_email);
                    
                    MySQLConnection::close();
                    $_SESSION['userStatus'] = "administrator acceptance needed!";
                    header("Location: https://www.nestinbase.com/roomclimate/login/login.php");
                } else {
                    MySQLConnection::close();
                    header( 'Location: https://www.nestinbase.com/roomclimate/errors/server_error.php' ); die;
                }
            } else {
                /*invalid password reset code*/
                /*Close MySQL connection*/
                MySQLConnection::close();
                $_SESSION['userStatus'] = "invalid register code!";
                header("Location: https://www.nestinbase.com/roomclimate/register/register.php");
            }
        }
        
    } else {
        /*Close MySQL connection*/
        MySQLConnection::close();
        $_SESSION['userStatus'] = "register request failed!";
        header("Location: https://www.nestinbase.com/roomclimate/register/register.php");
    }
    
?>