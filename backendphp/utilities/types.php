<?php
class NewComer {
    private $userid = "";
    private $username = "";
    private $date_time = "";
    
    function __construct($userid, $username, $date_time) {
        $this->userid = $userid;
        $this->username = $username;
        $this->date_time = $date_time;
    }
    
    public function getUserID() {
        return $this->userid;
    }
    
    public function getUsername() {
        return $this->username;
    }
    
    public function getDateTime() {
        return $this->date_time;
    }
    
    public function toString(){
        return "User ID: ".$this->userid."; Username: ".$this->username."; Date-Time: ".$this->date_time;
    }
}

class User {
    private $userindex = "";
    private $username = "";

    function __construct($userindex, $username) {
        $this->userindex = $userindex;
        $this->username = $username;
    }
    
    public function getUserIndex() {
        return $this->userindex;
    }
    
    public function getUsername() {
        return $this->username;
    }
    
    public function toString(){
        return "User Index: ".$this->userindex."; Username: ".$this->username;
    }
}

class UserAndRole {
    private $userindex = "";
    private $username = "";
    private $role = "";

    function __construct($userindex, $username, $role) {
        $this->userindex = $userindex;
        $this->username = $username;
        $this->role = $role;
    }
    
    public function getUserIndex() {
        return $this->userindex;
    }
    
    public function getUsername() {
        return $this->username;
    }
    
    public function getUserRole() {
        return $this->role;
    }
    
    public function toString(){
        return "User Index: ".$this->userindex."; Username: ".$this->username."; UserRole: ".$this->role;
    }
}
?>