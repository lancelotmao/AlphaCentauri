console.log('loading login');

var exports = {
	login: function(argument) {

        var uid = argument.username;
        var pwd = argument.password;

        var successCallback = argument.success;
        var errorCallback = argument.error;

        var identifier = argument.identifier;
        console.log("lucaiguang +++++++++++");
        console.log(identifier);

        if (!identifier) {
            identifier = "default";
        }

        if (this.needRegister(uid, identifier)) {
            console.log("register");
        	this.register({
        		username:uid,
        		password:pwd,
        		success: function(status, info) {
                    console.log("register success");
        			var keychain = new KeyChain();
        			keychain.save(identifier, uid);
                    this.exports.login(argument);
        		},
        		error: function(status, error) {
                    console.log("register error");
                    try {
                        var obj = JSON.parse(error);
                        errorCallback(status, obj.errorMessage);
                    } catch(e) {
                        console.log("ERROR:回调Login error.");
                        errorCallback(status, error);
                    }
        		}
        	});
        	return;
        };

        var env = mcloud.getEnvironment();
        var publicKey = this.getPublickey(env);
        var rsa = new Crypt.RSA();
        var rsaUID = rsa.encode(publicKey, uid);
        var rsaPwd = rsa.encode(publicKey, pwd);

        var encodeRsaUID = encodeURIComponent(rsaUID);
        var encodeRsaPwd = encodeURIComponent(rsaPwd);

        var loginURL = this.getURL(env,"Login");
        console.log("login====loginURL:"+loginURL);
        var setLoginHeader = this.getHeader;

         $.ajax({
         	url: loginURL,
         	async: true,
         	type: "POST",
         	data:"uid="+encodeRsaUID+"&"+"password="+encodeRsaPwd,
         	timeout:30000,
         	beforeSend : function(xhr) {
         		setLoginHeader(rsaUID, xhr, env);
                console.log("beforeSend");
            },
            complete :function(xhr, status) {
                console.log("complete " + status);
            },
            success :function(result , status, xhr) {
                console.log("login ajax success");
                console.log(result);
                try {
                    var obj = JSON.parse(result);
                    if (obj.login == "successed") {
                        successCallback(obj.login, status);
                        xhr.saveCookies(identifier);
                    } else {
                        errorCallback(status, obj.errorMessage);
                    }
                } catch(e) {
                    errorCallback(status, result);
                }
            },
            error :function(xhr , status, error) {
               console.log("ERROR: " + error);
            }
         });
	},
    register: function(argument) {
        var uid = argument.username;
        var pwd = argument.password;
        var successCallback = argument.success;
        var errorCallback = argument.error;

        var env = mcloud.getEnvironment();
        console.log("env = " + env);
        var publicKey = this.getPublickey(env);
        var rsa = new Crypt.RSA();
        var rsaUID = rsa.encode(publicKey, uid);
        var rsaPwd = rsa.encode(publicKey, pwd);
        console.log("rsaUID = " + rsaUID + ", rsaPwd = " + rsaPwd);
        var encodeRsaUID = encodeURIComponent(rsaUID);
        var encodeRsaPwd = encodeURIComponent(rsaPwd);
       // console.log("encodeRsaUID = " + encodeRsaUID);
        var loginURL = this.getURL(env,"DevRegister");
        console.log("loginURL = " + loginURL);
        var setLoginHeader = this.getHeader;

         $.ajax({
         	url: loginURL,
         	async: true,
         	type: "POST",
         	data: "uid="+encodeRsaUID+"&"+"password="+encodeRsaPwd,
         	timeout:30000,
         	beforeSend : function(xhr) {
         		setLoginHeader(rsaUID, xhr, env);
                console.log("beforeSend: rsaUID = " + rsaUID);
            },
            complete :function(xhr, status) {
                console.log("complete: status =  " + status);
            },
            success :function(result , status, xhr) {
                //TODO:注意try catch
                // var obj = JSON.parse(result);
                //用户类型 obj.MagUserType
                //证书 obj.jsonDevCert
                // console.log("lucaiguang" + obj.MagUserType);
                // var cert = JSON.parse(obj.jsonDevCert);
                // console.log("lucaiguang - " + cert.cert);
                // console.log("lucaiguang - " + cert.validTime);
                // console.log("lucaiguang - " + cert.password);
                // console.log("lucaiguang - " + cert.flag);
                // console.log("lucaiguang - " + cert.serialNumber);
                // console.log("lucaiguang - " + cert.certType);

                try {
                    var obj = JSON.parse(result);
                    console.log("register ajax success");
                    if (obj.jsonDevCert) {
                        successCallback(status, "{'success':'success'}");

                    } else {
                        errorCallback(status, result);
                    }
                } catch(e) {
                    console.log("register ajax error");
                    errorCallback(status, result);
                }
            },
            error :function(xhr , status, error) {
            	console.log("errorCallback: error = " + error);
            	errorCallback(status, error);
            }
         });

    },
    getURL: function(enviroment, port) {

    	if (enviroment == "pub") {
    		return "http://w3m.huawei.com/mcloud/umag/" + port;
    	} else if (enviroment == "unicom") {
    		return "http://haepub-gw.huawei.com/mcloud/umag/" + port;
    	} else if (enviroment == "sit") {
    		return "http://w3m-alpha.huawei.com/mcloud/mag/" + port;
    	} else {
    		return "http://w3m-beta.huawei.com/mcloud/mag/" + port;
    	}
    },
    getHeader: function(rsausername, xhr, enviroment) {
    	var acceptLanguage = xhr.getAcceptLanguage();
    	var ip = xhr.getIPAddress();
    	var operator = xhr.getOperator();
    	var networkType = xhr.getNetworkState();
    	var sessionKey;
    	if (enviroment == "pub" || enviroment == "unicom") {
    		sessionKey = rsausername;
        } else {
    		sessionKey = "aRIyNxmMSDEj7lWBwY0a9bve+AyMbeM7PhxOBlpDL/J0HuLUI2JAepTP/FIkWWbSzctMETVK52DUAI2ArI2RRuRqqhDMYCuc/959hxcYg7agHB8VGR2UD4tu0d70yUvBFlKRFsiZPkkqkbw45QB50lSVeoj1Ah5hROLq6IIOsyQ=";
    	}
    	console.log("sessionKey=========="+sessionKey);
    	
    	xhr.setRequestHeader("sessionKey", sessionKey);
    	xhr.setRequestHeader("Accept-Language", acceptLanguage);
    	xhr.setRequestHeader("network",networkType);
    	xhr.setRequestHeader("sp",operator);
    	xhr.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
    	xhr.setRequestHeader("ip",ip);
    	xhr.setRequestHeader("bundleVersion","1.1.2");
        xhr.setRequestHeader("bundleName","LoginBundle");
    },
    getPublickey: function(enviroment) {
    	if (enviroment == "pub" || enviroment == "unicom") {
    		return "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDGZ8X4L60JTz2nhNhJPcnLSguN+mJsm/UOZIU8fKY2OI7K6WRMfNC2U7hStea6uoVPmcAXixMhKm6l3Aa7yK5crxE4rw9NkBmz1JDJa0X0k1yUWucDgz9XxpJsQQ0Alm3hmOSPnZM5ZmcJfm+yEAoc+9fNfZ2FBA3g69vlgWe7YwIDAQAB";
    	} else {
    		return "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDbf3N5eW+PgmaLBvDE23uMjdJW/eTrT8Hrx/fUvPcgeCoGqP8czJkFy2/XtDfWzaQJ1crPZTU/jGPPUIYeG7bWM61UHsMvDFos8F/RJhnreYML52MwRE55aD8AC0UOs0UxGBtT0ByG874qM8nOanN2Homy/hsJjj/HzQZuQ/vWUQIDAQAB";
    	}
    },
    needRegister: function(username, identifier) {
    	var keychain = new KeyChain();
        var oldUsername = keychain.get(identifier);
        console.log(oldUsername);
    	if (oldUsername == username) {
    		return false;
    	}
    	return true;
    },

};