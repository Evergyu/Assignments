var mysql=require('mysql');

var con=mysql.createConnection({
    host:"localhost",
    user:"root",
    password:"root",
    database:"mydb"
});

con.connect(function(err){
    var sql="SELECT Name, Major, Grade,Email FROM student";

    con.query(sql,function(err,result,fields){
        if(err) throw err;
        console.log(result);
    })
})

/*
con.connect(function(err){
    if(err) throw err;
    console.log("Connected!");

    var sql="CREATE TABLE customers ("+
        "id INT PRIMARY KEY,"+
        "name VARCHAR(255),"+
        "address VARCHAR(255)"+
        ")";

    con.query(sql,function(err,result){
        if(err) throw err;
        console.log("Table created");
    });
})
*/