

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
        DELETE();
    }
    function DELETE(){
        $conn=mysqli_connect('192.168.167.3', 'leeingyu', '1234', 'leeingyu_term',4567);
        $ID=$_POST['ID'];
       
    mysqli_query($conn, "DELETE FROM USER1 WHERE UserID={$ID};");
    }
?>
        <form method="post">
            <input type="number" name="ID" placeholder="ID(int)">
             <br><br>
            <input type="submit" name="INSERT1" value="DELETE">    
            </form>
            <br>
            <table>
      <thead>
        <tr>
          <th>ID</th>
          <th>PW</th>
          <th>Name</th>
          <th>Age</th>
          <th>NickName</th>
        </tr>
      </thead>
      <tbody>
        <?php
          $conn=mysqli_connect('192.168.167.3', 'leeingyu', '1234', 'leeingyu_term',4567);
          $sql = "SELECT * FROM USER1;";
          $result = mysqli_query( $conn, $sql );
          while( $row = mysqli_fetch_array( $result ) ) {
            echo
            '<tr>'  
            .'<td>'
              . $row[ 'UserID' ]
              . '</td>'
              .'<td>'
              . $row[ 'PW' ]
              . '</td>'
              .'<td>'
              . $row[ 'Name' ]
              . '</td>'
              .'<td>'
              . $row[ 'Age' ]
              . '</td>'
              .'<td>'
              . $row[ 'NickName' ]
              . '</td>'
              .'</tr>'
            ;
          }
        ?>
      </tbody>
    </table>
        </body>
</html>
