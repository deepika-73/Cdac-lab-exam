<?php

include "dbConnect.php" ;

$MovieId = $_POST['Movie'];
$MovieName = $_POST['MovieName'];
$DirectorName = $_POST['DirectorName'];


$sql="INSERT INTO movies (movieId,movie_name, director) VALUES ( '".$MovieId."', '".$MovieName."', '".$DirectorName."')";

if(mysqli_query($connect,$sql))
{
    echo "Successful";
    header("Location:list.php");
}
else{
    echo "Error".mysqli_error($connect);
}
?>
