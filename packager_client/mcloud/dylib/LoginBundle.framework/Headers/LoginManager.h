//
//  LoginManager.h
//  Login
//
//  Created by lucaiguang on 15/1/28.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MRuntime/MRuntime.h>
#import "LoginApi.h"
@interface LoginManager : MRBundleBase

@property (nonatomic, weak) id<LoginDelegate> delegate;
@property (nonatomic, strong) LoginApi *loginApi;

/*
提供对外接口给其它Bundle或应用调用。
1. 登录请求接口。
2. 用户注销接口。
3. 登录状态查询接口。
4. 用户身份和设备信息查询接口。
*/
///*1、init
/**
 *  <#Description#>
 *
 *  @param bundleName  LoginBundle
 *  @param environment 环境缩写， uat ,sit, pro（联通）
 *  @param netType     内外网，0内网 1 外网
 */
-(void)init:(NSString *)bundleName environment:(NSString *)environment netType:(NSString *)netType;

-(void)initForJS:(NSString *)bundleName environment:(NSString *)environment netType:(NSString *)netType callback:(JSValue *)callback;

//*1、init2
/** uniportal，是否为外网应用，true表示是，false表示不是**/
-(void)init2:(NSString *)bundleName uniportal:(BOOL)uniportal;
-(void)init2ForJS:(NSString *)bundleName uniportal:(BOOL)uniportal processCallbackBinder:(JSValue *)processCallbackBinder;

/**
 * @param map key必须包含bundleName,bundleVersionCode,uniportal
 * @return
 */

-(void)initEx:(NSDictionary *)dictionary;
-(void)initExForJS:(NSDictionary *)dictionary processCallbackBinder:(JSValue *)processCallbackBinder;


///*2、启动LoginBundle的登陆界面，startLoginActivity new
- (void)startLoginActivity:(JSValue *)processCallbackBinder;

- (void)startLoginActivityForJS:(JSValue *)processCallbackBinder;


///2、启动LoginBundle的登陆界面，startLoginActivity old(考虑到以前接口的兼容性保留原先接口)
/* 接口比对删除   by hwx241593
- (void)startLoginActivity:(NSString *)packageName processCallbackBinder:( id)processCallbackBinder;
- (void)startLoginActivityForJS:(NSString *)packageName processCallbackBinder:(JSValue *)processCallbackBinder;
*/

/////*3、login new
//- (void)login:( id)processCallbackBinder;
//
//- (void)loginForJS:(JSValue *)processCallbackBinder;

///*3、login new
- (void)login:( id)processCallbackBinder;

- (void)loginForJS:(JSValue *)processCallbackBinder;


///*3、login old
/*接口比对删除 by hwx241593
- (void)login:(NSString *)username password:(NSString *)password;
- (void)loginForJS:(NSString *)username password:(NSString *)password processCallbackBinder:(JSValue *)processCallbackBinder;
*/


///*4、后台登陆 loginWithNamePwd new
- (void)loginWithNamePwd:(NSString *)username password:(NSString *)password :(id<LoginDelegate>) delegate;

- (void)loginWithNamePwdForJS:(NSString *)username password:(NSString *)password processCallbackBinder:(JSValue *)processCallbackBinder;

///*4、后台登陆 loginWithNamePwd old
/*接口比对删除 by hwx241593
-(void)loginWithNamePwd:(NSString *)packageName username:(NSString *)username password:(NSString *)password processCallbackBinder:(JSValue *)processCallbackBinder;
-(void)loginWithNamePwdForJS:(NSString *)packageName username:(NSString *)username password:(NSString *)password processCallbackBinder:(JSValue *)processCallbackBinder;

*/


///*5、logout
- (void)logout :(id<MRuntimeDelegate>)d;
//- (void)logoutForJS:(JSValue *)processCallbackBinder;

- (void)logoutForJS:(BOOL)toLoginView processCallbackBinder:(JSValue *)processCallbackBinder;


///*6、getIMAuthedInfo
-(void)getIMAuthedInfo:(NSString *)packageName processCallbackBinder:(JSValue *)processCallbackBinder;
//-(void)getIMAuthedInfoForJS:(NSString *)packageName processCallbackBinder:(JSValue *)processCallbackBinder;
-(void)getIMAuthedInfoForJS:(NSDictionary *)dictionary processCallbackBinder:(JSValue *)processCallbackBinder;

-(NSDictionary *)getIMAuthedInfo;

//默认登录不弹出界面接口
-(void)defaultLogin:(id)delegate;


//*7、isLogined判断用户是否已经登陆
-(BOOL)isLogined;
-(BOOL)isLoginedForJS:(NSDictionary *)dictionary processCallbackBinder:(JSValue *)processCallbackBinder;

//*8、//获取用户最新登陆时间，如果没有为0
-(long)getLastLoginTime;
-(long)getLastLoginTimeForJS:(NSDictionary *)dictionary processCallbackBinder:(JSValue *)processCallbackBinder;

//*9、自动登陆,LoginBundle自动获取保存后的加密的用户名和密码
-(void)autoLogin;
-(void)autoLoginForJS:(NSDictionary *)dict processCallbackBinder:(JSValue *)processCallbackBinder;

@end
