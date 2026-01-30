<?php
    use PHPMailer\PHPMailer\PHPMailer;
    use PHPMailer\PHPMailer\Exception;
    use Dotenv\Dotenv;
    
    require "/home/ilaviniu/backendphp/utilities/PHPMailer/src/Exception.php";
    require "/home/ilaviniu/backendphp/utilities/PHPMailer/src/PHPMailer.php";
    require "/home/ilaviniu/backendphp/utilities/PHPMailer/src/SMTP.php";
    require "/home/ilaviniu/backendphpdotenv/vendor/autoload.php";


    class EmailSender {
        private static $smtpDebug = "";
        private static $hostName = "";
        private static $userName = "";
        private static $password = "";
        private static $smtpSecure = "";
        private static $smtpPort = "";
        
        private static $senderName = "";
        private static $senderTag  = "";
        
        private static $receiverName = "";
        private static $receiverTag  = "";
        
        private static $replyToName = "";
        private static $replyToTag  = "";
        
        private static $subject = "";
        private static $body = "";
        
        private static $sender = null;
        
        public function __construct($account_user, $subject, $body) {
            
            $dotenv = Dotenv::createImmutable("/home/ilaviniu/backendphpdotenv/");  /* folder containing .env */
            $dotenv->load();
            
            self::$smtpDebug = $_ENV['MAIL_SMTP_DBG'];
            self::$hostName = $_ENV['MAIL_HOST'];
            self::$userName = $_ENV['MAIL_USERNAME'];
            self::$password = $_ENV['MAIL_PASS'];
            self::$smtpSecure = $_ENV['MAIL_SMTP_SECURE'];
            self::$smtpPort = $_ENV['MAIL_SMTP_PORT'];
            
            self::$senderName = $_ENV['MAIL_SENDER_NAME'];
            self::$senderTag  = $_ENV['MAIL_SENDER_TAG'];
            
            self::$receiverName = $_ENV['MAIL_SECEIVER_NAME'];
            self::$receiverTag  = $_ENV['MAIL_SECEIVER_TAG'];
            
            self::$replyToName = $_ENV['MAIL_REPLY_TO_NAME'];
            self::$replyToTag  = $_ENV['MAIL_REPLY_TO_TAG'];
            
            self::$receiverName = $account_user;
            self::$subject = $subject;
            self::$body = $body;
            
            self::$sender = new PHPMailer(true);
            
            self::$sender->SMTPDebug = self::$smtpDebug;    /* Enable verbose debug output */
            self::$sender->isSMTP();                        /* Set mailer to use SMTP */
            self::$sender->Host = self::$hostName;          /* SMTP server host name */
            self::$sender->SMTPAuth = true;                 /* Enable SMTP authentication */
            self::$sender->Username = self::$userName;      /* SMTP username */
            self::$sender->Password = self::$password;      /* SMTP password */
            self::$sender->SMTPSecure = self::$smtpSecure;  /* Enable TLS encryption, [ICODE]ssl[/ICODE] also accepted */
            self::$sender->Port = self::$smtpPort;          /* SMTP port */
            
            self::$sender->setFrom(self::$senderName, self::$senderTag);
            self::$sender->addAddress(self::$receiverName, self::$receiverTag);
            self::$sender->addReplyTo(self::$replyToName, self::$replyToTag);
            
            self::$sender->isHTML(true);
            self::$sender->Subject = self::$subject;
            self::$sender->Body = self::$body;
            
            self::$sender->send();
        }
    }
?>