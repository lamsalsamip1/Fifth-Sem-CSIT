<?php

class user{
    public $name;
    public $email;
    public function disp_user(){
        echo "The user's name is $this->name";
    }
}

$user1 = new user;
$user1->name="John";
$user1->disp_user();


?>