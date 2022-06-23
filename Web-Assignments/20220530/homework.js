var mysql = require('mysql');

var con = mysql.createConnection({
    host: "localhost",
    user: "root",
    password: "root",
    database: "university"
})

con.connect(function (err) {
    if (err) throw err;
    console.log("Connected!");

    //Database Create
    con.query("CREATE DATABASE university", function (err, result) {
        if (err) throw err;
        console.log("Database created");
    })


    //Table Create
    var sql = "CREATE TABLE student (" +
        "id INT PRIMARY KEY," +
        "name VARCHAR(255)," +
        "major VARCHAR(255)," +
        "grade VARCHAR(255)," +
        "email VARCHAR(255)" +
        ")";

    con.query(sql, function (err, result) {
        if (err) throw err;
        console.log("Table created");
    });

    //Insert values
    var sql = "INSERT INTO student (id,name,major,grade,email) VALUES ?";
    var values = [
        [1000, 'Tim', 'Computer', 'Male', 'tim@gmail.com'],
        [1001, 'Sonya', 'Art', 'Female', 'sonya@naver.com'],
        [1002, 'Brain', 'Social', 'Male', 'Brain@yahoo.com'],
        [1003, 'Natasha', 'Math', 'Female', 'natasha@outlook.com']
    ];
    con.query(sql, [values], function (err, result) {
        if (err) throw err;
        console.log("Number of records inserted: " + result.affectedRows);
    });


    //insert result
    var sql = "SELECT id,name,major,grade,email FROM student";


    //Show result
    con.query(sql, function (err, result, fields) {
        if (err) throw err;
        console.log(result);
    })

    //Use Where Query to print tables with id<=1001
    var sql = "SELECT * FROM student WHERE id<=1001";
    con.query(sql, function (err, result, fields) {
        if (err) throw err;
        console.log(result);
    })

    //Update emails to 123@naver.com
    var sql = "UPDATE student SET email = '123@naver.com'";
    con.query(sql, function (err, result) {
        if (err) throw err;
        console.log(result.affectedRows + " record(s) updated");
    });

    //Delete item with id=1001
    var sql = "DELETE FROM student WHERE id = 1001";
    con.query(sql, function (err, result) {
        if (err) throw err;
        console.log("Number of records deleted: " + result.affectedRows);
    });

    //Show result  
    var sql = "SELECT id,name,major,grade,email FROM student";

    con.query(sql, function (err, result, fields) {
        if (err) throw err;
        console.log(result);
    })

})