//
//  MRPush.h
//  MRuntime
//
//  Created by Nil on 2/6/15.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MRPushListener <NSObject>

- (BOOL)onPushNotification:(NSDictionary *)userInfo;

@end


@interface MRPush : NSObject 
@property (nonatomic, assign) id<MRPushListener>delegate;

+(MRPush *)sharedPush;

- (void)registerPushServer;
/**
 * @brief 向服务器注册 device token
 * @param
 *     deviceToken - 通过 AppDelegate 中的 didRegisterForRemoteNotificationsWithDeviceToken 回调获取
 * @return
 *     none
 */
- (void)registerDeviceToken:(NSString *)deviceToken;

/**
 * @brief 在didReceiveRemoteNotification中调用，用于推送反馈
 * @param
 *     userInfo
 * @return
 *     none
 */
-(void)handleNotification:(NSDictionary *)userInfo;


@end
