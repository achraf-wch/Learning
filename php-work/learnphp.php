<?php
(int) $x = 5;
function hi() : void
{
    global $x; // get $ xevven if its not insde the fun
    echo $x;
    echo  $GLOBALS['x'];// do the same of global 
}
hi();
echo '<br />';
/////////////////////////////////////////////////
//static 
// the same idea which we saw in c++

function trystatic($how)
{
   static $stnum = $how;
    return $stnum++;
}
$how2 = 1;
echo trystatic($how2);
echo trystatic($how2);
echo trystatic($how2);
echo '<br />';
/////////////////////////////////////////////
//function take a lot of vars
function vars(int ...$numbers)
{
    echo array_sum($numbers);
    echo count($numbers);
    $sum = 0;
    for($i = 0;$i<count($numbers);$i++)
    {
           $sum+=$numbers[$i];
    }
    echo $sum;
}
 vars(1,2,3);
 echo '<be />';
///////////////////////////////////////////////////
//call a function with variables
function h($g)
{
    return $g;
}
$h = 'h';
echo $h(2);
echo '<br />';
/////////////////////////////////////////////
//anonymous functio : funs with  no name and also passing by reference
$ano = 2;
$an= function (int &$ano)
{
    $ano=0;
    return $ano;
};
echo $an($ano);
echo $ano . '<br />';
$arr = [1,3,5];
$anon = array_map(function($item){return $item+2;},$arr);
//arrow array
$aw = fn() => "hello";

/////////////////////////////////////////////////
//date time
date_default_timezone_set('UTC');//u put a default time pf utc u can put it or not
echo time() . '<br/>';
echo date('d/m/y g:ia', time()+48*60*60) . '<b />';//time() its added to the now time
//////////////////////////////////////////////////////
var_dump(ini_get('error_reporting')) . '<br/>';
var_dump(E_ALL);

?>