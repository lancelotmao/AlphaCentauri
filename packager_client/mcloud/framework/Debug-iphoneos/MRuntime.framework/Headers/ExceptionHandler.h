//
//  "ExceptionHandler.h"
//  ExceptionHandler
//
//  Created by StevenHu on 14-11-13.
//  Copyright (c) 2014年 HuaWei. All rights reserved.
//
/**
 *  获取crash崩溃日志接口
 *
 */
#import <UIKit/UIKit.h>

#define CRASH_LOG_FILENAME    @"CrashLog"

@interface ExceptionHandler : NSObject{
	BOOL dismissed;
}

/**
 *  获取崩溃日志文件路径
 *
 *  @return 崩溃日志文件路径
 */
+ (NSString*)getCrashLogDir;
+ (NSString *)getCrashLogFilePath;

@end

void InstallUncaughtExceptionHandler(void);
