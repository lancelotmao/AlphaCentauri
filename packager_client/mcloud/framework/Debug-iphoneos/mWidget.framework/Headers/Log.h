//
//  Log.h
//  MRuntime
//
//  Created by Nil on 13/10/15.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MRView.h"
@protocol LogExport <JSExport>

- (void)log:(JSValue *)message;
- (void)setEnableConsoleLog:(BOOL)enableConsoleLog;
- (void)setEnableFileLog:(BOOL)enableFileLog;
- (void)setPrintLevel:(double)printLevel;

- (void)printProcess:(NSString *)traceID :(NSString *)message;
- (void)printError:(NSString *)traceID :(NSString *)message;
- (void)printWarning:(NSString *)traceID :(NSString *)message;
- (void)printInfo:(NSString *)traceID :(NSString *)message;
- (void)printDebug:(NSString *)traceID :(NSString *)message;
- (void)printVerbose:(NSString *)traceID :(NSString *)message;

@end

@interface Log : NSObject<LogExport>

@end
