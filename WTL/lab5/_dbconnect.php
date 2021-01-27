<?php
    $servername = "localhost:3307";
    $username = "root";
    $password = "";
    $database = "ems";

    $conn = mysqli_connect($servername,$username,$password,$database);

    if($conn->connection_error)
        die("Connection to database failed ");

    // $con = mysqli_connect($servername,$username,$password,$database);

    // // Check connection
    // if (mysqli_connect_errno()) {
    //     echo "Failed to connect to MySQL: " . mysqli_connect_error();
    //     exit();
    // }
?>