var mysql = require('mysql');

exports.connection = mysql.createConnection({
    host: '120.25.219.17',
    port: 3306,
    user: 'lara',
    password: '!QAZ2wsx'
});

try {
    connection.connect();
} catch(e) {}
