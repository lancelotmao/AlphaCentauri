var mysql = require('mysql');

var pool = mysql.createPool({
    connectionLimit : 100, //important
    host: '120.25.219.17',
    port: 3306,
    user: 'lara',
    password: '!QAZ2wsx'
});

exports.getConnection = function(callback) {
    pool.getConnection(function(err, connection) {
        callback(connection);
    });
}
