

<!doctype html>
<html>
    <style>
        a{text-decoration:none; color:blue;}
        body{text-align:center}
      table {
        width: 100%;
      }
      th, td {
        padding: 10px;
        border-bottom: 1px solid #dadada;
      }
    </style>
    <head>
        <meta charset="utf-8">
        <title>Leeingyu</title>
    </head>
    <body>
        <h1>Insert User</h1>
        <h1><a href="index.php">Back to Index</a></h1>
        
<?php
    error_reporting(E_ALL);
    ini_set('display_errors', '1');

    if(array_key_exists('INSERT1',$_POST)){
        INSERT();
    }
    function INSERT(){
        $conn=mysqli_connect('192.168.167.3', 'leeingyu', '1234', 'leeingyu_term',4567);
        $RoomCode=$_POST['RoomCode'];
        $UserID=$_POST['UserID'];
        $ChatCode=$_POST['ChatCode'];

    mysqli_query($conn, "INSERT INTO CHATROOM (RoomCode,UserID,ChatCode) VALUES({$RoomCode},{$UserID},{$ChatCode})");
    }

?>
        <form method="post">
            <input type="number" name="RoomCode" placeholder="RoomCode(int)">
            <input type="number" name="UserID" placeholder="UserID(int)">
            <input type="number" name="ChatCode" placeholder="ChatCode(int)">
            <br><br>
            <input type="submit" name="INSERT1" value="INSERT">    
            </form>
            <br>
            <table>
      <thead>
        <tr>
          <th>RoomCode</th>
          <th>UserID</th>
          <th>ChatCode</th>
        </tr>
      </thead>
      <tbody>
        <?php
          $conn=mysqli_connect('192.168.167.3', 'leeingyu', '1234', 'leeingyu_term',4567);
          $sql = "SELECT * FROM CHATROOM;";
          $result = mysqli_query( $conn, $sql );
          while( $row = mysqli_fetch_array( $result ) ) {
            echo
            '<tr>'  
            .'<td>'
              . $row[ 'RoomCode' ]
              . '</td>'
              .'<td>'
              . $row[ 'UserID' ]
              . '</td>'
              .'<td>'
              . $row[ 'ChatCode' ]
              . '</td>'
            ;
          }
        ?>
      </tbody>
    </table>
        </body>
</html>
