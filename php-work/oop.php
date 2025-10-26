<?php 
class produit {
    public $name;
    public $prix;
    const charika = 'ibm';
    private $qte;
    public function set(int $n,int $p,int $q){
        $this->name = $n;
        $this->prix= $p;
        $this->qte = $q;
        //echo self::charika;

    }
    public function j()
    {
        echo 2;
        echo $this->prix;
        echo self::charika;
    }
    
}
class po extends produit{
private $gmail;
public function fun(int $g)
{
    $this->gmail = $g;
}
public function print()
{
    echo $this->gmail;
}
}
//////////////////////////////////////////////////////////::::
//abstraction
abstract class achraf{
   abstract public function sayhi();
   abstract public function sayho($say);
}
class adam extends achraf{
    public function sayhi(){
        echo 'hi';
    }
    public function sayho($say){
             echo $say;
    }
}
//////////////////////////////////////////////////////////////////////
//polymorphism
interface aya{
   public function sayhi();
  public function sayho($say);
}
class ayman implements aya{
    public function sayhi(){
        echo 'hi';
    }
    public function sayho($say){
             echo $say;
    }
}
class rachid implements aya{
    public function sayhi(){
        echo 'hey';
    }
    public function sayho($say){
             echo $say;
    }
}
////////////////////////////////////////////////////////////////
//magic methods
class cl{
    private $color;
    public function __construct($co)
    {
      $this->color = $co;   
    }
    public function __destruct(){
        echo 'the project has beind deleted';
    }
    public function __call($method,$arg){
        echo 'the function has not being foound';
    }
    public function __get($att)
    {
        echo'the attribut has not being found';
    }
    public function __set($att,$arg)
    {
        echo 'you can not set this att cuz it is potected or private';
    }

}
///////////////////////////////////////////////////////:::::
//traits and chaining methods
trait fe1{
    function sayhello()
    {
        echo 'hello';
        return $this;
    }

}
trait fe2{
    function dayhay()
    {
        echo 'hi';
        return $this;
    }
}
class feat{
    use fe1;
    use fe2;
    function sayhi()
    {
        echo 'hii';
        return $this;
    }
}



$ob = new feat();
$ob->dayhay()->sayhello()->sayhi();







?>