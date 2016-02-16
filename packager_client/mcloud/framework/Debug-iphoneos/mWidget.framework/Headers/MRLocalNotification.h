//
//  MRLocalNotification.h
//  MRuntime
//
//  Created by Nil on 16/4/15.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MRView.h"
@interface MRLocalNotification :MRView<MRJSView>
/**
 * 本地推送，最多支持64个
 * @param fireDate 本地推送触发的时间
 * @param alertBody 本地推送需要显示的内容
 * @param badge 角标的数字。如果不需要改变角标传-1
 * @param alertAction 弹框的按钮显示的内容（IOS 8默认为"打开",其他默认为"启动"）
 * @param notificationKey 本地推送标示符
 * @param userInfo 自定义参数，可以用来标识推送和增加附加信息
 * @param soundName 自定义通知声音，设置为nil为默认声音
 
 * IOS8新参数
 * @param region 自定义参数
 * @param regionTriggersOnce 自定义参数
 * @param category 自定义参数
 */

-(void)setLocalNotification:(NSUInteger )fireDate
                   alertBody:(NSString *)alertBody
                 alertAction:(NSString *)alertAction;
- (void)showNotification:(NSString *)title :(NSDictionary *)content;

-(void)registerLocalNotification;

/**
 * 本地推送在前台推送。默认App在前台运行时不会进行弹窗，在程序接收通知调用此接口可实现指定的推送弹窗。
 * @param notification 本地推送对象
 * @param notificationKey 需要前台显示的本地推送通知的标示符
 */
//+(void)showLocalNotificationAtFront:(UILocalNotification *)notification
//                      identifierKey:(NSString *)notificationKey;

/**
 * 删除本地推送
 * @param notificationKey 本地推送标示符
 * @param myUILocalNotification 本地推送对象
 */
-(void)cancelNotification;

/**
 * 获取指定通知
 * @param notificationKey 本地推送标示符
 * @return  本地推送对象数组,[array count]为0时表示没找到
 */
- (void)findNotification;

/**
 * 清除所有本地推送对象
 */
-(void)clearAllLocalNotifications;


@end
