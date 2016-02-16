//
//  SecurityHelper4iOS.h
//  Test
//
//  Created by mCloud on 15/4/10.
//  Copyright (c) 2015年 mCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface SecurityHelper4iOS : NSObject
/**
 * @function 获取userKey
 * @param    (NSString *)userName : 用户名
 * @return   (NSString *)         : userKey
 */
- (NSString *)userKeyByUserName:(NSString *)userName;

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
 * @function 获得SessionKey
 * @return   NSString * : sessionKey
 */
- (NSString *)sessionKey:(NSString*)publicKey;

/**
 * @function 根据userName获得SessionKey
 * @param    (NSString *)userName : 用户名
 * @return   NSString *           : sessionKey
 */
- (NSString *)sessionKeyByUserName:(NSString *)userName withPublicKey:(NSString*)publicKey;

/**
 * @function 创建新的SessionKey
 * @return   NSString * : sessionKey
 */
- (NSString *)createSessionKey:(NSString *)publicKey;

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
- (BOOL)saveSessionKeyExpirationWithTime:(int)time;

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
 * @function 保存用户证书和设备证书有效期
 * @param*
 *           (NSString *)userName      :  用户名
 */
- (BOOL)storeCertValidTime:(NSString *)userCertTime deviceCertTime:(NSString*)deviceCertTime withUserName:(NSString *)userName;
/**
 * @function 删除用户名下的用户证书和设备证书、登陆信息
 * @param*
 *           (NSString *)userName      :  用户名
 */
+ (void)clearAll:(NSString *)userName;

/**
 * @function 删除用户名下的登陆信息
 * @param*
 *           (NSString *)userName      :  用户名
 */
+ (void)clearLoginInfo:(NSString *)userName;



#pragma mark - private method, for test only
- (BOOL)validateCert:(NSString *)strCert userName:(NSString *)userName certPassword:(NSString *)certPassword;

- (BOOL)storeTestUserName;

- (NSString *)decryptDevicePwd:(NSString *)pwd;


@end
