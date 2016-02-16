//
//  LogManager.h
//  MRuntime
//
//  Created by hexiang on 15/7/14.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, LogManagerPrintLevel)
{
    LogManagerPrintLevelVerbose    ,
    LogManagerPrintLevelProcess    ,
};

@protocol LogManagerDelegate <NSObject>

- (void)mCloud_Log:(id)msg;

@end

@interface LogManager : NSObject

/**
 *  日志实例
 *
 *  @return 返回日志类实例
 */
+ (instancetype)sharedInstance;

@property (nonatomic, weak) id<LogManagerDelegate> delegate;

#pragma mark - Setter

- (void)setUserID:(unsigned long long)userID; 
- (void)setEnableConsoleLog:(BOOL)enableConsol;
- (void)setEnableFileLog:(BOOL)enableFile;
- (void)setPrintLevel:(LogManagerPrintLevel)level;

#pragma mark - Getter

/**
 *  获取操作日志，系统日志和崩溃日志的文件目录
 *
 */
- (NSString *)getOperateLogDir;
- (NSString *)getSystemLogDir;
- (NSString *)getCrashLogDir;

/**
 *  获取操作日志，系统日志和崩溃日志当天的文件
 *
 */
- (NSString *)currentOperateLogFilePath;
- (NSString *)currentSystemLogFilePath;
- (NSString *)currentCrashLogFilePath;

/**
 * 大数据日志接口
 */
- (BOOL)setupBigData:(NSDictionary *)param;
- (void)logBigData:(NSString *)message packageName:(NSString *)packageName;
- (NSArray *)bigDataLogFilesForUpload;

#pragma mark - Operate Log

- (void)logInfoMessage:(NSString *)message;
- (void)logInfoMessage:(NSInteger)traceid :(NSString *)message;

#pragma mark - System Log

- (void)logProcessMessage:(NSString *)message;
- (void)logErrorMessage:(NSString *)message;
- (void)logWarningMessage:(NSString *)message;
- (void)logDebugMessage:(NSString *)message;
- (void)logVerboseMessage:(NSString *)message;

- (void)logProcessMessage:(NSInteger)traceid :(NSString *)message;
- (void)logErrorMessage:(NSInteger)traceid :(NSString *)message;
- (void)logWarningMessage:(NSInteger)traceid :(NSString *)message;
- (void)logDebugMessage:(NSInteger)traceid :(NSString *)message;
- (void)logVerboseMessage:(NSInteger)traceid :(NSString *)message;

#pragma mark - log for JS
- (void)logProcessMessageForJS:(NSString *)traceid :(NSString *)message ;
- (void)logErrorMessageForJS:(NSString *)traceid :(NSString *)message;
- (void)logWarningMessageForJS:(NSString *)traceid :(NSString *)message;
- (void)logDebugMessageForJS:(NSString *)traceid :(NSString *)message;
- (void)logVerboseMessageForJS:(NSString *)traceid :(NSString *)message;

- (void)logWarningMessageForJS:(NSString *)message;
- (void)logProcessMessageForJS:(NSString *)message;
- (void)logErrorMessageForJS:(NSString *)message;
- (void)logDebugMessageForJS:(NSString *)message;
- (void)logVerboseMessageForJS:(NSString *)message;
- (void)logInfoMessageForJS:(NSString *)message;


@end
