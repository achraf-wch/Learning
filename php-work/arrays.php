<?php

(string)$x ='2';
(int)$y = "4";

$achraf=['hi','ach','so'];
print_r($achraf);
echo count($achraf);
$achraf[]='php';
array_push($achraf, 'si','bo');
print_r($achraf);
$arr = [
    'achraf' => '9',
    'anass' => '9'
];

unset($achraf[1]);
echo $arr['achr'];
echo(array_key_exists('achraf',$arr));
/*
assigement operation : += *= -+
aritmhetique operation : = + -
comperasion operation : == >= <= 

*/
require 'petie.php';
require_once 'petit.php';
include 'petit.php';
include_once '.petit.php';
    ?>