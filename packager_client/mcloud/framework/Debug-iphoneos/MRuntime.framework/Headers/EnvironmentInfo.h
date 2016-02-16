//
//  EnvInfo.h
//  LogBundle
//
//  Created by hexiang on 15/5/27.
//  Copyright (c) 2015年 HuaWei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface EnvironmentInfo : NSObject

+ (instancetype)sharedInstance;

- (NSString *)getCallerInfo:(NSInteger)level;

- (NSInteger)getThreadID;

- (NSString *)getNetworkType;

- (NSString *)getIPAddress;

- (NSString *)getAppInfo;

- (NSString *)getDeviceInfo;

- (NSString *)getNetworkService;

- (NSString *)getEnvInfo;

- (BOOL)createLogDir:(NSString *)dir;

- (NSString *)getCurrentDate:(NSDate *)date;

- (NSString *)getLogFileName:(NSString *)flag;

@end
