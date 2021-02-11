<?php



$connect=mysqli_connect("localhost","root","","movies");
if($connect==false)
{
    die("error:connection failed".mysqli_connect_error($connect));

}
else
    echo "";

?>