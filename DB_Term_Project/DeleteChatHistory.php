

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
        $ChatCode=$_POST['ChatCode'];

    mysqli_query($conn, "DELETE FROM CHATTING WHERE ChatCode={$ChatCode}; ");
    }

?>
        <form method="post">
            <input type="number" name="ChatCode" placeholder="ChatCode(int)">
            <br><br>
            <input type="submit" name="INSERT1" value="DELETE">    
            </form>
            <br>
            <table>
      <thead>
        <tr>
          <th>ChatCode</th>
          <th>ChatHistory</th>
        </tr>
      </thead>
      <tbody>
        <?php
          $conn=mysqli_connect('192.168.167.3', 'leeingyu', '1234', 'leeingyu_term',4567);
          $sql = "SELECT * FROM CHATTING;";
          $result = mysqli_query( $conn, $sql );
          while( $row = mysqli_fetch_array( $result ) ) {
            echo
            '<tr>'  
            .'<td>'
              . $row[ 'ChatCode' ]
              . '</td>'
              .'<td>'
              . $row[ 'ChatHistory' ]
              . '</td>'
              ;
          }
        ?>
      </tbody>
    </table>
        </body>
</html>
