//
//  MRTimer.h
//  MRAPI
//
//  Created by Nil on 7/1/15.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <JavascriptCore/JavaScriptCore.h>

@interface MRTimer : NSObject
@property (nonatomic, strong) NSTimer *timer;
@property (nonatomic, strong) JSValue *jsFunction;
- (void)start:(JSValue*)callback :(int)time; //旧API ,先保留
- (void)startTimerWithInterval:(double)interval delay:(double)delay isRepeat:(BOOL)isRepeat andCallBack:(JSValue *)callBack;
- (void)stop;


@end
