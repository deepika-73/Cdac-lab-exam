<head>
    <title>Movies</title>
    <meta charset="utf-8" />
   <link rel="stylesheet" type="text/css" href="../css/list.css">
</head>

<body>
<div class="main">
            
    <div class="title">
        <h1>Movie list</h1>
    </div>

    <div class="list">
    <?php
   include "dbConnect.php" ;
    $sql ="SELECT movieId, movie_name, director FROM movies ";
    $result = mysqli_query($connect,$sql);
    $MovieId="";
    $MovieName="";
    $MovieDirector="";
    echo "<table>"."<th>"."Movie Id".'</th> <th> '."Movie Name".'</th> <th>'. "Director Name".'</th>';
    while($row=mysqli_fetch_assoc($result))
    {
    $MovieId=$row['movieId'];
    $MovieName=$row['movie_name'];
    $MovieDirector=$row['director'];
    echo '<tr> <td>'.$MovieId.'</td> <td> ' . $MovieName.'</td> <td> ' .$MovieDirector.'</td></tr>';
    }
    echo "</table>";

    ?>
    </div>
 
</div>
</body>
