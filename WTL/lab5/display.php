<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script src="https://kit.fontawesome.com/a843b56b38.js" crossorigin="anonymous"></script>
        <title>Display details</title>

        <style>
            body {
                background-color: #e4e3e3;
                color: #204051;
            }
            h1 {
                margin: 20px 0;
                text-align: center;
                color: #204051;
            }
            #alert_success,
            #alert_danger {
                background: white;
                padding: 15px;
                font-weight: bold;
                font-size: 20px;
                color: #6dc26d;
            }
            #alert_danger {
                color: red;
            }
            div i{
                position: absolute;
                right: 40px;
                color: black;
            }
            table{
                font-family: 'Times New Roman', Times, serif;
                font-size: 15px;
                line-height: 15px;
                width: 70%;
                margin: 45px auto;
            }
            table tr th{
                padding: 10px;
                margin: 3px;
                background-image: linear-gradient(#3b6978, #84a9ac);
                color:white;
                font-size:17px;
            }
            table tr:first-child th{
                border: 2px solid blue;
                border-top-left-radius: 5px;
                border-top-right-radius: 5px;
                border-bottom: 3px solid blue;
            }
            table tr td{
                background-color: #3b6978;
                padding: 13px;
                margin: 2px;
                opacity:0.7;
                border-radius: 3px;
                text-shadow: 1px 1px -1px black;
            }
            table tr td:nth-child(2),table tr td:nth-child(3){
                text-align: center;
            }
            table tr td:hover{
                opacity:1;
            }
        </style>

    </head>

    <body>
        <h1>Employee Details</h1>
        <table>
            <tr><th>Employee ID</th>
            <th>Employee name</th>
            <th>Department Name</th>
            <th>Phone number</th>
            <th>Date of joining</th></tr>
        </table>

        <?php
            $exist = false;
            include '_dbconnect.php';
            $sql = "SELECT * FROM `employees`;";
            $result = mysqli_query($conn,$sql);
            if(mysqli_num_rows($result)>0)
            {
                while($row = mysqli_fetch_assoc($result))
                {
                    $empid = $row['empid'];
                    $name = $row['empname'];
                    $dept = $row['deptname'];
                    $phone = $row['phno'];
                    $date = $row['jdate'];
                    echo "<tr>
                    <td>$empid</td>
                    <td>$name</td>
                    <td>$dept</td>
                    <td>$phone</td>
                    <td>$date</td>
                    </tr>";
                }
            }
            else
            {
                echo "<div id='alert_danger'>No record exists!<i class='fa fa-times' onclick='alert_dismiss2()'></i></div>";
            }
        ?>
        <script>
            function alert_dismiss2()
            {
                document.getElementById("alert_danger").style.display="none";
            }
        </script>
    </body>
</html>