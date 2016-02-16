//
//  MRConfigBundle.h
//  MRConfigBundle
//
//  Created by rossyang on 14/11/20.
//  Copyright (c) 2014 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MRuntime/MRuntime.h>
//! Project version number for MRConfigBundle.
FOUNDATION_EXPORT double MRConfigBundleVersionNumber;

//! Project version string for MRConfigBundle.
FOUNDATION_EXPORT const unsigned char MRConfigBundleVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <MRConfigBundle/PublicHeader.h>
@interface MRConfigBundle : MRBundleBase

- (NSString *)getValueFromConfig:(NSString *) packageName key:(NSString *) key;

- (NSDictionary *)getMultiValuesFromConfig:(NSString *)packageName keys:(NSArray *) keys;

- (NSString *)getLoginUrl:(NSString *)packageName;

- (NSString *)getUpgradeUrl:(NSString *)packageName;

- (NSString *)getW3UpdateUrl:(NSString *)packageName;

- (NSString *)getChangePwdUrl:(NSString *)packageName;

- (NSString *)getProxy;

- (void)setProxy:(NSString *)proxyUrl;

- (NSString *)getAppEnvironment;

- (void)setAppEnvironment:(NSString *)environment;

- (void)releaseResource:(NSString *)packageName;

- (NSString *)getRetrievePwdUrl;

- (NSString *)getW3RetrivePwdUrl;

- (NSString *)getLogoutUrl;
- (NSString *)getDevRegisterUrl;

- (NSString *)getHostUrl:(BOOL)isLogin;
- (NSString *)getHostUrlForJS:(BOOL)isLogin :(JSValue *)callback;
/**
 *    用于给原生调用的符合两个参数，并且第一个参数为NSDictionary的函数
 */
- (NSString *)getValueFromConfig:(NSDictionary *)params :(id)result;
/**
 *    原生调用，直接返回一个NSDictionary
 *
 *    @param params 要带的参数
 *    @param result 直接返回值
 *
 *    @return 返回值
 */
- (NSDictionary *)getMultiValuesFromConfig:(NSDictionary *)params :(id)result;

- (NSString *)createCommonValue:(NSString *)key value:(id)value;
- (id)getCommonValue:(NSString *)key;
- (id)getCommonValueForJS:(NSString *)key defaultValue:(NSString *)defvalue binder:(JSValue *)jsFunction;
- (NSString *)createCommonValueForJS:(NSString *)key value:(id)value binder:(JSValue *)jsFunction;
- (BOOL)updateCommonValue:(NSString *)key value:(id)value;
- (BOOL)updateCommonValueForJS:(NSString *)key value:(id)value binder:(JSValue *)jsFunction;

- (BOOL)savePrivateValue:(NSString *)bundleName key:(NSString *)key value:(id)value;
- (BOOL)savePrivateValueForJS:(NSString *)packageName key:(NSString *)key value:(id)value binder:(JSValue *)jsFunction;
- (id)getPrivateValue:(NSString *)bundleName key:(NSString *)key;
- (id)getPrivateValueForJS:(NSString *)packageName key:(NSString *)key defaultValue:(NSString *)defValue binder:(JSValue *)jsFunction;
- (BOOL)removePrivateValue:(NSString *)packageName key:(NSString *)key;
- (BOOL)removePrivateValueForJS:(NSString *)packageName key:(NSString *)key binder:(JSValue *)jsFunction;

//SSO
- (void)saveSSOCookie:(NSString *)urlKey cookie:(NSData *)cookies;
- (NSData *)getSSOCookie:(NSString *)urlKey;
- (void)removeAllSSOCookie;


//KeyChain
- (BOOL)saveKeyChain:(NSString *)key value:(NSString *)value ;
- (BOOL)saveKeyChainByte:(NSString *)key value:(NSData *)value;
- (NSData *)getKeyChainByte:(NSString *)key;
- (void)removeKeyChain:(NSString *)key;
- (void)removeAllKeyChain;

#pragma mark - 安全包

/**
 * @function 检验用户证书是否有效
 * @param    (NSString *)userName : 用户名
 * @return   (BOOL)               : 校验结果
 */
- (BOOL)validateUserCertWithUserName:(NSString *)userName;

/**
 * @function 检验设备证书是否有效
 * @param    (NSString *)userName : 用户名
 * @return   (BOOL)               : 校验结果
 */
- (BOOL)validateDeviceCertWithUserName:(NSString *)userName;


/**
 * @function 根据用户名创建新的SessionKey
 * @param    (NSString *)userName : 用户名
 * @return   NSString *           : sessionKey
 */
- (NSString *)createSessionKeyWithUserName:(NSString *)userName withPublicKey:(NSString*)publicKey;


/**
 * @function 保存SessionKey超时时间
 * @param    (long)time : 超时时间
 * @return   BOOL       : 保存结果
 */
- (BOOL)saveSessionKeyExpirationWithTime:(NSNumber *)time;


/**
 * @function 保存DevCertPwd到keychain中
 * @param    (NSString *)pwd      :  需要保存的设备证书密码
 * @param    (NSString *)userName :  用户名
 * @return   BOOL                 :  保存结果
 */
- (BOOL)storeDevCertPwd:(NSString *)pwd withUserName:(NSString *)userName;

/**
 * @function 保存PinByPubDev到keychain中
 * @param    (NSString *)pinByPubDev :  需要保存的pinByPubDev
 * @param    (NSString *)userName    :  用户名
 * @return   BOOL                    :  保存结果
 */
- (BOOL)storePinByPubDev:(NSString *)pinByPubDev withUserName:(NSString *)userName;


/**
 * @function 保存fKeyByPubUser到keychain中
 * @param    (NSString *)fKeyByPubUser :  需要保存的fKeyByPubUser
 *           (NSString *)userName      :  用户名
 * @return   BOOL                      :  保存结果
 */
- (BOOL)storeFKeyByPubUser:(NSString *)fKeyByPubUser withUserName:(NSString *)userName;


/**
 * @function 保存指定用户的用户证书和设备证书
 * @param    (NSString *)userCert      :  需要保存的用户证书
 *           (NSString *)deviceCert    :  需要保存的设置证书
 *           (NSString *)userName      :  用户名
 * @return   BOOL                      :  保存结果
 */
- (BOOL)storeUserCert:(NSString *)userCert deviceCert:(NSString *)deviceCert withUserName:(NSString *)userName;

/**
 * @function 删除用户名下的用户证书和设备证书、登陆信息
 * @param*
 *           (NSString *)userName      :  用户名
 */
- (void)clearAll:(NSString *)userName;

- (BOOL)dtmAesEncrypt:(NSString *)plainText :(void (^)(NSString *))completionBlock;
- (BOOL)dtmAesDecrypt:(NSString *)encryptedText :(void (^)(NSString *))completionBlock;

@end


