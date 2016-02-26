var mysql = require('mysql');
var connection = mysql.createConnection({
	host: '120.25.219.17',
	port: 3306,
	user: 'lance',
	password: 'm9l0d6',
	database: 'aran'
});

connection.connect();

connection.query('select * from user;', function(err, rows, fields){
	console.log('', rows);
});