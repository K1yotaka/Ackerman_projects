<?php

include("./config.php");
$servername = $db_host;
$dbname = $db_name;
$username = $db_user;
$password = $db_pass;

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("连接失败: " . $conn->connect_error);
}

//$sql = "CREATE TABLE MyGuests (
//    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
//    firstname VARCHAR(30) NOT NULL,
//    lastname VARCHAR(30) NOT NULL,
//    email VARCHAR(50),
//    reg_data TIMESTAMP
//)";
//
//if ($conn->query($sql) === TRUE) {
//    echo "Table MyGuests created successfully";
//} else {
//    echo "创建数据表错误: " . $conn->error;
//}

// 检测插入单条数据是否成功

//$sql = "INSERT INTO MyGuests (firstname,lastname,email) VALUES ('John','Doe','john@example.com')";
//
//if ($conn->query($sql) == TRUE)
//    echo "Succesful!";
//else
//    echo "Error: " . $sql . "<br>" . $conn->error;
//

// 检测插入多条数据是否成功

$sql = "INSERT INTO MyGuests (firstname, lastname, email)
VALUES ('John', 'Doe', 'john@example.com');";
$sql .= "INSERT INTO MyGuests (firstname, lastname, email)
VALUES ('Mary', 'Moe', 'mary@example.com');";
$sql .= "INSERT INTO MyGuests (firstname, lastname, email)
VALUES ('Julie', 'Dooley', 'julie@example.com')";

if ($conn->multi_query($sql) == TRUE)
    echo "Succesful!";
else
    echo "Error: " . $sql . "<br>" . $conn->error;


$conn->close();