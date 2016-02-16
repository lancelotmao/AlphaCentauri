//
//  SecurityLockManager.h
//  SecurityLock
//
//  Created by lucaiguang on 15/5/21.
//  Copyright (c) 2015年 HuaWei. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^SecurityLockBlock)(int,id);

@interface SecurityLockManager : NSObject

/**************************************************************/
// 初始化
// 参数:
//			strUser-[IN]用户名
// 返回值: YES-成功      NO-失败
/**************************************************************/
- (BOOL)init:(NSString *)strUser;

/**************************************************************/
// 进入后台
// 参数:
//			strUser-[IN]用户名
// 返回值:
/**************************************************************/
- (void)applicationDidEnterBackground:(NSString *)strUser;

/**************************************************************/
// 进入前台
// 参数:
//			strUser-[IN]用户名
//			parentVC-[IN]父UIViewController
//			bShow-[IN]是否必须显示锁屏界面
//			image-[IN]用户头像
//			PwdErrorCallBack-[IN]密码错误回调函数
// 返回值:
/**************************************************************/
- (void)applicationDidBecomeActive:(NSString *)strUser parentVC:(UIViewController *)parentVC IsMustShow:(NSNumber *)bShow userPortrait:(UIImage *)image completion:(SecurityLockBlock)PwdErrorCallBack;

/**************************************************************/
// 显示手势设置页面
// 参数:
//			strUser-[IN]用户名
//			PwdErrorCallBack-[IN]密码错误回调函数
// 返回值:
/**************************************************************/
- (void)ShowGestureSettingPage:(NSString *)strUser completion:(SecurityLockBlock)PwdErrorCallBack;

/**************************************************************/
// 检测是否强制锁屏
// 参数:
//			strUser-[IN]用户名
//			PwdErrorCallBack-[IN]密码错误回调函数
// 返回值:
/**************************************************************/
- (void)CheckIsForceLockScreen:(NSString *)strUser completion:(SecurityLockBlock)PwdErrorCallBack;

@end
