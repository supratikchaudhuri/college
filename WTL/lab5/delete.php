<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script src="https://kit.fontawesome.com/a843b56b38.js" crossorigin="anonymous"></script>
        <title>Delete details</title>

        <style>
            body {
                background-color: #e4e3e3;
            }
            h1 {
                margin: 20px 0;
                text-align: center;
                color: #204051;
            }
            form {
                border: 1px ridge;
                width: 80%;
                margin: auto;
                padding: 15px;
                box-shadow: 1px 1px 25px -10px #204051;
                border-radius: 15px;
                background-color: white;
            }
            form div {
                margin: 10px auto;
                width: 80%;
            }
            form input {
                outline: none;
                padding: 5px;
                width: 80%;
            }
            .btn {
                cursor: pointer;
                padding: 5px 25px;
                background-color: #84a9ac;
                color: black;
                font-weight: bold;
                border-radius: 7px;
                font-size: 1rem;
                margin: 5px auto;
                width: 20%;
                display: inline-block;
            }
            .btn:hover {
                background-color: #3b6978;
            }
            small {
                color: red;
                font-family: Arial, Helvetica, sans-serif;
                font-size: 13px;
                display: block;
                margin: 7px 30px;
            }
            #alert_success,#alert_danger {
                background: white;
                padding: 15px;
                font-weight: bold;
                font-size: 20px;
                color: #6dc26d;
            }
            #alert_danger{
                color:red;
            }
            div i{
                position:absolute;
                right:40px;
                color:black;
            }
        </style>
    </head>

    <body onload="document.Valid.empid.focus()">
        <?php
            $exist = false;
            if($_SERVER['REQUEST_METHOD']=='POST')
            {
                include '_dbconnect.php';
                $empid = $_POST['empid'];
                $exist_sql = "SELECT * FROM `employees` WHERE `empid` = '$empid';";
                $result = mysqli_query($conn,$exist_sql);
                if(mysqli_num_rows($result)>0)
                {
                    $sql = "DELETE FROM `employees` where `empid`='$empid';";
                    $result = mysqli_query($conn,$sql);
                    if($result)
                        echo "<div id='alert_success'>Record deleted successfully!<i class='fa fatimes' onclick='alert_dismiss1()'></i></div>";
                    else
                        echo "<div id='alert_danger'>Error in connection : ".mysqli_error($conn)."<i class='fa fa-times' onclick='alert_dismiss2()'></i></div>";
                }
                else
                    echo "<div id='alert_danger'>Employee ID does not exist!<i class='fa fatimes' onclick='alert_dismiss2()'></i></div>";
            }
        ?>
        <h1>Delete Employee Details</h1>
        <div>
        <form name="Valid" action="delete.php" method="POST">
            <div>
                Employee ID : <input type="text" id="empid" name="empid" onblur="return check_empid()">
                <small id="empid_alert"></small>
            </div>
            <div>
                <input type="submit" class="btn" name="submit" value="Delete">
                <input type="reset" class="btn">
            </div>
        </form>
        </div>
        
        <script>
            function check_empid() {
                empid = document.getElementById("empid").value;
                empid = empid.trim();
                if (empid == "") {
                    document.getElementById("empid_alert").innerHTML = "Employee ID cannot be empty";
                    document.Valid.empid.focus();
                    return false;
                } 
                else if (isNaN(empid)) {
                    document.getElementById("empid_alert").innerHTML = "Employee ID must be a number";
                    document.Valid.empid.focus();
                    return false;
                }
                document.getElementById("empid_alert").innerHTML = "";
                return true;
            }

            function alert_dismiss1()
            {
                document.getElementById("alert_success").style.display="none";
            }

            function alert_dismiss2()
            {
                document.getElementById("alert_danger").style.display="none";
            }
        </script>
    </body>
</html>