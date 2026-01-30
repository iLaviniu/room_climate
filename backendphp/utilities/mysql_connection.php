<?php
    use Dotenv\Dotenv;
    
    require "/home/ilaviniu/backendphpdotenv/vendor/autoload.php";
    
    
    class MySQLConnection {
        /*info link : https://phpenthusiast.com/blog/the-singleton-design-pattern-in-php*/
        private static $servername = "";
        private static $username = "";
        private static $password = "";
        private static $dbname = "";
        private static $conn = null;
        
        private static $instance = null;
        private function __construct() {
            //... constructor
            
            $dotenv = Dotenv::createImmutable("/home/ilaviniu/backendphpdotenv/");  /* folder containing .env */
            $dotenv->load();
            
            self::$servername = $_ENV['DB_HOST'];
            self::$username = $_ENV['DB_USER'];
            self::$password = $_ENV['DB_PASS'];
            self::$dbname = $_ENV['DB_NAME'];
            
            self::$conn = new mysqli(self::$servername, self::$username, self::$password, self::$dbname);
            
            // Check connection
            if (self::$conn->connect_error) {
                header( 'Location: https://www.nestinbase.com/front_end/server_error.php' ); die;
            }
        }
        
        public static function getInstance() {
            if (self::$instance == null) {
                self::$instance = new MySQLConnection();
            }
            return self::$instance;
        }
        
        public static function getConnection() {
            return self::$conn;
        }
        
        public static function close() {
            self::$conn->close();
            self::$conn = null;
        }
        
        public static function isConnectionAlive() {
            if(self::$conn == null) {
                return false;
            } else {
                return true;
            }
        }
    }
?>